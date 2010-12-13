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
#ifndef __wyRect_h__
#define __wyRect_h__

#ifdef __cplusplus
extern "C" {
#endif

static const wyRect wyrZero = { 0.0f, 0.0f, 0.0f, 0.0f };

static inline wyRect wyr(float x, float y, float w, float h) {
	wyRect r = { x, y, w, h };
	return r;
}

static inline bool wyrEquals(wyRect r1, wyRect r2) {
	return r1.x == r2.x &&
			r1.y == r2.y &&
			r1.width == r2.width &&
			r1.height == r2.height;
}

static inline bool wyrContains(wyRect r1, wyPoint p) {
	return p.x >= r1.x &&
		p.x < r1.x + r1.width &&
		p.y >= r1.y &&
		p.y < r1.y + r1.height;
}

#ifdef __cplusplus
}
#endif

#endif // __wyRect_h__
