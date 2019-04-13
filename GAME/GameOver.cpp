#include "GameOver.h"

bool GameOver(Dino& Dino, Barrier& Cactus1,Barrier& Cactus2, Barrier& BARRIER1,
               Barrier& BARRIER2,SDL_Renderer* gRenderer,LTexture& gameOver)
{   bool end=false;

    int distance_left1_c = Cactus1.getPosX()-Dino.getPosX();
    int distance_right1_c = Dino.getPosX()- Cactus1.getPosX();
    int distance_left2_c = Cactus2.getPosX()-Dino.getPosX();
    int distance_right2_c = Dino.getPosX()- Cactus2.getPosX();

    int distance_left1_b = BARRIER1.getPosX()-Dino.getPosX();
    int distance_right1_b = Dino.getPosX()- BARRIER1.getPosX();
    int distance_left2_b = BARRIER2.getPosX()-Dino.getPosX();
    int distance_right2_b = Dino.getPosX()- BARRIER2.getPosX();

// cactus
    if( distance_left1_c <= limit_left_C && Dino.getPosy() > limit_above_C && Cactus1.getPosX()> Dino.getPosX())
    {
        int x=Cactus1.getPosX();
        int y=Dino.getPosy();


        Dino.End(y);
        Cactus1.End(x);
        Cactus2.End(x+distanceCactus);
        BARRIER1.End(0-BARRIER1.WIDTH);
        BARRIER2.End(0-BARRIER1.WIDTH);

        end=true;
    }


    if ( distance_right1_c <= limit_right_C && Dino.getPosy() > limit_above_C && Cactus1.getPosX()< Dino.getPosX() )
    {
        int x=Cactus1.getPosX();
        int y=Dino.getPosy();
        int z=BARRIER1.getPosX();

        BARRIER1.End(z);
        BARRIER2.End(z+distanceBarrier);
        Cactus1.End(x);
        Cactus2.End(x+distanceCactus);
        Dino.End(y);
        end=true;
    }


    if( distance_left2_c <= limit_left_C && Dino.getPosy() > limit_above_C && Cactus2.getPosX()> Dino.getPosX())
    {
        int x=Cactus2.getPosX();
        int y=Dino.getPosy();

        Cactus2.End(x);
        Cactus1.End(x-distanceCactus);
        Dino.End(y);
        BARRIER1.End(0-BARRIER1.WIDTH);
        BARRIER2.End(0-BARRIER1.WIDTH);
         end=true;
    }

    if ( distance_right2_c <= limit_right_C && Dino.getPosy() > limit_above_C && Cactus2.getPosX()< Dino.getPosX())
    {
        int x=Cactus2.getPosX();
        int y=Dino.getPosy();
        int z=BARRIER2.getPosX();

        BARRIER2.End(z);
        BARRIER1.End(z-distanceBarrier);

        Cactus2.End(x);
        Cactus1.End(x-SCREEN_WIDTH/2);
        Dino.End(y);

        end=true;
    }
// barrier

    if( distance_left1_b <= limit_left_B && Dino.getPosy() > limit_above_B && BARRIER1.getPosX()> Dino.getPosX())
    {
        int x=BARRIER1.getPosX();
        int y=Dino.getPosy();
        int z=Cactus2.getPosX();

        Dino.End(y);
        BARRIER1.End(x);
        BARRIER2.End(x+distanceBarrier);
        Cactus2.End(z);
        Cactus1.End(z-distanceCactus);

        end=true;
    }

    if( distance_left2_b <= limit_left_B && Dino.getPosy() > limit_above_B && BARRIER2.getPosX()> Dino.getPosX())
    {
        int x=BARRIER2.getPosX();
        int y=Dino.getPosy();
        int z=Cactus1.getPosX();

        Dino.End(y);
        BARRIER1.End(x-distanceBarrier);
        BARRIER2.End(x);

        Cactus1.End(z);
        Cactus2.End(z+distanceCactus);

        end=true;
    }

    if ( distance_right1_b <= limit_right_B && Dino.getPosy() > limit_above_B && BARRIER1.getPosX()< Dino.getPosX() )
    {
        int x=BARRIER1.getPosX();
        int y=Dino.getPosy();
        int z=Cactus2.getPosX();

        BARRIER1.End(x);
        BARRIER2.End(x+distanceBarrier);
        Dino.End(y);
        Cactus2.End(z);
        Cactus1.End(z-distanceCactus);

        end=true;
    }

    if ( distance_right2_b <= limit_right_B && Dino.getPosy() > limit_above_B && BARRIER2.getPosX()< Dino.getPosX() )
    {
        int x=BARRIER2.getPosX();
        int y=Dino.getPosy();
        int z=Cactus1.getPosX();

        BARRIER1.End(x-distanceBarrier);
        BARRIER2.End(x);
        Dino.End(y);
        Cactus1.End(z);
        Cactus2.End(z+distanceCactus);
        end=true;
    }

    if (end == true)
    {
    gameOver.loadTexture("GameOver.jpg",gRenderer);
    gameOver.render( ( SCREEN_WIDTH-gameOver.getWidth() )/2 ,( SCREEN_HEIGHT-gameOver.getHeight() ) /2 , gRenderer,NULL );
    }
    else gameOver.free();
    return end;
}

