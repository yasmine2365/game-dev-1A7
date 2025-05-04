#include <SDL/SDL_image.h>
#include <SDL/SDL.h>/* All SDL App’s need this */
#include <stdio.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include "minmax.h"
#include "header.h"
int main() {
    SDL_Rect pos;
    /* Initialize defaults, Video and Audio */
if((SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_JOYSTICK|SDL_INIT_TIMER)==-1)) {
printf("Could not initialize SDL: %s.\n", SDL_GetError());
return -1;
}
printf("SDL initialized.\n");

//setting window
SDL_putenv("SDL_VIDEO_WINDOW_POS=center");
SDL_Surface* screen = SDL_SetVideoMode(640, 410, 8, SDL_SWSURFACE|SDL_ANYFORMAT);
if( screen == NULL ) {
fprintf(stderr, "Couldn’t set 640x480x8 video mode: %s\n",SDL_GetError());
return 1;
}
    SDL_Rect pos_board;
    SDL_Surface* image;
    pos.x=80;
    pos.y=50;
    display_img(screen,pos,"./XO.png",image);
    int board[9] = {0,0,0,0,0,0,0,0,0};
    //computer squares are 1, player squares are -1.
    printf("Computer: O, You: X\nPlay (1)st or (2)nd? ");
    int player=0;
    scanf("%d",&player);
    printf("\n");
    unsigned turn;
    for(turn = 0; turn < 9 && win(board) == 0; ++turn) {
        if((turn+player) % 2 == 0)
            computerMove(board);
        else {
            draw(board,screen);
            playerMove(board);
        }
    }
        TTF_Font* font;
    SDL_Color color={255,0,0};
    SDL_Rect pos_text;
    pos_text.y=320;
    pos_text.x=210;
    SDL_Surface* text;
    TTF_Init();
    font=TTF_OpenFont("Ubuntu-B.ttf",90);
    switch(win(board)) {
        case 0:
            printf("A draw. How droll.\n");
            text=TTF_RenderText_Blended(font,"Draw",color);SDL_BlitSurface(text, NULL, screen, &pos_text);
            SDL_Flip(screen);
            SDL_Delay(500);
            break;
        case 1:
            draw(board,screen);
            printf("You lose.\n");
            text=TTF_RenderText_Blended(font,"Lose",color);SDL_BlitSurface(text, NULL, screen, &pos_text);
            SDL_Flip(screen);
            SDL_Delay(5000);
            break;
        case -1:
            printf("You win. Inconceivable!\n");
            text=TTF_RenderText_Blended(font,"Win",color);SDL_BlitSurface(text, NULL, screen, &pos_text);
            SDL_Flip(screen);
            SDL_Delay(5000);
            break;
    }
}