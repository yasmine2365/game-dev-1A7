 #include "perso.h"
void initPerso(Personne *p)
{  
   (*p).image=IMG_Load("persoasma2.png");  

    p->position.x=0;
    p->position.y=285;
    p->position.w=80;
    p->position.h=0;
    p->frame.w=80;
    p->frame.h=100;
    p->frame.x=0;
    p->frame.y=0;

    p->curframe=0;
    p->vitesse=1;
    p->direction=1;
    p->isjumping=0;
   
    p->x = 4;
    p->grav = 0.5;
    p->saut = -6,5;
    p->y = p->saut;
   
}
void initPerso2(Personne *p2)
{
     (*p2).image=IMG_Load("persoasma2.png");  

    p2->position.x=400;
    p2->position.y=285;
    p2->position.w=80;
    p2->position.h=0;
    p2->frame.w=80;
    p2->frame.h=100;
    p2->frame.x=0;
    p2->frame.y=0;

    p2->curframe=0;
    p2->vitesse=1;
    p2->direction=1;
  p2->isjumping=0;
   
    p2->x = 4;
    p2->grav = 0.5;
    p2->saut = -6.5;
    p2->y = p2->saut;

}

void afficherPerso (Personne p,SDL_Surface *screen)
{
SDL_Surface* image1;
image1=IMG_Load("./images/1st level");
SDL_BlitSurface(p.image,&(p.frame),image1,&(p.position)); 
SDL_BlitSurface(p.image,&(p.frame),screen,&(p.position));
}

void deplacerperso(Personne *p,int dt) 
{
 if (dt==1)
    p->position.x=p->position.x+p->vitesse;
 if (dt==2)
     p->position.x=p->position.x-p->vitesse;

}

void animerPerso(Personne *p)
{
         
               p->curframe++ ;
     if(p->curframe>4)
	{
		p->curframe=0;
	}
		p->frame.x=p->curframe * p->frame.w;  // (num img * 80)



}
void sauter(Personne *p)
{if((*p).isjumping ==0) (*p).isjumping = 1;
}


void saut(Personne *p)
{
if((*p).isjumping>0){if ((*p).isjumping <4) (*p).isjumping ++;else (*p).isjumping=-1;}
if((*p).isjumping<0){if ((*p).isjumping >-4) (*p).isjumping --;else (*p).isjumping=0;}
(*p).position.y-=10*(*p).isjumping;
if((*p).direction==1) (*p).position.x+=(*p).isjumping*(*p).isjumping;
else(*p).position.x-=(*p).isjumping*(*p).isjumping;
}
 
 
 
 
 
 
 
 
