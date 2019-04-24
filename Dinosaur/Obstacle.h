#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "Texture.h"

#include <iostream>
using namespace std;
class Obstacle
{
private:
    int PosX, PosY;
    int VelX;
    int VELX_C;
    int accelerate;

public:
    Obstacle(int x,int y);

    const int WIDTH=80;

    void handleEvent( SDL_Event&e );

    void move( Texture& Texture );

    void Render( Texture& Texture,SDL_Renderer* Renderer );

    int getPosX();
    int getPosy();

    void End(int x);

};
#endif // OBSTACLE_H

