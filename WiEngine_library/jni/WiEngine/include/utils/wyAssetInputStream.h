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
#ifndef __wyAssetInputStream_h__
#define __wyAssetInputStream_h__

#include "wyObject.h"
#include <stdio.h>

/**
 * @class wyAssetInputStream
 *
 * 封装一个Asset资源, 将其保证成一个输入流, 可以在其上执行read, seek等
 * 通用IO方法
 */
class wyAssetInputStream : public wyObject {
private:
	// Asset class get from resource id or asset path
	// use void* to avoid include any headers in .h
	void* m_asset;

	// FILE pointer used for file path
	FILE* m_fp;

public:
	/**
	 * 构造函数
	 *
	 * @param resId 资源文件id
	 */
	wyAssetInputStream(int resId);

	/**
	 * 构造函数
	 *
	 * @param path 文件路径
	 * @param isFile true表示path是一个文件系统路径, false表示path是一个asset下的路径
	 */
	wyAssetInputStream(const char* path, bool isFile);

	/**
	 * 析构函数
	 */
	virtual ~wyAssetInputStream();

	/**
	 * 载入文件所有内容, 返回一个缓冲区, 返回的缓冲区需要调用者负责释放
	 *
	 * @return 包含文件所有内容的缓冲区
	 */
	char* getBuffer();

	/**
	 * 得到当前读取位置相对于头部的偏移
	 *
	 * @return 当前读取位置相对于头部的偏移
	 */
	int getPosition();

	/**
	 * 得到所有可读的数据字节长度
	 *
	 * @return 所有数据长度
	 */
	int getLength();

	/**
	 * 打开相关的Asset资源
	 *
	 * @return true表示打开成功
	 */
	bool open();

	/**
	 * 关闭Asset
	 */
	void close();

	/**
	 * 读取指定长度的数据
	 *
	 * @param buffer 缓冲区, 必须具有足够的空间
	 * @param length 要速度的字节数
	 * @return 实际读取的字节数, 为0表示已无数据可读, -1表示出错
	 */
	int read(char* buffer, int length);

	/**
	 * 改变指针位置
	 *
	 * @param offset 偏移
	 * @param mode SEEK_CUR表示从当前位置计算, SEEK_SET表示从开头计算, SEEK_END表示从结尾处计算
	 * @return 修改后的实际位置
	 */
	int seek(int offset, int mode);
};

#endif // __wyAssetInputStream_h__
