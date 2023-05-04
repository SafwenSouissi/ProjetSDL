#include"header_lot2.h"
void main(){
	int end=1;
	int attack=0;
	int x=10,y=500;
	int d=2;
	int r=0;
	int l=0;
	int up=0;
	int down=0;
	int ri=1;
	ScoreInfo s;
	strcpy(s.playername,"player1");
	s.temps=0;
	s.score=0;
	background b;
	image lb,lb2,bg2;
	character e1,e2,e3,e4,e5,e6;
	SDL_Surface* screen;
	SDL_Event e;
	int score=0;
	TTF_Init();
	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER)==-1){
		printf("Coundn't initialise\n");
	}
	else{
		screen=SDL_SetVideoMode(SCREEN_W,SCREEN_H,32,SDL_HWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF);
		initBack(&b,"v1.0/map/2.png");
		initilize_img(&lb,"leaderboard.png",0,0);
		initilize_img(&bg2,"bg2.jpg",0,0);
		initilize_img(&lb2,"lb.png",SCREEN_W/2-100,SCREEN_H/2-100);
		init_character(&e1,"v1.0/HERO/RUN/1.png",x,y);
		init_character(&e2,"v1.0/HERO/RUN/2.png",x,y);
		init_character(&e3,"v1.0/HERO/RUN/3.png",x,y);
		init_character(&e4,"v1.0/HERO/RUN/4.png",x,y);
		init_character(&e5,"v1.0/HERO/RUN/5.png",x,y);
		init_character(&e6,"v1.0/HERO/RUN/6.png",x,y);
		while(end==1){
			afficherBack(b,screen,b.pos.x,b.pos.y);
			afficher_image(screen,lb);
			if(e.motion.x<200 && e.motion.x>0 && e.motion.y<200 && e.motion.y>0 && e.type==SDL_MOUSEBUTTONDOWN){
				score=0;
				while(score==0){
					afficher_image(screen,bg2);
					afficher_image(screen,lb2);
					SDL_Flip(screen);
					if(e.type==SDL_KEYUP && e.key.keysym.sym==SDLK_ESCAPE){
						score=1;
					}
				}
			}
			if(ri==1){
				afficher_character(screen,e4,x,y);
			}
			else{
				afficher_character(screen,e1,x,y);
			}
			SDL_Flip(screen);
			if(r==1){
				scrolling (&b,up,down,r,l,20,10);
				scrolling_caractere(b,e1,up,down,r,l,&x,&y);
				/*if((x+e1.url->w)<1700){
					x+=10;
				}
				else{
					if(b.pos.x==-1920 && (x+e1.url->w)<1750){
						x+=5;
					}
				}*/
				/*afficher_character(screen,e4,x,y);
				SDL_Delay(2);
				SDL_Flip(screen);
				afficher_character(screen,e5,x,y);
				SDL_Delay(2);
				SDL_Flip(screen);
				afficher_character(screen,e6,x,y);
				SDL_Delay(2);
				SDL_Flip(screen);*/
			}
			if(l==1){
				scrolling (&b,up,down,r,l,20,10);
				scrolling_caractere(b,e1,up,down,r,l,&x,&y);
				/*afficher_character(screen,e1,x,y);
				SDL_Delay(20);
				SDL_Flip(screen);
				afficher_character(screen,e2,x,y);
				SDL_Delay(20);
				SDL_Flip(screen);
				afficher_character(screen,e3,x,y);				
				SDL_Delay(20);
				SDL_Flip(screen);*/
			}
			if(up==1){
				scrolling_caractere(b,e1,up,down,r,l,&x,&y);
			}
			if(down==1){
				scrolling_caractere(b,e1,up,down,r,l,&x,&y);
			}
			SDL_Flip(screen);
			while(SDL_PollEvent(&e)){
				switch(e.type){
					case SDL_KEYDOWN:{
						switch(e.key.keysym.sym){
							case SDLK_RIGHT:{
								d=0;
								r=1;
								break;
							}
							case SDLK_LEFT:{
								l=1;
								d=1;
								break;
							}
							case SDLK_UP:{
								d=2;
								up=1;
								break;
							}
							case SDLK_DOWN:{
								d=3;
								down=1;
								break;
							}
							case SDLK_ESCAPE:{
								end=0;
								break;
							}
						}
						break;
					}
					case SDL_KEYUP:{
						s.score+=10;
						switch(e.key.keysym.sym){
							case SDLK_RIGHT:{
								r=0;
								ri=1;
								break;
							}
							case SDLK_LEFT:{
								ri=0;
								l=0;
								break;
							}
							case SDLK_UP:{
								up=0;
								break;
							}
							case SDLK_DOWN:{
								down=0;
								break;
							}
							case SDLK_ESCAPE:{
								end=0;
								break;
							}
						}
						break;
					}
					case SDL_QUIT:{
						end=0;
						break;
					}
				}
			}
		}
		saveScore(s,"meilleur score");
		
	}
}
