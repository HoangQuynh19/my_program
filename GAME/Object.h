#ifndef OBJECT_H
#define OBJECT_H

#include "loadTexture.h"

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 500;

#define J_HEIGHT 19
#define J_GLAVITY 1

class Dino
{
private:
    int PosX,PosY;
    int altitude;
    int gravity;
public:
    static const int POSX_BEGIN_DINO = 120;
    static const int POSY_BEGIN_DINO = 345;
    Dino();
    void handleEvent( SDL_Event&e );

    void jump();

    void Render(LTexture& gDino,SDL_Renderer* gRenderer);//,SDL_Rect gDinoClips[4]);

    int getPosX();
    int getPosy();
    void End(int y);

};

class Cactus
{
private:
    int PosX, PosY;
    int VelX;
    int VELX_C;
public:
    static const int WIDTH_CACTUS=80;

    Cactus(int x,int y);

    void handleEvent(LTexture& gPlay, SDL_Event&e );

    void move();

    void Render(LTexture& gCactus,SDL_Renderer* gRenderer);

    int getPosX();
    int getPosy();
    void End(int x);
};


#endif // OBJECT_H
