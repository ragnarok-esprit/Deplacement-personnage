#ifndef PERSO_H_INCLUDED
#define PERSO_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

typedef struct personnage
{
int score;
int vie;
SDL_Surface *tab[7];
SDL_Rect position;
}personnage;


void initialiser_personnage(personnage *p);
void afficher_personnage(personnage p,SDL_Surface *screen);

#endif

