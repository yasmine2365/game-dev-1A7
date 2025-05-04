#include <stdio.h>
#include <SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include<SDL/SDL_ttf.h>
#include "header1.h"
#define LARGEUR_FENETRE 1200
#define HAUTEUR_FENETRE 600
struct Personne
{
   
       	SDL_Surface *image;
	SDL_Rect position;
	SDL_Rect frame;
	int curframe; 
	int direction;	 
	float vitesse;
        float x;
        float y ;   
	float grav ;
	float saut ;
int isjumping;

	 
	
} ;
typedef struct Personne Personne ;

void initPerso(Personne *p) ;
void initPerso2(Personne *p2) ;
void afficherPerso (Personne p,SDL_Surface *screen) ;
void deplacerperso(Personne *p,int dt)  ;
void animerPerso(Personne *p) ;
void sauter(Personne *p);
void saut(Personne *p);
