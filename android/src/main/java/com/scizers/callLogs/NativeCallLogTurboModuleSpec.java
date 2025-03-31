package com.scizers.callLogs;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReadableMap;
import com.facebook.react.bridge.WritableArray;
import com.facebook.react.turbomodule.core.interfaces.TurboModule;

public abstract class NativeCallLogTurboModuleSpec extends ReactContextBaseJavaModule implements TurboModule {
    public NativeCallLogTurboModuleSpec(ReactApplicationContext reactContext) {
        super(reactContext);
    }

    @Override
    public abstract @NonNull String getName();

    public abstract WritableArray load(int limit);

    public abstract WritableArray loadWithFilter(int limit, @Nullable ReadableMap filter);

    public abstract WritableArray loadAll();
}
