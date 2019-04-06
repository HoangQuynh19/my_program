#ifndef LOADTEXTURE_H
#define LOADTEXTURE_H

#include <SDL.h>
#include <SDL_image.h>
#include <string>

class LTexture
{
	public:
		LTexture();
		~LTexture();

		bool loadTexture( std::string path,SDL_Renderer* gRenderer );

		void free();

		void render( int x, int y, SDL_Renderer* gRenderer,SDL_Rect* clip = NULL );

		int getWidth();
		int getHeight();

	private:

		SDL_Texture* mTexture;

		int mWidth;
		int mHeight;
};


#endif // LOADTEXTURE_H
