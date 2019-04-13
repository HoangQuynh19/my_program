#include "Object.h"

SDL_Renderer* gRenderer=NULL;
SDL_Window* gWindow=NULL;

const char WINDOW_TITLE[]="DINOSAUR";
const int POSY_BEGIN_CACTUS = 300;

#define limit_left 115
#define limit_right 45
#define limit_above 300

LTexture gBackground;
LTexture gDino;
LTexture gCactus;
//LTexture gBarrier;
LTexture gPlay;
LTexture gameOver;

Dino Dino;
Cactus Cactus1(SCREEN_WIDTH,POSY_BEGIN_CACTUS);
Cactus Cactus2(SCREEN_WIDTH+SCREEN_WIDTH/2,POSY_BEGIN_CACTUS);
//Cactus Barrier(SCREEN_WIDTH+SCREEN_WIDTH/6,POSY_BEGIN_CACTUS);
SDL_Rect gDinoClips[4];

bool init();
void close();

bool loadMedia()
{
	bool success = true;

	if (gBackground.loadTexture("background.jpg",gRenderer) == NULL ) success = false;

    if (gCactus.loadTexture("barrier1.gif",gRenderer) == NULL ) success = false ;

    if (gDino.loadTexture("dinosaur.png",gRenderer) == NULL ) success = false;

    if (gPlay.loadTexture("Play.png",gRenderer) == NULL ) success = false;

 //   if (gBarrier.loadTexture("barrier2.gif",gRenderer) == NULL ) success =false;
	return success;
}

bool GameOver()
{   bool end=false;

    int distance_left1 = Cactus1.getPosX()-Dino.getPosX();
    int distance_right1 = Dino.getPosX()- Cactus1.getPosX();
    int distance_left2 = Cactus2.getPosX()-Dino.getPosX();
    int distance_right2 = Dino.getPosX()- Cactus2.getPosX();

    if( distance_left1 <= limit_left && Dino.getPosy() > limit_above && Cactus1.getPosX()> Dino.getPosX())
    {
        int x=Cactus1.getPosX();
        int y=Dino.getPosy();

        Dino.End(y);
        Cactus1.End(x);
        Cactus2.End(x+SCREEN_WIDTH/2);

        end=true;
    }

    if ( distance_right1 <= limit_right && Dino.getPosy() > limit_above && Cactus1.getPosX()< Dino.getPosX() )
    {
        int x=Cactus1.getPosX();
        int y=Dino.getPosy();

        Cactus1.End(x);
        Cactus2.End(x+SCREEN_WIDTH/2);
        Dino.End(y);
        end=true;
    }

    if( distance_left2 <= limit_left && Dino.getPosy() > limit_above && Cactus2.getPosX()> Dino.getPosX())
    {
        int x=Cactus2.getPosX();
        int y=Dino.getPosy();

        Cactus2.End(x);
        Cactus1.End(x-SCREEN_WIDTH/2);
        Dino.End(y);

         end=true;
    }

    if ( distance_right2 <= limit_right && Dino.getPosy() > limit_above && Cactus2.getPosX()< Dino.getPosX())
    {
        int x=Cactus2.getPosX();
        int y=Dino.getPosy();

        Cactus2.End(x);
        Cactus1.End(x-SCREEN_WIDTH/2);
        Dino.End(y);

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


void Render(int& scrollingOffset)
{
    --scrollingOffset;
    if( scrollingOffset < -gBackground.getWidth() )
    {
        scrollingOffset = 0;
    }

    gBackground.render( scrollingOffset, 0,gRenderer,NULL );
    gBackground.render( scrollingOffset + gBackground.getWidth(), 0 ,gRenderer,NULL );

    gPlay.render( ( SCREEN_WIDTH-gPlay.getWidth() )/2 ,( SCREEN_HEIGHT-gPlay.getHeight() ) /2 , gRenderer,NULL );

    Cactus1.Render( gCactus,gRenderer );
    Cactus2.Render( gCactus,gRenderer );
 //   Barrier.Render(gBarrier,gRenderer);
    Dino.Render( gDino,gRenderer );
}

int main(int argc, char* args[])
{
    if( !init() ) return -1;

	if( !loadMedia() ) return -1;

    SDL_Event e;
    bool quit=false;

    int scrollingOffset = 0;

    while(!quit)
    {
        while(SDL_PollEvent(&e)!=0)
        {
            if( e.type == SDL_QUIT )
            {
                quit = true;

            }
            Cactus1.handleEvent(gPlay,e);
            Cactus2.handleEvent(gPlay,e);
         //   Barrier.handleEvent(gPlay,e);
            Dino.handleEvent(e);
        }
        Cactus1.move();
        Cactus2.move();
     //   Barrier.move();
        Dino.jump();

        SDL_RenderClear( gRenderer );

        Render(scrollingOffset);
        GameOver();
        SDL_RenderPresent( gRenderer );
    }
    close();
    return 0;
}

bool init(){
    bool success = true;
    if( SDL_Init(SDL_INIT_VIDEO)<0 ) success = false;
	else{
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) ){
			printf( "Warning: Linear texture filtering not enabled!" );
		}
		gWindow = SDL_CreateWindow( WINDOW_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL ){
			success = false;
		} else{
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if(gRenderer == NULL) success = false;
			else{
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) ){
					success = false;
				}
			}
		}
	}

	return success;
}
void close()
{
    gBackground.free();
    gDino.free();
    gCactus.free();
    gPlay.free();

	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	IMG_Quit();
	SDL_Quit();
}
