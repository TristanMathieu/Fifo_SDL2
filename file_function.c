
#include "file.h"

void initialisation (File * suite){
  suite->debut = NULL;
  suite->fin = NULL;
  suite->taille = 0;
}

void initActeur(tActor * monAct, SDL_Renderer *renderer, int chgmntVis){
    monAct->Vect.nx = 0+chgmntVis;
    monAct->Vect.ny = 0+chgmntVis;
    monAct->textActor = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET,monAct->Vect.nx,monAct->Vect.ny);
    monAct->height = 200-chgmntVis;
    monAct->width = 100-chgmntVis;
}

/* enfiler (ajouter) un élément dans la file */
int enFiler (File * suite, Chainon * courant, tActor *donnee){
  Chainon *nouveau_element;
  if ((nouveau_element = (Chainon *) malloc (sizeof (Chainon))) == NULL)
        return -1;
  if ((nouveau_element->donnee = (tActor *) malloc (50 * sizeof (tActor)))
      == NULL)
        return -1;

  nouveau_element->donnee=donnee;

  if(courant == NULL && suite->taille == 0){

        suite->fin = nouveau_element;
        nouveau_element->suivant = suite->debut;
        suite->debut = nouveau_element;

  }else {
    if(courant->suivant == NULL){
        suite->fin = nouveau_element;
        nouveau_element->suivant = courant->suivant;
        courant->suivant = nouveau_element;
    }

  }
  suite->taille++;
  return 0;
}

/* deFiler (supprimer) un élément de la file */
/*
int deFiler (File * suite){
  Element *supp_element;

  if (suite->taille == 0)
    return -1;

  supp_element = suite->debut;
  suite->debut = suite->debut->suivant;
  free (supp_element->donnee);
  free (supp_element);
  suite->taille--;
  return 0;
}
*/


/* affichage de la file */

void affiche(File *suite, SDL_Renderer *renderer){
    Chainon *courant;
    int i;
    courant = suite->debut;
    SDL_Rect surPos;
    int oui;
    for(i=0;i<suite->taille;++i){
        SDL_SetRenderDrawColor(renderer,255,255,0,255);

        SDL_SetRenderTarget(renderer, courant->donnee->textActor);
        SDL_RenderDrawLine(renderer,0,0,courant->donnee->height,courant->donnee->width);
        SDL_SetRenderTarget(renderer, NULL);

        surPos.x=courant->donnee->Vect.nx;
        surPos.y=courant->donnee->Vect.ny;
        SDL_QueryTexture(courant->donnee->textActor, NULL, NULL, &surPos.w, &surPos.h);
        SDL_RenderCopy(renderer,courant->donnee->textActor,NULL,&surPos);
        SDL_RenderPresent(renderer);
        SDL_DestroyTexture(courant->donnee->textActor);
        SDL_RenderPresent(renderer);

        courant = courant->suivant;
    }
}
