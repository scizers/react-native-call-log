#include "CallLogsModule.h"
#include <android/log.h>
#include <fbjni/fbjni.h>
#include <jsi/jsi.h>
#include <react/jni/JCallback.h>
#include <ReactCommon/TurboModuleUtils.h>
#include <memory>
#include <string>

using namespace facebook;
using namespace facebook::jni;
using namespace facebook::jsi;
using namespace facebook::react;

namespace scizers {
namespace calllogs {

CallLogsTurboModule::CallLogsTurboModule(std::shared_ptr<CallLogsModuleJNI> javaModule)
    : NativeTurboModule("CallLogs", javaModule), javaModule_(javaModule) {}

std::shared_ptr<TurboModule> CallLogsTurboModule::create(const std::string &moduleName, const JavaTurboModule::InitParams &params) {
  auto javaModule = std::make_shared<CallLogsModuleJNI>(params.javaClassLocalRef);
  return std::make_shared<CallLogsTurboModule>(javaModule);
}

jsi::Value CallLogsTurboModule::load(jsi::Runtime &rt, const jsi::Value &thisValue, const jsi::Value *args, size_t count) {
  if (count < 1) {
    throw jsi::JSError(rt, "CallLogsModule.load: Expected at least 1 argument");
  }

  int limit = args[0].getNumber();

  return javaModule_->load(rt, limit);
}

jsi::Value CallLogsTurboModule::loadWithFilter(jsi::Runtime &rt, const jsi::Value &thisValue, const jsi::Value *args, size_t count) {
  if (count < 2) {
    throw jsi::JSError(rt, "CallLogsModule.loadWithFilter: Expected at least 2 arguments");
  }

  int limit = args[0].getNumber();
  jsi::Object filterObj = args[1].getObject(rt);

  return javaModule_->loadWithFilter(rt, limit, std::move(filterObj));
}

jsi::Value CallLogsTurboModule::loadAll(jsi::Runtime &rt, const jsi::Value &thisValue, const jsi::Value *args, size_t count) {
  return javaModule_->loadAll(rt);
}

MethodMap<CallLogsTurboModule::MethodMetadata> const &CallLogsTurboModule::getMethodsMap() {
  static const MethodMap<MethodMetadata> methodMap = {
      {"load", {1, &CallLogsTurboModule::load}},
      {"loadWithFilter", {2, &CallLogsTurboModule::loadWithFilter}},
      {"loadAll", {0, &CallLogsTurboModule::loadAll}},
  };
  return methodMap;
}

} // namespace calllogs
} // namespace scizers
