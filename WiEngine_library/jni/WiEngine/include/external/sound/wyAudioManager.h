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

#include "wyObject.h"
#include "wyHashSet.h"
#include <jni.h>

#define STREAM_TYPE_MP3 1
#define STREAM_TYPE_WAV 2

class wyAudioStream;
class wyAudioMixer;
class wyAudioFile;

class wyAudioManager : public wyObject {
public:
	static wyAudioManager* s_Instance;
	static wyAudioManager* getInstance();

private:
	wyAudioStream* m_BackgroundStream;
	wyAudioMixer* m_AudioMixer;
	jobject m_AudioEngine;
	bool m_AudioFormatSet;

	wyHashSet* m_AudioCache;
private:
	wyAudioManager();

	void setNeedsPlay();
	void stopPlay();
	wyAudioStream* play(wyAudioFile* file, int type);
	wyAudioStream* play(int resId, int type);
	wyAudioStream* play(const char* path, bool isFile, int type);

	void playBackgroundMusic(wyAudioFile* file, int type);

	void playEffect(wyAudioFile* source, int type, bool copy = true);

public:
	virtual ~wyAudioManager();

	/**
	 * 设置音频输出参数。缺省情况下这个会在第一个音频流被播放之前自动调用。
	 * 但是如果需要播放多个音频流且它们的格式有区别，则应该手动调用该方法
	 * 设置输出参数
	 */
	void setConfig(int bufferSize, int sampleRates, int channelCount);

	wyAudioMixer* getAudioMixer() const { return m_AudioMixer; }
	wyAudioStream* getBackgroundStream() const { return m_BackgroundStream; }

	/**
	 * 根据resourceId播放
	 */
	void playBackgroundMusic(int resourceId, int type);

	/**
	 * 根据文件名播放
	 */
	void playBackgroundMusic(const char* path, bool isFile = false, int type = STREAM_TYPE_MP3);

	/**
	 * 根据resourceId播放
	 */
	void playEffect(int resourceId, int type);

	/**
	 * 根据文件名播放
	 */
	void playEffect(const char* path, bool isFile = false, int type = STREAM_TYPE_MP3);

	/**
	 * 根据预加载的文件播放
	 */
	void playPreloadEffect(int key, int type);

	/**
	 * 根据resourceId加载
	 */
	void preloadEffect(int key, int resourceId);

	/**
	 * 根据文件名加载
	 */
	void preloadEffect(int key, const char* path, bool isFile = false, int type = STREAM_TYPE_MP3);

	void stopBackgroundMusic();
	void pauseBackgroundMusic();
	void resumeBackgroundMusic();
};
