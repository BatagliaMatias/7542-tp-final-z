#include "CSurface.h"

CSurface::CSurface(){
}

SDL_Surface* CSurface::onLoad(char* file){
	SDL_Surface* surf_temp = NULL;
	SDL_Surface* surf_return = NULL;
	
	if ((surf_temp = SDL_LoadBMP(file)) == NULL)
		return NULL;
	
	surf_return = SDL_DisplayFormat(surf_temp);
	SDL_FreeSurface(surf_temp);
	
	return surf_return;
}

static bool get_rect(SDL_Rect &rect, SDL_Surface* surf, int x, int y, int w = -1, int h = -1){
	if (surf == NULL)
		return false;
	
	rect.x = x;
	rect.y = y;
	
	if (w > 0)
		rect.w = w;
	if (h > 0)
		rect.h = h;
	
	return true;
}

bool onDraw(SDL_Surface* surf_dest, SDL_Surface* surf_src, int x, int y){
	SDL_Rect destR;
	
	if (!get_rect(destR, surf_dest, x, y) || surf_src == NULL)
		return false;
	
	SDL_BlitSurface(surf_src, NULL, surf_dest, &destR);
	
	return true;
}

bool onDraw(SDL_Surface* surf_dest, SDL_Surface* surf_src, int x, int y, int x2, int y2, int w, int h){
	SDL_Rect destR, srcR;
	
	if (!get_rect(destR, surf_dest, x, y) || !get_rect(srcR, surf_src, x2, y2, w, h))
		return false;
	
	SDL_BlitSurface(surf_src, &srcR, surf_dest, &destR);
	
	return true;
}

bool transparent(SDL_Surface* surf_dest, int r, int g, int b){
	if (surf_dest == NULL)
		return false;
	
	SDL_SetColorKey(surf_dest, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(surf_dest->format, r, g, b));
	
	return true;
}