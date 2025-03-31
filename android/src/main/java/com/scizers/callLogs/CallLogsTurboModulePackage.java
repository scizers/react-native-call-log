package com.scizers.callLogs;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

import com.facebook.react.ReactPackage;
import com.facebook.react.bridge.NativeModule;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.module.model.ReactModuleInfo;
import com.facebook.react.module.model.ReactModuleInfoProvider;
import com.facebook.react.turbomodule.core.interfaces.TurboModule;
import com.facebook.react.turbomodule.core.TurboModuleManagerDelegate;
import com.facebook.react.uimanager.ViewManager;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class CallLogsTurboModulePackage implements ReactPackage, TurboModuleManagerDelegate.Provider {

    @NonNull
    @Override
    public List<ViewManager> createViewManagers(@NonNull ReactApplicationContext reactContext) {
        return Collections.emptyList();
    }

    @NonNull
    @Override
    public List<NativeModule> createNativeModules(@NonNull ReactApplicationContext reactContext) {
        List<NativeModule> modules = new ArrayList<>();
        modules.add(new CallLogTurboModule(reactContext));
        return modules;
    }

    @Nullable
    @Override
    public TurboModuleManagerDelegate getTurboModuleManagerDelegate(@NonNull ReactApplicationContext reactContext) {
        return new CallLogsTurboModuleManagerDelegate(reactContext);
    }

    public static class CallLogsTurboModuleManagerDelegate extends TurboModuleManagerDelegate {
        private final ReactApplicationContext mReactContext;
        private final Map<String, TurboModule> mModules = new HashMap<>();

        public CallLogsTurboModuleManagerDelegate(ReactApplicationContext reactContext) {
            super();
            mReactContext = reactContext;
        }

        @Nullable
        @Override
        public TurboModule getModule(String name) {
            if (name.equals("CallLogs")) {
                if (!mModules.containsKey(name)) {
                    mModules.put(name, new CallLogTurboModule(mReactContext));
                }
                return mModules.get(name);
            }
            return null;
        }

        @NonNull
        @Override
        public List<String> getEagerInitModuleNames() {
            return Collections.emptyList();
        }
    }

    public static ReactModuleInfoProvider getReactModuleInfoProvider() {
        return () -> {
            final Map<String, ReactModuleInfo> moduleInfos = new HashMap<>();
            boolean isTurboModule = BuildConfig.IS_NEW_ARCHITECTURE_ENABLED;

            moduleInfos.put(
                    "CallLogs",
                    new ReactModuleInfo(
                            "CallLogs",
                            "CallLogs",
                            false, // canOverrideExistingModule
                            false, // needsEagerInit
                            true,  // hasConstants
                            false, // isCxxModule
                            isTurboModule // isTurboModule
                    ));

            return moduleInfos;
        };
    }
}
