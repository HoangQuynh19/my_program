#ifndef GAMEOVER_H_
#define GAMEOVER_H_

#include "loadTexture.h"
#include "Object.h"
#include "Barrier.h"


#define limit_left_C 115
#define limit_right_C 40
#define limit_above_C 300

#define limit_above_B 330
#define limit_left_B 105
#define limit_right_B 45

#define distanceBarrier 250
#define distanceCactus 550
bool GameOver(Dino& Dino, Barrier & Cactus1,Barrier & Cactus2, Barrier &BARRIER1,
               Barrier &BARRIER2,SDL_Renderer*gRenderer,LTexture& gameOver );

#endif // GAMEOVER_H_

