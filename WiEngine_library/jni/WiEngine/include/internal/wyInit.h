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
#ifndef __wyInit_h__
#define __wyInit_h__

#define CLASS_DIRECTOR "com/wiyun/engine/nodes/Director"
#define CLASS_IDIRECTORLIFECYCLELISTENER "com/wiyun/engine/nodes/Director$IDirectorLifecycleListener"
#define CLASS_TEXTURE2D "com/wiyun/engine/opengl/Texture2D"
#define CLASS_GLUTILS "android/opengl/GLUtils"
#define CLASS_ITOUCHHANDLER "com/wiyun/engine/events/ITouchHandler"
#define CLASS_IMULTITOUCHHANDLER "com/wiyun/engine/events/IMultiTouchHandler"
#define CLASS_IKEYHANDLER "com/wiyun/engine/events/IKeyHandler"
#define CLASS_IACCELEROMETERHANDLER "com/wiyun/engine/events/IAccelerometerHandler"
#define CLASS_ACCELEROMETER "com/wiyun/engine/events/Accelerometer"
#define CLASS_WYGLSURFACEVIEW "com/wiyun/engine/opengl/WYGLSurfaceView"
#define CLASS_INODEVIRTUALMETHODS "com/wiyun/engine/nodes/INodeVirtualMethods"
#define CLASS_WYSIZE "com/wiyun/engine/types/WYSize"
#define CLASS_LAYOUTUTIL "com/wiyun/engine/utils/LayoutUtil"
#define CLASS_ONDOUBLETAPLISTENER "android/view/GestureDetector$OnDoubleTapListener"
#define CLASS_ONGESTURELISTENER "android/view/GestureDetector$OnGestureListener"
#define CLASS_FILEDESCRIPTOR "java/io/FileDescriptor"
#define CLASS_CONTEXT "android/content/Context"
#define CLASS_RESOURCES "android/content/res/Resources"
#define CLASS_KEYEVENT "android/view/KeyEvent"
#define CLASS_MOTIONEVENT "android/view/MotionEvent"
#define CLASS_BITMAP "android/graphics/Bitmap"
#define CLASS_DISPLAYMETRICS "android/util/DisplayMetrics"
#define CLASS_VERSION "android/os/Build$VERSION"
#define CLASS_INTENT "android/content/Intent"
#define CLASS_TYPEFACE "android/graphics/Typeface"

#define CLASS_ACTION_CALLBACK "com/wiyun/engine/actions/Action$Callback"
#define CLASS_WYPOINT "com/wiyun/engine/types/WYPoint"
#define CLASS_WYRECT "com/wiyun/engine/types/WYRect"
#define CLASS_WYVERTEX3D "com/wiyun/engine/types/WYVertex3D"
#define CLASS_WYCOLOR3B "com/wiyun/engine/types/WYColor3B"
#define CLASS_WYCOLOR3F "com/wiyun/engine/types/WYColor3F"
#define CLASS_WYCOLOR4B "com/wiyun/engine/types/WYColor4B"
#define CLASS_WYCOLOR4F "com/wiyun/engine/types/WYColor4F"
#define CLASS_WYQUAD2D "com/wiyun/engine/types/WYQuad2D"
#define CLASS_WYQUAD3D "com/wiyun/engine/types/WYQuad3D"
#define CLASS_WYBEZIERCONFIG "com/wiyun/engine/types/WYBezierConfig"
#define CLASS_WYAFFINETRANSFORM "com/wiyun/engine/types/WYAffineTransform"
#define CLASS_TARGETSELECTOR "com/wiyun/engine/utils/TargetSelector"

// sal definition
typedef char* (*scaleImageFunc)(int config, char* originData, int originWidth, int originHeight, float scale);
typedef char* (*scalePVRFunc)(int format, char* originData, int originWidth, int originHeight, float scale);
typedef void (*calculateTextSizeWithFontFunc)(const char* text, const char* fontName, float fontSize, bool bold, bool italic, int* w, int* h);
typedef void (*calculateTextSizeWithCustomFontFunc)(const char* text, const char* fontData, int dataLength, float fontSize, int* w, int* h);
typedef const char* (*createLabelBitmapWithFontFunc)(const char* text, const char* fontName, float fontSize, bool bold, bool italic);
typedef const char* (*createLabelBitmapWithCustomFontFunc)(const char* text, const char* fontData, int dataLength, float fontSize);
typedef struct wySAL {
	scaleImageFunc scaleImage;
	scalePVRFunc scalePVR;
	calculateTextSizeWithFontFunc calculateTextSizeWithFont;
	calculateTextSizeWithCustomFontFunc calculateTextSizeWithCustomFont;
	createLabelBitmapWithFontFunc createLabelBitmapWithFont;
	createLabelBitmapWithCustomFontFunc createLabelBitmapWithCustomFont;
} wySAL;

#endif // __wyInit_h__
