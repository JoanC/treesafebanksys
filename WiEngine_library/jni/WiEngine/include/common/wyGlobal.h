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
#ifndef __wyGlobal_h__
#define __wyGlobal_h__

// 预定义的density
/// 低分辨率, 相当于120dpi
#define DENSITY_LDPI 0.75f

/// 中分辨率, 相当于160dpi
#define DENSITY_MDPI 1.f

/// 高分辨率，相当于240dpi
#define DENSITY_HDPI 1.5f

/**
 * @class wyGlobal
 *
 * 只用来封装一些全局参数
 */
class wyGlobal {
public:
	wyGlobal();
	virtual ~wyGlobal();

	/// 当前系统api版本，3表示1.5, 4表示1.6，等等
	static int apiLevel;

	/// OpenGL支持的最大贴图尺寸
	static int maxTextureSize;

	/// 当前设备的屏幕分辨率
	static float density;

	/// 当前设备屏幕的字体分辨率
	static float scaledDensity;

	/**
	 * 图片的缺省分辨率，这个参数会影响到所有图片的解析。
	 * 如果这个参数和density相同，那么图片不会被缩放。
	 * 如果density是1.5，而这个值是1，那么图片将会被放大到1.5倍
	 */
	static float defaultInDensity;

	/// OpenGL Surface的像素宽度
	static int winWidth;

	/// OpenGL Surface的像素高度
	static int winHeight;
};

#endif // __wyGlobal_h__
