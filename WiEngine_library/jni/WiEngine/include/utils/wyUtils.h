/*
 * Copyright (c) 2010 WiYun Inc.

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#ifndef __wyUtils_h__
#define __wyUtils_h__

#include <jni.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "wyTypes.h"

struct wyBezierConfig;
struct wyQuad2D;
struct wyQuad3D;
struct wyColor4B;
struct wyRect;
struct wyAffineTransform;
struct wyPoint;
struct wyKeyEvent;
struct wyMotionEvent;

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

// toast duration
#define TOAST_LENGTH_SHORT 0
#define TOAST_LENGTH_LONG 1

/**
 * @class wyUtils
 *
 * 工具类, 都是静态方法
 */
class wyUtils {
private:
	/**
	 * 解压，内部调用
	 *
	 * @param in 输入的压缩过的数据
	 * @param inLength 压缩数据长度
	 * @param out 输出缓冲区指针
	 * @param outLength 整数指针，用于返回解压后的数据长度
	 */
	static int internal_gunzip(char* in, int inLength, char** out, int* outLength);

public:
	/*
	 * basic type operations
	 */

	/**
	 * 把java的WYBeizerConfig对象转换成native端的wyBeizerConfig结构
	 *
	 * @param env JNIEnv指针
	 * @param config java的WYBeizerConfig对象
	 * @return \link wyBezierConfig wyBezierConfig结构\endlink
	 */
	static wyBezierConfig to_wyBezierConfig(JNIEnv* env, jobject config);

	/**
	 * 把java的WYQuad2D对象转换成native端的wyQuad2D结构
	 *
	 * @param env JNIEnv指针
	 * @param quad java的WYQuad2D对象
	 * @return \link wyQuad2D wyQuad2D结构\endlink
	 */
	static wyQuad2D to_wyQuad2D(JNIEnv* env, jobject quad);

	/**
	 * 把java的WYQuad3D对象转换成native端的wyQuad3D结构
	 *
	 * @param env JNIEnv指针
	 * @param quad java的WYQuad3D对象
	 * @return \link wyQuad3D wyQuad3D结构\endlink
	 */
	static wyQuad3D to_wyQuad3D(JNIEnv* env, jobject quad);

	/**
	 * 把java的WYColor4B对象转换成native端的wyColor4B结构
	 *
	 * @param env JNIEnv指针
	 * @param color java的WYColor4B对象
	 * @return \link wyColor4B wyColor4B结构\endlink
	 */
	static wyColor4B to_wyColor4B(JNIEnv* env, jobject color);

	/**
	 * 把java的WYColor3B对象转换成native端的wyColor3B结构
	 *
	 * @param env JNIEnv指针
	 * @param color java的WYColor3B对象
	 * @return \link wyColor3B wyColor3B结构\endlink
	 */
	static wyColor3B to_wyColor3B(JNIEnv* env, jobject color);

	/**
	 * 把java的WYRect对象转换成native端的wyRect结构
	 *
	 * @param env JNIEnv指针
	 * @param rect java的WYRect对象
	 * @return \link wyRect wyRect结构\endlink
	 */
	static wyRect to_wyRect(JNIEnv* env, jobject rect);

	/**
	 * 把native端的wyRect结构内容复制到java端的WYRect对象中
	 *
	 * @param env JNIEnv指针
	 * @param r native端的\link wyRect wyRect结构\endlink
	 * @param jr java端的WYRect对象
	 */
	static void returnRect(JNIEnv* env, wyRect r, jobject jr);

	/**
	 * 把native端的wyAffineTransform结构内容复制到java端的WYAffineTransform对象中
	 *
	 * @param env JNIEnv指针
	 * @param t \link wyAffineTransform wyAffineTransform结构\endlink
	 * @param jt WYAffineTransform对象
	 */
	static void returnAffineTransform(JNIEnv* env, wyAffineTransform t, jobject jt);

	/*
	 * resource related operations
	 */

	/**
	 * 通过资源名称和资源类型名得到资源id
	 *
	 * @param name 资源名称
	 * @param type 资源类型名
	 * @param type2 资源的其他类型名, 如果在type指定的资源中没有找到，会再尝试在type2中寻找
	 * @return 资源id
	 */
	static int getResId(const char* name, const char* type, const char* type2);

	/**
	 * 通过资源全名获得资源id. 全名指的是"R.drawable.abc"这样的名称.
	 *
	 * @param fullName 资源全名
	 * @return 资源id
	 */
	static int getResId(const char* fullName);

	/**
	 * 从资源文件中载入png图片
	 *
	 * @param resId png图片资源id
	 * @param w 保存png图片宽度的指针, 为NULL则不返回宽度
	 * @param h 保存png图片高度的指针, 为NULL则不返回高度
	 * @param sizeOnly true表示仅获得png图片大小, 不解析png图片数据
	 * @param scale 缺省的缩放比例, 为1表示不缩放图片, 为2表示放大一倍
	 * @return 经过解析后的png图片数据, RGBA8888格式
	 */
	static char* loadPNG(int resId, int* w, int* h, bool sizeOnly, float scale);

	/**
	 * 从内存的数组中载入png图片
	 *
	 * @param data png文件的字节数组
	 * @param length data的长度
	 * @param w 保存png图片宽度的指针, 为NULL则不返回宽度
	 * @param h 保存png图片高度的指针, 为NULL则不返回高度
	 * @param sizeOnly true表示仅获得png图片大小, 不解析png图片数据
	 * @param scale 缺省的缩放比例, 为1表示不缩放图片, 为2表示放大一倍
	 * @return 经过解析后的png图片数据, RGBA8888格式
	 */
	static char* loadPNG(const char* data, int length, int* w, int* h, bool sizeOnly, float scale);

	/**
	 * 从一个标准FILE指针中读取png图片，这个方法会负责关闭文件
	 *
	 * @param f FILE指针
	 * @param w 保存png图片宽度的指针, 为NULL则不返回宽度
	 * @param h 保存png图片高度的指针, 为NULL则不返回高度
	 * @param sizeOnly true表示仅获得png图片大小, 不解析png图片数据
	 * @param scale 缺省的缩放比例, 为1表示不缩放图片, 为2表示放大一倍
	 */
	static char* loadPNG(FILE* f, int* w, int* h, bool sizeOnly, float scale);

	/**
	 * 从文件系统或者asset中载入png图片
	 *
	 * @param path png图片在文件系统中的路径
	 * @param isFile true表示这是一个文件系统上的文件, false表示这是一个asset中的文件
	 * @param w 保存png图片宽度的指针, 为NULL则不返回宽度
	 * @param h 保存png图片高度的指针, 为NULL则不返回高度
	 * @param sizeOnly true表示仅获得png图片大小, 不解析png图片数据
	 * @param scale 缺省的缩放比例, 为1表示不缩放图片, 为2表示放大一倍
	 */
	static char* loadPNG(const char* path, bool isFile, int* w, int* h, bool sizeOnly, float scale);

	/**
	 * 从一个标准FILE指针中读取jpg图片，这个方法会负责关闭文件
	 *
	 * @param f FILE指针
	 * @param w 保存png图片宽度的指针, 为NULL则不返回宽度
	 * @param h 保存png图片高度的指针, 为NULL则不返回高度
	 * @param sizeOnly true表示仅获得png图片大小, 不解析png图片数据
	 * @param scale 缺省的缩放比例, 为1表示不缩放图片, 为2表示放大一倍
	 */
	static char* loadJPG(FILE* f, int* w, int* h, bool sizeOnly, float scale);

	/**
	 * 从文件系统或者asset中载入jpg图片
	 *
	 * @param path jpg图片在文件系统中的路径
	 * @param isFile true表示这是一个文件系统上的文件, false表示这是一个asset中的文件
	 * @param w 保存jpg图片宽度的指针, 为NULL则不返回宽度
	 * @param h 保存jpg图片高度的指针, 为NULL则不返回高度
	 * @param sizeOnly true表示仅获得jpg图片大小, 不解析jpg图片数据
	 * @param scale 缺省的缩放比例, 为1表示不缩放图片, 为2表示放大一倍
	 */
	static char* loadJPG(const char* path, bool isFile, int* w, int* h, bool sizeOnly, float scale);

	/**
	 * 从内存的数组中载入jpg图片
	 *
	 * @param data jpg文件的字节数组
	 * @param length data的长度
	 * @param w 保存jpg图片宽度的指针, 为NULL则不返回宽度
	 * @param h 保存jpg图片高度的指针, 为NULL则不返回高度
	 * @param sizeOnly true表示仅获得jpg图片大小, 不解析jpg图片数据
	 * @param scale 缺省的缩放比例, 为1表示不缩放图片, 为2表示放大一倍
	 * @return 经过解析后的jpg图片数据, RGBA8888格式
	 */
	static char* loadJPG(const char* data, int length, int* w, int* h, bool sizeOnly, float scale);

	/**
	 * 从资源文件中载入jpg图片
	 *
	 * @param resId jpg图片资源id
	 * @param w 保存jpg图片宽度的指针, 为NULL则不返回宽度
	 * @param h 保存jpg图片高度的指针, 为NULL则不返回高度
	 * @param sizeOnly true表示仅获得jpg图片大小, 不解析jpg图片数据
	 * @param scale 缺省的缩放比例, 为1表示不缩放图片, 为2表示放大一倍
	 * @return 经过解析后的jpg图片数据, RGBA8888格式
	 */
	static char* loadJPG(int resId, int* w, int* h, bool sizeOnly, float scale);

	/**
	 * 从某个FILE指针中读取所有内容
	 *
	 * @param f 文件的FILE指针
	 * @param length 要载入的数据长度，缺省为0，表示一直读到文件尾
	 * @return 文件数据
	 */
	static char* loadRaw(FILE* f, int length = 0);

	/**
	 * 载入文件系统或者asset中某个文件的内容
	 *
	 * @param path 文件在文件系统中的路径
	 * @param isFile true表示path是一个文件系统路径
	 * @param outLen 可选参数, 如果不为NULL, 将返回文件总长度
	 * @return 文件数据
	 */
	static char* loadRaw(const char* path, bool isFile, int* outLen = NULL);

	/**
	 * 载入资源文件的raw数据
	 *
	 * @param resId 资源id
	 * @param outLen 可选参数, 如果不为NULL, 将返回文件总长度
	 * @return 文件数据
	 */
	static char* loadRaw(int resId, int* outLen = NULL);

	/**
	 * 从资源文件中读取一个0结尾字符串, 0是由方法自动
	 * 追加的. 这个资源文件必须是一个纯文本文件
	 *
	 * @param resId 资源id
	 * @return 未经处理的原始数据, 结尾跟一个0字节
	 */
	static char* loadCString(int resId);

	/**
	 * 从文件系统或者asset中载入一个c字符串.
	 *
	 * @param path 文件路径, 必须是一个纯文本文件
	 * @param isFile true表示path是一个文件系统路径, false表示是一个asset下的路径
	 * @return 未经处理的原始数据, 结尾跟一个0字节
	 */
	static char* loadCString(const char* path, bool isFile);

	/**
	 * 得到PVR图片的大小
	 *
	 * @param data PVR数据数组
	 * @param length PVR数据数组长度
	 * @param w 保存pvr图片宽度的指针, 为NULL则不返回宽度
	 * @param h 保存pvr图片高度的指针, 为NULL则不返回高度
	 * @param scale 缺省的缩放比例, 为1表示不缩放图片, 为2表示放大一倍
	 * @return true表示获得大小成功, false表示失败
	 */
	static bool getPVRSize(const char* data, int length, int* w, int* h, float scale);

	/**
	 * 得到PVR图片的大小
	 *
	 * @param resId pvr图片资源id
	 * @param w 保存pvr图片宽度的指针, 为NULL则不返回宽度
	 * @param h 保存pvr图片高度的指针, 为NULL则不返回高度
	 * @param scale 缺省的缩放比例, 为1表示不缩放图片, 为2表示放大一倍
	 * @return true表示获得大小成功, false表示失败
	 */
	static bool getPVRSize(int resId, int* w, int* h, float scale);

	/**
	 * 得到PVR图片的大小
	 *
	 * @param f pvr文件的FILE指针
	 * @param w 保存pvr图片宽度的指针, 为NULL则不返回宽度
	 * @param h 保存pvr图片高度的指针, 为NULL则不返回高度
	 * @param scale 缺省的缩放比例, 为1表示不缩放图片, 为2表示放大一倍
	 * @return true表示获得大小成功, false表示失败
	 */
	static bool getPVRSize(FILE* f, int* w, int* h, float scale);

	/**
	 * 得到PVR图片的大小
	 *
	 * @param path pvr文件在文件系统或者asset中的路径
	 * @param isFile true表示path是一个文件系统路径
	 * @param w 保存pvr图片宽度的指针, 为NULL则不返回宽度
	 * @param h 保存pvr图片高度的指针, 为NULL则不返回高度
	 * @param scale 缺省的缩放比例, 为1表示不缩放图片, 为2表示放大一倍
	 * @return true表示获得大小成功, false表示失败
	 */
	static bool getPVRSize(const char* path, bool isFile, int* w, int* h, float scale);

	/*
	 * Event related operations
	 */

	/**
	 * 把坐标从Android坐标系转换到OpenGL坐标系
	 *
	 * @param p \link wyPoint wyPoint结构\endlink 指针
	 */
	static void convertToGL(wyPoint* p);

	/**
	 * 把坐标从Android坐标系转换到OpenGL坐标系
	 *
	 * @param x 坐标x值指针
	 * @param y 坐标y值指针
	 */
	static void convertToGL(float* x, float* y);

	/**
	 * 把java的KeyEvent对象中的数据转换成\link wyKeyEvent wyKeyEvent结构\endlink
	 *
	 * @param env JNIEnv指针
	 * @param je java端的KeyEvent对象
	 * @param event 保存数据的\link wyKeyEvent wyKeyEvent结构\endlink 指针
	 */
	static void convertKeyEvent(JNIEnv* env, jobject je, wyKeyEvent* event);

	/**
	 * 把java的MotionEvent对象转换成\link wyMotionEvent wyMotionEvent结构\endlink
	 *
	 * @param env JNIEnv指针
	 * @param je java端的MotionEvent对象
	 * @param event 保存数据的\link wyMotionEvent wyMotionEvent结构\endlink 指针
	 */
	static void convertMotionEvent(JNIEnv* env, jobject je, wyMotionEvent* event);

	/*
	 * Mathematical methods
	 */

	/**
	 * 返回一个大于x的数，要求最接近x，且是2的整数次方。比如如果x是5，则返回8
	 *
	 * @param x 参考值
	 * @return 最接近x的2的整数次方值
	 */
	static int getNextPOT(int x);

	/**
	 * 把角度转换为弧度
	 *
	 * @param degree 角度值
	 * @return 弧度值
	 */
	static float d2r(float degree);

	/**
	 * 把弧度转换为角度
	 *
	 * @param angle 弧度
	 * @return 角度
	 */
	static float r2d(float angle);

	/**
	 * 产生一个在[-1, 1]范围内的随机数
	 *
	 * @return 随机数
	 */
	static float randMinusOneToOne();

	/**
	 * 尝试一个[0, max]之间的随机数
	 *
	 * @return 随机数
	 */
	static int randMax(int max);

	/*
	 * time helper
	 */

	/**
	 * 得到当前时间距离1970年1月1日的毫秒数
	 *
	 * @return 当前时间距离1970年1月1日的毫秒数
	 */
	static int64_t currentTimeMillis();

	/*
	 * Array helper
	 */

	/**
	 * 交换浮点数组中的两个元素
	 *
	 * @param f 浮点数组指针
	 * @param index1 元素1位置
	 * @param index2 元素2位置
	 */
	static void swap(float* f, int index1, int index2);

	/**
	 * 在整数数组中进行二分查找
	 *
	 * @param a 整数数组指针
	 * @param len 数组长度
	 * @param key 要查找的整数
	 * @return 如果找到了，返回索引位置，如果没有找到，将返回值取绝对值再减1就是插入位置
	 */
	static int binarySearch(int* a, int len, int key);

	/*
	 * encode/decode support
	 */

	/**
	 * 解码base64
	 *
	 * @param enc base64编码的数组
	 * @param length 数组长度
	 * @param retLen 用来返回解码后的长度
	 * @return 解码后的数组指针
	 */
	static char* decodeBase64(const char* enc, int length, int* retLen);

	/**
	 * 解压
	 *
	 * @param in 保存压缩数据的数组
	 * @param inLength 数组长度
	 * @param out 用来返回解压数据的缓冲区指针
	 * @return 解压后的数组长度
	 */
	static int gunzip(char* in, int inLength, char** out);

	/*
	 * string helper
	 */

	/**
	 * 去掉字符串头尾的空格字符
	 *
	 * @param s 输入字符串
	 * @return 去掉空格后字符串的长度
	 */
	static int trim(char* s);

	/**
	 * 判断字符串是否为空
	 *
	 * @param s 字符串指针，可以为NULL
	 * @return true表示字符串为NULL或者没有内容
	 */
	static bool isEmpty(char* s);

	/**
	 * 拷贝一个字符串
	 *
	 * @param src 源字符串
	 * @return 拷贝后的字符串
	 */
	static const char* copy(const char* src);

	/*
	 * resolution helper
	 */

	// resolution independent
	static float resolveDp(float dp);
	static float resolveSp(float sp);
	static wyRect resolveRect(wyRect rect);
	static wyPoint resolvePoint(wyPoint point);

	/*
	 * interoperation with java layer
	 */

	// for activity starting
	static jobject newIntent(const char* activityName);
	static void putBooleanExtra(jobject intent, const char* name, bool value);
	static void putByteExtra(jobject intent, const char* name, unsigned char value);
	static void putCharExtra(jobject intent, const char* name, unsigned short value);
	static void putDoubleExtra(jobject intent, const char* name, double value);
	static void putFloatExtra(jobject intent, const char* name, float value);
	static void putIntExtra(jobject intent, const char* name, int value);
	static void putStringExtra(jobject intent, const char* name, const char* value);
	static void putLongExtra(jobject intent, const char* name, long value);
	static void putShortExtra(jobject intent, const char* name, short value);
	static void startActivity(jobject intent);
	static void sendBroadcast(jobject intent);

	// for toast
	// 0 means Toast.LENGTH_SHORT
	static void showToast(int resId, int duration = TOAST_LENGTH_SHORT);
	static void showToast(const char* text, int duration = TOAST_LENGTH_SHORT);

	// for font related functions
	static wySize calculateTextSize(const char* text, const char* fontPath, float fontSize);
	static wySize calculateTextSize(const char* text, const char* fontName, float fontSize, wyFontStyle style);
	static const char* createLabelBitmap(const char* text, const char* fontPath, float fontSize);
	static const char* createLabelBitmap(const char* text, const char* fontName, float fontSize, wyFontStyle style);

	/*
	 * memory file system
	 */

	// get file data
	static bool getFile(const char* filename, const char** buffer, int* size);

	/*
	 * opengl screenshot
	 */

	/**
	 * 抓取当前帧, 保存为png图片. 这个方法会将图片保存到指定路径，由于牵涉到文件
	 * 写操作, 因此速度较慢, 另外使用的OpenGL接口可能在低版本Android系统上没有
	 * 实现，因此只可用于演示目的.
	 *
	 * @param dir 截图保存的目录路径
	 * @param index 截图的索引, 比如是100, 则会保存为000100.png
	 */
	static void makeScreenshot(const char* dir, int index);

	/*
	 * jni helper
	 */

	/**
	 * 获得一个JNIEnv指针，一般需要进行一些jni相关操作时，可以用这个方法
	 * 得到环境指针
	 */
	static JNIEnv* getJNIEnv();
};

#endif // __wyUtils_h__
