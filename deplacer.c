#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
void main  (){
  SDL_Surface *screen;
  SDL_Surface *image;

  SDL_Rect positionecran;
  char pause;
  int done=1;
  SDL_Event event;

  SDL_Surface *bg;
  SDL_Rect posbg;

  
  screen = SDL_SetVideoMode(1600,400,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
  
  image = IMG_Load("detective.png");

  bg = SDL_LoadBMP("background.bmp");
  
  positionecran.x = 225-32;    posbg.x = 0;
  positionecran.y = 225-32;    posbg.y = 0;
  positionecran.h = image->h;  posbg.h = image->h;
  positionecran.w = image->w;  posbg.w = image->w;
  while(done)
  {
    SDL_BlitSurface(bg,NULL,screen,&posbg);
    SDL_SetColorKey(image,SDL_SRCCOLORKEY,SDL_MapRGB(image->format,255,255,255));
    SDL_BlitSurface(image,NULL,screen,&positionecran);
    SDL_Flip(screen);
    while(SDL_PollEvent(&event))
    {
     switch(event.type)
     {
        case SDL_KEYDOWN:
          if((event.key.keysym.sym == SDLK_LEFT )|| (event.key.keysym.sym ==SDLK_q))
          {
           positionecran.x -= 5;
           SDL_BlitSurface(image,NULL,screen,&positionecran);
         }
          if((event.key.keysym.sym == SDLK_RIGHT)|| (event.key.keysym.sym ==SDLK_d))
          {
            positionecran.x += 5;
           SDL_BlitSurface(image,NULL,screen,&positionecran);
         }
         if((event.key.keysym.sym == SDLK_UP)|| (event.key.keysym.sym ==SDLK_z))
          {
           
           positionecran.y -= 5;
            SDL_BlitSurface(image,NULL,screen,&positionecran);
         }
          if((event.key.keysym.sym == SDLK_DOWN)|| (event.key.keysym.sym ==SDLK_s))
          {
          positionecran.y += 5;
            //affichage d image
            SDL_BlitSurface(image,NULL,screen,&positionecran);
         }
        break;
        case SDL_MOUSEBUTTONUP:
          if(event.button.button == SDL_BUTTON_LEFT )
          {
            positionecran.x -= 5;
           SDL_BlitSurface(image,NULL,screen,&positionecran);
          }
          if(event.button.button == SDL_BUTTON_RIGHT)
          {
           positionecran.x += 5;
           SDL_BlitSurface(image,NULL,screen,&positionecran);
          }
          if(event.button.button== SDL_BUTTON_WHEELUP)
          {
            positionecran.x+=10;
            positionecran.y -= 20;
            SDL_BlitSurface(image,NULL,screen,&positionecran);
          }
          if(event.button.button == SDL_BUTTON_WHEELDOWN)
          {
            positionecran.y += 5;
            //affichage d image
           SDL_BlitSurface(image,NULL,screen,&positionecran);
          }
        break;
        case SDL_QUIT:

        break;
      }
    }
  }
 
  SDL_FreeSurface(image);
SDL_Quit;
}
