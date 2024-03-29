#include "CAnimation.h"

CAnimation::CAnimation(){
	this->currentFrame = 0;
	this->maxFrames = 0;
	this->frameInc = 1;
	
	this->frameRate = 100; //Miliseconds
	this-> oldTime = 0;
	
	oscillate = false;
}

void CAnimation::onAnimate(){
	if (oldTime + frameRate > SDL_GetTicks())
		return;
	
	oldTime = SDL_GetTicks();
	
	currentFrame += frameInc;
	
	if (oscillate){
		if (frameInc > 0){
			if (currentFrame >= maxFrames){
				frameInc = -frameInc;
			}
		} else {
			if (currentFrame <= 0){
				frameInc = -frameInc;
			}
		}
	} else {
		if (currentFrame >= maxFrames){
			currentFrame = 0;
		}
	}
}

void CAnimation::setFrameRate(int rate){
	frameRate = rate;
}

void CAnimation::setCurrentFrame(int frame){
	if (frame < 0 || frame >= maxFrames)
		return;
	
	currentFrame = frame;
}

int CAnimation::getCurrentFrame(){
	return currentFrame;
}