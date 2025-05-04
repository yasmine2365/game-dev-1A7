#include <SDL/SDL_image.h>
#include <SDL/SDL.h>/* All SDL App’s need this */
#include <stdio.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "minimap.h"
#include "header.h"
#include <SDL/SDL_rotozoom.h>
#include "time.h"
#include <string.h>
/**
* @file minimap.c
* @brief this is where all minimap functions are 
*/
/**
* @brief To calculate player position on the minimap
* @param minimap for the struct
* @param camera for adjusting position of player on minimap
* @return Nothing
*/
void MAJMinimap(SDL_Rect posJoueur,minimap* m,SDL_Rect camera,int redimensionnement)
{
    SDL_Rect posJoueurABS;
posJoueurABS.x = posJoueur.x + camera.x;
posJoueurABS.y = posJoueur.y + camera.y;
m->pos_p.x=posJoueurABS.x*redimensionnement/100;
m->pos_p.y=posJoueurABS.y*redimensionnement/100;
}

void afficher (SDL_Rect player,minimap m, SDL_Surface * screen){
SDL_Rect camera;int done=0;
SDL_Event test_event;
camera.x=1150;
camera.y=310;
MAJMinimap(player,&m,camera,15);
SDL_BlitSurface(m.player, NULL, screen, &m.pos_p);
}
    
/**
* @brief initialisation minimap
* @param minimap for the struct
* @return Nothing
*/
void init_minimap(minimap* m){
SDL_Surface* tmp = IMG_Load("./images/1st level.png");
m->image =rotozoomSurface(tmp,0,0.15,0);   //rotozoom
m->pos.x=170;
m->pos.y=40;
if (m->image == NULL) {
printf("Couldnt load : %s\n", SDL_GetError());
}
m->player = IMG_Load("./images/red.png");
if (m->player == NULL) {
printf("Couldnt load : %s\n", SDL_GetError());
return;
}
}

/**
* @brief to show the scoreboard
* @param screen to show it on
* @return Nothing
*/
void afficher_scoreboard (SDL_Surface* screen){ //shows scoreboard at the options menu
SDL_Rect pos;
SDL_Surface* image;
pos.x=0;
pos.y=0;
display_img(screen,pos,"./images/background.png",image);
    FILE* ptr;
    char* ch;
 
    // Opening file in reading mode
    ptr = fopen("./score/score.txt", "r");
 
    if (NULL == ptr) {
        printf("file can't be opened \n");
    }
 
    // Printing what is written in file
    // character by character using loop.
    TTF_Font* font;
        SDL_Surface* text;
        SDL_Rect textpos;
        char *filename = "./score/score.txt";
        FILE *fp = fopen(filename, "r");

        if (fp == NULL)
        {
            printf("Error: could not open file %s", filename);
            return ;
        }

        // reading line by line, max 256 bytes
        const unsigned MAX_LENGTH = 256;
        char buffer[MAX_LENGTH];

        while (fgets(buffer, MAX_LENGTH, fp))
            buffer[strcspn(buffer, "\n")] = 0;
            char * token = strtok(buffer, " ");
            for(int i=0;i<256;i++)buffer[i]=toupper(buffer[i]);
        // loop through the string to extract all other tokens
        textpos.x=20;
        textpos.y=200;
        while( token != NULL ) {
            printf( " %s\n", token ); //printing each token
            SDL_Colour colorblack={153,153,0};
            write_texte(30,token,font,colorblack,text,textpos, screen);
            textpos.x+=500;
            token = strtok(NULL, " ");
   }

        // close the file
        fclose(fp);
    return ;
}


void save_score(char nom_joueur[],int score){ //save score in text file a la fin de chaque partie
FILE* f=fopen("./score/score.txt","w");
if (f == NULL) 
            {   
              printf("Error! Could not open file\n"); 
              exit(-1); // must include stdlib.h 
            } 
fprintf(f, "%s                                 %d\n",nom_joueur,score); // write to file
fclose(f);
}


int enter_player_name(SDL_Surface* screen,char* player_name,SDL_Event test_event,Time* t){ //takes the player name at the start of each game
SDL_Rect pos;
pos.x=0;
pos.y=0;
SDL_Colour colorblack={153,153,0};
TTF_Font* font;
SDL_Surface* text;
SDL_Rect textpos;
textpos.x=240;
textpos.y=210;
int done=0;
int last=0;
int i=0;
SDL_Surface* image;
char string[20]="";
display_img(screen,pos,"./images/keyboard.png",image);
    while(!( done==1)){
    while(SDL_PollEvent(&test_event)) {
        switch(test_event.type){
            case SDL_MOUSEBUTTONDOWN:
            if(test_event.motion.y<=34 && test_event.motion.y>=10 &&(test_event.motion.x<=80 && test_event.motion.x>=9)){return 0;}
            break;
            case SDL_KEYDOWN:
            if(strcmp(PrintKeyInfo(&test_event.key),"return")==0||strcmp(PrintKeyInfo(&test_event.key),"enter")==0){done=1;return 1; break;}
            if((strlen(PrintKeyInfo(&test_event.key))<2 && i<8)||(strcmp(PrintKeyInfo(&test_event.key),"space")==0)){
            if(strcmp(PrintKeyInfo(&test_event.key),"space")==0){
                    strcpy(string," ");
                    strcat(player_name," ");
                }else{
            strcpy(string,PrintKeyInfo(&test_event.key));
            strcat(player_name,PrintKeyInfo(&test_event.key));
                }
            for(int i=0;i<20;i++)string[i]=toupper(string[i]);
            write_texte(30,string,font,colorblack,text,textpos, screen);
            textpos.x=textpos.x+21;
            i++;
            }
            break;
            case SDL_QUIT:
                SDL_Quit();
                //shutdown all sub systems
                exit(0);
                printf("Quiting....\n");
            break;
        }
    }
}
}


void Timer(int *tempsdebut)
{
    
   if( SDL_GetTicks() - *tempsdebut >= 1000 )
    {
        *tempsdebut = SDL_GetTicks() ;
      
      
    }
  
}

void inittemps(Time *t)
{   int test; 
	t->tempsdebut=SDL_GetTicks();
	t->mm=0;
	t->ss=0;
}

void update_time(Time* T,SDL_Surface* screen)
{   
    int ts;
    TTF_Font* font;
    SDL_Rect pos;
    pos.x=550;
    pos.y=5;
    SDL_Surface* text;
    SDL_Color color={0,0,0};
    Timer(&T->tempsdebut);
    ts=T->tempsdebut/1000;
    T->mm=ts/60;
    T->ss=ts % 60;
    if(T->mm<10&&T->ss<10)
       sprintf(T->temps,"0%d:0%d",T->mm,T->ss);
    else if(T->mm<10&&T->ss>10)
        sprintf(T->temps,"0%d:%d",T->mm,T->ss);
    else if(T->mm>10&&T->ss<10)
        sprintf(T->temps,"%d:0%d",T->mm,T->ss);
        write_texte(20,T->temps,font,color,text,pos,screen);
    //ttfrender tekho l police o txt o couleur taa l text eli besh taficchiih
}
void affichier_diag(Boite b,SDL_Surface* screen){
    SDL_Rect pos;
    TTF_Font* font;
    SDL_Color color={0,0,0};
    SDL_Surface* text;
    SDL_Rect textpos;
    pos.x=20;
    pos.y=50;
    textpos.x=pos.x+30;
    textpos.y=pos.y+20;
    SDL_BlitSurface(b.diag,NULL,screen,&pos);
    write_texte(20,b.text,font,color,text,textpos,screen);
}
