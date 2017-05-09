#ifndef __CEVENT_H__
#define __CEVENT_H__

#include <SDL.h>

class CEvent {
public:
	CEvent();
	virtual ~CEvent();
	virtual void onEvent(SDL_Event* event);
	virtual void onInputFocus();
	virtual void onInputBlur();
	virtual void onKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);
	virtual void onKeyUp(SDLKEY sym, SDLMod mod, Uint16 unicode);
	virtual void onMouseFocus();
	virtual	void onMouseBlur();
	virtual void onMouseMove(int mx, int my, int relx, int rely, bool left, bool right, bool middle);
	virtual void onMouseWheel(bool up, bool down);
	virtual void onLButtonDown(int mx, int my);
	virtual void onLButtonUp(int mx, int my);
	virtual void onRButtonDown(int mx, int my);
	virtual void onRButtonUp(int mx, int my);
	virtual void onMButtonDown(int mx, int my);
	virtual void onMButtonUp(int mx, int my);
	virtual void onJoyAxis(Uint8 which, Uint8 axis, Sint16 value);
	virtual void onJoyButtonDown(Uint8 which, Uint8 button);
	virtual void onJoyButtonUp(Uint8 which, Uint8 button);
	virtual void onJoyHat(Uint8 which, Uint8 hat, Uint8 value);
	virtual void onJoyBall(Uint8 which, Uint8 ball, Sint16 xrel,  Sint16 yrel);
	virtual void onMinimize();
	virtual void onRestore();
	virtual void onResize();
	virtual void onExpose();
	virtual void onExit();
	virtual void onUser(Uint8 type, int code, void* data1, void* data2);
};

#endif