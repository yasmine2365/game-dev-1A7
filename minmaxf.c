#include <SDL/SDL_image.h>
#include <SDL/SDL.h>/* All SDL App’s need this */
#include <stdio.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include "header.h"
#include "minmax.h"

#include <stdio.h>

char gridChar(int i) {
    switch(i) {
        case -1:
            return 'X';
        case 0:
            return ' ';
        case 1:
            return 'O';
    }
}

void draw(int b[9],SDL_Surface* screen) {
    TTF_Font* font;
    SDL_Color color={255,0,0};
    SDL_Rect pos_text;
    SDL_Surface* text;
    TTF_Init();
    printf(" %c | %c | %c\n",gridChar(b[0]),gridChar(b[1]),gridChar(b[2]));
    printf("---+---+---\n");
    printf(" %c | %c | %c\n",gridChar(b[3]),gridChar(b[4]),gridChar(b[5]));
    printf("---+---+---\n");
    printf(" %c | %c | %c\n",gridChar(b[6]),gridChar(b[7]),gridChar(b[8]));
    for(int i=0;i<9;i++){
    switch(i){
        case 0:
        pos_text.x=110;
        pos_text.y=35;
        break;
        case 1:
        pos_text.x=280;
        pos_text.y=35;
        break;
        case 2:
        pos_text.x=450;
        pos_text.y=35;
        break;
        case 3:
        pos_text.x=110;
        pos_text.y=120;
        break;
        case 4:
        pos_text.x=280;
        pos_text.y=120;
        break;
        case 5:
        pos_text.x=450;
        pos_text.y=120;
        break;
        case 6:
        pos_text.x=110;
        pos_text.y=210;
        break;
        case 7:
        pos_text.x=280;
        pos_text.y=210;
        break;
        case 8:
        pos_text.x=450;
        pos_text.y=210;
        break;
    }
font=TTF_OpenFont("Ubuntu-B.ttf",90);
if(gridChar(b[i])=='X'){text=TTF_RenderText_Blended(font,"X",color);SDL_BlitSurface(text, NULL, screen, &pos_text);}
if(gridChar(b[i])=='O'){text=TTF_RenderText_Blended(font,"O",color);SDL_BlitSurface(text, NULL, screen, &pos_text);} 
SDL_Flip(screen);
    }
TTF_CloseFont(font);
TTF_Quit();
}

int win(const int board[9]) {
    //determines if a player has won, returns 0 otherwise.
    unsigned wins[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    int i;
    for(i = 0; i < 8; ++i) {
        if(board[wins[i][0]] != 0 &&
           board[wins[i][0]] == board[wins[i][1]] &&
           board[wins[i][0]] == board[wins[i][2]])
            return board[wins[i][2]];
    }
    return 0;
}

int minimax(int board[9], int player) {
    //How is the position like for player (their turn) on board?
    int winner = win(board);
    if(winner != 0) return winner*player;

    int move = -1;
    int score = -2;//Losing moves are preferred to no move
    int i;
    for(i = 0; i < 9; ++i) {//For all moves,
        if(board[i] == 0) {//If legal,
            board[i] = player;//Try the move
            int thisScore = -minimax(board, player*-1);
            if(thisScore > score) {
                score = thisScore;
                move = i;
            }//Pick the one that's worst for the opponent
            board[i] = 0;//Reset board after try
        }
    }
    if(move == -1) return 0;
    return score;
}

void computerMove(int board[9]) {
    int move = -1;
    int score = -2;
    int i;
    for(i = 0; i < 9; ++i) {
        if(board[i] == 0) {
            board[i] = 1;
            int tempScore = -minimax(board, -1);
            board[i] = 0;
            if(tempScore > score) {
                score = tempScore;
                move = i;
            }
        }
    }
    //returns a score based on minimax tree at a given node.
    board[move] = 1;
}

void playerMove(int board[9]) {
int move = 0;
do {
start:
printf("\nInput move ([0..8]): ");
scanf("%d", &move);
if(board[move] != 0) {
printf("Its Already Occupied !");
goto start;
}
printf("\n");
} while (move >= 9 || move < 0 && board[move] == 0);
board[move] = -1;
}
void XO(){
        SDL_Rect pos;
    /* Initialize defaults, Video and Audio */
if((SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_JOYSTICK|SDL_INIT_TIMER)==-1)) {
printf("Could not initialize SDL: %s.\n", SDL_GetError());
return ;
}
printf("SDL initialized.\n");

//setting window
SDL_putenv("SDL_VIDEO_WINDOW_POS=center");
SDL_Surface* screen = SDL_SetVideoMode(640, 410, 8, SDL_SWSURFACE|SDL_ANYFORMAT);
if( screen == NULL ) {
fprintf(stderr, "Couldn’t set 640x480x8 video mode: %s\n",SDL_GetError());
return ;
}
    SDL_Rect pos_board;
    SDL_Surface* image;
    pos.x=80;
    pos.y=50;
    display_img(screen,pos,"./images/XO.png",image);
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
            SDL_Delay(3000);
            break;
        case 1:
            draw(board,screen);
            printf("You lose.\n");
            text=TTF_RenderText_Blended(font,"Lose",color);SDL_BlitSurface(text, NULL, screen, &pos_text);
            SDL_Flip(screen);
            SDL_Delay(3000);
            break;
        case -1:
            printf("You win. Inconceivable!\n");
            text=TTF_RenderText_Blended(font,"Win",color);SDL_BlitSurface(text, NULL, screen, &pos_text);
            SDL_Flip(screen);
            SDL_Delay(3000);
            break;
    }
}
