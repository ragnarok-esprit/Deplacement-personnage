#include "perso.h"
void initialiser_personnage(personnage *p)
{
  
   p->score=0;
  
   p->vie=4;
  
   
    p->tab[0]=IMG_Load("image0.png");
    p->tab[1]=IMG_Load("image1.png");
    p->tab[2]=IMG_Load("image2.png");
    p->tab[3]=IMG_Load("image3.png");
    p->tab[4]=IMG_Load("image4.png");
    p->tab[5]=IMG_Load("image5.png");
    p->tab[6]=IMG_Load("image6.png");
    
  p->position.x=0;
  p->position.y=10;
}
void afficher_personnage(personnage p,SDL_Surface *screen,int i)
{
  SDL_BlitSurface(p->tab[i],NULL,screen,&p.position);

}
