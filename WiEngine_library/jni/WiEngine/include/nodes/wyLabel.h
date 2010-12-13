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
#ifndef __wyLabel_h__
#define __wyLabel_h__

#include "wyTextureNode.h"

class wyLabel : public wyTextureNode {
public:
	static wyLabel* make(const char* text);
	static wyLabel* make(const char* text, float fontSize, const char* fontPath = NULL);
	static wyLabel* make(const char* text, float fontSize, wyFontStyle style, const char* fontName = NULL);

	wyLabel();
	wyLabel(const char* text, float fontSize, const char* fontPath = NULL);
	wyLabel(const char* text, float fontSize, wyFontStyle style, const char* fontName = NULL);
	virtual ~wyLabel();

	// 获得文字字符串
	virtual const char* getText() { return tex->getText(); }

	// 设置文字
	virtual void setText(const char* text) { setString(text); }

	void setString(const char* text);
};

#endif // __wyLabel_h__
