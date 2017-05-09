#include "CApp.h"

CApp::CApp{
	surf_display = NULL;
	surf_player = NULL;
	running = true;
}

int CApp::onExecute(){
	if (this.onInit() == false)
		return -1;
	
	SDL_Event event;
	
	while (running){
		while (SDL_PollEvent(&event)) {
			onEvent(&event);
		}
		onLoop();
		onRender();
	}
	
	onCleanup();
	
	return 0;
}

bool CApp::onInit(){
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		return false;
	
	if ((surf_display = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUFF)) == NULL)
		return false;
	
	return true;
}

void CApp::onEvent(SDL_Event* event){
	CEvent::onEvent(event);
}

void CApp::onExit(){
	running = false;
}

void CApp::onLoop(){
}

void CApp::onRender(){
	SDL_Flip(surf_display);
}

void CApp::onCleanup(){
	SDL_FreeSurface(surf_dislay);
	SDL_Quit();
}