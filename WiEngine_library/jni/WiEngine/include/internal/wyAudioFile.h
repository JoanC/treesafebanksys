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
#ifndef __wyAudioFile_h__
#define __wyAudioFile_h__

#include <stdio.h>
#include "wyObject.h"

#define MAX_CHANNEL_COUNT 2

class wyAssetInputStream;
class wyAudioFile : public wyObject {
private:
	int m_Length;
	int m_Position;
	char* m_Buffer;

	void* m_ResourceName;
	bool m_Inherit;

	// asset input stream
	wyAssetInputStream* m_ais;

public:
	wyAudioFile();
	wyAudioFile(int resId);
	wyAudioFile(const char* path, bool isFile);
	virtual ~wyAudioFile();

public:
	void* getResourceName() { return m_ResourceName; };
	void setResourceName(void* name) { m_ResourceName = name; };

	bool open();
	void close();
	int read(unsigned char* buffer, int length);
	int seek(int offset, int mode);

	void preload();
	void copy(wyAudioFile* sourceFile);
};

#endif // __wyAudioFile_h__
