#include "enemie.h"

void initEnnemi(Ennemi *e)
{
    e->sprite=IMG_Load("enemie.png");
    e->pos.y=280;
    e->pos.x=200;
    e->pos.h=100;
    e->pos.w=50;
    e->direction=0;


    e->pos_sp.x=0;
    e->pos_sp.y=0;
    e->pos_sp.h=100;
    e->pos_sp.w=100;

}



void afficherEnnemi(Ennemi e, SDL_Surface * screen)
{
    SDL_BlitSurface(e.sprite , &e.pos_sp , screen , &e.pos) ;
}

void animerEnnemi( Ennemi * e)
{
    e->pos_sp.x += e->pos_sp.w ;
    if (e->pos_sp.x==400)
    {
        e->pos_sp.x=0;
    }
     e->pos_sp.y = e->direction * e->pos_sp.h;
}

void deplacer( Ennemi * e){
    int Xmin =50 , Xmax= 600;
    if (e->direction==0)
    {
        e->pos.x += 10;
    }
    else if (e->direction==1)
    {
        e->pos.x -= 10;
    }



    if (e->pos.x <= Xmin)
    {
        e->direction = 0;
    }
    if (e->pos.x >= Xmax)
    {
        e->direction = 1;
    }




}



int collision(SDL_Rect E, SDL_Rect p) {
  int collision;
  if (((p.x + p.w) < E.x) || (p.x > (E.x + E.w)) || ((p.y + p.h) < E.y) || (p.y > (E.y + E.h)))
  {
    collision = 0;
  } else {
    collision = 1;
  }
  return collision;
}
void deplacerIA(Ennemi * E, SDL_Rect posPerso) {
  if (((E -> pos.x - posPerso.x) < 300) && ((E -> pos.x - posPerso.x) > 80)) {
    E -> direction = 1;
    E -> pos.x -= 20;

  } else if (((E -> pos.x - posPerso.x) < -80) && ((E -> pos.x - posPerso.x) > -300)) {
    E -> direction = 0;
    E -> pos.x += 20;

  } else if (((E -> pos.x - posPerso.x) <= 80) && ((E -> pos.x - posPerso.x) >= 0)) {
    E -> direction = 3;

  } else if (((E -> pos.x - posPerso.x) <= 0) && ((E -> pos.x - posPerso.x) >= -80)) {
    E -> direction = 2;
  } else deplacer(E);

}
