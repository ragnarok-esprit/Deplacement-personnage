
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>


int main(int argc, char *argv[])
{
SDL_Surface *ecran = NULL, *perso = NULL, *backmask=NULL,*back=NULL;
SDL_Rect positionPerso,positionmasque,positionback;
SDL_Event event;
int continuer = 1,r,z;
int quit =1;

SDL_Init(SDL_INIT_VIDEO);

ecran = SDL_SetVideoMode(1600,400, 32, SDL_HWSURFACE);
SDL_WM_SetCaption("Collision avec le background", NULL);

/* Chargement de Zozor */
perso = IMG_Load("detective.png");
backmask= IMG_Load("collisiontest.png");
back= IMG_Load("calque.png");

positionback.x=0;
positionback.y=0;
/* On centre Zozor à l'écran */
positionPerso.x = ecran->w / 2 - perso->w / 2;
positionPerso.y = ecran->h / 2 - perso->h / 2;
SDL_EnableKeyRepeat(10,10); // activation de la touche //

while (continuer)
{

SDL_PollEvent(&event);

r= collision_parfaite(backmask,perso,positionPerso,z);

switch(event.type)
{
case SDL_QUIT:
continuer = 0;
break;
case SDL_KEYDOWN:
switch(event.key.keysym.sym)
{
case SDLK_UP: // Flèche haut
positionPerso.y-=2;
z=2;
if(r==1)
	{positionPerso.y += 2;}
break;
case SDLK_DOWN: // Flèche bas
positionPerso.y +=2;
z=3;
if(r==1)
	{positionPerso.y -= 2;}
break;
case SDLK_RIGHT: // Flèche droite
positionPerso.x += 2;
z=0;
if(r==1)
	{positionPerso.x -= 2;}
break;
case SDLK_LEFT: // Flèche gauche
positionPerso.x-=2;
z=1;
if(r==1)
	{positionPerso.x += 2;}
break;
}
break;
}

r=0;
SDL_BlitSurface(back, NULL, ecran, &positionback);
/*SDL_BlitSurface(backmask, NULL, ecran, &positionback);*/
SDL_BlitSurface(perso, NULL, ecran, &positionPerso);

/* On met à jour l'affichage */
SDL_Flip(ecran);

}

SDL_FreeSurface(perso);
SDL_FreeSurface(back);
SDL_FreeSurface(backmask);



SDL_Quit();
return EXIT_SUCCESS;
}
