#ifndef DINO_H
#define DINO_H

#include "Texture.h"
#include <SDL_mixer.h>

#define HEIGHT 21
#define GRAVITY 1
#define Animation_Frames 4

class Dino
{
private:
    int PosX,PosY;
    int Altitude;
    int Gravity;
    Mix_Chunk* Sound_jump;
public:
    static const int POSX_BEGIN_DINO = 120;
    static const int POSY_BEGIN_DINO = 340;

    Dino();

    void handleEvent( SDL_Event& e, bool& endGame );

    void jump(int& frame);

    void Render(Texture& Dino, SDL_Renderer* Renderer, SDL_Rect SpriteClips[Animation_Frames], int& frame);

    int getPosX();
    int getPosy();

    void End(int y);

};

#endif // DINO_H

