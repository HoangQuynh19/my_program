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
