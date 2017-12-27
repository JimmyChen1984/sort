#include <jni.h>
#include <string>
#include "Sort.h"
#include "Stack.h"
#include "iostream"
#include "MaxStack.h"

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

JNIEXPORT void JNICALL
Java_com_chen_sort_MainActivity_test(JNIEnv *env, jobject instance) {

    CStack<int> stack;
    for (int i = 0; i < 100; ++i) {
        stack.push(i);
    }
    int size = stack.size();
    int capability = stack.capability();
    int val;
    for (int i = 0; i < size; i++) {
        if (stack.pop(val)) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
    CStack<int> cStack(stack);
    CStack<int> stack1 = stack;

    CMaxStack maxStack;
    int a[] = {5, 4, 3, 2, 1, 10, 9, 8, 7, 6, 15};

    int len = sizeof(a) / sizeof(int);
    for (int i = 0; i < len; i++)
        maxStack.push(a[i]);
    int max = maxStack.max();

    for (int i = 0; i < len; i++) {
        maxStack.pop(val);
        max = maxStack.max();

    }
}

#ifdef __cplusplus
}
#endif