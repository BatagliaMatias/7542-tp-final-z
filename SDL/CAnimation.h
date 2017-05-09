#ifndef __CANIMATION_H__
#define __CANIMATION_H__

#include <SDL.h>

class CAnimation {
private:
	int currentFrame;
	int frameInc;
	int frameRate;
	int oldTime;
	
public:
	int maxFrames;
	bool oscillate;
	
	CAnimation();
	void onAnimate();
	void setFrameRate(int rate);
	void setCurrentFrame(int frame);
	int getCurrentFrame();
};

#endif