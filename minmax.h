#ifndef MINMAX_H_   /* Include guard */
#define MINMAX_H_
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>/* All SDL App’s need this */
#include <stdio.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
void playerMove(int board[9]);
void computerMove(int board[9]);
int minimax(int board[9], int player);
int win(const int board[9]);
void draw(int b[9],SDL_Surface* screen);
char gridChar(int i);
void XO();
#endif
