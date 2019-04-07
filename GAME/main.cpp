#include "Object.h"

SDL_Renderer* gRenderer=NULL;
SDL_Window* gWindow=NULL;

const char WINDOW_TITLE[]="DINOSAUR";
const int POSY_BEGIN_CACTUS = 300;

LTexture gBackground;
LTexture gDino;
LTexture gCactus;
LTexture gPlay;
LTexture gameOver;

Dino Dino;
Cactus Cactus1(SCREEN_WIDTH,POSY_BEGIN_CACTUS);
Cactus Cactus2(SCREEN_WIDTH+600,POSY_BEGIN_CACTUS);

SDL_Rect gDinoClips[4];

bool init();
void close();

bool loadMedia()
{
	bool success = true;

	if (gBackground.loadTexture("background.jpg",gRenderer)==NULL) success = false;

    if (gCactus.loadTexture("barrier1.gif",gRenderer)==NULL) success = false ;

    if (gDino.loadTexture("dinosaur.png",gRenderer)==NULL) success = false;

    if (gPlay.loadTexture("Play.png",gRenderer)==NULL) success = false;

	return success;
}

bool GameOver()
{   bool end=false;
    if( Cactus1.getPosX()-Dino.getPosX()<=118 && Cactus1.getPosX()> Dino.getPosX()&&Dino.getPosy()>300)
    {
        gameOver.loadTexture("GameOver.jpg",gRenderer);
        gameOver.render( ( SCREEN_WIDTH-gameOver.getWidth() )/2 ,( SCREEN_HEIGHT-gameOver.getHeight() ) /2 , gRenderer,NULL );

        int x=Cactus1.getPosX();
        int y=Dino.getPosy();
        Dino.End(y);
        Cactus1.End(x);
        Cactus2.End(x+600);
        end=true;

    } else gameOver.free();

    if ( Dino.getPosX()- Cactus1.getPosX()<=50 && Cactus1.getPosX()< Dino.getPosX() && Dino.getPosy()>300 )
    {
        gameOver.loadTexture("GameOver.jpg",gRenderer);
        gameOver.render( ( SCREEN_WIDTH-gameOver.getWidth() )/2 ,( SCREEN_HEIGHT-gameOver.getHeight() ) /2 , gRenderer,NULL );

        int x=Cactus1.getPosX();
        int y=Dino.getPosy();

        Cactus1.End(x);
        Cactus2.End(x+600);

        Dino.End(y);
        end=true;

    } else gameOver.free();

    if( Cactus2.getPosX()-Dino.getPosX()<=118 && Cactus2.getPosX()> Dino.getPosX()&&Dino.getPosy()>300)
    {
        gameOver.loadTexture("GameOver.jpg",gRenderer);
        gameOver.render( ( SCREEN_WIDTH-gameOver.getWidth() )/2 ,( SCREEN_HEIGHT-gameOver.getHeight() ) /2 , gRenderer,NULL );

        int x=Cactus2.getPosX();

        Cactus2.End(x);
        Cactus1.End(x-600);
        int y=Dino.getPosy();
        Dino.End(y);
        end=true;

    } else gameOver.free();

    if ( Dino.getPosX()- Cactus2.getPosX()<=53 && Cactus2.getPosX()< Dino.getPosX() && Dino.getPosy()>300 )
    {
        gameOver.loadTexture("GameOver.jpg",gRenderer);
        gameOver.render( ( SCREEN_WIDTH-gameOver.getWidth() )/2 ,( SCREEN_HEIGHT-gameOver.getHeight() ) /2 , gRenderer,NULL );

        int x=Cactus2.getPosX();
        int y=Dino.getPosy();

        Cactus2.End(x);
        Cactus1.End(x-600);

        Dino.End(y);
        end=true;

    } else gameOver.free();
    return end;
}
void event(SDL_Event& e,bool&quit)
{
    Cactus1.handleEvent(gPlay,e);
    Cactus2.handleEvent(gPlay,e);
    Dino.handleEvent(e);

    if (GameOver()==true){
        if( e.type == SDL_KEYDOWN )
        {
            switch( e.key.keysym.sym )
            {
                case SDLK_n: quit==true;
            }
        }
    }
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

    Dino.Render( gDino,gRenderer );
}

int main(int argc, char* args[])
{
    if( !init() )
	{
		return -1;
	}
	if( !loadMedia() )
    {
        return -1;
    }
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
            event(e,quit);

        }
        Cactus1.move();
        Cactus2.move();
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
