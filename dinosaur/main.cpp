#include"dino.h"

SDL_Renderer* gRenderer=NULL;
SDL_Window* gWindow=NULL;

LTexture gBackground;
LTexture gDino;
LTexture gCactus;
LTexture gPlay;

const char WINDOW_TITLE[]="GAME";

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
bool loadMedia(SDL_Renderer* gRenderer)
{
	bool success = true;

	if (gBackground.loadTexture("background.jpg",gRenderer)==NULL) success = false;

    if (gCactus.loadTexture("barrier1.gif",gRenderer)==NULL) success = false ;

    if (gDino.loadTexture("dinosaur.png",gRenderer)==NULL) success = false;

    if (gPlay.loadTexture("Play.png",gRenderer)==NULL) success = false;

	return success;
}
int main(int argc, char* args[])
{
    if( !init() )
	{
		return -1;
	}
	if( !loadMedia(gRenderer) )
    {
        return -1;
    }

    Dino Dino;
    Cactus Cactus;

    SDL_Event e;
    bool quit=false;
    while(!quit)
    {
        while(SDL_PollEvent(&e)!=0)
        {
            if( e.type == SDL_QUIT )
            {
                quit = true;
            }
            Cactus.handleEvent(gPlay,e);
            Dino.handleEvent(e);

        }
        Cactus.move();
        Dino.jump();

        SDL_RenderClear( gRenderer );

        gBackground.render(0,0,gRenderer,NULL);
        gPlay.render(SCREEN_WIDTH/2-90,70,gRenderer,NULL);
        Cactus.Render(gCactus,gRenderer);
        Dino.Render(gDino,gRenderer);

        SDL_RenderPresent( gRenderer );
    }
    close();
    return 0;
}
