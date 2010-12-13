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
#ifndef __wyObject_h__
#define __wyObject_h__

#include <stdbool.h>
#include <stdlib.h>
#include "wyArray.h"

// comment following line when leak tracing is not needed
//#define LEAK_TRACE

class wyTargetSelector;

typedef enum {
	// base
	WY_OBJECT,

	// singleton and auxiliary
	WY_DIRECTOR,
	WY_EVENT_DISPATCHER,
	WY_SCHEDULER,
	WY_ACTION_MANAGER,
	WY_TEXTURE_MANAGER,
	WY_ZWOPTEX_MANAGER,
	WY_SCHEDULER_TIMER,
	WY_TARGET_SELECTOR,
	WY_CHIPMUNK,

	// others
	WY_FRAME,
	WY_TEXTURE_FRAME,
	WY_ATLAS_FRAME,
	WY_ANIMATION,
	WY_ATLAS_ANIMATION,
	WY_SHAPE_ANIMATION,
	WY_ZWOPTEX,
	WY_ZWOPTEX_FRAME,

	// node
	WY_NODE,
	WY_SCENE,
	WY_LAYER,
	WY_COLOR_LAYER,
	WY_MULTIPLEX_LAYER,
	WY_RENDER_TEXTURE,
	WY_TEXTURE_NODE,
	WY_SPRITE,
	WY_LABEL,
	WY_ATLAS_SPRITE,
	WY_ATLAS_NODE,
	WY_ATLAS_LABEL,
	WY_BUTTON,
	WY_ATLAS_BUTTON,
	WY_MENU,
	WY_MENUITEM,
	WY_MENUITEM_ATLAS_LABEL,
	WY_MENUITEM_ATLAS_SPRITE,
	WY_MENUITEM_LABEL,
	WY_MENUITEM_SPRITE,
	WY_MENUITEM_TOGGLE,
	WY_PROGRESS_TIMER,
	WY_RIBBON_SEGMENT,
	WY_RIBBON,
	WY_MOTION_STREAK,
	WY_PARALLAX_OBJECT,
	WY_PARALLAX_NODE,
	WY_TILE_MAP_ATLAS,
	WY_ARRAY_TILE_MAP_ATLAS,
	WY_TGA_TILE_MAP_ATLAS,
	WY_TMX_LAYER,
	WY_TMX_TILE_MAP,
	WY_PARTICLE_SYSTEM,
	WY_POINT_PARTICLE_SYSTEM,
	WY_QUAD_PARTICLE_SYSTEM,

	// transition scene
	WY_TRANSITION_SCENE_START, // only for checking
	WY_TRANSITION_SCENE,
	WY_LEFT_PUSH_IN_TRANSITION,
	WY_RIGHT_PUSH_IN_TRANSITION,
	WY_TOP_PUSH_IN_TRANSITION,
	WY_BOTTOM_PUSH_IN_TRANSITION,
	WY_LEFT_SLIDE_IN_TRANSITION,
	WY_RIGHT_SLIDE_IN_TRANSITION,
	WY_TOP_SLIDE_IN_TRANSITION,
	WY_BOTTOM_SLIDE_IN_TRANSITION,
	WY_BOTTOM_TILES_SHRINK_OUT_TRANSITION,
	WY_TOP_TILES_SHRINK_OUT_TRANSITION,
	WY_LEFT_BOTTOM_TILES_SHRINK_OUT_TRANSITION,
	WY_RIGHT_TOP_TILES_SHRINK_OUT_TRANSITION,
	WY_TURN_OFF_TILES_TRANSITION,
	WY_COLOR_FADE_TRANSITION,
	WY_CROSS_FADE_TRANSITION,
	WY_FLIP_ANGULAR_TRANSITION,
	WY_FLIP_X_TRANSITION,
	WY_FLIP_Y_TRANSITION,
	WY_ZOOM_FLIP_ANGULAR_TRANSITION,
	WY_ZOOM_FLIP_X_TRANSITION,
	WY_ZOOM_FLIP_Y_TRANSITION,
	WY_JUMP_ZOOM_TRANSITION,
	WY_PAGE_TURN_3D_TRANSITION,
	WY_ROTATE_ZOOM_TRANSITION,
	WY_SHRINK_GROW_TRANSITION,
	WY_SPLIT_COLS_TRANSITION,
	WY_SPLIT_ROWS_TRANSITION,
	WY_TRANSITION_SCENE_END, // only for checking

	// texture
	WY_TEXTURE_2D,
	WY_TEXTURE_ATLAS,

	// camera
	WY_CAMERA,

	// grid
	WY_BASE_GRID,
	WY_GRID_3D,
	WY_TILED_GRID_3D,
	WY_GRABBER,

	// actions
	WY_ACTION,
	WY_FINITE_TIME_ACTION,
	WY_INTERVAL_ACTION,
	WY_INSTANT_ACTION,
	WY_REPEAT,
	WY_REPEAT_FOREVER,
	WY_SEQUENCE,
	WY_ANIMATE,
	WY_BEZIER,
	WY_BLINK,
	WY_DELAY_TIME,
	WY_CALL_FUNC,
	WY_CAMERA_ACTION,
	WY_ORBIT_CAMERA,
	WY_FADE_IN,
	WY_FADE_OUT,
	WY_FADE_TO,
	WY_HIDE,
	WY_JUMP_BY,
	WY_JUMP_TO,
	WY_MOVE_BY,
	WY_MOVE_BY_ANGLE,
	WY_MOVE_TO,
	WY_PLACE,
	WY_PROGRESS_BY,
	WY_PROGRESS_TO,
	WY_REVERSE_TIME,
	WY_ROTATE_BY,
	WY_ROTATE_TO,
	WY_SCALE_BY,
	WY_SCALE_TO,
	WY_SHOW,
	WY_SPAWN,
	WY_SPEED,
	WY_TINT_BY,
	WY_TINT_TO,
	WY_TOGGLE_VISIBILITY,

	// ease actions
	WY_EASE_ACTION,
	WY_EASE_RATE_ACTION,
	WY_EASE_IN,
	WY_EASE_OUT,
	WY_EASE_IN_OUT,
	WY_EASE_SINE_IN,
	WY_EASE_SINE_OUT,
	WY_EASE_SINE_IN_OUT,
	WY_EASE_EXPONENTIAL_IN,
	WY_EASE_EXPONENTIAL_OUT,
	WY_EASE_EXPONENTIAL_IN_OUT,
	WY_EASE_ELASTIC,
	WY_EASE_ELASTIC_IN,
	WY_EASE_ELASTIC_OUT,
	WY_EASE_ELASTIC_IN_OUT,
	WY_EASE_BOUNCE,
	WY_EASE_BOUNCE_IN,
	WY_EASE_BOUNCE_OUT,
	WY_EASE_BOUNCE_IN_OUT,
	WY_EASE_BACK_IN,
	WY_EASE_BACK_OUT,
	WY_EASE_BACK_IN_OUT,

	// grid actions
	WY_GRID_ACTION,
	WY_GRID_3D_ACTION,
	WY_TILED_GRID_3D_ACTION,
	WY_REUSE_GRID,
	WY_STOP_GRID,
	WY_GRID_FLIP_X,
	WY_GRID_FLIP_Y,
	WY_BOTTOM_LINE_SHRINK_OUT,
	WY_TOP_LINE_SHRINK_OUT,
	WY_RIGHT_LINE_SHRINK_OUT,
	WY_LEFT_LINE_SHRINK_OUT,
	WY_BOTTOM_TILES_SHRINK_OUT,
	WY_TOP_TILES_SHRINK_OUT,
	WY_LEFT_BOTTOM_TILES_SHRINK_OUT,
	WY_RIGHT_TOP_TILES_SHRINK_OUT,
	WY_JUMP_TILES_3D,
	WY_LENS_3D,
	WY_LIQUID,
	WY_PAGE_TURN_3D,
	WY_RIPPLE_3D,
	WY_SHAKY_3D,
	WY_SHAKY_TILES_3D,
	WY_SHATTERED_TILES_3D,
	WY_SHUFFLE_TILES,
	WY_SPLIT_COLS,
	WY_SPLIT_ROWS,
	WY_TURN_OFF_TILES,
	WY_TWIRL,
	WY_WAVES,
	WY_WAVES_3D,
	WY_WAVES_TILES_3D,
} wyObjectType;

/**
 * @class wyObject
 *
 * 大部分类的基类，封装了引用计数的逻辑和IAnimation接口方法
 */
class wyObject {
protected:
	/// 对象类型常量，目前是一些预定义的类型，子类不方便增加，可能在以后修改
	wyObjectType type;

	/// 对象的引用计数，计数为0时将被销毁，通过new创建的对象初始计数为1
	int retainCount;

public:
	/**
	 * 构造函数
	 */
	wyObject();

	/**
	 * 虚析构
	 */
	virtual ~wyObject();

	/**
	 * 得到类名的字符串表示
	 *
	 * @return 类型字符串指针
	 */
	virtual const char* getClassName();

	/**
	 * 检查是否是某个对象类型，目前还不能检查父子类关系
	 *
	 * @param type 对象类型常量
	 * @return true表示对象类型匹配
	 */
	bool isTypeOf(wyObjectType type);

	/**
	 * 使对象的引用计数加1
	 *
	 * @return 当前对象指针
	 */
	virtual wyObject* retain();

	/**
	 * 使对象的引用计数立刻减1，如果对象的引用计数在调用之前为1，会导致
	 * 对象立刻被销毁
	 */
	virtual void release();

	/**
	 * 在渲染下一帧时将对象的引用计数减1，这个方法在主线程中调用也是安全的，底层
	 * 会自动进行处理以避免OpenGL线程提前释放对象
	 *
	 * @return 当前对象指针
	 */
	virtual wyObject* autoRelease();

	/**
	 * 直到Director退出时才将对象引用计数减1，该方法主要为Java层设计，在native
	 * 层应避免使用该方法
	 *
	 * @return 当前对象指针
	 */
	virtual wyObject* lazyRelease();

	/**
	 * 在lazy release pool中查找某个对象, 如果找到了, 则从lazy release
	 * pool中删除并减少引用计数. 这个方法主要的目的是方便java层能够释放native层
	 * 对象, 开发者在任何时候都不需要手动调用此方法.
	 */
	void javaRelease();

	/**
	 * 获得对象的当前引用计数
	 *
	 * @return 当前引用计数
	 */
	int getRetainCount();

	/**
	 * 获得对象类型
	 *
	 * @return 对象类型
	 */
	wyObjectType getType();

	/**
	 * 如果有一个TargetSelector绑定在当前对象上并被触发，则对象的该方法
	 * 将被调用。在这个方法里可以判断是哪个TargetSelector被触发并进行相应
	 * 处理
	 *
	 * @param ts \link wyTargetSelector wyTargetSelector对象 \endlink
	 */
	virtual void onTargetSelectorInvoked(wyTargetSelector* ts);

	/* other optional interface, we don't use multiple inheritance */

	/* IAnimation */

	/**
	 * 动画接口实现: 得到动画总持续时间
	 *
	 * @return 动画总持续时间
	 */
	virtual float getDuration() { return 0.f; }

	/**
	 * 动画接口实现: 获得帧列表
	 *
	 * @return 帧对象数组
	 */
	virtual wyArray* getFrames() { return NULL; }

	/**
	 * 动画接口实现: 得到动画id。为了区分动画，可以给动画一个id
	 *
	 * @return 动画id
	 */
	virtual int getId() { return 0; }
};

#ifdef __cplusplus
extern "C" {
#endif

/**
 * 增加对象的引用计数，这个方法会检查空指针
 *
 * @param obj 需要增加计数的对象，为NULL则无效果
 * @return 传入的对象指针
 */
wyObject* wyObjectRetain(wyObject* obj);

/**
 * 在渲染下一帧时将对象的引用计数减1，这个方法在主线程中调用也是安全的，底层
 * 会自动进行处理以避免OpenGL线程提前释放对象。这个方法会检查空指针
 *
 * @param obj 需要增加计数的对象，为NULL则无效果
 * @return 传入的对象指针
 */
wyObject* wyObjectAutoRelease(wyObject* obj);

/**
 * 直到Director退出时才将对象引用计数减1，该方法主要为Java层设计，在native
 * 层应避免使用该方法。这个方法会检查空指针
 *
 * @param obj 需要增加计数的对象，为NULL则无效果
 * @return 传入的对象指针
 */
wyObject* wyObjectLazyRelease(wyObject* obj);

/**
 * 使对象的引用计数立刻减1，如果对象的引用计数在调用之前为1，会导致
 * 对象立刻被销毁。这个方法会检查空指针
 *
 * @param obj 需要减少计数的对象，为NULL则无效果
 */
void wyObjectRelease(wyObject* obj);

#ifdef __cplusplus
}
#endif

#endif // __wyObject_h__
