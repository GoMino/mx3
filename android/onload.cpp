#include "prefix.h"
#include <vector>
#include <jni.h>
#include <android/Log.h>
#include <string.h>
#include <libgen.h>
#include <unistd.h>

#ifdef __ANDROID_API__
//#define FILENAME ( strrchr(__FILE__,'/') ? strrchr(__FILE__,'/') + 1 : __FILE__)
#define FILENAME ( basename(__FILE__) ) // eventually _splitpath on widows
#define STRINGIFY(x) #x
#define LOG_TAG FILENAME
//#define LOGI(...)  ((void)__android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__))
//define LOGE(...)  ((void)__android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__))
#define LOGV(fmt, ...) __android_log_print(ANDROID_LOG_VERBOSE,LOG_TAG,("[%s:%d] "  fmt), __FUNCTION__, __LINE__, ##__VA_ARGS__);
#define LOGD(fmt, ...) __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,("[%s:%d] "  fmt), __FUNCTION__, __LINE__, ##__VA_ARGS__);
#define LOGI(fmt, ...) __android_log_print(ANDROID_LOG_INFO,LOG_TAG,("[%s:%d] "  fmt), __FUNCTION__, __LINE__, ##__VA_ARGS__);
#define LOGW(fmt, ...) __android_log_print(ANDROID_LOG_WARN,LOG_TAG,("[%s:%d] "  fmt), __FUNCTION__, __LINE__, ##__VA_ARGS__);
#define LOGE(fmt, ...) __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,("[%s:%d] "  fmt), __FUNCTION__, __LINE__, ##__VA_ARGS__);
#define LOGF(fmt, ...) __android_log_print(ANDROID_LOG_FATAL,LOG_TAG,("[%s:%d] "  fmt), __FUNCTION__, __LINE__, ##__VA_ARGS__);

#endif


extern "C" void nativeSayHi(JNIEnv * e) {
    // do something
	LOGE("Hello world");
}

extern "C" MX3EXPORT jint JNI_OnLoad(JavaVM * vm, void *) {
	//sleep(10);
	LOGD("begin");

    JNIEnv * env = nullptr;
    auto result = vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6);
    if (result != JNI_OK) {
        return JNI_ERR;
    }
    vm->AttachCurrentThread(&env, 0);

    // todo(kabbes) load libraries in a nicer way
    jclass clazz = env->FindClass("com/mx3/Api");

    std::vector<JNINativeMethod> methods;
    methods.push_back(JNINativeMethod {"nativeSayHi", "()V", (void*)(&nativeSayHi)});
    env->RegisterNatives(clazz, methods.data(), (int)methods.size());
    LOGI("end");
    return JNI_VERSION_1_6;
}
