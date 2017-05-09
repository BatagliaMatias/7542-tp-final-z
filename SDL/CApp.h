#ifndef __CAPP_H__
#define __CAPP_H__

#include <SDL.h>

#include "CSurface.h"
#include "CEvent.h"

class CApp : CEvent {
protected:
	bool running;
	SDL_Surface* surf_display;

public:
	CApp();
	int onExecute();
	
	virtual bool onInit();
	virtual void onEvent(SDL_Event* event);
	virtual void onExit();
	virtual void onLoop();
	virtual void onRender();
	virtual void onCleanup();
};

#endif