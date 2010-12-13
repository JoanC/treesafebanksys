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
#ifndef __wyTexture2D_h__
#define __wyTexture2D_h__

#include <stdbool.h>
#include <stdint.h>
#include <GLES/gl.h>
#include "wyTypes.h"
#include "wyObject.h"

typedef enum {
	// texture source
	SOURCE_INVALID,
	SOURCE_JPG,
	SOURCE_PNG,
	SOURCE_PVR,
	SOURCE_LABEL,
	SOURCE_BITMAP,
	SOURCE_OPENGL
} wyTextureSource;

// PVR flag
typedef enum {
	PVR_TEXTURE_FLAG_TYPE_MASK = 0xff,
	PVR_TEXTURE_FLAG_FLIPPED_MASK = 0x10000
} wyPVRFlag;

// PVR format type
typedef enum {
	PVR_RGBA_4444 = 0x10,
	PVR_RGBA_5551 = 0x11,
	PVR_RGBA_8888 = 0x12,
	PVR_RGB_565 = 0x13,
	PVR_RGB_555 = 0x14,
	PVR_RGB_888 = 0x15,
	PVR_I_8 = 0x16,
	PVR_AI_88 = 0x17,
	PVR_PVRTC_2 = 0x18,
	PVR_PVRTC_4 = 0x19,
	PVR_BGRA_8888 = 0x1A,
	PVR_A_8 = 0x1B
} wyPVRFormat;

// field index
typedef enum {
	PVR_INDEX_TEXTURE_FORMAT,
	PVR_INDEX_INTERNAL_FORMAT,
	PVR_INDEX_OPENGL_FORMAT,
	PVR_INDEX_OPENGL_TYPE,
	PVR_INDEX_BPP,
	PVR_INDEX_COMPRESSED,
} wyPVRIndex;

// - PVR texture format
// - OpenGL internal format
// - OpenGL format
// - OpenGL type
// - bpp
// - compressed
static int sPVRFormats[][6] = {
	/*
	 * 4444, 5551 and 565 has problem in testing, so disable it now
	 * pvrtc 2/4 is power vr only
	 */
	{ PVR_RGBA_4444, GL_RGBA, GL_RGBA, GL_UNSIGNED_SHORT_4_4_4_4, 16, 0 },
	{ PVR_RGBA_5551, GL_RGBA, GL_RGBA, GL_UNSIGNED_SHORT_5_5_5_1, 16, 0 },
    { PVR_RGBA_8888, GL_RGBA, GL_RGBA, GL_UNSIGNED_BYTE, 32, 0 },
	{ PVR_RGB_565, GL_RGB, GL_RGB, GL_UNSIGNED_SHORT_5_6_5, 16, 0 },
    { PVR_I_8, GL_LUMINANCE, GL_LUMINANCE, GL_UNSIGNED_BYTE, 8, 0 },
    { PVR_AI_88, GL_LUMINANCE_ALPHA, GL_LUMINANCE_ALPHA, GL_UNSIGNED_BYTE, 16, 0 },
//        { PVR_PVRTC_2, GL_COMPRESSED_RGBA_PVRTC_2BPPV1_IMG, -1, -1, 2, 1 },
//        { PVR_PVRTC_4, GL_COMPRESSED_RGBA_PVRTC_4BPPV1_IMG, -1, -1, 4, 1 },
//        { PVR_BGRA_8888, GL_RGBA, GL_BGRA, GL_UNSIGNED_BYTE, 32, 0 },
    { PVR_A_8, GL_ALPHA, GL_ALPHA, GL_UNSIGNED_BYTE, 8, 0 }
};
#define MAX_TABLE_ELEMENTS (sizeof(sPVRFormats) / sizeof(sPVRFormats[0]))

typedef struct wyPVRHeader {
	int headerLength;
	int height;
	int width;
	int numMipmaps;
	int flags;
	int dataLength;
	int bpp;
	int bitmaskRed;
	int bitmaskGreen;
	int bitmaskBlue;
	int bitmaskAlpha;
	int pvrTag;
	int numSurfs;
} wyPVRHeader;

class wyTexture2D : public wyObject {
	friend class wyTextureManager;

private:
	// texture source
	wyTextureSource source;

	// resource id
	int resId;

	// asset path or file system path
	const char* m_path;

	// true means the m_path is file system path, otherwise it is asset path
	bool m_isFile;

	// for pvr
	int pvrFormatIndex;
	bool hasAlpha;

	// for label
	float fontSize;
	wyFontStyle fontStyle;
	const char* fontName;
	const char* fontPath;
	const char* text;

	// for bitmap
	jobject bitmap;

	// for binary
	const char* data;
	int length;

	// for memory file system
	const char* mfsName;

	// flag indicating we need update current label texture
	bool needUpdateLabel;

	// rate between real size and pixel size
	float widthScale, heightScale;

	/// OpenGL层的贴图标识, 属于OpenGL内部使用的标识
	int texture;

	/**
	 * wyTexture2D对象的唯一标识符, 通过这个id可以获得这个对象.
	 * 主要用来支持对象的重用. 也可以通过这个id删除贴图.
	 */
	int64_t texId;

	// pixel size and real size
	int pixelWidth, pixelHeight;
	float width, height;

	// texture parameters
	int minFilter;
	int magFilter;
	int wrapS;
	int wrapT;

	// flag indicating draw a Y-flipped image
	bool flipY;

	// source density, only available for png and pvr
	float inDensity;

private:
	// init texture 2d struct with effective size
	void initSize(int realWidth, int realHeight);
	char** unpackPVRData(char* data, wyPVRHeader* header, int** mipmapLens);

public:
	static wyTexture2D* makeJPG(int resId, float inDensity = 0);
	static wyTexture2D* makeJPG(const char* data, int length, float inDensity = 0);
	static wyTexture2D* makeJPG(const char* assetPath, float inDensity = 0);
	static wyTexture2D* makeMemoryJPG(const char* mfsName, float inDensity = 0);
	static wyTexture2D* makeFileJPG(const char* fsPath, float inDensity = 0);
	static wyTexture2D* makePNG(int resId, float inDensity = 0);
	static wyTexture2D* makePNG(const char* data, int length, float inDensity = 0);
	static wyTexture2D* makePNG(const char* assetPath, float inDensity = 0);
	static wyTexture2D* makeMemoryPNG(const char* mfsName, float inDensity = 0);
	static wyTexture2D* makeFilePNG(const char* fsPath, float inDensity = 0);
	static wyTexture2D* makePVR(int resId, float inDensity = 0);
	static wyTexture2D* makePVR(const char* data, int length, float inDensity = 0);
	static wyTexture2D* makePVR(const char* assetPath, float inDensity = 0);
	static wyTexture2D* makeMemoryPVR(const char* mfsName, float inDensity = 0);
	static wyTexture2D* makeFilePVR(const char* fsPath, float inDensity = 0);
	static wyTexture2D* makeLabel(const char* text, float fontSize, const char* fontPath = NULL);
	static wyTexture2D* makeLabel(const char* text, float fontSize, wyFontStyle style, const char* fontName = NULL);
	static wyTexture2D* makeGL(int texture, int w, int h);
	static wyTexture2D* makeBitmap(jobject bitmap);

	// constructor/deconstructor
	wyTexture2D(int64_t texId = 0);
	virtual ~wyTexture2D();

	// destroy OpenGL texture object
	void deleteTexture(bool noDeleteGL = false);

	// load texture
	void load();

	// update label
	void updateLabel(const char* text);
	void updateLabel(const char* text, float fontSize, const char* fontPath = NULL);
	void updateLabel(const char* text, float fontSize, wyFontStyle style, const char* fontName = NULL);

	// set anti alias
	void setAntiAlias(bool on);

	// set repeat
	void setRepeat(bool on);

	// set tex parameters
	void setParameters(int min, int mag, int wrapS, int wrapT);

	// apply tex parameters
	void applyParameters();

	// get premultiplied alpha flag
	bool hasPremultipliedAlpha();

	// draw texture
	void draw(float x, float y);
	void draw(float x, float y, bool flipX, bool flipY);

	// getters
	float getWidth() { return width; }
	float getHeight() { return height; }
	int getPixelWidth() { return pixelWidth; }
	int getPixelHeight() { return pixelHeight; }
	float getWidthScale() { return widthScale; }
	float getHeightScale() { return heightScale; }
	int getTexture() { return texture; }
	void setTexture(int tex) { texture = tex; }
	const char* getText() { return text; }
	wyTextureSource getSource() { return source; }
	int64_t getTexId() { return texId; }
	void setTexId(int64_t texId) { this->texId = texId; }
};

#endif // __wyTexture2D_h__
