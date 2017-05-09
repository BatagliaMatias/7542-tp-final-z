#ifndef __CSURFACE_H__
#define __CSURFACE_H__

#include <SDL.h>

class CSurface {
private:
	static bool get_rect(SDL_Rect &rect, SDL_Surface* surf, int x, int y, int w = -1, int h = -1);
public:
	CSurface();
	static SDL_Surface* onLoad(char* file);
	static bool onDraw(SDL_Surface* surf_dest, SDL_Surface* surf_src, int x, int y);
	static bool onDraw(SDL_Surface* surf_dest, SDL_Surface* surf_src, int x, int y, int x2, int y2, int w, int h);
	static bool transparent(SDL_Surface* surf_dest, int r, int g, int b);
};

#endif