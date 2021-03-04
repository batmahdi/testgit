#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_ttf.h>
int main(int argc, char *argv[])
{

   
   SDL_Surface *ecran = NULL, *texte = NULL,*image3 = NULL,*image2 = NULL, *image1 = NULL, *image_backg = NULL, *image3G = NULL,*image2G = NULL, *image1G = NULL, *quitter = NULL;

   SDL_Rect posimage, posimage1, posimage2, posimage3, postexte, posimage1G, posimage2G, posimage3G, postexteG,posquitter;

   Mix_Music *musique; //Creation du pointeur de type Mix_Music    
   SDL_Event event;
   
   TTF_Font *police;
	SDL_Color policeNoire = {0,0,0};
 	SDL_Color policeBlanche = {255,255,255}; 
 	SDL_Color policeRouge = {255,0,0};

SDL_Init(SDL_INIT_VIDEO); //Initialisation

TTF_Init(); //Initialisation TFF (texte)

police = TTF_OpenFont("Mount Hills.otf",20); //charger police

//texte = TTF_RenderText_Blended(police, "OVERCLOCKED BRAINS", policeNoire);
quitter = TTF_RenderText_Blended(police, "Press 'esc' to quit", policeNoire);


SDL_WM_SetCaption("Rewind", NULL); //sets the title bar and icon name of the display window

   ecran = SDL_SetVideoMode(1200,627,32, SDL_HWSURFACE | SDL_DOUBLEBUF); //Creation fenetre

if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
   {
      printf("%s", Mix_GetError());
   }
   
   musique = Mix_LoadMUS("musique2.mp3"); //Chargement de la musique
   Mix_PlayMusic(musique, -1); //Jouer infiniment la musique
   
   
   image_backg = IMG_Load ("bgcarth.jpg");  
   image1 = IMG_Load ("Asset_1.png");
   image1G = IMG_Load ("Asset_2.png");
   image2 = IMG_Load ("Asset_3.png");
   image2G = IMG_Load ("Asset_4.png");
   image3 = IMG_Load ("Asset_5.png");
   image3G = IMG_Load ("Asset_6.png");
	//SDL_LoadBMP("image.bmp");

   posimage.x = 0;
   posimage.y = 0;
   posimage.w = ecran -> w;   
   posimage.h = ecran -> h;

   posimage1.x = 800;
   posimage1.y = 200;
   posimage1.w = ecran -> w;   
   posimage1.h = ecran -> h;

   posimage2.x = 800;
   posimage2.y = 300;
   posimage2.w = ecran -> w;   
   posimage2.h = ecran -> h;

   posimage3.x = 800;
   posimage3.y = 400;
   posimage3.w = ecran -> w;   
   posimage3.h = ecran -> h;

   posimage1G.x = 800;
   posimage1G.y = 200;
   posimage1G.w = ecran -> w;   
   posimage1G.h = ecran -> h;

   posimage2G.x = 800;
   posimage2G.y = 300;
   posimage2G.w = ecran -> w;   
   posimage2G.h = ecran -> h;

   posimage3G.x = 800;
   posimage3G.y = 400;
   posimage3G.w = ecran -> w;   
   posimage3G.h = ecran -> h;

   postexte.x = 50;
   postexte.y = 350;
   posquitter.x = 0;
   posquitter.y = 10;

   int continuer = 1,test=1,up=0,down=0;
   while(continuer)
   {
      
     SDL_BlitSurface(image_backg, NULL, ecran, &posimage); //coller surface
     SDL_BlitSurface(image1, NULL, ecran, &posimage1); 
     SDL_BlitSurface(image2, NULL, ecran, &posimage2); 
     SDL_BlitSurface(image3, NULL, ecran, &posimage3); 
     SDL_BlitSurface(texte, NULL, ecran, &postexte); 
     SDL_BlitSurface(quitter, NULL, ecran, &posquitter);
     
     SDL_Flip(ecran); //refresh
      SDL_WaitEvent(&event);
      switch(event.type)
      {
         case SDL_QUIT:
            continuer = 0;
            break;
	case SDL_KEYUP:
		switch(event.key.keysym.sym)
		{
		case SDLK_ESCAPE:
			continuer=0;
		break;

	case SDLK_UP:
		do 
		{
			up=up+1;
		if (up==4)
				up=1;

		if (up==1)
		{
		SDL_BlitSurface(image3G,NULL,ecran,&posimage3G);
		SDL_Flip(ecran);
		SDL_WaitEvent(&event);
		SDL_PumpEvents();
		}	
		else if (up==2)
		{
		SDL_BlitSurface(image2G,NULL,ecran,&posimage2G);
		SDL_BlitSurface(image3,NULL,ecran,&posimage3);
		SDL_Flip(ecran);
		SDL_WaitEvent(&event);
		SDL_PumpEvents();
		}
		else if (up==3)
		{
		SDL_BlitSurface(image1G,NULL,ecran,&posimage1G);
		SDL_BlitSurface(image2,NULL,ecran,&posimage2);
		SDL_Flip(ecran);
		SDL_WaitEvent(&event);
		SDL_PumpEvents();
		}		
		}while((event.key.keysym.sym == SDLK_UP) && (up==4) );
		break;
	case SDLK_DOWN:
		do 
		{
			down=down+1;
		if (down==4)
				down=1;
	
		if (down==1)
		{
		SDL_BlitSurface(image1G,NULL,ecran,&posimage1G);
		SDL_Flip(ecran);
		SDL_WaitEvent(&event);
		SDL_PumpEvents();
		}	
		else if (down==2)
		{
		SDL_BlitSurface(image2G,NULL,ecran,&posimage2G);
		SDL_BlitSurface(image1,NULL,ecran,&posimage1);
		SDL_Flip(ecran);
		SDL_WaitEvent(&event);
		SDL_PumpEvents();
		}
		else if (down==3)
		{
		SDL_BlitSurface(image3G,NULL,ecran,&posimage3G);
		SDL_BlitSurface(image2,NULL,ecran,&posimage2);
		SDL_Flip(ecran);
		SDL_WaitEvent(&event);
		SDL_PumpEvents();
		}		
		}while((event.key.keysym.sym == SDLK_DOWN) && (down==4) );
		break;
		
	
		

	}
      }
   }
	SDL_FreeSurface(image1);
	SDL_FreeSurface(image2);
	SDL_FreeSurface(image3);
	SDL_FreeSurface(image1G);
	SDL_FreeSurface(image2G);
	SDL_FreeSurface(image3G);
	SDL_FreeSurface(image_backg);
	SDL_FreeSurface(quitter);
	SDL_FreeSurface(texte);
 //liberation surface
						//SDL_Delay(5000); >pause
   TTF_Quit();
   Mix_FreeMusic(musique); //Liberation de la musique
   Mix_CloseAudio(); //Fermeture de l'API
   SDL_Quit(); //arret de la SDL
   return EXIT_SUCCESS;
}


