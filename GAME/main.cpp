#include "Object.h"
#include "Barrier.h"
#include "GameOver.h"
SDL_Renderer* gRenderer=NULL;
SDL_Window* gWindow=NULL;

const char WINDOW_TITLE[]="DINOSAUR";
const int POSY_BEGIN_CACTUS = 300;

LTexture gBackground;
LTexture gDino;
LTexture gCactus;
LTexture gBarrier;
LTexture gPlay;
LTexture gameOver;

Dino Dino;
#define posxCactus2 1550
#define posxBarrier2 1800

Barrier Cactus1(SCREEN_WIDTH,POSY_BEGIN_CACTUS);
Barrier Cactus2(posxCactus2,POSY_BEGIN_CACTUS);

Barrier BARRIER1(SCREEN_WIDTH+SCREEN_WIDTH/4,396);
Barrier BARRIER2(posxBarrier2,396);

bool init();
void close();

bool loadMedia()
{
	bool success = true;

	if (gBackground.loadTexture("background.jpg",gRenderer) == NULL ) success = false;

    if (gCactus.loadTexture("barrier1.gif",gRenderer) == NULL ) success = false ;

    if (gDino.loadTexture("dinosaur.png",gRenderer) == NULL ) success = false;

    if (gPlay.loadTexture("Play.png",gRenderer) == NULL ) success = false;

   if (gBarrier.loadTexture("barrier2.gif",gRenderer)== NULL ) success = false;

	return success;
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

    if(Cactus1.getPosX()< Dino.getPosX()||( Cactus1.getPosX()> Dino.getPosX()&& Cactus1.getPosX() - Dino.getPosX() >700 ))
    {
        BARRIER1.Render(gBarrier,gRenderer);
    }

    if (Cactus2.getPosX()< Dino.getPosX()||( Cactus2.getPosX()> Dino.getPosX()&& Cactus2.getPosX() - Dino.getPosX() >700 ))
    {
        BARRIER2.Render(gBarrier,gRenderer);
    }
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
            BARRIER1.handleEvent(gPlay,e);
            BARRIER2.handleEvent(gPlay,e);
            Dino.handleEvent(e);
        }
        Cactus1.move(gCactus);
        Cactus2.move(gCactus);
        BARRIER1.move(gBarrier);
        BARRIER2.move(gBarrier);

        Dino.jump();

        SDL_RenderClear( gRenderer );

        Render(scrollingOffset);

        GameOver(Dino, Cactus1,Cactus2,BARRIER1,BARRIER2,gRenderer,gameOver);
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
