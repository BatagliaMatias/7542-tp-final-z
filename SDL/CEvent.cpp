#include "CEvent.h"

CEvent::CEvent(){
}

CEvent::~CEvent(){
}

void CEvent::onEvent(SDL_Event* event){
	switch (event->type) {
		case SDL_ACTIVEEVENT: {
			switch (event->active.state) {
				case SDL_APPMOUSEFOCUS: {
					if (event->active.gain)
						this->onMouseFocus();
					else
						this->onMouseBlur();
					break;
				}
				case SDL_APPINPUTFOCUS: {
					if (event->active.gain)
						this->onInputFocus();
					else
						this->onInputBlur();
					break;
				}
				case SDL_APPACTIVE: {
					if (event->active.gain)
						this->onRestore();
					else
						this->onMinimize();
					break;
				}
			}
			break;
		}
		
		case SDL_KEYDOWN: {
			this->onKeyDown(event->key.keysym.sym, event->key.keysym.mod, event->key.keysym.unicode);
			break;
		}
		
		case SDL_KEYUP: {
			this->onKeyUp(event->key.keysym.sym, event->key.keysym.mod, event->key.keysym.unicode);
			break;
		}
		
		case SDL_MOUSEMOTION: {
			this->onMouseMove(event->motion.x, event->motion.y, event->motion.xrel, event->motion.yrel,
				(event->motion.state & SDL_BUTTON(SDL_BUTTON_LEFT)) != 0,
				(event->motion.state & SDL_BUTTON(SDL_BUTTON_RIGHT)) != 0
				(event->motion.state & SDL_BUTTON(SDL_BUTTON_MIDDLE)) != 0);
			break;
		}
		
		case SDL_MOUSEBUTTONDOWN: {
			switch (event->button.button) {
				case SDL_BUTTON_LEFT: {
					this->onLButtonDown(event->button.x, event->button.y);
					break;
				}
				case SDL_BUTTON_RIGHT: {
					this->onRButtonDown(event->button.x, event->button.y);
					break;
				}
				case SDL_BUTTON_MIDDLE: {
					this->onMButtonDown(event->button.x, event->button.y);
					break;
				}
			}
		}
		
		case SDL_MOUSEBUTTONUP: {
			switch (event->button.button) {
				case SDL_BUTTON_LEFT: {
					this->onLButtonUp(event->button.x, event->button.y);
					break;
				}
				case SDL_BUTTON_RIGHT: {
					this->onRButtonUp(event->button.x, event->button.y);
					break;
				}
				case SDL_BUTTON_MIDDLE: {
					this->onMButtonUp(event->button.x, event->button.y);
					break;
				}
			}
		}
		
		case SDL_JOYAXISMOTION: {
			this->onJoyAxisMotion(event->jaxis.which, event->jaxis.axis, event->jaxis.value);
			break;
		}
		
		case SDL_JOYBALLMOTION: {
			this->onJoyBall(event->jball.which, event->jball.ball, event->jball.xrel, event->jball.yrel);
			break;
		}
		
		case SDL_JOYHATMOTION: {
			this->onJoyHat(event->jhat.which, event->jhat.hat, event->jhat.value);
			break;
		}
		
		case SDL_JOYBUTTONDOWN: {
			this->onJoyButtonDown(event->jbutton.which, event->jbutton.button);
			break
		}
		
		case SDL_JOYBUTTONUP: {
			this->onJoyButtonUp(event->jbutton.which, event->jbutton.button);
			break
		}
		
		case SDL_QUIT: {
			this->onExit();
			break;
		}
		
		case SDL_SYSWEVENT: {
			break;
		}
		
		case SDL_VIDEORESIZE: {
			this->onResize(event->resize.w, event->resize.h);
			break;
		}
		
		case SDL_VIDEOEXPOSE: {
			this->onExpose();
			break;
		}
		
		default: {
			this->onUser(event->user.type, event->user.code, event->user.data1, event->user.data2);
			break;
		}
	}
}

virtual void onInputFocus(){}
virtual void onInputBlur(){}
virtual void onKeyDown(){}
virtual void onKeyUp(){}
virtual void onMouseFocus(){}
virtual	void onMouseBlur(){}
virtual void onMouseMove(int mx, int my, int relx, int rely, bool left, bool right, bool middle){}
virtual void onMouseWheel(bool up, bool down){}
virtual void onLButtonDown(int mx, int my){}
virtual void onLButtonUp(int mx, int my){}
virtual void onRButtonDown(int mx, int my){}
virtual void onRButtonUp(int mx, int my){}
virtual void onMButtonDown(int mx, int my){}
virtual void onMButtonUp(int mx, int my){}
virtual void onJoyAxis(Uint8 which, Uint8 axis, Sint16 value){}
virtual void onJoyButtonDown(Uint8 which, Uint8 button){}
virtual void onJoyButtonUp(Uint8 which, Uint8 button){}
virtual void onJoyHat(Uint8 which, Uint8 hat, Uint8 value){}
virtual void onJoyBall(Uint8 which, Uint8 ball, Sint16 xrel,  Sint16 yrel){}
virtual void onMinimize(){}
virtual void onRestore(){}
virtual void onResize(){}
virtual void onExpose(){}
virtual void onExit(){}
virtual void onUser(Uint8 type, int code, void* data1, void* data2){}