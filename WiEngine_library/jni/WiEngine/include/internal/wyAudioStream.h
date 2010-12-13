#ifndef __wyAudioStream_h__
#define __wyAudioStream_h__

#include "wyAudioFile.h"

class wyAudioStream : public wyObject{
protected:
	wyAudioFile* m_AudioFile;

	/// 放置临时PCM数据
	unsigned char* m_Buffer;

	/// 放置最后一帧的音频数据，和channel数成正比
	short m_LastFrame[MAX_CHANNEL_COUNT];

	int m_BufferLength;
	int m_SampleRates;
	int m_ChannelCount;
	int m_AudioBits;
	int m_BufferSize;
	bool m_Playing;
	bool m_Repeat;
	bool m_Complete;

public:
	void reopenStream();
	void pause();
	void resume();
	bool isPlaying() const { return m_Playing; };
	bool isRepeat() const { return m_Repeat; };
	bool isComplete() const { return m_Complete; };
	void setComplete(bool complete) { m_Complete = complete; };
	void setRepeat(bool repeat) { m_Repeat = repeat; };
	int getMinBufferSize() const { return m_BufferSize; };
	int getSampleRates() const { return m_SampleRates;}
	int getChannelCount() const { return m_ChannelCount;}
	int getAudioBits() const { return m_AudioBits;}

	/**
	 * 从音频文件里读取音频数据，并转换成需要的采样率和通道数
	 */
	int readAndConvertAudioData(short* buffer, int bufferSize, int sampleRates, int channelCount);

public:
	wyAudioStream(wyAudioFile* audioFile);
	virtual ~wyAudioStream();
	virtual bool openStream();
	virtual void closeStream();
	virtual int readStream(unsigned char* buffer, int length) = 0;
};

#endif // __wyAudioStream_h__
