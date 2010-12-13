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
#ifndef __wyDirector_h__
#define __wyDirector_h__

#include <stdbool.h>
#include <jni.h>
#include "wyLabel.h"
#include "wyScene.h"
#include "wyArray.h"

typedef enum {
	/**
	 * 正交投影方式
	 */
	PROJECTION_2D = 1,

	/**
	 * 3D投影方式，fovy=60, znear=0.5f, zfar=1500.
	 */
	PROJECTION_3D,

	/**
	 * 自定义投影方式，用户需要自己调用OpenGL接口设置投影方式
	 */
	PROJECTION_CUSTOM
} wyProjectionType;

#define PROJECTION_DEFAULT PROJECTION_3D

/**
 * Director生命周期监听器接口
 */
typedef struct wyDirectorLifecycleListener {
	void (*onSurfaceCreated)();
	void (*onSurfaceChanged)(int w, int h);
	void (*onSurfaceDestroyed)();
	void (*onDirectorEnded)();
} wyDirectorLifecycleListener;

class wyDirector : public wyObject {
private:
	/// 投影类型，取值PROJECTION_3D，PROJECTION_2D,默认PROJECTION_DEFAULT
	wyProjectionType m_projection;

	/// 两帧之间的时间差，如果一秒平均60帧，则m_delta取值在17，16毫秒之间，取值样例为0.017
	float m_delta;

	// fps label variables
	float m_frameDelta;
	float m_frameRate;
	int m_frames;

	/// 上一帧更新的时间
	int64_t m_lastUpdateTime;

	// true表示需要在合适的时候检查底层的贴图对象是否被释放，如果是则要重新载入
	bool m_needCheckTexture;

	/// 标识当前场景是否暂停状态
	bool m_paused;

	/// 标识是否显示FPS 在屏幕左下角
	bool m_displayFPS;

	// max frame rate and 0 means no limit
	int m_maxFrameRate;

	// last drawing time
	int64_t m_lastFrameTime;

	// minimum frame interval, only used when max frame rate is set
	int64_t m_minFrameInterval;

	// unused delta time for frame interval
	int64_t m_savedDelta;

	/// 下一场景\link wyScene wyScene对象 \endlink 的指针
	wyScene* m_nextScene;

	/// 正在显示场景\link wyScene wyScene对象 \endlink 的指针
	wyScene* m_runningScene;

	/// 用来显示FPS的\link wyLabel wyLabel对象 \endlink 的指针
	wyLabel* m_fpsLabel;

	/// 场景堆栈 \link wyArray wyArray对象 \endlink 的指针
	wyArray* m_scenesStack;

	/// Director生命周期事件监听器
	wyArray* m_lifecycleListeners;

	/// java端的生命周期监听器
	wyArray* m_jLifecycleListeners;

	/// OpenGlView的java对象
	jobject m_glView;

	/// Android Context的java对象
    jobject m_context;

private:
    /**
	 * 构造函数
	 */
	wyDirector();

	/**
	 * 计算两帧之间的时间差
	 */
	void calculateDeltaTime();

	/**
	 * 显示FPS
	 */
	void showFPS();

	/**
	 * 设置当前的场景
	 *
	 * @param scene 场景\link wyScene wyScene对象 \endlink 的指针
	 */
	void setRunningScene(wyScene* scene);

	/**
	 * 设置下一场景
	 *
	 * @param scene 场景\link wyScene wyScene对象 \endlink 的指针
	 */
	void setNextScene(wyScene* scene);

	/**
	 * 切换倒下一场景
	 */
	void gotoNextScene();

	/**
	 * 初始化SAL
	 */
	void setupSAL();

	/**
	 * 初始化一些全局参数
	 */
	void initGlobal();

	static bool releaseScene(wyArray* arr, void* ptr, int index, void* data);
	static bool notifySurfaceCreated(wyArray* arr, void* ptr, int index, void* data);
	static bool notifySurfaceChanged(wyArray* arr, void* ptr, int index, void* data);
	static bool notifySurfaceDestroyed(wyArray* arr, void* ptr, int index, void* data);
	static bool notifyDirectorEnded(wyArray* arr, void* ptr, int index, void* data);
	static bool j_notifySurfaceCreated(wyArray* arr, void* ptr, int index, void* data);
	static bool j_notifySurfaceChanged(wyArray* arr, void* ptr, int index, void* data);
	static bool j_notifySurfaceDestroyed(wyArray* arr, void* ptr, int index, void* data);
	static bool j_notifyDirectorEnded(wyArray* arr, void* ptr, int index, void* data);
	static bool j_releaseListener(wyArray* arr, void* ptr, int index, void* data);

public:
	/**
	 * 获得\link wyDirector wyDirector对象 \endlink指针
	 *
	 * @return \link wyDirector wyDirector对象 \endlink指针
	 */
	static wyDirector* getInstance();

	/**
	 * 析构函数
	 */
	virtual ~wyDirector();

	// set default density
	static void setDefaultInDensity(float density);
	static float getDefaultInDensity();

	/**
	 * 获得窗口尺寸\link wySize wySize结构 \endlink
	 *
	 * @return \link wySize wySize结构 \endlink
	 */
	wySize getWindowSize();

	/**
	 * 获得窗口宽度
	 *
	 * @return 窗口宽度
	 */
	int getWindowWidth();

	/**
	 * 获得窗口高度
	 *
	 * @return 窗口高度
	 */
	int getWindowHeight();

	/**
	 * 设置WYGLSurfaceView对象, 应该由java层调用。如果将WiEngine用于动态壁纸，则
	 * 这个方法不需要被调用。
	 *
	 * @param glView WYGLSurfaceView对象
	 */
	void attachInView(jobject glView);

	/**
	 * 设置android.content.Context对象, 应该由java层调用。
	 *
	 * @param context  android.content.Context对象
	 */
	void attachContext(jobject context);

	// surface lifecycle
	void onSurfaceCreated();
	void onSurfaceChanged(int w, int h);
	void onSurfaceDestroyed();
	void addLifecycleListener(const wyDirectorLifecycleListener* l) {
		wyArrayPush(m_lifecycleListeners, (void*)l);
	}

	/**
	 * 添加一个java端的生命周期监听器
	 *
	 * @param l java端声明周期监听器，需要是一个实现了IDirectorLifecycleListener接口的对象
	 */
	void addLifecycleListener(jobject l);

	// set depth test
	void setDepthTest(bool on);

	/**
	 * 设置是否显示FPS标签
	 *
	 * @param show true为显示
	 */
	void setShowFPS(bool show) { m_displayFPS = show; }

	/**
	 * 设置投影方式
	 *
	 * @param projection 投影方式
	 */
	void setProjection(wyProjectionType projection);

	/**
	 * 设置投影方式为正交投影方式
	 */
	void set2DProjection();

	/**
	 * 设置投影方式为3D投影方式
	 */
	void set3DProjection();

	/**
	 * 设置投影方式为默认投影方式
	 */
	void setDefaultProjection();

	/**
	 * 该方法负责画下一帧场景
	 */
	void drawFrame();

	/**
	 * 暂停当前场景,返回true为设置成功,如果返回false说明已经是暂停状态
	 */
	bool pause();

	/**
	 * 恢复当前场景,返回true为设置成功,如果返回false说明已经是恢复状态
	 */
	bool resume();

	// set max frame rate
	void setMaxFrameRate(int maxFrameRate);

	// set blend
	void setAlphaBlending(bool on);

	/**
	 * 运行场景
	 *
	 * @param scene 需要运行的\link wyScene wyScene对象指针 \endlink
	 */
	void runWithScene(wyScene* scene);

	/**
	 * 切换场景,切换到当前场景在栈中的上一个场景
	 */
	void popScene();

	/**
	 * 切换场景,该方法会保留当前的场景在栈中,在下一场景按back键回回到当前场景
	 *
	 * @param scene 需要切换的\link wyScene wyScene对象指针 \endlink
	 */
	void pushScene(wyScene* scene);

	/**
	 * 切换场景,替换当前的运行场景,该方法不会保留当前的场景在栈中
	 *
	 * @param scene 需要切换的\link wyScene wyScene对象指针 \endlink
	 */
	void replaceScene(wyScene* scene);

	// checking texture flag
	void setNeedCheckTexture(bool flag) { m_needCheckTexture = flag; }

	/**
	 * 获得当前场景的上一个场景\link wyScene wyScene对象指针 \endlink
	 *
	 * @return 当前场景的上一个场景\link wyScene wyScene对象指针 \endlink
	 */
	wyScene* getPreviousScene();

	/**
	 * 获得当前场景\link wyScene wyScene对象指针 \endlink
	 *
	 * @return 当前场景\link wyScene wyScene对象指针 \endlink
	 */
	wyScene* getRunningScene() { return m_runningScene; }

	/**
	 * 获得WYGLSurfaceView对象
	 *
	 * @return WYGLSurfaceView对象
	 */
	jobject getGLView() { return m_glView; }

	/**
	 * 获得android.content.Context对象
	 *
	 * @return android.content.Context对象
	 */
	jobject getContext() { return m_context; }

	/**
	 * 获得当前是否为暂停状态,true为暂停
	 *
	 * @return 当前暂停状态
	 */
	bool isPaused() { return m_paused; }
	int getMaxFrameRate() { return m_maxFrameRate; }

	/**
	 * 返回当前的投影方式
	 *
	 * @return 当前的投影方式
	 */
	wyProjectionType getProjection() { return m_projection; }
};

#endif // __wyDirector_h__
