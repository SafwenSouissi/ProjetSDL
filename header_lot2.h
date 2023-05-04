#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<SDL/SDL.h>
#include<SDL/SDL_mixer.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#define SCREEN_W 1920 
#define SCREEN_H 1080
typedef struct{
int score;
int temps;
char playername[20];
}ScoreInfo;

typedef struct{
	SDL_Surface* url;
	SDL_Rect pos;
	char* name;
}background;
typedef struct{
	char *name;
	SDL_Surface *url;
	SDL_Rect pos;
}image;
typedef struct{
	SDL_Surface *txt;
	SDL_Rect pos;
	SDL_Color color;
	TTF_Font *font;
}texte;
typedef struct 
{
	char *name;
	SDL_Surface *url;
	SDL_Rect pos;
	float vitesse ;
	float acceleration;
	int up; 
	int health;
	ScoreInfo SI;
	int frame;
	int direction;
	image RUN_R[8];
	image ATTACK_R[4];
	image DEATH_R[14];
	image HIT_R[6];
	image IDLE_R[4];
	image JUMP_R[7];
	image RUN_L[8];
	image ATTACK_L[4];
	image DEATH_L[14];
	image HIT_L[6];
	image IDLE_L[4];
	image JUMP_L[7];
	image actuelimage;
	
}character;
void initBack(background* b,char* path);
void afficherBack(background b, SDL_Surface* screen,int x,int y);
void free_bg(background b);
void scrolling(background* b,int up,int down,int r,int l,int x,int y);
void scrolling_caractere (background b,character c,int up,int down,int r,int l,int *x,int *y);
void animerBack(background* b);
void saveScore(ScoreInfo s,char* filename);
void bestScore(char* filename,ScoreInfo t[]);
////////////////////////////////////////////////////
void init_character(character* ch,int x,int y);
void afficher_character(SDL_Surface *surf,character *ch,int x,int y);
void free_character(character ch);
///////////////////////////////////////
void initilize_img(image* img,char* path,int x,int y);
void afficher_image(SDL_Surface *surf,image img);
void free_image(image img);
////////////////////////////////////////////////////
void initialiser_text(texte* text,char* font,float size,int r,int g,int b,int x,int y);
void afficher_text(SDL_Surface* screen,texte text,char* message);
void free_text(texte text);












