#pragma once

#include <ReactCommon/TurboModule.h>
#include <fbjni/fbjni.h>
#include <jsi/jsi.h>
#include <memory>
#include <string>

namespace scizers {
namespace calllogs {

class CallLogsModuleJNI : public facebook::jni::HybridClass<CallLogsModuleJNI> {
public:
  static constexpr auto kJavaDescriptor = "Lcom/scizers/callLogs/CallLogTurboModule;";

  static facebook::jni::local_ref<jhybriddata> initHybrid(facebook::jni::alias_ref<jhybridobject> jThis);

  static void registerNatives();

  facebook::jsi::Value load(facebook::jsi::Runtime &rt, int limit);

  facebook::jsi::Value loadWithFilter(facebook::jsi::Runtime &rt, int limit, facebook::jsi::Object filter);

  facebook::jsi::Value loadAll(facebook::jsi::Runtime &rt);

private:
  friend HybridBase;
  facebook::jni::alias_ref<CallLogsModuleJNI::jhybridobject> javaPart_;

  explicit CallLogsModuleJNI(facebook::jni::alias_ref<jhybridobject> jThis);
};

class CallLogsTurboModule : public facebook::react::NativeTurboModule {
public:
  CallLogsTurboModule(std::shared_ptr<CallLogsModuleJNI> javaModule);

  static std::shared_ptr<facebook::react::TurboModule> create(
      const std::string &moduleName,
      const facebook::react::JavaTurboModule::InitParams &params);

private:
  facebook::jsi::Value load(
      facebook::jsi::Runtime &rt,
      const facebook::jsi::Value &thisValue,
      const facebook::jsi::Value *args,
      size_t count);

  facebook::jsi::Value loadWithFilter(
      facebook::jsi::Runtime &rt,
      const facebook::jsi::Value &thisValue,
      const facebook::jsi::Value *args,
      size_t count);

  facebook::jsi::Value loadAll(
      facebook::jsi::Runtime &rt,
      const facebook::jsi::Value &thisValue,
      const facebook::jsi::Value *args,
      size_t count);

  std::shared_ptr<CallLogsModuleJNI> javaModule_;

protected:
  facebook::react::MethodMap<facebook::react::NativeTurboModule::MethodMetadata> const &getMethodsMap() override;
};

} // namespace calllogs
} // namespace scizers
