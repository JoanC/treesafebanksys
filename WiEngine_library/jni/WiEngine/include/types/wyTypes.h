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
#ifndef __wyTypes_h__
#define __wyTypes_h__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef FLT_EPSILON
	#define FLT_EPSILON 1.19209290e-07f
#endif

#define GOLDEN_MEAN 1.1547f
#define MAX_FLOAT 3.4028235E38f
#define MAX_INT 0x7fffffff

// basic types
typedef struct wyPoint { float x, y; } wyPoint;
typedef struct wyDimension { int x, y; } wyDimension;
typedef struct wySize { float width, height; } wySize;
typedef struct wyRect { float x, y, width, height; } wyRect;
typedef struct wyVertex3D { float x, y, z; } wyVertex3D;
typedef struct wyQuad3D {
	float bl_x, bl_y, bl_z;
	float br_x, br_y, br_z;
	float tl_x, tl_y, tl_z;
	float tr_x, tr_y, tr_z;
} wyQuad3D;
typedef struct wyQuad2D {
	// bottom left
	float bl_x, bl_y;

	// bottom right
	float br_x, br_y;

	// top left
	float tl_x, tl_y;

	// top right
	float tr_x, tr_y;
} wyQuad2D;
typedef struct wyAffineTransform { float a, b, c, d, tx, ty; } wyAffineTransform;
typedef struct wyBlendFunc { int src, dst; } wyBlendFunc;
typedef struct wyColor3B { unsigned char r, g, b; } wyColor3B;
typedef struct wyColor4B { unsigned char r, g, b, a; } wyColor4B;
typedef struct wyColor4F { float r, g, b, a; } wyColor4F;
typedef struct wyBezierConfig {
	float startX, startY, endX, endY, cp1X, cp1Y, cp2X, cp2Y;
} wyBezierConfig;

typedef enum {
    NORMAL = 0,
    BOLD   = 0x01,
    ITALIC = 0x02,
    BOLD_ITALIC = 0x03
} wyFontStyle;

typedef enum {
	KEY_ACTION_DOWN,
	KEY_ACTION_UP,
	KEY_ACTION_MULTIPLE
} wyKeyAction;

typedef enum {
	UNKNOWN_PLIST_TAG,
	DOCUMENT,
	PLIST,
	DICT,
	KEY,
	REAL,
	STRING,
	INTEGER
} wyPListTag;

typedef enum {
	KEYCODE_UNKNOWN         = 0,
	KEYCODE_SOFT_LEFT       = 1,
	KEYCODE_SOFT_RIGHT      = 2,
	KEYCODE_HOME            = 3,
	KEYCODE_BACK            = 4,
	KEYCODE_CALL            = 5,
	KEYCODE_ENDCALL         = 6,
	KEYCODE_0               = 7,
	KEYCODE_1               = 8,
	KEYCODE_2               = 9,
	KEYCODE_3               = 10,
	KEYCODE_4               = 11,
	KEYCODE_5               = 12,
	KEYCODE_6               = 13,
	KEYCODE_7               = 14,
	KEYCODE_8               = 15,
	KEYCODE_9               = 16,
	KEYCODE_STAR            = 17,
	KEYCODE_POUND           = 18,
	KEYCODE_DPAD_UP         = 19,
	KEYCODE_DPAD_DOWN       = 20,
	KEYCODE_DPAD_LEFT       = 21,
	KEYCODE_DPAD_RIGHT      = 22,
	KEYCODE_DPAD_CENTER     = 23,
	KEYCODE_VOLUME_UP       = 24,
	KEYCODE_VOLUME_DOWN     = 25,
	KEYCODE_POWER           = 26,
	KEYCODE_CAMERA          = 27,
	KEYCODE_CLEAR           = 28,
	KEYCODE_A               = 29,
	KEYCODE_B               = 30,
	KEYCODE_C               = 31,
	KEYCODE_D               = 32,
	KEYCODE_E               = 33,
	KEYCODE_F               = 34,
	KEYCODE_G               = 35,
	KEYCODE_H               = 36,
	KEYCODE_I               = 37,
	KEYCODE_J               = 38,
	KEYCODE_K               = 39,
	KEYCODE_L               = 40,
	KEYCODE_M               = 41,
	KEYCODE_N               = 42,
	KEYCODE_O               = 43,
	KEYCODE_P               = 44,
	KEYCODE_Q               = 45,
	KEYCODE_R               = 46,
	KEYCODE_S               = 47,
	KEYCODE_T               = 48,
	KEYCODE_U               = 49,
	KEYCODE_V               = 50,
	KEYCODE_W               = 51,
	KEYCODE_X               = 52,
	KEYCODE_Y               = 53,
	KEYCODE_Z               = 54,
	KEYCODE_COMMA           = 55,
	KEYCODE_PERIOD          = 56,
	KEYCODE_ALT_LEFT        = 57,
	KEYCODE_ALT_RIGHT       = 58,
	KEYCODE_SHIFT_LEFT      = 59,
	KEYCODE_SHIFT_RIGHT     = 60,
	KEYCODE_TAB             = 61,
	KEYCODE_SPACE           = 62,
	KEYCODE_SYM             = 63,
	KEYCODE_EXPLORER        = 64,
	KEYCODE_ENVELOPE        = 65,
	KEYCODE_ENTER           = 66,
	KEYCODE_DEL             = 67,
	KEYCODE_GRAVE           = 68,
	KEYCODE_MINUS           = 69,
	KEYCODE_EQUALS          = 70,
	KEYCODE_LEFT_BRACKET    = 71,
	KEYCODE_RIGHT_BRACKET   = 72,
	KEYCODE_BACKSLASH       = 73,
	KEYCODE_SEMICOLON       = 74,
	KEYCODE_APOSTROPHE      = 75,
	KEYCODE_SLASH           = 76,
	KEYCODE_AT              = 77,
	KEYCODE_NUM             = 78,
	KEYCODE_HEADSETHOOK     = 79,
	KEYCODE_FOCUS           = 80,   // *Camera* focus
	KEYCODE_PLUS            = 81,
	KEYCODE_MENU            = 82,
	KEYCODE_NOTIFICATION    = 83,
	KEYCODE_SEARCH          = 84,
	KEYCODE_MEDIA_PLAY_PAUSE= 85,
	KEYCODE_MEDIA_STOP      = 86,
	KEYCODE_MEDIA_NEXT      = 87,
	KEYCODE_MEDIA_PREVIOUS  = 88,
	KEYCODE_MEDIA_REWIND    = 89,
	KEYCODE_MEDIA_FAST_FORWARD = 90,
	KEYCODE_MUTE            = 91,
	KEYCODE_PAGE_UP         = 92,
	KEYCODE_PAGE_DOWN       = 93,
	KEYCODE_PICTSYMBOLS     = 94,   // switch symbol-sets (Emoji,Kao-moji)
	KEYCODE_SWITCH_CHARSET  = 95   // switch char-sets (Kanji,Katakana)
} wyKeyCode;

// event types
typedef struct wyKeyEvent {
	// key code
	wyKeyCode keyCode;

	// action
	wyKeyAction action;

	// int repeat count
	int repeatCount;

	// event time
	int64_t eventTime;

	// down time
	int64_t downTime;
} wyKeyEvent;

#define ACTION_MASK 0xff
#define ACTION_POINTER_ID_MASK 0xff00
#define ACTION_POINTER_ID_SHIFT 8
typedef enum {
	MOTION_ACTION_DOWN,
	MOTION_ACTION_UP,
	MOTION_ACTION_MOVE,
	MOTION_ACTION_CANCEL,
	MOTION_ACTION_OUTSIDE,
	MOTION_ACTION_POINTER_DOWN,
	MOTION_ACTION_POINTER_UP
} wyMotionAction;

typedef struct wyMotionEvent {
	// action code, it may contains pointer id
	wyMotionAction action;

	// pointer count
	int pointerCount;

	// pointer ids, max 5
	int pid[5];

	// pointer x and y, we set 5 here
	// the x/y is in Android coordination and relative to left top corner of GL surface view
	float x[5];
	float y[5];

	// pressure
	float pressure;

	// event time
	int64_t eventTime;

	// down time
	int64_t downTime;
} wyMotionEvent;

#ifdef __cplusplus
}
#endif

// other includes
#include "wyPoint.h"
#include "wyDimension.h"
#include "wySize.h"
#include "wyVertex3D.h"
#include "wyRect.h"
#include "wyQuad2D.h"
#include "wyQuad3D.h"
#include "wyColor4F.h"
#include "wyColor3B.h"
#include "wyColor4B.h"
#include "wyAffineTransform.h"
#include "wyBlendFunc.h"

#endif // __wyTypes_h__
