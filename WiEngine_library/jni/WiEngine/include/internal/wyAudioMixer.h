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
#pragma once

#include <pthread.h>
#include "wyObject.h"
#include "wyAudioStream.h"

class wyAudioMixer : public wyObject{
private:
	int m_Count;
	int m_Size;
	wyAudioStream** m_List;
	pthread_mutex_t m_Mutex;

	/**
	 * 混音后的采样率和通道数
	 */
	int m_SampleRates;
	int m_ChannelCount;

	/**
	 * 用来进行混音的缓冲区
	 */
	short* m_TempBuffer;

public:
	wyAudioMixer();
	virtual ~wyAudioMixer();

	/**
	 * This is used for setting mixing audio format.
	 * It will be called by AudioManager directly.
	 */
	void setOutputConfig(int sampleRates, int channelCount);

	/**
	 * Add audio stream for mixing
	 */
	bool addAudioStream(wyAudioStream* stream);

	/**
	 * Remove audio stream from mixing
	 */
	void removeAudioStream(wyAudioStream* stream);

	/**
	 * Check whether there is audio need to mixing
	 */
	bool hasAudioToPlay();

	/**
	 * Read mixed audio data
	 */
	int  readMixData(unsigned char* buffer, int length);
};

