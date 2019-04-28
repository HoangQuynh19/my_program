#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "Texture.h"

class Obstacle
{
private:
    int PosX, PosY;
    int VelX;
    int VELX_C;

public:
    Obstacle(int x,int y);

    void handleEvent( SDL_Event&e );

    void move( Texture& Texture );

    void Render( Texture& Texture,SDL_Renderer* Renderer );

    int getPosX();
    int getPosy();

    void End(int x);

};
#endif // OBSTACLE_H

