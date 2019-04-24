#ifndef GAMEOVER_H
#define GAMEOVER_H

#include "Texture.h"
#include "Obstacle.h"
#include "Dino.h"

#define Lim_left 110
#define Lim_right 50
#define Lim_above 290

bool GameOver( SDL_Event&e, Dino& Dino, Obstacle & Cactus1,Obstacle & Cactus2,
               SDL_Renderer* &Renderer, Texture& gameOver,bool& PlayAgain, bool& quit );

#endif // GAMEOVER_H
