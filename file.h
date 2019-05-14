#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

#include<stdlib.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL2\SDL.h>
#include <SDL2\SDL_image.h>
#include <time.h>

#define LIMITETAILLE 10
#define MINITAILLE 2

//Creation des structuress
typedef struct tVector2D{
    int nx;
    int ny;
}tVector2d;

typedef struct tActor{
    SDL_Texture *textActor;
    tVector2d Vect;
    int height;
    int width;
}tActor;

typedef struct tChainon{
    tActor *donnee;
    struct tChainon *suivant;
}Chainon;

typedef struct tHautFile{
    Chainon *debut;
    Chainon *fin;
    int taille;
}File;

/* initialisation */
extern void initialisation (File * suite);
extern void initActeur (tActor * monAct, SDL_Renderer *renderer, int chgmntVis);

/* ENFILER*/
extern int enFiler (File * suite, Chainon * courant, tActor *donnee);

/* DE_FILER*/
//extern int deFiler (File * suite);

/* FirstInFirstOut */
#define file_donnee(suite) suite->debut->donnee

/* Affiche la file */
extern void affiche(File *suite, SDL_Renderer *renderer);
#endif // FILE_H_INCLUDED
