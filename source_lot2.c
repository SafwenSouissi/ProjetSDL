#include"header_lot2.h"
void initBack(background* b,char* path){
	b->name=path;
	b->url=IMG_Load(b->name);
	if(b->url==NULL){
		printf("Pas d'image\n");
	}
	b->pos.x=0;
	b->pos.y=0;
	b->pos.w=b->url->w;
	b->pos.h=b->url->h;
}
void afficherBack(background b, SDL_Surface* screen,int x,int y){
//affich background(image et son qui change selon la difficulté / stage / nb vies  / diminution score / s'approche de l'ennemi / son lors de l'attaque ou du saut.. )
	b.pos.x=x;
	b.pos.y=y;
	SDL_BlitSurface(b.url,NULL,screen,&(b.pos));
}
void free_bg(background b){
	SDL_FreeSurface(b.url);
}
///////////////////////////////////////
/*void initilize_img(image* img,char* path,int x,int y){
	img->name=path;
	img->url=IMG_Load(img->name);
	if(img->url==NULL){
		printf("Pas d'image\n");
	}
	else{
		img->pos.x=x;
		img->pos.y=y;
	}
}
void afficher_image(SDL_Surface *surf,image img){
	SDL_BlitSurface(img.url,NULL,surf,&(img.pos));
}
void free_image(image img){
	SDL_FreeSurface(img.url);
}*/
///////////////////////////////////////
////////////////////////////////////////////////////
void initialiser_text(texte* text,char* font,float size,int r,int g,int b,int x,int y){
	text->font=TTF_OpenFont(font,size);
	text->color.r=r;
	text->color.g=g;
	text->color.b=b;
	text->pos.x=x;
	text->pos.y=y;
}
void afficher_text(SDL_Surface* screen,texte text,char* message){
	text.txt=TTF_RenderText_Blended(text.font,message,text.color);
	SDL_BlitSurface(text.txt,NULL,screen,&text.pos);
}
void free_text(texte text){
	TTF_CloseFont(text.font);//segmentation fault
}
//////////////////////////////////:
void scrolling(background* b,int up,int down,int r,int l,int x,int y){ //+scrolling haut et bas
	if(r==1){
		if((b->pos.x)>-11311){
			b->pos.x-=x;
		}
	}
	if(l==1){
		if((b->pos.x+x)<0){
			b->pos.x+=x;
		}
	}
	if(up==1){
		if((b->pos.y+y)<0){
			b->pos.y+=y;
		}
	}
	if(down==1){
		if((b->pos.y)>-50){
			b->pos.y-=y;
		}
	}
}
void scrolling_caractere(background b,character c,int up,int down,int r,int l,int *x,int *y){
	if(r==1){
		printf("pos: %d\n",*x);
		if(((*x)+c.actuelimage.url->w)<1600){
			(*x)+=20;
		}
		else{
			if(b.pos.x<=-11311 && (c.pos.x+c.actuelimage.url->w)<=1885){
				printf("in\n");
				(*x)+=5;
			}
		}
	}
	if(l==1){
		if((*x)>=10){
			(*x)-=20;
		}
		else{
			if(b.pos.x<=0 && (*x)>=0){
				(*x)-=5;
			}
		}
	}
	if(up==1){
		if((*y)>0){
			(*y)-=5;
		}
	}
	if(down==1){
		if((*y)<600){
			(*y)+=5;
		}
	}
}
void animerBack(background* b){}//-----------------------------------------------------
void saveScore(ScoreInfo s,char* filename){
	FILE* f=fopen(filename,"a");
	if(f==NULL){
		printf("Espace memoire insuffisant!!\n");
	}
	else{
		fprintf(f,"Nom:%s | Score:%d | Temps:%d \n",s.playername,s.score,s.temps);
		fclose(f);
	}
}
void bestScore(char* filename,ScoreInfo *t){
	char st[strlen(filename)+4];
	strcpy(st,strcat(filename,".txt"));
	FILE* f=fopen(filename,"r");
	int score,temps;
	char name[20];
	int i=0;
	if(f==NULL){
		printf("Espace memoire insuffisant!!\n");
	}
	else{
		while(!(feof(f))){
			t=(ScoreInfo*)realloc(t,(i+1)*sizeof(ScoreInfo));
			fscanf(f,"Nom:%s | Score:%d | Temps:%d \n",(t+i)->playername,&(t+i)->score,&(t+i)->temps);
			i++;
		}
		fclose(f);
	}
}
////////////////////////////////////////////////////////
void init_character(character* e,int x,int y)
{
	char string[30];
	e->pos.x=x;
	e->pos.y=y;
	e->health=100;
	e->frame=0;
	e->actuelimage.url=IMG_Load("v1.0/right/HERO/IDLE/1.png");
	for(int i=0;i<8;i++){
		sprintf(string,"v1.0/right/HERO/RUN/%d.png",i+1);
		e->RUN_R[i].url=IMG_Load(string);
		sprintf(string,"v1.0/left/HERO/RUN/%d.png",i+1);
		e->RUN_L[i].url=IMG_Load(string);
	}
	for(int i=0;i<2;i++){
		sprintf(string,"v1.0/right/HERO/ATTACK/%d.png",i+1);
		e->ATTACK_R[i].url=IMG_Load(string);
		sprintf(string,"v1.0/left/HERO/ATTACK/%d.png",i+1);
		e->ATTACK_L[i].url=IMG_Load(string);
	}
	for(int i=0;i<8;i++){
		sprintf(string,"v1.0/right/HERO/DEATH/%d.png",i+1);
		e->DEATH_R[i].url=IMG_Load(string);
		sprintf(string,"v1.0/left/HERO/DEATH/%d.png",i+1);
		e->DEATH_L[i].url=IMG_Load(string);
	}
	for(int i=0;7<i;i++){
		sprintf(string,"v1.0/right/HERO/JUMP/%d.png",i+1);
		e->JUMP_R[i].url=IMG_Load(string);
		sprintf(string,"v1.0/left/HERO/JUMP/%d.png",i+1);
		e->JUMP_L[i].url=IMG_Load(string);
	}
	for(int i=0;i<4;i++){
		sprintf(string,"v1.0/right/HERO/IDLE/%d.png",i+1);
		e->IDLE_R[i].url=IMG_Load(string);
		sprintf(string,"v1.0/left/HERO/IDLE/%d.png",i+1);
		e->IDLE_L[i].url=IMG_Load(string);
	}
	(*e).vitesse=10; //vitesse maximale
	(*e).acceleration=0; // acceleration intiale
	(*e).up=0; //pas de saut 
}
void afficher_character(SDL_Surface *surf,character *ch,int x,int y)
{
	ch->pos.x=x;
	ch->pos.y=y;
	SDL_BlitSurface(ch->actuelimage.url,NULL,surf,&(ch->pos));
}

void free_character(character ch)
{
	SDL_FreeSurface(ch.url);
}
