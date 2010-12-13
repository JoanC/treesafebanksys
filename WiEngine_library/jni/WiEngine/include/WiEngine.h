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
#ifndef __WiEngine_h__
#define __WiEngine_h__

// common headers
#include "wyGlobal.h"
#include "wyTypes.h"
#include "wyArray.h"
#include "wyHashSet.h"
#include "wyThread.h"

// actions
#include "wyAnimate.h"
#include "wyBezier.h"
#include "wyBlink.h"
#include "wyCallFunc.h"
#include "wyCameraAction.h"
#include "wyDelayTime.h"
#include "wyFadeIn.h"
#include "wyFadeOut.h"
#include "wyFadeTo.h"
#include "wyHide.h"
#include "wyJumpBy.h"
#include "wyJumpTo.h"
#include "wyMoveBy.h"
#include "wyMoveByAngle.h"
#include "wyMoveTo.h"
#include "wyOrbitCamera.h"
#include "wyPlace.h"
#include "wyProgressBy.h"
#include "wyProgressTo.h"
#include "wyRepeat.h"
#include "wyRepeatForever.h"
#include "wyReverseTime.h"
#include "wyRotateBy.h"
#include "wyRotateTo.h"
#include "wyScaleBy.h"
#include "wyScaleTo.h"
#include "wySequence.h"
#include "wyShow.h"
#include "wySpawn.h"
#include "wySpeed.h"
#include "wyTintBy.h"
#include "wyTintTo.h"
#include "wyToggleVisibility.h"

// ease actions
#include "wyEaseBackIn.h"
#include "wyEaseBackInOut.h"
#include "wyEaseBackOut.h"
#include "wyEaseBounceIn.h"
#include "wyEaseBounceInOut.h"
#include "wyEaseBounceOut.h"
#include "wyEaseExponentialIn.h"
#include "wyEaseExponentialInOut.h"
#include "wyEaseExponentialOut.h"
#include "wyEaseIn.h"
#include "wyEaseInOut.h"
#include "wyEaseOut.h"
#include "wyEaseSineIn.h"
#include "wyEaseSineInOut.h"
#include "wyEaseSineOut.h"
#include "wyEaseElasticIn.h"
#include "wyEaseElasticInOut.h"
#include "wyEaseElasticOut.h"

// grid actions
#include "wyBottomLineShrinkOut.h"
#include "wyBottomTilesShrinkOut.h"
#include "wyGridFlipX.h"
#include "wyGridFlipY.h"
#include "wyJumpTiles3D.h"
#include "wyLeftBottomTilesShrinkOut.h"
#include "wyLeftLineShrinkOut.h"
#include "wyLens3D.h"
#include "wyLiquid.h"
#include "wyPageTurn3D.h"
#include "wyReuseGrid.h"
#include "wyRightLineShrinkOut.h"
#include "wyRightTopTilesShrinkOut.h"
#include "wyRipple3D.h"
#include "wyShaky3D.h"
#include "wyShakyTiles3D.h"
#include "wyShatteredTiles3D.h"
#include "wyShuffleTiles.h"
#include "wySplitCols.h"
#include "wySplitRows.h"
#include "wyStopGrid.h"
#include "wyTopLineShrinkOut.h"
#include "wyTopTilesShrinkOut.h"
#include "wyTurnOffTiles.h"
#include "wyTwirl.h"
#include "wyWaves.h"
#include "wyWaves3D.h"
#include "wyWavesTiles3D.h"

// singletons
#include "wyDirector.h"
#include "wyActionManager.h"
#include "wyTextureManager.h"
#include "wyScheduler.h"
#include "wyEventDispatcher.h"

// animations
#include "wyAnimation.h"
#include "wyAtlasAnimation.h"
#include "wyTextureFrame.h"
#include "wyAtlasFrame.h"

// nodes
#include "wyArrayTileMapAtlas.h"
#include "wyTGATileMapAtlas.h"
#include "wyAtlasButton.h"
#include "wyAtlasLabel.h"
#include "wyButton.h"
#include "wyLabel.h"
#include "wyColorLayer.h"
#include "wyMultiplexLayer.h"
#include "wyScene.h"
#include "wyMenu.h"
#include "wyMenuItemLabel.h"
#include "wyMenuItemSprite.h"
#include "wyMenuItemAtlasLabel.h"
#include "wyMenuItemAtlasSprite.h"
#include "wyMenuItemAtlasLabel.h"
#include "wyMenuItemAtlasSprite.h"
#include "wyMenuItemToggle.h"
#include "wyMotionStreak.h"
#include "wyParallaxNode.h"
#include "wyProgressTimer.h"
#include "wyRenderTexture.h"
#include "wyTiledSprite.h"
#include "wyTMXTileMap.h"

// opengl base
#include "wyPrimitives.h"

// particle
#include "wyPointParticleSystem.h"
#include "wyQuadParticleSystem.h"
#include "wyParticleLoader.h"

// transitions
#include "wyBottomPushInTransition.h"
#include "wyTopPushInTransition.h"
#include "wyLeftPushInTransition.h"
#include "wyRightPushInTransition.h"
#include "wyBottomSlideInTransition.h"
#include "wyTopSlideInTransition.h"
#include "wyLeftSlideInTransition.h"
#include "wyRightSlideInTransition.h"
#include "wyBottomTilesShrinkOutTransition.h"
#include "wyTopTilesShrinkOutTransition.h"
#include "wyLeftBottomTilesShrinkOutTransition.h"
#include "wyRightTopTilesShrinkOutTransition.h"
#include "wyColorFadeTransition.h"
#include "wyCrossFadeTransition.h"
#include "wyFlipAngularTransition.h"
#include "wyFlipXTransition.h"
#include "wyFlipYTransition.h"
#include "wyZoomFlipAngularTransition.h"
#include "wyZoomFlipXTransition.h"
#include "wyZoomFlipYTransition.h"
#include "wyJumpZoomTransition.h"
#include "wyRotateZoomTransition.h"
#include "wyShrinkGrowTransition.h"
#include "wySplitColsTransition.h"
#include "wySplitRowsTransition.h"
#include "wyTurnOffTilesTransition.h"
#include "wyPageTurn3DTransition.h"

// utils
#include "wyUtils.h"
#include "wyLayoutUtil.h"
#include "wyScroller.h"

#endif // __WiEngine_h__
