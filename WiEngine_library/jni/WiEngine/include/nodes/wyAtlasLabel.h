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
#ifndef __wyAtlasLabel_h__
#define __wyAtlasLabel_h__

#include "wyAtlasNode.h"

class wyAtlasLabel : public wyAtlasNode {
protected:
    // string to render
    const char* text;

    // the first char in the charmap, we use short here to support non-English character
    unsigned short mapStartChar;

    // init
    void init(const char* text, wyTexture2D* tex, int itemWidth, int itemHeight);

private:
    void updateAtlasValues();

public:
    wyAtlasLabel(const char* text, wyTexture2D* tex, int itemWidth, int itemHeight, unsigned short startChar);
    virtual ~wyAtlasLabel();

	// 获得文字字符串
	virtual const char* getText() { return text; }

	// 设置文字
	virtual void setText(const char* text) { setString(text); }

	// set string
	void setString(const char* text);
};

#endif // __wyAtlasLabel_h__
