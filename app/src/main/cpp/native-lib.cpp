#include <jni.h>
#include <string>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;

extern "C"
{

void Java_com_upwork_alex_opencv_1prototype_MainActivity_process(JNIEnv*, jobject, jlong srcRgbaMatPtr, jlong dstRgbaMatPtr, jint radius)
{
    Mat& src = *(Mat*)srcRgbaMatPtr;
    Mat& dst = *(Mat*)dstRgbaMatPtr;
    blur(src, dst, Size(radius, radius), Point(-1, -1));
}

jlong Java_com_upwork_alex_opencv_1prototype_MainActivity_processClone(JNIEnv*, jobject, jlong srcRgbaMatPtr, jint radius)
{
    Mat& src = *(Mat*)srcRgbaMatPtr;
    Mat *dst = new Mat(src.clone());
    blur(src, *dst, Size(radius, radius), Point(-1, -1));
    return (jlong)dst;
}

}
