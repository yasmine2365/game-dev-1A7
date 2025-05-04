#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"header1.h"


void partage(background b,SDL_Surface *ecran)
{	
b.pos_background.x+=ecran->w/2;
	SDL_BlitSurface(b.afficher_background,&(b.pos_background2),ecran,&(b.pos_background));
}

void scrolling_partage(background *b,int d,int p)
{
if(d==1)b->pos_background2.x+=p;else b->pos_background2.y+=p;
if(b->pos_background2.x<0) b->pos_background2.x=0;if(b->pos_background2.x>360) b->pos_background2.x=360;
}

void scrolling_i(background *b,int d,int p)
{
if(d==1)b->pos_background2.x+=p;else b->pos_background2.y+=p;
if(b->pos_background2.x<0) b->pos_background2.x=0;
if(b->pos_background2.x>3115) b->pos_background2.x=40;
}
void initBack(background *b)
{

	Mix_Music  *music;
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    	{
        	printf("%s", Mix_GetError());
    	}
	music = Mix_LoadMUS("map1.mp3");	
	Mix_PlayMusic(music,-1) ;

    char ch[50];
    int i,j;
    char chh[50];


	    for(j=1; j<6; j++)
    {
        sprintf(ch,"dhaw/%d.png",j);
        b->porte[j]=IMG_Load(ch);
    }
    for(i=1; i<12; i++)
    {
        sprintf(chh,"owl2/%d.png",i);
        b->owl[i]=IMG_Load(chh);
    }

	b->calque_background=NULL;
	b->calque_background=IMG_Load("masque.png");
	b->afficher_background=NULL;
	b->afficher_background=IMG_Load("1st level.png");
	b->aff=NULL;
	b->aff=IMG_Load("1st level.png");
	b->pos_background.x=0;
	b->pos_background.y=0;
	b->pos_background2.x=0;
	b->pos_background2.y=0;
	b->pos_background2.h=1020;
	b->pos_background2.w=1920;
	b->port.x=  0 ;
        b->port.y=  -600 ;
        b->owll.x=  0 ;
        b->owll.y=  -400 ;
}


void afficherBack(background b,SDL_Surface *ecran)
{	
	SDL_BlitSurface(b.afficher_background,&(b.pos_background2),ecran,&(b.pos_background));
}


void animerBackground (background *b,SDL_Surface *ecran)
{   
    int j;
    char ch[50];
    int i;
    char chh[50];
     SDL_BlitSurface(b->aff,NULL,ecran,&(b->port));
    for(j=1; j<6; j++)
    {
        SDL_BlitSurface( b->porte[j], NULL,ecran,&(b->port));
        SDL_Delay(130);      
    }
SDL_Delay(1000);
SDL_BlitSurface(b->aff,NULL,ecran,&(b->port));
    for(j=1; j<12; j++)
    {
        SDL_BlitSurface( b->owl[j], NULL,ecran,&(b->owll));
        SDL_Delay(130);
    }
SDL_Delay(2000);
    for(j=1; j<12; j++)
    {
        SDL_BlitSurface( b->owl[j], NULL,ecran,&(b->owll));
        SDL_Delay(130);
    }


}

