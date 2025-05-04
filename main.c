#include <SDL/SDL_image.h>
#include <SDL/SDL.h>/* All SDL App’s need this */
#include <stdio.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "header.h"
#include "header2.h"
#include "minimap.h"
#include <SDL/SDL_rotozoom.h>
#include "time.h"
#include <string.h>
#include"perso.h"
#include "minmax.h"
#include "header1.h"
#include "enemie.h"
#include "quiz.h"
/**
* @file main.c
* @brief Testing Program.
* @author C Team
* @version 1
* @date Apr 01, 2022
*
* Testing program for Minimap
*
*/

int main() {
SDL_Surface* screen;
SDL_Rect pos;

	TTF_Init();
//initializing image position
SDL_Rect posmenu;
SDL_Rect posmenu1;
SDL_Rect posmenu2;
SDL_Rect posoptions;
SDL_Rect posmenu3;

//initializing time
Time temps,enigme;
inittemps(&temps);

//initializing minimap
minimap m;
int count;
init_minimap(&m);



posoptions.x=167;posoptions.y=66;posmenu.x=200;posmenu.y=70;posmenu.h=0;posmenu.w=0;posmenu1.x=200;posmenu1.y=130;posmenu1.h=0;posmenu1.w=0;posmenu2.x=200;posmenu2.y=190;posmenu2.h=0;posmenu2.w=0;posmenu3.x=200;posmenu3.y=250;posmenu3.h=0;posmenu3.w=0;

printf("Initializing SDL.\n");
/* Initialize defaults, Video and Audio */
if((SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_JOYSTICK|SDL_INIT_TIMER)==-1)) {
printf("Could not initialize SDL: %s.\n", SDL_GetError());
return -1;
}
printf("SDL initialized.\n");

//setting window
SDL_putenv("SDL_VIDEO_WINDOW_POS=center");
screen = SDL_SetVideoMode(640, 410, 8, SDL_SWSURFACE|SDL_ANYFORMAT);
if( screen == NULL ) {
fprintf(stderr, "Couldn’t set 640x480x8 video mode: %s\n",SDL_GetError());
return 1;
}


//playing music

Mix_Music * music;
initialize_audio(music);
int received =-1;
arduinoWriteData(0);


int position =0; //hover position mouse
hover(position,posmenu,screen);
SDL_Event test_event;
SDLKey key;
char string[20]="";

printf("menu inintialized!\n");
printf("listening on events ...\n");
int i=0;
int col=0,col2=0;
float level=2;
char player_name[20];
char player[20]="";
    TTF_Font* font;
    SDL_Surface* text;
    int done1=0;
    SDL_Color color={0,0,0};
    int last=0;
while(1){
    int done=0;
switch(menu_loop(test_event,posmenu,screen)){
    case 1:
    //init temps
    //load play
    pos.x=0;
    pos.w=640;
    pos.h=480;
    pos.y=-10;
    SDL_Rect pos1;
    int last1;
    pos1.x=0;
    pos1.y=0;
    SDL_Surface* image;
    int colorkey;
  Ennemi E ;
  initEnnemi(&E);
Personne p ,p2;
int j;
    initPerso(&p) ;
    initPerso(&p2) ;
    pos.x=0;
    pos.y=0;
    int done=1;
    SDL_Event test_event1; //y 133 151 //y 240 260
    display_img(screen,pos,"./images/multiplayersingleplayer.png",image);
    while(done==1){
        SDL_PollEvent(&test_event1);
        switch(test_event1.type){
            case SDL_MOUSEBUTTONDOWN:
                if(test_event1.button.button==SDL_BUTTON_LEFT && (test_event1.motion.y<=151 && test_event1.motion.y>=133 && test_event1.motion.x<=125 && test_event1.motion.x>=100)){ j= 1; done=0;}
                if(test_event1.button.button==SDL_BUTTON_LEFT && (test_event1.motion.y<=260 && test_event1.motion.y>=240 && test_event1.motion.x<=125 && test_event1.motion.x>=100)){ j= 2;done=0; }
            break;
            case SDL_QUIT:
                SDL_Quit();
                //shutdown all sub systems
                return -1;
                printf("Quiting....\n");
            break;

        }
    }
SDL_Event event;
    display_img(screen,pos1,"./images/keyboard.png",image);
    memset(player_name, 0, sizeof player_name);
    enter_player_name(screen,player_name,test_event,&temps);
    printf("player name is %s \n",player_name);
    int done1;
    display_img(screen,pos1,"./images/1st level.png",image);
    SDL_Rect player;
    SDL_Surface* player_image;
    afficher(player,m,screen);
    Boite b;
    /*b.diag=IMG_Load("./images/dialogue.png");
    strcpy(b.text,"hey! i am ");
    strcat(b.text,player_name);
    affichier_diag(b,screen);
    affichier_diag(b,screen);SDL_Delay(1500);SDL_Flip(screen);*/

    SDL_Rect posref;
    background bg,bg2;
    SDL_Rect text_pos;
    text_pos.x=300;
    text_pos.y=5;
    initBack(&bg);
    initBack(&bg2);

//animerBackground (&bg,screen);
SDL_Rect pos;
    inittemps(&temps);
    //SDL_Rect S=p.position;
        while(!( done==1)){
afficherBack(bg,screen);
   SDL_Rect both;
   SDL_Rect both2;
   both.x=p.position.x + bg.pos_background2.x;
   both.y=p.position.y + bg.pos_background2.y;
   both2.x=p2.position.x + bg2.pos_background2.x;
   both2.y=p2.position.y + bg2.pos_background2.y;
   both2.x-=300;
 posref.x=510;
    posref.y=0;
    int collided;
    int temp=0;
        //display_img(screen,posref,"images/minimaprefreshtime.png",image);
        //if((temps.ss>last)||(temps.mm>last1)){

//collision firas

if(both.x<680){
if(collisionPP(bg.calque_background,p.image,both,both)==2)
{
    printf("\n %d ",p.position.x);
 puts("colide");
 if(p.isjumping!=0){temp=p.isjumping;}
 if(p.isjumping==0)p.isjumping=0;

}
else  {
    if(p.isjumping==0)p.position.y+=3;
p.isjumping=temp;
saut(&p,&bg);
if(p.isjumping==0)
puts("didn't collide");
 }
        }
afficherPerso ( p,screen) ;
  if (j==2)
	{   SDL_Rect camera;
        camera.x=1150;
        camera.y=310;
        partage(bg2,screen);
        SDL_BlitSurface(m.image, NULL, screen, &m.pos);
        MAJMinimap(both2,&m,camera,15);
        SDL_BlitSurface(m.player, NULL, screen, &m.pos_p);
        afficher(both,m,screen);
        char string[20];
        //sprintf(string,"score :%d",temps.ss*10+temps.mm*600);
        //write_texte(20,string,font,color,text,text_pos,screen);
        afficherPerso ( p2,screen) ;
    if (collision(E.pos,p2.position)==1)
    if (col2==0) {quiz_final(screen);col2=1;
screen = SDL_SetVideoMode(640, 410, 8, SDL_SWSURFACE|SDL_ANYFORMAT);}}
SDL_BlitSurface(m.image, NULL, screen, &m.pos);
        if(j==2) SDL_BlitSurface(m.player, NULL, screen, &m.pos_p);
        afficher(both,m,screen);
        char string[20];
        sprintf(string,"score :%d",temps.ss*10+temps.mm*600);
        write_texte(20,string,font,color,text,text_pos,screen);
    deplacer(&E);
    animerEnnemi(&E);
    afficherEnnemi(E,screen);
    if(p.position.x<50)p.position.x=50;
    if (collision(E.pos,p.position)==1)
    if (col==0) {quiz_final(screen);col=1;
screen = SDL_SetVideoMode(640, 410, 8, SDL_SWSURFACE|SDL_ANYFORMAT);}
        update_time(&temps,screen);
MAJMinimap(p.position,&m,pos,1);
saut(&p,&bg);saut(&p2,&bg2);
   SDL_Flip(screen);SDL_Delay(50);  
   arduinoReadData(&received);
   SDL_PollEvent(&event);
   if(bg.pos_background2.x>3115-640)bg.pos_background2.x=3115-640;
   if(bg.pos_background2.x<20)bg.pos_background2.x=20;
   if(bg2.pos_background2.x>2780)bg2.pos_background2.x=2780;
   if(bg2.pos_background2.x<50)bg2.pos_background2.x=50;
   if(p.position.x>=200)p.position.x=200;
   if(p2.position.x>=530)p2.position.x=530;
   if(p2.position.x<=310)p2.position.x=310;
   if(received==2){p.frame.w=80 ;
                     p.frame.h=100 ;
                     p.frame.x=0 ;
                     p.frame.y=0 ;
                     animerPerso(&p) ;
                     p.direction=1;
                     if(p.vitesse!=0)bg.pos_background2.x+=10;}
                     else if(received==1){p.frame.w=80 ;
                 p.frame.h=200 ;
                 p.frame.x=320 ;
                 p.frame.y=115 ;
                 animerPerso(&p) ;
                 p.direction=2 ;
                 if(p.vitesse-=0)bg.pos_background2.x-=10;
                 //scrolling_i(&bg,1,-2);
                //S.x-=3.5;

                 if (p.position.x==0)
                 {
                p.direction=1 ;
                p.frame.w=80 ;
                p.frame.h=100 ;
                p.frame.x=0 ;
                p.frame.y=0 ;
                  }
              deplacerperso(&p,p.direction) ;}
              printf("\nreceived : %d  \n",received);
switch(event.type)
      {
           case SDL_QUIT :
           SDL_FreeSurface(screen);
           done = 1;
           break ;
       

          case SDL_KEYDOWN:
               switch(event.key.keysym.sym)
                 { 
		case SDLK_UP:
		sauter(&p);
        if(p.direction==1)if(p.vitesse!=0)bg.pos_background2.x+=15;else if(p.vitesse==0)bg.pos_background2.x-=15;
        /*if(p.direction==1)
        scrolling_i(&bg,1,6);
        if(p.direction==2)
        scrolling_i(&bg,1,-6);*/
break;
                   case SDLK_RIGHT:
                     p.frame.w=80 ;
                     p.frame.h=100 ;
                     p.frame.x=0 ;
                     p.frame.y=0 ;

                     animerPerso(&p) ;
                     p.direction=1;
                     if(p.vitesse!=0)bg.pos_background2.x+=10;
                     //scrolling_i(&bg,1,2);
                    //S.x+=3.5;
                   
 
                     if (p.position.x==530)
                     { 
                        p.direction=2 ;
                        p.frame.w=80 ;
                        p.frame.h=200 ;
                        p.frame.x=320 ;
                        p.frame.y=115 ;
                     }
             
                   deplacerperso(&p,p.direction) ; 
                 

                   break ; 

                 case SDLK_LEFT:
                 p.frame.w=80 ;
                 p.frame.h=200 ;
                 p.frame.x=320 ;
                 p.frame.y=115 ;
                 animerPerso(&p) ;
                 p.direction=2 ;
                 if(p.vitesse-=0)bg.pos_background2.x-=10;
                 //scrolling_i(&bg,1,-2);
                //S.x-=3.5;

                 if (p.position.x==0)
                 {
                p.direction=1 ;
                p.frame.w=80 ;
                p.frame.h=100 ;
                p.frame.x=0 ;
                p.frame.y=0 ;
                  }
              deplacerperso(&p,p.direction) ;
               break ;
         case SDLK_u:
         p.vitesse= p.vitesse+0.05;
          break; 

          case SDLK_i:
          while(p.vitesse>1)
         p.vitesse= p.vitesse-0.05;
          break ;
          case SDLK_0:
         saut(&p,&bg);
          break ; 
          
          if (j==2)
         {

		case SDLK_z:
		sauter(&p2);
        if(p2.direction==1) bg2.pos_background2.x+=10; else
        bg2.pos_background2.x-=10;
		break;
             case SDLK_d:
                   p2.frame.w=80 ;
                     p2.frame.h=100 ;
                     p2.frame.x=0 ;
                     p2.frame.y=0 ;
                     animerPerso(&p2) ;
                     p2.direction=1 ;
                    bg2.pos_background2.x+=10;
                     if (p2.position.x==530)
                     { 
                        p2.direction=2 ;
                        p2.frame.w=80 ;
                        p2.frame.h=200 ;
                        p2.frame.x=320 ;
                        p2.frame.y=115 ;

                     }
             
                   deplacerperso(&p2,p2.direction) ; 
                   break ;
             case SDLK_q :
                p2.frame.w=80 ;
                 p2.frame.h=200 ;
                 p2.frame.x=320 ;
                 p2.frame.y=115 ;
                 animerPerso(&p2) ;
                 p2.direction=2 ;
                bg2.pos_background2.x-=10;
                 if (p.position.x==0)
                 {
                p2.direction=1 ;
                p2.frame.w=80 ;
                p2.frame.h=100 ;
                p2.frame.x=0 ;
                p2.frame.y=0 ;
                  }
              deplacerperso(&p2,p2.direction) ;
            break ;
       //  }
 }
  break ;
      } 

        last=temps.ss;
        last1=temps.mm;
        }
        done1=0;
    save_score(player_name,temps.ss*10);
        while(SDL_PollEvent(&test_event)) {
        switch(test_event.type) {

            case SDL_MOUSEBUTTONDOWN:
            if(test_event.motion.y<=34 && test_event.motion.y>=10 &&(test_event.motion.x<=80 && test_event.motion.x>=9)){done=1;}
            break;
            
            case SDL_QUIT:
                SDL_Quit();
                //shutdown all sub systems
                return -1;
                printf("Quiting....\n");
            break;
        }
        }
        }
    break;
    case 2:
    while(!(done==1)){
    display_img(screen,posoptions,"./images/optionsmenu.png",image);
    while(SDL_PollEvent(&test_event)) {
        switch(test_event.type) {
            case SDL_MOUSEBUTTONDOWN:
                if(test_event.button.button==SDL_BUTTON_RIGHT && (test_event.motion.y<=160 && test_event.motion.y>=148 && test_event.motion.x<=368 && test_event.motion.x>=352)){
                    level= level+0.5;
                    Mix_VolumeMusic(MIX_MAX_VOLUME/level);
                    if(level==5)Mix_VolumeMusic(0);
                    
                }
                if(test_event.button.button==SDL_BUTTON_LEFT && (test_event.motion.y<=160 && test_event.motion.y>=148 && test_event.motion.x<=368 && test_event.motion.x>=352)){
                    if(level>=2)
                    level=level -0.5;
                    Mix_VolumeMusic(MIX_MAX_VOLUME/level);
                    
                }
                //clicked on full screen
                if(test_event.button.button==SDL_BUTTON_LEFT && (test_event.motion.y<=197 && test_event.motion.y>=185 && test_event.motion.x<=368 && test_event.motion.x>=352)){
                    if(i==0){SDL_WM_ToggleFullScreen(screen);i++;}
                }
                //clicked on windowed
                if(test_event.button.button==SDL_BUTTON_LEFT && (test_event.motion.y<=235 && test_event.motion.y>=220 && test_event.motion.x<=368 && test_event.motion.x>=352)){
                    if(i==1){SDL_WM_ToggleFullScreen(screen);i--;}
                }
                if(test_event.button.button==SDL_BUTTON_LEFT && (test_event.motion.y<=110 && test_event.motion.y>=81 && test_event.motion.x<=212 && test_event.motion.x>=184)){
                    done=1;
                }
            break;
            case SDL_QUIT:
                SDL_Quit();
                //shutdown all sub systems
                return -1;
                printf("Quiting....\n");
            break;
        }
    }
    //load options
    }
    break;
    case 3:
    done1=0;
    afficher_scoreboard(screen);
        while(!(done1==1)){
        while(SDL_PollEvent(&test_event)) {
            switch(test_event.type) {
                case SDL_MOUSEBUTTONDOWN:
                    if(test_event.motion.y<=38 && test_event.motion.y>=10 &&(test_event.motion.x<=632 && test_event.motion.x>=557)) done1=1;
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
    //load credits
    break;
    case 4:
    XO();
    //load minigame
    break;
    case 5:
    //load load
    printf("loading...\n");
	int positionFond = 150 ;
	short int Z = 10 ;
	short int A = 5 ;
	int score = 3205 ; 
	int vie = 3 ;
	int running = 1 ;
	int i ;
				FILE* f=NULL;
				f=fopen("./score/saveload.txt","r");
				if(f!=NULL)
				{
				fscanf(f,"%d , %hd , %hd , %d , %d ",&positionFond,&Z,&A,&score,&vie) ; 
				printf("positionFond : %d \t Z : %hd \t A : %hd \t score : %d \t vie : %d\t \n",positionFond,Z,A,score,vie) ; 
				}
				else
				{
				printf("the file is empty\n");
				} 
				fclose(f) ; 
    break;

    case -1: 
    return -1;
    break;
}

}
}
