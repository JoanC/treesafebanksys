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
#ifndef __wyParticleSystem_h__
#define __wyParticleSystem_h__

#include "wyNode.h"
#include "wyParticle.h"
#include "wyArray.h"
#include "wyScheduler.h"

/** The Particle emitter lives forever */
#define PARTICLE_DURATION_INFINITY -1

/** The starting size of the particle is equal to the ending size */
#define PARTICLE_START_SIZE_EQUAL_TO_END_SIZE -1

/** The starting radius of the particle is equal to the ending radius */
#define PARTICLE_START_RADIUS_EQUAL_TO_END_RADIUS -1

/**
 * 粒子系统模式
 */
typedef enum {
	/** Gravity mode (A mode) */
	GRAVITY = 1,

	/** Radius mode (B mode) */
	RADIUS
} wyParticleSystemMode;

typedef enum {
	/** If the emitter is repositioned, the living particles won't be repositioned */
	FREE = 1,

	/** If the emitter is repositioned, the living particles will be repositioned too */
	GROUPED,
} wyParticleSystemPositionType;

class wyParticleSystem : public wyNode {
protected:
	// flag indicating update is in calling
	bool updating;

	// is the particle system active ?
	bool active;

	// duration in seconds of the system. -1 is infinity
	float duration;

	// time elapsed since the start of the system (in seconds)
	float elapsed;

	// position is from "superclass" CocosNode
	// Emitter centerOfGravity position
	wyPoint centerOfGravity;

	// Position variance
	wyPoint centerOfGravityVar;

	// The angle (direction) of the particles measured in degrees
	float angle;

	// Angle variance measured in degrees;
	float angleVar;

	// start ize of the particles
	float startSize;

	// start Size variance
	float startSizeVar;

	// End size of the particle
	float endSize;

	// end size of variance
	float endSizeVar;

	// How many seconds will the particle live
	float life;
	float lifeVar;

	// Start color of the particles
	wyColor4F startColor;

	// Start color variance
	wyColor4F startColorVar;

	// End color of the particles
	wyColor4F endColor;

	// End color variance
	wyColor4F endColorVar;

	// self rotation angle of the particles, in degree
	float startSpin;

	// start angle variance
	float startSpinVar;

	// End angle of the particle
	float endSpin;

	// end angle ariance
	float endSpinVar;

	// Array of particles
	wyArray* particles;

	// Maximum particles
	int maxParticles;

	// Count of active particles
	int particleCount;

	// How many particles can be emitted per second
	float emissionRate;
	float emitCounter;

	// Texture of the particles
	wyTexture2D* tex;

	// blend function
	wyBlendFunc blendFunc;

	// movment type: free or grouped
	wyParticleSystemPositionType positionType;

	// Whether or not the node will be auto-removed when there are not particles
	bool autoRemoveOnFinish;

	//  particle idx
	int particleIdx;

	// mode
	wyParticleSystemMode emitterMode;

	// flag indicating we need change emitter position
	// and the pending x & y location
	bool pendingPosition;
	float pendingX;
	float pendingY;

	// update timer
	wyTimer* timer;

	// ////////////////////////////
	// gravity mode only
	//////////////////////////////

	// gravity of the particles
	wyPoint gravity;

	// The speed the particles will have.
	float speed;

	// The speed variance
	float speedVar;

	// Tangential acceleration
	float tangentialAccel;

	// Tangential acceleration variance
	float tangentialAccelVar;

	// Radial acceleration
	float radialAccel;

	// Radial acceleration variance
	float radialAccelVar;

	// ////////////////////////////
	// radius mode only
	//////////////////////////////

	// The starting radius of the particles
	float startRadius;

	// The starting radius variance of the particles
	float startRadiusVar;

	// The ending radius of the particles
	float endRadius;

	// The ending radius variance of the particles
	float endRadiusVar;

	// Number of degrees to rotate a particle around the source pos per second
	float rotationDegree;

	// Variance in degrees in one second for particle revolution
	float rotationDegreeVar;

private:
	static bool releaseParticle(wyArray* arr, void* ptr, int index, void* data);

protected:
	virtual void postStep() = 0;
	virtual void updateQuadWithParticle(wyParticle* particle, wyPoint newPosition) = 0;

	bool isFull() { return particleCount == maxParticles; }
	bool addParticle();
	void initParticle(wyParticle* particle);

public:
	wyParticleSystem(int numberOfParticles);
	virtual ~wyParticleSystem();

	/* target method for native target selector */
	virtual void onTargetSelectorInvoked(wyTargetSelector* ts);

	// update
	void update(float dt);

	// node
	virtual void setPosition(float x, float y);

	// get blend func
	virtual wyBlendFunc getBlendFunc() { return blendFunc; }

	// set blend func
	virtual void setBlendFunc(wyBlendFunc func) { blendFunc = func; }

	// get texture
	virtual wyTexture2D* getTexture() { return tex; }

	// set texture
	virtual void setTexture(wyTexture2D* tex);

	// start/stop
	void resetSystem();
	void stopSystem();

	// setters
	void setBlendAdditive(bool additive);
	bool isBlendAdditive() { return blendFunc.src == GL_SRC_ALPHA && blendFunc.dst == GL_ONE; }
	void setParticlePositionVariance(float baseX, float baseY, float varianceX, float varianceY);
	void setDirectionAngleVariance(float base, float variance);
	void setStartSizeVariance(float base, float variance);
	void setEndSizeVariance(float base, float variance);
	void setLifeVariance(float base, float variance);
	void setStartColorVariance(float baseR, float baseG, float baseB, float baseA, float varR, float varG, float varB, float varA);
	void setEndColorVariance(float baseR, float baseG, float baseB, float baseA, float varR, float varG, float varB, float varA);
	void setStartSpinVariance(float base, float variance);
	void setEndSpinVariance(float base, float variance);
	void setSpeedVariance(float base, float variance);
	void setParticleGravity(float gravityX, float gravityY);
	void setTangentialAccelerationVariance(float base, float variance);
	void setRadialAccelerationVariance(float base, float variance);
	void setStartRadiusVariance(float base, float variance);
	void setEndRadiusVariance(float base, float variance);
	void setRotationVariance(float base, float variance);

	// getter/setters
	wyPoint getParticleGravity() { return gravity; }
	void setDuration(float d) { duration = d; }
	float getDuration() { return duration; }
	wyPoint getCenterOfGravity() { return centerOfGravity; }
	bool isAutoRemoveOnFinish() { return autoRemoveOnFinish; }
	void setAutoRemoveOnFinish(bool flag) { autoRemoveOnFinish = flag; }
	float getEmissionRate() { return emissionRate; }
	void setEmissionRate(float rate) { emissionRate = rate; }
	float getLife() { return life; }
	wyParticleSystemMode getEmitterMode() { return emitterMode; }
	void setEmitterMode(wyParticleSystemMode mode) { emitterMode = mode; }
	wyParticleSystemPositionType getPositionType() { return positionType; }
	void setPositionType(wyParticleSystemPositionType type) { positionType = type; }
	int getParticleCount() { return particleCount; }
	int getMaxParticles() { return maxParticles; }
};

#endif // __wyParticleSystem_h__
