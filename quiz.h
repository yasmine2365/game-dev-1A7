#include<string.h>
#include<SDL/SDL.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_image.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define LARGEUR 1280
#define HAUTEUR 720
#define BPP 32

typedef struct Question {
	char question[255];
	char reponse1[255];
	char reponse2[255];
	char reponse3[255];
} Question;

typedef struct Quiz {
	FILE *f;
	Question questions[5];
} Quiz;

void quiz_final(SDL_Surface *screen);
