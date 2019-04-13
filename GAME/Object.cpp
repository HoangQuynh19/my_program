#include "Object.h"

Dino::Dino()
{
    PosX=POSX_BEGIN_DINO;
    PosY=POSY_BEGIN_DINO;
    altitude=0;
    gravity=0;
}
void Dino::handleEvent(SDL_Event& e)
{
    if( e.type == SDL_KEYDOWN &&PosY==POSY_BEGIN_DINO )
    {
        switch( e.key.keysym.sym )
        {
            case SDLK_SPACE:
                {
                    altitude=J_HEIGHT;
                    gravity=J_GLAVITY;
                    break;
                }
        }
    }
}
void Dino::jump()
{

    PosY-=altitude;
    altitude-=gravity;
    if(PosY>=POSY_BEGIN_DINO)
    {
        gravity=0;
        altitude=0;
    }
}
void Dino::Render(LTexture& gDino,SDL_Renderer* gRenderer)
{

    gDino.render( PosX , PosY,gRenderer,NULL );

}

int Dino::getPosX()
{
    return PosX;
}
int Dino::getPosy()
{
    return PosY;
}
void Dino::End(int y)
{
    PosY=y;
    altitude=0;
    gravity=0;
}

// BARRIER
Cactus::Cactus(int x,int y)
{
    PosX = x;
    PosY = y;

    VelX = 0;
    VELX_C=6;
}

void Cactus::handleEvent(LTexture& gPlay,SDL_Event& e)
{
    if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        switch( e.key.keysym.sym )
        {
            case SDLK_p:
            {
            VelX -= VELX_C;
            gPlay.free();
            break;
            }
            case SDLK_y:
            {
                VELX_C=7;
            }
        }
    }
    if(e.type == SDL_KEYDOWN && e.key.repeat >= 0)
    {
        switch( e.key.keysym.sym )
        {
            case SDLK_p:
            {
             VELX_C=0;
            break;
            }
        }
    }
}

void Cactus::move()
{
    PosX+=VelX;
    if( PosX < 0-WIDTH_CACTUS )
    {
        PosX =WIDTH_CACTUS+ (PosX + SCREEN_WIDTH + VelX) % SCREEN_WIDTH;
    }
}
void Cactus::Render(LTexture& gCactus,SDL_Renderer* gRenderer)
{
    gCactus.render(PosX,PosY,gRenderer,NULL);
}
int Cactus::getPosX()
{
    return PosX;
}
int Cactus::getPosy()
{
    return PosY;
}
void Cactus::End(int x)
{
    PosX=x;
    VelX=0;
}
