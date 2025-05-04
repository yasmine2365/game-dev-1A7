#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"header2.h"
SDL_Color GetPixel(SDL_Surface *surface,int x,int y)
{
	SDL_Color color ;
	Uint32 col = 0 ;
	char* pPosition = ( char* ) surface->pixels ;
	pPosition += ( surface->pitch * y ) ;
	pPosition += ( surface->format->BytesPerPixel * x ) ;
	memcpy ( &col , pPosition , surface->format->BytesPerPixel ) ;
	SDL_GetRGB ( col , surface->format , &color.r , &color.g , &color.b ) ;
	return ( color ) ;
}
int collisionPP(SDL_Surface *calque,SDL_Surface *perso,SDL_Rect posperso,SDL_Rect posmap)
{
  SDL_Color col2,col22;
	col2=GetPixel(calque,posperso.x+20,posperso.y+90);
	col2=GetPixel(calque,posperso.x,posperso.y+90);
	if ((col2.r==0)&&(col2.b==0)&&(col2.g==0))
 	 return 2;	
if ((col22.r==0)&&(col22.b==0)&&(col22.g==0))
  	 return 2;
if(posperso.x>420) return 2;	
	 
return 0;
}

