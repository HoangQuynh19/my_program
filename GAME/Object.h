#ifndef OBJECT_H
#define OBJECT_H

#include"loadTexture.h"

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 500;

const int POSX_BEGIN_DINO = 120;
const int POSY_BEGIN_DINO = 305;

const int POSY_BEGIN_CACTUS = 265;

int VELX_C =7;

#define J_HEIGHT 19
#define J_GLAVITY 1

class Dino
{
private:
    int PosX,PosY;
    int altitude;
    int gravity;
public:
    Dino();
    void handleEvent( SDL_Event&e );
    void jump();
    void Render(LTexture& gDino,SDL_Renderer* gRenderer);
};

class Cactus
{
private:
    int PosX, PosY;
    int VelX;
public:
    static const int WIDTH_CACTUS=80;

    Cactus();

    void handleEvent(LTexture& gPlay, SDL_Event&e );

    void move();

    void Render(LTexture& gCactus,SDL_Renderer* gRenderer);
};

void loadMedia();
#endif // OBJECT_H