#include "GameOver.h"

bool GameOver(SDL_Event&e,Dino& Dino, Obstacle& Cactus1,Obstacle& Cactus2,
               SDL_Renderer* &Renderer,Texture& gameOver,bool& PlayAgain, bool& quit)
{
    bool end=false;

    int Distance_left1 = Cactus1.getPosX()-Dino.getPosX();
    int Distance_right1 = Dino.getPosX()- Cactus1.getPosX();

    int Distance_left2 = Cactus2.getPosX()-Dino.getPosX();
    int Distance_right2 = Dino.getPosX()- Cactus2.getPosX();


    if( Distance_left1 <= Lim_left && Dino.getPosy() > Lim_above && Cactus1.getPosX()> Dino.getPosX())
    {
        int x=Cactus1.getPosX();
        int y=Dino.getPosy();


        Dino.End(y);
        Cactus1.End(x);
        Cactus2.End(x+SCREEN_WIDTH/2);

        end=true;
    }

    if ( Distance_right1 <= Lim_right && Dino.getPosy() > Lim_above && Cactus1.getPosX()< Dino.getPosX() )
    {
        int x=Cactus1.getPosX();
        int y=Dino.getPosy();

        Cactus1.End(x);
        Cactus2.End(x+SCREEN_WIDTH/2);
        Dino.End(y);

        end=true;
    }

    if( Distance_left2 <= Lim_left && Dino.getPosy() > Lim_above && Cactus2.getPosX()> Dino.getPosX())
    {
        int x=Cactus2.getPosX();
        int y=Dino.getPosy();

        Cactus2.End(x);
        Cactus1.End(x-SCREEN_WIDTH/2);
        Dino.End(y);

        end=true;
    }
    if ( Distance_right2 <= Lim_right && Dino.getPosy() > Lim_above && Cactus2.getPosX()< Dino.getPosX())
    {
        int x=Cactus2.getPosX();
        int y=Dino.getPosy();

        Cactus2.End(x);
        Cactus1.End(x-SCREEN_WIDTH/2);
        Dino.End(y);

        end=true;
    }
    if (end==true){
    if( e.type == SDL_KEYDOWN )
                {
                 switch ( e.key.keysym.sym)
                    {
                         case SDLK_y:{PlayAgain=true;quit=true;break;}
                         case SDLK_n:{PlayAgain=false;quit=true;break;}
                    }
                }
    }
    return end;
}
