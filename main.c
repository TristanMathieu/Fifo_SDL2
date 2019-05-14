#include "file.h"

int main (int argc, char** argv)
{


          //Initialisation de la SDL
        if (SDL_Init(SDL_INIT_VIDEO) != 0 )
        {
            //Message d'erreur
            fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
            return -1;
        } else {
            printf("\nSDL Initialisee.\n");
            //Traitement

            //Création de la page
            SDL_Window *pWindow = SDL_CreateWindow("File de texture par Tristan M.", 100, 100, 640, 480, 0);
            SDL_Renderer *renderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);
            SDL_RenderPresent(renderer);

            //Si la page s'est bien créée
            if( pWindow )
            {
                //Init. Var.
                int cont = 1;
                SDL_Event event;

                File *suite;
                tActor *monAct;

                if ((suite = (File *) malloc (sizeof (File))) == NULL)
                        return -1;
                if ((monAct = (tActor *) malloc (50 * sizeof (tActor))) == NULL)
                        return -1;

                initialisation (suite);

                initActeur (monAct, renderer, 10);
                enFiler (suite, suite->fin, monAct);

                initActeur (monAct, renderer, 25);
                enFiler (suite, suite->fin, monAct);

                initActeur (monAct, renderer, 50);
                enFiler (suite, suite->fin, monAct);

                //Boucle SDL
                while(cont !=0){
                    while (SDL_PollEvent(&event))
                    {
                        switch(event.type)
                        {
                            //case on click sur la croix en haut a droite
                            case SDL_QUIT:
                                printf("\n\nProcedure de fermeture lancee.");
                                cont = 0;
                                break;

                            default:
                                break;
                        }

                    //Affichage
                    //Peindre l'arriere plan en noir
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                    SDL_RenderClear(renderer);
                    SDL_RenderPresent(renderer);

                    affiche(suite, renderer);



                    }
                }

            //Si la page ne s'est pas bien créée
            free(monAct);
            free(suite);
            } else {
                //Message d'erreur
                fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
            }

            }
        //Fermeture de fichier SDL

        SDL_Quit();


      return 0;
}
