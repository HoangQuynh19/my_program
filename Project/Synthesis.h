#ifndef SYMTHESIS_H
#define SYMTHESIS_H

#include "Texture.h"
#include "Dino.h"
#include "Obstacle.h"

const char WINDOW_TITLE[]="DINOSAUR";
const int RUNNING_ANIMATION_FRAMES = 4;

bool init( SDL_Renderer* &Renderer , SDL_Window* &Window , const int SCREEN_WIDTH , const int SCREEN_HEIGHT );

void close( SDL_Renderer* Renderer , SDL_Window* Window );

bool loadMedia( Texture& Background, Texture& DINO, Texture& Cactus, Texture& Play,Texture& GameOver,
               SDL_Rect DinoClips[RUNNING_ANIMATION_FRAMES], SDL_Renderer* &Renderer );

void RENDER( Texture& Background, Texture& DINO, Texture& Cactus, Texture& Play,Texture& gameOver, Dino& Dinosaur, Obstacle& Cactus1, Obstacle& Cactus2,
               SDL_Rect DinoClips[RUNNING_ANIMATION_FRAMES], int& scrollingOffset, int& frame, SDL_Renderer* &Renderer,bool& endGame );

#endif // SYMTHESIS_H
