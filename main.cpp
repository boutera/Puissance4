#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <SDL/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <cstdlib>
#include "Player.h"
#include "Board.h"
#include <fmod.h>

//#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>




using namespace std;



SDL_Surface *ecran = NULL,*choix=NULL, *imageDeFond = NULL,*fondnoir = NULL, *menu = NULL, *instructions = NULL,*pionrouge=NULL,*pionblanc=NULL,*win1=NULL,*lose1=NULL;
SDL_Rect positionCase={0,0,0,0};
  SDL_Rect positionFond,positionmenu;

int algoType=0;









int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) == -1) // Démarrage de la SDL. Si erreur :
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError()); // Écriture de l'erreur
        return EXIT_FAILURE; // On quitte le programme
    }
    SDL_Surface *ecran = NULL, *imageDeFond = NULL,*texte = NULL ,*gagner = NULL,*fondnoir = NULL, *menu = NULL, *instructions = NULL;

    SDL_Event event; SDL_WaitEvent(&event);
      int continuer = 1;


l:
 SDL_Rect positioninstructions,positionfondnoir,positionTexte;

    positionfondnoir.x=0;
    positionfondnoir.y=0;
    positioninstructions.x=0;
    positioninstructions.y=0;
    positionmenu.x = 0;
    positionmenu.y = 0;
    positionFond.x = 206;
    positionFond.y = 91;



FMOD_SYSTEM *system;


    FMOD_SOUND *tir;


    FMOD_RESULT resultat;

    /* Création et initialisation d'un objet système */
    FMOD_System_Create(&system);
    FMOD_System_Init(system, 1, FMOD_INIT_NORMAL, NULL);

    /* Chargement du son et vérification du chargement */
    resultat = FMOD_System_CreateSound(system, "click.mp3", FMOD_CREATESAMPLE, 0, &tir);

FMOD_SOUND *tir1;


    FMOD_RESULT resultat1;

    /* Création et initialisation d'un objet système */
    FMOD_System_Create(&system);
    FMOD_System_Init(system, 1, FMOD_INIT_NORMAL, NULL);

    /* Chargement du son et vérification du chargement */
    resultat1 = FMOD_System_CreateSound(system, "theme.mp3", FMOD_CREATESAMPLE, 0, &tir1);



    SDL_Init(SDL_INIT_VIDEO);

   // SDL_WM_SetIcon(SDL_LoadBMP("cb.bmp"), NULL);

    ecran = SDL_SetVideoMode(918,611, 32, SDL_HWSURFACE); // Ouverture de la fenêtre
    if( ecran == NULL ){
        return EXIT_FAILURE;
    }

    SDL_WM_SetCaption("Puissance 4", NULL);

    continuer=1;
    int comteur=0;


        menu = SDL_LoadBMP("menu.bmp");
        fondnoir = SDL_LoadBMP("hh.bmp");
        imageDeFond = SDL_LoadBMP("truebord.bmp");
        choix=SDL_LoadBMP("choix.bmp");


    SDL_BlitSurface(menu, NULL, ecran, &positionmenu);
    SDL_FreeSurface(menu);
    SDL_Flip(ecran);

    while (continuer)
 {
    SDL_WaitEvent(&event);
    switch(event.type)
    {
        case SDL_QUIT:
            continuer = 0;
            break;
        case SDL_MOUSEBUTTONDOWN: FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, tir, 0, NULL);break;

        case SDL_MOUSEBUTTONUP:

                if (  (event.button.y >= 250 && event.button.y<300 && event.button.x <200))

                {
    FMOD_SYSTEM *system;
    FMOD_System_Create(&system);
    FMOD_System_Init(system, 2, FMOD_INIT_NORMAL, NULL);

    FMOD_SOUND *mtheme;
    FMOD_RESULT resultat3;

    resultat3=FMOD_System_CreateSound(system, "theme.mp3", FMOD_SOFTWARE | FMOD_2D | FMOD_CREATESTREAM, 0, &mtheme);

    /// On vérifie si elle a bien été ouverte (IMPORTANT)
    if (resultat3 != FMOD_OK)
    {
        fprintf(stderr, "Impossible de lire le fichier mp3\n");
        exit(EXIT_FAILURE);
    }

    /// On active la répétition de la musique à l'infini
    FMOD_Sound_SetLoopCount(mtheme, -1);

    /// On joue la musique
    FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, mtheme, 0, NULL);





  SDL_BlitSurface(choix, NULL, ecran, &positionfondnoir);
  SDL_Flip(ecran);


              while (continuer)
 {
    SDL_WaitEvent(&event);
    switch(event.type)
    {
        case SDL_QUIT:
            continuer = 0;
            break;
        case SDL_MOUSEBUTTONUP:
           if (  (event.button.y >=195 && event.button.y<274 && event.button.x >=300 && event.button.x<=600))             {
                FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, tir, 0, NULL);
     algoType=1;
goto a;
}
           else {
            if (  (event.button.y >=318 && event.button.y<395 && event.button.x >=300 && event.button.x<=600))  {
                    FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, tir, 0, NULL);
                    algoType=2;
goto a;
           }
 }
break;}}
a:
  //                  fondnoir = SDL_LoadBMP("hh.bmp");
                    SDL_BlitSurface(fondnoir, NULL, ecran, &positionfondnoir);

   //                 imageDeFond = SDL_LoadBMP("truebord.bmp");
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);

     //
    SDL_FreeSurface(imageDeFond); // Libération de la surface



int i,j;
SDL_Flip(ecran);
   Board B;
    B.play(algoType,ecran,positionFond);



}
  else
    { if (  (event.button.y >= 320 && event.button.y<370 && event.button.x <200))

           {     resultat = FMOD_System_CreateSound(system, "click.mp3", FMOD_CREATESAMPLE, 0, &tir);
               fondnoir = SDL_LoadBMP("hh.bmp");
            SDL_BlitSurface(fondnoir, NULL, ecran, &positionfondnoir);

           instructions = SDL_LoadBMP("instructions.bmp");
           SDL_BlitSurface(instructions, NULL, ecran, &positioninstructions);
           SDL_Flip(ecran); /* Mise à jour de l'écran avec sa nouvelle couleur */

            while (continuer)
 {
    SDL_WaitEvent(&event);
    switch(event.type)
    {
        case SDL_QUIT:
            continuer = 0;
            break;
        case SDL_MOUSEBUTTONUP:
           if (  (event.button.y >=545 && event.button.y<611 && event.button.x >=658))             {
           FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, tir, 0, NULL);goto l;


             }break;

           }}}
           else {
            if (  (event.button.y >= 390 && event.button.y<440 && event.button.x <200))
            {
                    resultat = FMOD_System_CreateSound(system, "click.mp3", FMOD_CREATESAMPLE, 0, &tir);
                SDL_Quit();
                return EXIT_SUCCESS;
            }
           }




      }
   break; }
    SDL_Flip(ecran);
 }

 FMOD_Sound_Release(tir1);
 FMOD_Sound_Release(tir);
    FMOD_System_Close(system);
    FMOD_System_Release(system);



  SDL_FreeSurface(imageDeFond);
    SDL_FreeSurface(pionrouge);
      SDL_FreeSurface(pionblanc);
        SDL_FreeSurface(fondnoir);
                SDL_FreeSurface(choix);
SDL_Quit();
    return EXIT_SUCCESS; // Fermeture du programme
     SDL_FreeSurface(imageDeFond);


}

