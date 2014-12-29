#include "AnimationHandler.h"

/*	Animation	*/
unsigned int Animation::getLength() {
	return endFrame - startFrame +1;
}

unsigned int Animation::getStartFrame() {
	return startFrame;
}

unsigned int Animation::getEndFrame() {
	return endFrame;
}

float Animation::getDuration() {
	return duration;
}


Animation::Animation(unsigned int start, unsigned int end, float d) {
	startFrame = start;
	endFrame = end;
	duration = d;
}

Animation::~Animation() {}
/*				*/

/*	Animation handler	*/
void AnimationHandler::update(const float dt)
{
	if (currentAnimation >= animations.size() || currentAnimation < 0) return;

	float duration = animations[currentAnimation].getDuration();

	/* Check if the animation has progessed to a new frame and if so
	* change to the next frame */
	if (int((time + dt) / duration) > int(time / duration))	{
		/* Calculate the frame number */
		int frame = int((time + dt) / duration);

		/* Adjust for looping */
		frame %= animations[currentAnimation].getLength();

		/* Set the sprite to the new frame */
		IntRect rect = frameSize;
		rect.left = rect.width * frame;
		rect.top = rect.height * currentAnimation;
		bounds = rect;
	}

	/* Increment the time elapsed */
	this->time += dt;
	/* Adjust for looping */
	if (time > duration * animations[currentAnimation].getLength())
		time = 0.0f;

	return;
}

void AnimationHandler::addAnimation(Animation& animation) {
	animations.push_back(animation);
}

void AnimationHandler::changeAnimation(unsigned int animationID) {
	/* Do not change the animation if the animation is currently active or
	* the new animation does not exist */
	if (currentAnimation == animationID || animationID >= animations.size() || animationID < 0) 
		return;

	/* Set the current animation */
	currentAnimation = animationID;
	/* Update the animation bounds */
	IntRect rect = frameSize;
	rect.top = rect.height * animationID;
	bounds = rect;
	time = 0.0f;
}

AnimationHandler::AnimationHandler() {
	time = 0.0f;
	currentAnimation = -1;
}
AnimationHandler::AnimationHandler(const IntRect& size) {
	frameSize = size;

	time = 0.0f;
	currentAnimation = -1;
}
/*						*/