package com.mx3;

import android.util.Log;

public class Api {
    static {
        System.loadLibrary("mx3_jni");
    }

    Api() {}

    public void sayHi() {
    	Log.d("Api","calling native method");
        nativeSayHi();
    }

    private static native void nativeSayHi();

    public static void main(String[] args) {
        Api api = new Api();
        api.sayHi();
        System.out.println("Hello, World!");
    }
}
