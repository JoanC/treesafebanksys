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
#ifndef __wyNode_h__
#define __wyNode_h__

#include <stdbool.h>
#include "wyAction.h"
#include "wyCamera.h"
#include "wyBaseGrid.h"
#include "wyScheduler.h"
#include "wyTypes.h"
#include "wyEventDispatcher.h"
#include "wyArray.h"
#include "wyTexture2D.h"
#include "wyFrame.h"
#include "wyTargetSelector.h"
#include <jni.h>

#define INVALID_TAG -1

class wyNode : public wyObject {
	friend class wyEventDispatcher;

private:
    // current touch state, it is controled by event dispatcher
    int m_state;

protected:
	// transform matrix used to convert node space to parent space
	wyAffineTransform transformMatrix;

	// transform matrix used to convert parent space to node space
	wyAffineTransform inverseMatrix;

	// flag indicating transform matrix need be recalculated
	bool transformDirty;

	// flag indicating inverse matrix need be recalculated
	bool inverseDirty;

	/// 标识当前对象是否可用状态,true可用状态
	bool enabled;

	/// 标识当前对象是否选中状态,true选中状态
	bool selected;

	/// 标识当前对象是否可见,true可见
	bool visible;

	/// 标识当前对象是否需要画,true为不绘画
	bool noDraw;

	// flag indicating transforming is performed related to anchor point
	bool relativeAnchorPoint;

	/// 标识当前对象是否是激活状态,一般在@see wyNode::onEnter之后设置,true为激活状态
	bool running;

	/// 标识当前对象是否监听触摸事件,true为监听
	bool touchEnabled;

	/// 标识当前对象是否监听键盘事件,true为监听
	bool keyEnabled;

	/// 标识当前对象是否监听加速事件,true为监听
	bool accelerometerEnabled;

	/// 标识当前对象是否监听手势事件,true为监听
	bool gestureEnabled;

	/// 标识当前对象是否监听双击事件,true为监听
	bool doubleTabEnabled;

	// for 2.0 back key compatibility
	bool backKeyTracking;

	// z-order of this node
	int zOrder;

	// tag of this node
	int tag;

	// anchor position relative to self space
	// it is calculated by content size and anchor percent
	float anchorX;
	float anchorY;

	// anchor point related to bounding box
	// so 1.0f means the right/bottom side and 0.0f means left/top side
	float anchorPercentX;
	float anchorPercentY;

	// anchor location, if you set anchor as (0.5, 0.5), then
	// the position is center point
	// the difference between mPosition and mAnchorPosition is the coordinate system
	// mPosition is relative to parent space and mAnchorPosition is relative to self space
	float positionX;
	float positionY;

	// node size
	float width;
	float height;

	// rotation transform, in degree
	float rotation;

	// scale transform of x/y axis
	float scaleX;
	float scaleY;

	// vertex z depth
	float vertexZ;

	// parent, child, sibling
	wyNode* parent;
	wyArray* children;

	// grid
	wyBaseGrid* grid;

	// camera
	wyCamera* camera;

	// scheduled timers
	wyArray* timers;

	// java layer event handler, if it is not null, event will redirect back to java layer
	jobject eventHandler;

	// java layer virtual methods event
	jobject jVirtualMethods;

	// target selector for event
	wyTargetSelector* downSelector;
	wyTargetSelector* upSelector;
	wyTargetSelector* moveOutSelector;

	// custom data
	void* data;

	// for java layer
	jobject j_data;

private:
	static bool activateTimer(wyArray* arr, void* ptr, int index, void* data);
	static bool deactivateTimer(wyArray* arr, void* ptr, int index, void* data);
	static bool releaseTimer(wyArray* arr, void* ptr, int index, void* data);
	static bool zOrderLocator(void* elementPtr, void* ptr, void* data);
	static bool tagLocator(void* elementPtr, void* ptr, void* data);
	static bool sOnEnter(wyArray* arr, void* ptr, int index, void* data);
	static bool sOnExit(wyArray* arr, void* ptr, int index, void* data);
	static bool sOnEnterTransitionDidFinish(wyArray* arr, void* ptr, int index, void* data);
	static bool sCleanup(wyArray* arr, void* ptr, int index, void* data);

protected:
	int insertChild(wyNode* n, int z);
	void activateTimers();
	void deactivateTimers();

public:
	// constructor/deconstructor
	wyNode();
	virtual ~wyNode();

	// method sub type can override
	virtual void draw();
	virtual void visit();
	virtual void transform();
	virtual void transformAncestors();
	virtual void onEnter();
	virtual void onExit();
	virtual void onEnterTransitionDidFinish();
	virtual void cleanup();

	// setters
	virtual void setAnchorPercent(float x, float y);
	virtual void setAnchorPercentX(float x);
	virtual void setAnchorPercentY(float y);
	virtual void setContentSize(float w, float h);
	virtual void setPosition(float x, float y);
	virtual void setRotation(float rot);
	virtual void setScale(float scale);
	virtual void setScaleX(float scaleX);
	virtual void setScaleY(float scaleY);
	virtual void setSelected(bool selected) { this->selected = selected; }
	virtual void setVertexZ(float vertexZ) { this->vertexZ = vertexZ; }
	virtual void setVisible(bool visible) { this->visible = visible; }
	virtual void setEnabled(bool enabled) { this->enabled = enabled; }

	/////////////////////////////////
	// system event methods
	/////////////////////////////////

	// accelerometer
	virtual void accelerometerChanged(float accelX, float accelY, float accelZ);

	// key events
	virtual bool keyDown(wyKeyEvent& event);
	virtual bool keyUp(wyKeyEvent& event);
	virtual bool keyMultiple(wyKeyEvent& event);

	// touch events, double tap and gesture
	virtual bool touchesBegan(wyMotionEvent& e);
	virtual bool touchesMoved(wyMotionEvent& e);
	virtual bool touchesEnded(wyMotionEvent& e);
	virtual bool touchesCancelled(wyMotionEvent& e);
	virtual bool touchesPointerBegan(wyMotionEvent& e);
	virtual bool touchesPointerEnded(wyMotionEvent& e);
	virtual bool onDoubleTap(wyMotionEvent& e);
	virtual bool onDoubleTapEvent(wyMotionEvent& e);
	virtual bool onSingleTapConfirmed(wyMotionEvent& e);
	virtual bool onDown(wyMotionEvent& e);
	virtual bool onFling(wyMotionEvent& e1, wyMotionEvent& e2, float velocityX, float velocityY);
	virtual void onLongPress(wyMotionEvent& event);
	virtual bool onScroll(wyMotionEvent& e1, wyMotionEvent& e2, float distanceX, float distanceY);
	virtual void onShowPress(wyMotionEvent& e);
	virtual bool onSingleTapUp(wyMotionEvent& e);

	// hit test
	virtual bool hitTest(float x, float y);

	// set relative anchor point flag
	virtual void setRelativeAnchorPoint(bool flag);

	// update node to parent transform
	void updateNodeToParentTransform();

	// update parent to node transform
	void updateParentToNodeTransform();

	// get node to world transform
	wyAffineTransform getNodeToWorldTransform();

	// get world to node transform
	wyAffineTransform getWorldToNodeTransform();

	// set transform dirty flag
	void setTransformDirty();

	// get/set scale
	float getScale();
	float getScaleX() { return scaleX; }
	float getScaleY() { return scaleY; }

	// translate
	void translate(float x, float y);

	// set grid
	void setGrid(wyBaseGrid* grid);

	// add child, postfix "Locked" means they all are synchronized
	virtual void addChildLocked(wyNode* child);
	virtual void addChildLocked(wyNode* child, int z);
	virtual void addChildLocked(wyNode* child, int z, int tag);
	virtual void addChild(wyNode* child, int z, int tag);
	virtual int reorderChild(wyNode* child, int z);

	// remove child
	virtual void removeAllChildrenLocked(bool cleanup);
	virtual void removeAllChildren(bool cleanup);
	virtual void removeChildLocked(wyNode* child, bool cleanup);
	virtual void removeChildByTagLocked(int tag, bool cleanup);
	virtual void removeChild(wyNode* child, bool cleanup);

	// reorder child, return new index of this child
	virtual int reorderChildLocked(wyNode* child, int z);

	// find child
	virtual wyNode* getChildByTagLocked(int tag);
	virtual wyNode* getChildByTag(int tag);

	// get first child, if no, return NULL
	virtual wyNode* getFirstChild();

	// get child absolution position
	// if relativeAnchorPoint is true, then the position is anchor, otherwise is left-bottom corner
	wyPoint getAbsolutePosition();

	// actions
	void runAction(wyAction* action);
	void stopAction(int tag);
	void stopAllActions(bool includeChildren = false);

	// node to world/parent or vice versa, AR means relative to anchor point
	wyPoint worldToNodeSpace(wyPoint p);
	wyPoint worldToNodeSpaceAR(wyPoint p);
	wyPoint nodeToWorldSpace(wyPoint p);
	wyPoint nodeToWorldSpaceAR(wyPoint p);
	wyPoint parentToNodeSpace(wyPoint p);
	wyPoint parentToNodeSpaceAR(wyPoint p);
	wyPoint nodeToParentSpace(wyPoint p);
	wyPoint nodeToParentSpaceAR(wyPoint p);
	wyPoint touchToNodeSpace(wyPoint p);
	wyPoint touchToNodeSpaceAR(wyPoint p);

	// get bounding box
	wyRect getBoundingBox();
	wyRect getBoundingBoxRelativeToParent();
	wyRect getBoundingBoxRelativeToWorld();

	// set enable flag
	void setAccelerometerEnabled(bool enabled);
	void setKeyEnabled(bool enabled);
	void setTouchEnabled(bool enabled);
	void setDoubleTapEnabled(bool enabled);
	void setGestureEnabled(bool enabled);
	bool isTouchEnabled() { return touchEnabled; }
	bool isKeyEnabled() { return keyEnabled; }
	bool isAccelerometerEnabled() { return accelerometerEnabled; }
	bool isGestureEnabled() { return gestureEnabled; }
	bool isDoubleTabEnabled() { return doubleTabEnabled; }

	// other getters
	float getAnchorX() { return anchorX; }
	float getAnchorY() { return anchorY; }
	float getAnchorPercentX() { return anchorPercentX; }
	float getAnchorPercentY() { return anchorPercentY; }
	wyCamera* getCamera() { return camera; }
	wyBaseGrid* getGrid() { return grid; }
	bool isVisible() { return visible; }
	bool isSelected() { return selected; }
	bool isEnabled() { return enabled; }
	int getVertexZ() { return vertexZ; }
	float getRotation() { return rotation; }
	float getPositionX() { return positionX; }
	float getPositionY() { return positionY; }
	bool isRelativeAnchorPoint() { return relativeAnchorPoint; }
	bool isRunning() { return running; }
	float getWidth() { return width; };
	float getHeight() { return height; }
	wySize getContentSize() { return wys(width, height); }
	wyArray* getChildren() { return children; }
	int getChildCount() { return children->num; }

	// java custom data
	void setJavaData(jobject data);
	jobject getJavaData() { return j_data; }

	// parent
	wyNode* getParent() { return parent; }
	void setParent(wyNode* p) { parent = p; }

	// tag
	void setTag(int tag) { this->tag = tag; }
	int getTag() { return tag; }

	// zorder
	void setZOrder(int z) { zOrder = z; }
	int getZOrder() { return zOrder; }

	// schedule/unschedule
	void scheduleLocked(wyTimer* t);
	void unscheduleLocked(wyTimer* t);

	// no draw flag
	bool isNoDraw() { return noDraw; }
	void setNoDraw(bool flag) { noDraw = flag; }

	// set java side handlers
	void setJavaEventHandler(jobject h);
	jobject getJavaEventHandler() { return eventHandler; }
	void setJavaVirtualMethods(jobject h);
	jobject getJavaVirtualMethods() { return jVirtualMethods; }

	// set target selector
	void setDownSelector(wyTargetSelector* ts);
	wyTargetSelector* getDownSelector() { return downSelector; }
	void setUpSelector(wyTargetSelector* ts);
	wyTargetSelector* getUpSelector() { return upSelector; }
	void setMoveOutSelector(wyTargetSelector* ts);
	wyTargetSelector* getMoveOutSelector() { return moveOutSelector; }

	/* other optional interface, we don't use multiple inheritance */

	/* IFrames */

	// 添加一个动画
	/**
	 * 添加一个动画
	 *
	 * @param animation \link wyObject wyObject对象指针 \endlink
	 */
	virtual void addAnimation(wyObject* animation) {}

	/**
	 * 通过id获得动画对象
	 *
	 * @param id 动画id
	 * @return \link wyObject wyObject对象指针 \endlink
	 */
	virtual wyObject* getAnimationById(int id) { return NULL; }

	/**
	 * 获得当前帧
	 *
	 * @return \link wyFrame wyFrame对象指针 \endlink
	 */
	virtual wyFrame* getDisplayFrame() { return NULL; }

	/**
	 * 检查某帧是否现在正在显示
	 *
	 * @param frame \link wyFrame wyFrame对象指针 \endlink
	 * @return true为是
	 */
	virtual bool isFrameDisplayed(wyFrame* frame) { return false; }

	/**
	 * 设置当前帧
	 *
	 * @param newFrame \link wyFrame wyFrame对象指针 \endlink
	 */
	virtual void setDisplayFrame(wyFrame* newFrame) {}

	/**
	 * 通过动画id和帧索引设置当前帧
	 *
	 * @param id 动画id
	 * @param frameIndex 帧索引
	 */
	virtual void setDisplayFrameById(int id, int frameIndex) {}

	/* ILabel */

	/**
	 * 获得文字字符串
	 *
	 * @return 文字字符串
	 */
	virtual const char* getText() { return NULL; }

	/**
	 * 设置文字
	 *
	 * @param text 文字
	 */
	virtual void setText(const char* text) {}

	/* ITransparent */

	/**
	 * 得到当前alpha值
	 *
	 * @return alpha值
	 */
	virtual int getAlpha() { return 255; }

	/**
	 * 设置alpha值
	 *
	 * @param alpha alpha值
	 */
	virtual void setAlpha(int alpha) {}

	/* IRGB */

	/**
	 * 得到当前颜色
	 *
	 * @return 颜色\link wyColor3B wyColor3B结构 \endlink
	 */
	virtual wyColor3B getColor() { return wyc3bWhite; }

	/**
	 * 设置颜色
	 *
	 * @param color \link wyColor3B wyColor3B结构 \endlink
	 */
	virtual void setColor(wyColor3B color) {}

	/* IBlendable */

	/**
	 * 得到当前\link wyBlendFunc wyBlendFunc结构 \endlink
	 *
	 * @return \link wyBlendFunc wyBlendFunc结构 \endlink
	 */
	virtual wyBlendFunc getBlendFunc() { return wybfDefault; }

	/**
	 * 设置\link wyBlendFunc wyBlendFunc结构 \endlink
	 *
	 * @param func \link wyBlendFunc wyBlendFunc结构 \endlink
	 */
	virtual void setBlendFunc(wyBlendFunc func) {}

	/* ITextureOwner */

	/**
	 * 得到当前\link wyTexture2D wyTexture2D对象指针 \endlink
	 *
	 * @return \link wyTexture2D wyTexture2D对象指针 \endlink
	 */
	virtual wyTexture2D* getTexture() { return NULL; }

	/**
	 * 设置\link wyTexture2D wyTexture2D对象指针 \endlink
	 *
	 * @param tex \link wyTexture2D wyTexture2D对象指针 \endlink
	 */
	virtual void setTexture(wyTexture2D* tex) {}
};

#endif // __wyNode_h__
