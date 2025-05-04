#include "header.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>/* All SDL App’s need this */
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "minimap.h"
#include "time.h"
#include <stdio.h>

void display_bmp(SDL_Surface* screen,SDL_Rect pos,const char * path)
{
pos.x=0;
pos.y=0;
pos.h=0;
pos.w=0;
SDL_Surface *image;
//Load the BMP file into a surface 
image = SDL_LoadBMP(path);
if (image == NULL) {
printf("Couldnt load : %s\n", SDL_GetError());
return;
}
//Blit onto the screen surface 
if(SDL_BlitSurface(image, NULL, screen, &pos)){
printf("BlitSurface error: %s\n", SDL_GetError());
}
SDL_Flip(screen);
}
void display_img(SDL_Surface* screen,SDL_Rect pos,const char * path,SDL_Surface* image){
{
//Load the BMP file into a surface 
image = IMG_Load(path);
if (image == NULL) {
printf("Couldnt load : %s\n", SDL_GetError());
return;
}
//Blit onto the screen surface 
if(SDL_BlitSurface(image, NULL, screen, &pos)){
printf("BlitSurface error: %s\n", SDL_GetError());
}
SDL_Flip(screen);
SDL_Flip(image);
}
}
void initialize_audio(Mix_Music * music){
    if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1){
    printf("%s",SDL_GetError());
    
}
music=Mix_LoadMUS("Myrath - Wide Shut (mp3cut.net).mp3");
Mix_PlayMusic(music,-1);
Mix_VolumeMusic(MIX_MAX_VOLUME/3.5);
}
char* PrintKeyInfo( SDL_KeyboardEvent *key ){
        /* Print the name of the key */
        return SDL_GetKeyName( key->keysym.sym );
    }
void hover(int possition,SDL_Rect posmenu,SDL_Surface* screen){
    posmenu.x=posmenu.x+30;
    posmenu.y=posmenu.y-2;
    SDL_Surface* image;
    switch(possition){
    case 1:
        display_img(screen,posmenu,"./images/1.png",image);
    break;
    case 2:
        display_img(screen,posmenu,"./images/2.png",image);
    break;
    case 3:
        display_img(screen,posmenu,"./images/3.png",image);
    break;
    case 4:
        display_img(screen,posmenu,"./images/4.png",image);

    break;
    case 0:
    display_img(screen,posmenu,"./images/0.png",image);
    break;
}
//Game-Button-Sounds-Pack-Free-Sounds-_AudioTrimmer.com_.wav
}
void write_texte(int fontsize,const char message[], TTF_Font* font,SDL_Color colorblack,SDL_Surface* text,SDL_Rect textpos,SDL_Surface* screen){
TTF_Init();
font=TTF_OpenFont("Ubuntu-B.ttf",fontsize);
text =TTF_RenderText_Blended(font,message,colorblack);
SDL_BlitSurface(text, NULL, screen, &textpos); 
SDL_Flip(screen);
TTF_CloseFont(font);
TTF_Quit();
}


int menu_loop(SDL_Event test_event,SDL_Rect posmenu,SDL_Surface* screen){
Mix_Chunk * son;
int position =0;
SDL_Rect pos;
SDL_Colour colorblack={153,153,0};
TTF_Font* font;
SDL_Surface* text;
SDL_Rect textpos;
textpos.x=250;
textpos.y=390;
textpos.w=0;
textpos.h=0;

hover(0,posmenu,screen);

int i=1;
while(1){
i++;
if(i>=11){
    i=1;
}
live_background(screen,pos,i);
write_texte(12,"all rights reserved",font,colorblack,text,textpos, screen);
while(SDL_PollEvent(&test_event)) {
//handeling hovering on buttons using mouse
switch(test_event.type) {
    case SDL_MOUSEMOTION:
            if(test_event.motion.y<=120 && test_event.motion.y>=80 &&(test_event.motion.x<=423 && test_event.motion.x>=213)){
                if(position!=1){ position=1;
                hover(position,posmenu,screen);
                play_effect(son);}
            }
            else if(test_event.motion.y<=181 && test_event.motion.y>=136 && test_event.motion.x<=423 && test_event.motion.x>=213){
                if(position!=2){ position=2;
                hover(position,posmenu,screen);
                
                play_effect(son);
                }
            }
            else if(test_event.motion.y<=240 && test_event.motion.y>=195 &&(test_event.motion.x<=423 && test_event.motion.x>=213)){
                if(position!=3){ position=3;
                hover(position,posmenu,screen);
                
                play_effect(son);}
            }
            else if(test_event.motion.y<=300 && test_event.motion.y>=255 &&(test_event.motion.x<=423 && test_event.motion.x>=213)){
                if(position!=4){ position=4;
                hover(position,posmenu,screen);
                
                play_effect(son);}
            }
            else {
                if(position!=0){ position=0;
                hover(position,posmenu,screen);
                }
            }
        break;

    //handeling clicking on buttons using mouse



    case SDL_MOUSEBUTTONDOWN:
    if(test_event.button.button==SDL_BUTTON_LEFT && (test_event.motion.y<=120 && test_event.motion.y>=80 && test_event.motion.x<=423 && test_event.motion.x>=213)){
        puts("click play");
        return 1;
    }
    else if(test_event.button.button==SDL_BUTTON_LEFT && (test_event.motion.y<=181 && test_event.motion.y>=136 && test_event.motion.x<=423 && test_event.motion.x>=213)){
        puts("clicked options");
        //never quit loop till pressed return
        //display_img(screen,posoptions,"optionsmenu.png");
        return 2;
    }
    else if(test_event.button.button==SDL_BUTTON_LEFT && (test_event.motion.y<=240 && test_event.motion.y>=195 && test_event.motion.x<=423 && test_event.motion.x>=213)){
        puts("click credits");
        return 3;
    }
    else if(test_event.button.button==SDL_BUTTON_LEFT && (test_event.motion.y<=300 && test_event.motion.y>=255 && test_event.motion.x<=423 && test_event.motion.x>=213)){
        puts("click quits");
        SDL_Quit();
        //shutdown all sub systems
        return -1;
        printf("Quiting....\n");
    }
    else puts("unrecognized click");
        break;



    case SDL_KEYDOWN:
    //SDL_WM_ToggleFullScreen(screen);
        PrintKeyInfo(&test_event.key); //printing pressed or released button name
            //handeling switch menu element using up and down buttons
            if(strcmp(SDL_GetKeyName(test_event.key.keysym.sym),"down")==0){
                if(position<4)position++;
                hover(position,posmenu,screen);
                
                play_effect(son);
            }
            if(strcmp(SDL_GetKeyName(test_event.key.keysym.sym),"up")==0){
                if(position>1)position--;
                hover(position,posmenu,screen);
                
                play_effect(son);
            }

            //handeling entering a menu element using enter button
            if(strcmp(SDL_GetKeyName(test_event.key.keysym.sym),"return")==0 || strcmp(SDL_GetKeyName(test_event.key.keysym.sym),"enter")==0){
            switch(position){
                case 1:
                puts("pressed enter on play");
                return 1;
                break;
                case 2:
                puts("pressed enter on options");
                return 2;
                break;
                case 3:
                puts("pressed enter on credits");
                return 3;
                break;
                case 4:
                puts("pressed enter on quit");
                return -1;
                SDL_Quit();
                //shutdown all sub systems
                printf("Quiting....\n");
                break;
            }
            }
    break;

    /* SDL_QUIT event (window close) */
    case SDL_QUIT:
        SDL_Quit();
        return -1;
        //shutdown all sub systems
        printf("Quiting....\n");
        break;
}
}
}
}
void play_effect(Mix_Chunk* son){
Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
son = Mix_LoadWAV("simple.wav");
if(son==NULL) printf("%s",SDL_GetError());
Mix_VolumeChunk(son,MIX_MAX_VOLUME/2.5);
Mix_PlayChannel(-1,son,0);
}


void live_background(SDL_Surface* screen,SDL_Rect pos,int i){
SDL_Surface* image;
char filename[50];
pos.x=0;
pos.y=0;
SDL_Delay(50);
    sprintf(filename,"./images/%d",i);
    strcat(filename,".jpg.png");
    display_img(screen,pos,filename,image);
}