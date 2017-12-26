#include <jni.h>
#include <string>
#include "sort.h"

#ifdef __cplusplus
extern "C" {
#endif


JNIEXPORT jstring JNICALL
Java_com_chen_sort_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

JNIEXPORT void JNICALL
Java_com_chen_sort_MainActivity_sort(JNIEnv *env, jobject instance, jintArray arr_, jint type) {
    jint *arr = env->GetIntArrayElements(arr_, NULL);

    int size = env->GetArrayLength(arr_);
    CSort::sort(arr, size, (ESortType) type);
    env->SetIntArrayRegion(arr_, 0, size, arr);
    env->ReleaseIntArrayElements(arr_, arr, 0);
}


#ifdef __cplusplus
}
#endif