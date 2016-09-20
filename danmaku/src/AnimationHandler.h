#pragma once
#include "Includes.h"

class Animation {
private:
	unsigned int startFrame, endFrame;
	float duration;

public:
	unsigned int getLength();
	unsigned int getStartFrame();
	unsigned int getEndFrame();
	float		 getDuration();

	Animation(unsigned int, unsigned int, float);
	virtual ~Animation();
};


class AnimationHandler {
private:
	vector<Animation> animations;
	float time;
	unsigned int currentAnimation;

public:
	void addAnimation(Animation&);

	/* Update the current frame of animation. */
	/* dt is the time since last call.		  */
	void update(const float);

	/* Change the animation, resetting t in the process */
	void changeAnimation(unsigned int);

	/* Current section of the texture that should be displayed */
	IntRect bounds;

	/* Pixel dimensions of each individual frame */
	IntRect frameSize;

	/* Constructor */
	AnimationHandler();
	AnimationHandler(const IntRect&);
};