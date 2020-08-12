#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<graphics.h>
#include<math.h>
#include<time.h>
/*
By: Yoyo and Joraso
Arturo Arellano Bautista
and 
Jose Ramon Solorzano Roa
*/
enum dir{
	esc = 27,
	up = 72,
	left = 75,
	derecha = 77,
	down = 80,
	enter = 13,
	n1 = 49,
	n2 = 50,
	n3 = 51,
	n4,
	n5,
	n6,
	n7,
	n8,
	n9,	
};
void pared(int x,int y,int tiempo){
	int rec[10];
	rec[0] = x;
	rec[1] = y;
	rec[2] = x+250;
	rec[3] = y;
	rec[4] = x+250;
	rec[5] = y+600;
	rec[6] = x;
	rec[7] = y+600;
	rec[8] = x;
	rec[9] = y;
	
	setcolor(WHITE);
	setfillstyle(1,6);
	fillpoly(4,rec);
	//rectangle(x,y,x+250,y+600);
	int x0,y0;
	
	
	if (tiempo == 1){
		y-=50;
	}
	
	for(y0=tiempo;y0<(12+tiempo);y0++){
		for(x0=0;x0<=150;x0+=100){
			if((y0%2 == 1)and(x0 == 0)){
				x0+=50;
			}
			rectangle(x+x0,y+(y0*50),x+x0+100,y+50+(y0*50));
		}
	}
}

void muro(int tiempo){
	pared(50,50,tiempo);
	pared(800,50,!tiempo);
	rectangle(50,50,800,650);	
	int rec[10];
	int x=300,y=50;
	rec[0] = x;
	rec[1] = y;
	rec[2] = 800;
	rec[3] = y;
	rec[4] = 800;
	rec[5] = y+600;
	rec[6] = x;
	rec[7] = y+600;
	rec[8] = x;
	rec[9] = y;
	
	setcolor(WHITE);
	setfillstyle(1,9);
	fillpoly(4,rec);
}

void granpantalla(){
	int x,y;
	setfillstyle(1,RED);
	setcolor(BLUE);
	setbkcolor(RED);
	x = getmaxx();
	y = getmaxy();
	int prove = 0;
	settextstyle(1,0,3);
	int rec[10]={50,50,400,50,400,200,50,200,50,50};
	while((x < 1050) or (y < 650)){
		prove = 1;
		x = getmaxx();
		y = getmaxy();
		fillpoly(4,rec);
		outtextxy(50,50,"Por favor");
		outtextxy(50,100,"Pon Pantalla Completa");
		outtextxy(50,150,"Esc para continuar");
		circle(1050,650,10);
		getch();
		//Sleep(1000);
	}
	
	setbkcolor(BLACK);
	
	if(prove){
	cleardevice();
	}
}
typedef struct hitbox{
	int x,y,activo,tipo;
}gamer;


void dibujaGallina(gamer gallina, int tiempo,int dir)
{
	setbkcolor(BLACK);
    setcolor(WHITE);
    if (dir == 0){
    	{//CRESTA 0
		setcolor(RED);
		setfillstyle(1, RED); 
		fillellipse(gallina.x-28, gallina.y-30, 7, 8);
		fillellipse(gallina.x-18, gallina.y-33, 7, 8);
		fillellipse(gallina.x-9, gallina.y-30, 7, 8);
		}
		{//PICO 0
		setcolor(YELLOW);
		int vec0[6];
		vec0[0]=gallina.x-48;
		vec0[1]=gallina.y-14;
		vec0[2]=gallina.x-36;
		vec0[3]=gallina.y-7;
		vec0[4]=gallina.x-34;
		vec0[5]=gallina.y-17;
		setfillstyle(1, YELLOW);
		fillpoly(3, vec0);
		}
		{//CUERPO 0
		setcolor(WHITE);
		setfillstyle(1, WHITE);
		fillellipse(gallina.x-21, gallina.y-15, 16, 16);
		fillellipse(gallina.x+4, gallina.y+17, 38, 28);
		fillellipse(gallina.x-30, gallina.y, 8, 28);
		fillellipse(gallina.x+35, gallina.y+2, 8, 8);
		fillellipse(gallina.x+33, gallina.y-5, 8, 8);
		int vec1[6];
		vec1[0]=gallina.x+36;
		vec1[1]=gallina.y-12;
		vec1[2]=gallina.x+10;
		vec1[3]=gallina.y-10;
		vec1[4]=gallina.x+22;
		vec1[5]=gallina.y;
		setfillstyle(1, WHITE);
		fillpoly(3, vec1);
		int vec2[6];
		vec2[0]=gallina.x+43;
		vec2[1]=gallina.y+5;
		vec2[2]=gallina.x+40;
		vec2[3]=gallina.y+15;
		vec2[4]=gallina.x+35;
		vec2[5]=gallina.y+10;
		setfillstyle(1, WHITE);
		fillpoly(3, vec2);
		}
		{//BARBILLA 0
		setcolor(RED);
		setfillstyle(1, RED);
		fillellipse(gallina.x-42, gallina.y+2, 3, 3);
		fillellipse(gallina.x-36, gallina.y+2, 3, 3);
		int vec[6];
		vec[0]=gallina.x-44;
		vec[1]=gallina.y+1;
		vec[2]=gallina.x-34;
		vec[3]=gallina.y+1;
		vec[4]=gallina.x-39;
		vec[5]=gallina.y-9;
		setfillstyle(1, RED);
		fillpoly(3, vec);
		}
		{//ALA 0
		setcolor(BLACK);
		arc(gallina.x+1, gallina.y+7, 180, 350, 21);
		arc(gallina.x+18, gallina.y+5, 250, 60, 8);
		arc(gallina.x+17, gallina.y+2, 260, 65, 7);
		}
		{//OJO 0
		setcolor(BLACK);
		setfillstyle(1, WHITE);
		fillellipse(gallina.x-30, gallina.y-17, 5, 5);
		setfillstyle(1, BLACK);
		fillellipse(gallina.x-32, gallina.y-17, 3, 5);
		}
	}
    if(tiempo==0 && dir == 3)
    {
    	{//CRESTA 0
		setcolor(RED);
		setfillstyle(1, RED); 
		fillellipse(gallina.x-28, gallina.y-30, 7, 8);
		fillellipse(gallina.x-18, gallina.y-33, 7, 8);
		fillellipse(gallina.x-9, gallina.y-30, 7, 8);
		}
		{//PICO 0
		setcolor(YELLOW);
		int vec0[6];
		vec0[0]=gallina.x-48;
		vec0[1]=gallina.y-14;
		vec0[2]=gallina.x-36;
		vec0[3]=gallina.y-7;
		vec0[4]=gallina.x-34;
		vec0[5]=gallina.y-17;
		setfillstyle(1, YELLOW);
		fillpoly(3, vec0);
		}
		{//CUERPO 0
		setcolor(WHITE);
		setfillstyle(1, WHITE);
		fillellipse(gallina.x-21, gallina.y-15, 16, 16);
		fillellipse(gallina.x+4, gallina.y+17, 38, 28);
		fillellipse(gallina.x-30, gallina.y, 8, 28);
		fillellipse(gallina.x+35, gallina.y+2, 8, 8);
		fillellipse(gallina.x+33, gallina.y-5, 8, 8);
		int vec1[6];
		vec1[0]=gallina.x+36;
		vec1[1]=gallina.y-12;
		vec1[2]=gallina.x+10;
		vec1[3]=gallina.y-10;
		vec1[4]=gallina.x+22;
		vec1[5]=gallina.y;
		setfillstyle(1, WHITE);
		fillpoly(3, vec1);
		int vec2[6];
		vec2[0]=gallina.x+43;
		vec2[1]=gallina.y+5;
		vec2[2]=gallina.x+40;
		vec2[3]=gallina.y+15;
		vec2[4]=gallina.x+35;
		vec2[5]=gallina.y+10;
		setfillstyle(1, WHITE);
		fillpoly(3, vec2);
		}
		{//BARBILLA 0
		setcolor(RED);
		setfillstyle(1, RED);
		fillellipse(gallina.x-42, gallina.y+2, 3, 3);
		fillellipse(gallina.x-36, gallina.y+2, 3, 3);
		int vec[6];
		vec[0]=gallina.x-44;
		vec[1]=gallina.y+1;
		vec[2]=gallina.x-34;
		vec[3]=gallina.y+1;
		vec[4]=gallina.x-39;
		vec[5]=gallina.y-9;
		setfillstyle(1, RED);
		fillpoly(3, vec);
		}
		{//ALA 0
		setcolor(BLACK);
		arc(gallina.x+1, gallina.y+7, 180, 350, 21);
		arc(gallina.x+18, gallina.y+5, 250, 60, 8);
		arc(gallina.x+17, gallina.y+2, 260, 65, 7);
		}
		{//OJO 0
		setcolor(BLACK);
		setfillstyle(1, WHITE);
		fillellipse(gallina.x-30, gallina.y-17, 5, 5);
		setfillstyle(1, BLACK);
		fillellipse(gallina.x-32, gallina.y-17, 3, 5);
		}
	}else
		{
			if(tiempo==1 && dir == 3)
			{
				{//CRESTA 1 
				setcolor(RED);
				setfillstyle(1, RED); 
				fillellipse(gallina.x-28, gallina.y-30, 7, 8);
				fillellipse(gallina.x-18, gallina.y-33, 7, 8);
				fillellipse(gallina.x-9, gallina.y-30, 7, 8);
				}
				{//PICO 1
				setcolor(YELLOW);
				int vec0[6];
				vec0[0]=gallina.x-48;
				vec0[1]=gallina.y-14;
				vec0[2]=gallina.x-36;
				vec0[3]=gallina.y-7;
				vec0[4]=gallina.x-34;
				vec0[5]=gallina.y-17;
				setfillstyle(1, YELLOW);
				fillpoly(3, vec0);
				}
				{//CUERPO 1
				setcolor(WHITE);
				setfillstyle(1, WHITE);
				fillellipse(gallina.x-21, gallina.y-15, 16, 16);
				fillellipse(gallina.x+4, gallina.y+17, 38, 28);
				fillellipse(gallina.x-30, gallina.y, 8, 28);
				fillellipse(gallina.x+35, gallina.y+2, 8, 8);
				int vec2[6];
				vec2[0]=gallina.x+43;
				vec2[1]=gallina.y+5;
				vec2[2]=gallina.x+40;
				vec2[3]=gallina.y+15;
				vec2[4]=gallina.x+35;
				vec2[5]=gallina.y+10;
				setfillstyle(1, WHITE);
				fillpoly(3, vec2);
				}
				{//BARBILLA 1
				setcolor(RED);
				setfillstyle(1, RED);
				fillellipse(gallina.x-42, gallina.y+2, 3, 3);
				fillellipse(gallina.x-36, gallina.y+2, 3, 3);
				int vec[6];
				vec[0]=gallina.x-44;
				vec[1]=gallina.y+1;
				vec[2]=gallina.x-34;
				vec[3]=gallina.y+1;
				vec[4]=gallina.x-39;
				vec[5]=gallina.y-9;
				setfillstyle(1, RED);
				fillpoly(3, vec);
				}
				{//ALA 1
				setcolor(BLACK);
				setfillstyle(1, WHITE);
				fillellipse(gallina.x+30, gallina.y-19, 8, 4);	
				fillellipse(gallina.x+34, gallina.y-15, 8, 4);	
				fillellipse(gallina.x+34, gallina.y-10, 8, 4);	
				fillellipse(gallina.x+32, gallina.y-5, 8, 4);	
				fillellipse(gallina.x+28, gallina.y, 8, 4);	
				setcolor(WHITE);
				setfillstyle(1, WHITE);
				fillellipse(gallina.x+15, gallina.y-8, 20, 15);
				int vec1[6];
				vec1[0]=gallina.x+29;
				vec1[1]=gallina.y-23;
				vec1[2]=gallina.x+17;
				vec1[3]=gallina.y-22;
				vec1[4]=gallina.x+20;
				vec1[5]=gallina.y-10;
				setfillstyle(1, WHITE);
				fillpoly(3, vec1);
				}
				{//OJO 1
				setcolor(BLACK);
				setfillstyle(1, WHITE);
				fillellipse(gallina.x-30, gallina.y-17, 5, 5);
				setfillstyle(1, BLACK);
				fillellipse(gallina.x-32, gallina.y-17, 3, 5);
				}	
			}else{
				if(tiempo==0 && dir==4)
				{
					{//CRESTA 2
					setcolor(RED);
					setfillstyle(1, RED); 
					fillellipse(gallina.x-28*(-1), gallina.y-30, 7, 8);
					fillellipse(gallina.x-18*(-1), gallina.y-33, 7, 8);
					fillellipse(gallina.x-9*(-1), gallina.y-30, 7, 8);
					}
					{//PICO 2
					setcolor(YELLOW);
					int vec0[6];
					vec0[0]=gallina.x-48*(-1);
					vec0[1]=gallina.y-14;
					vec0[2]=gallina.x-36*(-1);
					vec0[3]=gallina.y-7;
					vec0[4]=gallina.x-34*(-1);
					vec0[5]=gallina.y-17;
					setfillstyle(1, YELLOW);
					fillpoly(3, vec0);
					}
					{//CUERPO 2
					setcolor(WHITE);
					setfillstyle(1, WHITE);
					fillellipse(gallina.x-21*(-1), gallina.y-15, 16, 16);
					fillellipse(gallina.x+4*(-1), gallina.y+17, 38, 28);
					fillellipse(gallina.x-30*(-1), gallina.y, 8, 28);
					fillellipse(gallina.x+35*(-1), gallina.y+2, 8, 8);
					int vec2[6];
					vec2[0]=gallina.x+43*(-1);
					vec2[1]=gallina.y+5;
					vec2[2]=gallina.x+40*(-1);
					vec2[3]=gallina.y+15;
					vec2[4]=gallina.x+35*(-1);
					vec2[5]=gallina.y+10;
					setfillstyle(1, WHITE);
					fillpoly(3, vec2);
					}
					{//BARBILLA 2
					setcolor(RED);
					setfillstyle(1, RED);
					fillellipse(gallina.x-42*(-1), gallina.y+2, 3, 3);
					fillellipse(gallina.x-36*(-1), gallina.y+2, 3, 3);
					int vec[6];
					vec[0]=gallina.x-44*(-1);
					vec[1]=gallina.y+1;
					vec[2]=gallina.x-34*(-1);
					vec[3]=gallina.y+1;
					vec[4]=gallina.x-39*(-1);
					vec[5]=gallina.y-9;
					setfillstyle(1, RED);
					fillpoly(3, vec);
					}
					{//ALA 2
					setcolor(BLACK);
					setfillstyle(1, WHITE);
					fillellipse(gallina.x+30*(-1), gallina.y-19, 8, 4);	
					fillellipse(gallina.x+34*(-1), gallina.y-15, 8, 4);	
					fillellipse(gallina.x+34*(-1), gallina.y-10, 8, 4);	
					fillellipse(gallina.x+32*(-1), gallina.y-5, 8, 4);	
					fillellipse(gallina.x+28*(-1), gallina.y, 8, 4);	
					setcolor(WHITE);
					setfillstyle(1, WHITE);
					fillellipse(gallina.x+15*(-1), gallina.y-8, 20, 15);
					int vec1[6];
					vec1[0]=gallina.x+29*(-1);
					vec1[1]=gallina.y-23;
					vec1[2]=gallina.x+17*(-1);
					vec1[3]=gallina.y-22;
					vec1[4]=gallina.x+20*(-1);
					vec1[5]=gallina.y-10;
					setfillstyle(1, WHITE);
					fillpoly(3, vec1);	
					}
					{//OJO 2
					setcolor(BLACK);
					setfillstyle(1, WHITE);
					fillellipse(gallina.x-30*(-1), gallina.y-17, 5, 5);
					setfillstyle(1, BLACK);
					fillellipse(gallina.x-32*(-1), gallina.y-17, 3, 5);
					}	
				}else{
					if(tiempo==1 && dir==4)
					{
						{//CRESTA 3
						setcolor(RED);
						setfillstyle(1, RED); 
						fillellipse(gallina.x-28*(-1), gallina.y-30, 7, 8);
						fillellipse(gallina.x-18*(-1), gallina.y-33, 7, 8);
						fillellipse(gallina.x-9*(-1), gallina.y-30, 7, 8);
						}
						{//PICO 3
						setcolor(YELLOW);
						int vec0[6];
						vec0[0]=gallina.x-48*(-1);
						vec0[1]=gallina.y-14;
						vec0[2]=gallina.x-36*(-1);
						vec0[3]=gallina.y-7;
						vec0[4]=gallina.x-34*(-1);
						vec0[5]=gallina.y-17;
						setfillstyle(1, YELLOW);
						fillpoly(3, vec0);
						}
						{//CUERPO 3
						setcolor(WHITE);
						setfillstyle(1, WHITE);
						fillellipse(gallina.x-21*(-1), gallina.y-15, 16, 16);
						fillellipse(gallina.x+4*(-1), gallina.y+17, 38, 28);
						fillellipse(gallina.x-30*(-1), gallina.y, 8, 28);
						fillellipse(gallina.x+35*(-1), gallina.y+2, 8, 8);
						fillellipse(gallina.x+33*(-1), gallina.y-5, 8, 8);
						int vec1[6];
						vec1[0]=gallina.x+36*(-1);
						vec1[1]=gallina.y-12;
						vec1[2]=gallina.x+10*(-1);
						vec1[3]=gallina.y-10;
						vec1[4]=gallina.x+22*(-1);
						vec1[5]=gallina.y;
						setfillstyle(1, WHITE);
						fillpoly(3, vec1);
						int vec2[6];
						vec2[0]=gallina.x+43*(-1);
						vec2[1]=gallina.y+5;
						vec2[2]=gallina.x+40*(-1);
						vec2[3]=gallina.y+15;
						vec2[4]=gallina.x+35*(-1);
						vec2[5]=gallina.y+10;
						setfillstyle(1, WHITE);
						fillpoly(3, vec2);
						}
						{//BARBILLA 3
						setcolor(RED);
						setfillstyle(1, RED);
						fillellipse(gallina.x-42*(-1), gallina.y+2, 3, 3);
						fillellipse(gallina.x-36*(-1), gallina.y+2, 3, 3);
						int vec[6];
						vec[0]=gallina.x-44*(-1);
						vec[1]=gallina.y+1;
						vec[2]=gallina.x-34*(-1);
						vec[3]=gallina.y+1;
						vec[4]=gallina.x-39*(-1);
						vec[5]=gallina.y-9;
						setfillstyle(1, RED);
						fillpoly(3, vec);
						}
						{//ALA 3
						setcolor(BLACK);
						arc(gallina.x+1*(-1), gallina.y+7, 190, 360, 21);
						arc(gallina.x+18*(-1), gallina.y+5, 150, 280, 8);
						arc(gallina.x+17*(-1), gallina.y+2, 110, 275, 7);	
						}
						{//OJO 3
						setcolor(BLACK);
						setfillstyle(1, WHITE);
						fillellipse(gallina.x-30*(-1), gallina.y-17, 5, 5);
						setfillstyle(1, BLACK);
						fillellipse(gallina.x-32*(-1), gallina.y-17, 3, 5);
						}
					}
				}
			}
		}
	
	
}

//skins

//int cf=0;

void chiken(gamer gallina, int tiempo,int dir)
{
	setbkcolor(0);
    setcolor(15);
    if (dir == 0){
    	{//CRESTA 0
		setcolor(4);
		setfillstyle(1, 4); 
		fillellipse(gallina.x-28, gallina.y-30, 7, 8);
		fillellipse(gallina.x-18, gallina.y-33, 7, 8);
		fillellipse(gallina.x-9, gallina.y-30, 7, 8);
		//PICO 0
		setcolor(14);
		setfillstyle(1, 14);
		int vec0[6]={gallina.x-48,gallina.y-14,gallina.x-36,gallina.y-7,gallina.x-34,gallina.y-17};
		fillpoly(3, vec0);
		//CUERPO 0
		setcolor(15);
		setfillstyle(1, 15);
		fillellipse(gallina.x-21, gallina.y-15, 16, 16);
		fillellipse(gallina.x+4, gallina.y+17, 38, 28);
		fillellipse(gallina.x-30, gallina.y, 8, 28);
		fillellipse(gallina.x+35, gallina.y+2, 8, 8);
		fillellipse(gallina.x+33, gallina.y-5, 8, 8);
		int vec1[6]={gallina.x+36,gallina.y-12,gallina.x+10,gallina.y-10,gallina.x+22,gallina.y};
		int vec2[6]{gallina.x+43,gallina.y+5,gallina.x+40,gallina.y+15,gallina.x+35,gallina.y+10};
		fillpoly(3, vec1);
		fillpoly(3, vec2);
		//BARBILLA 0
		setcolor(4);
		setfillstyle(1, 4);
		fillellipse(gallina.x-42, gallina.y+2, 3, 3);
		fillellipse(gallina.x-36, gallina.y+2, 3, 3);
		int vec[6]{gallina.x-44,gallina.y+1,gallina.x-34,gallina.y+1,gallina.x-39,gallina.y-9};
		fillpoly(3, vec);
		//ALA 0
		setcolor(0);
		arc(gallina.x+1, gallina.y+7, 180, 350, 21);
		arc(gallina.x+18, gallina.y+5, 250, 60, 8);
		arc(gallina.x+17, gallina.y+2, 260, 65, 7);
		//OJO 0
		setcolor(0);
		setfillstyle(1, 15);
		fillellipse(gallina.x-30, gallina.y-17, 5, 5);
		setfillstyle(1, 0);
		fillellipse(gallina.x-32, gallina.y-17, 3, 5);
		}
	}
    if(tiempo==0 && dir == 3)
    {
		{//CRESTA 0
		setcolor(4);
		setfillstyle(1, 4); 
		fillellipse(gallina.x-28, gallina.y-30, 7, 8);
		fillellipse(gallina.x-18, gallina.y-33, 7, 8);
		fillellipse(gallina.x-9, gallina.y-30, 7, 8);
		//PICO 0
		setcolor(14);
		setfillstyle(1, 14);
		int vec0[6]={gallina.x-48,gallina.y-14,gallina.x-36,gallina.y-7,gallina.x-34,gallina.y-17};
		fillpoly(3, vec0);
		//CUERPO 0
		setcolor(15);
		setfillstyle(1, 15);
		fillellipse(gallina.x-21, gallina.y-15, 16, 16);
		fillellipse(gallina.x+4, gallina.y+17, 38, 28);
		fillellipse(gallina.x-30, gallina.y, 8, 28);
		fillellipse(gallina.x+35, gallina.y+2, 8, 8);
		fillellipse(gallina.x+33, gallina.y-5, 8, 8);
		int vec1[6]={gallina.x+36,gallina.y-12,gallina.x+10,gallina.y-10,gallina.x+22,gallina.y};
		int vec2[6]{gallina.x+43,gallina.y+5,gallina.x+40,gallina.y+15,gallina.x+35,gallina.y+10};
		fillpoly(3, vec1);
		fillpoly(3, vec2);
		//BARBILLA 0
		setcolor(4);
		setfillstyle(1, 4);
		fillellipse(gallina.x-42, gallina.y+2, 3, 3);
		fillellipse(gallina.x-36, gallina.y+2, 3, 3);
		int vec[6]{gallina.x-44,gallina.y+1,gallina.x-34,gallina.y+1,gallina.x-39,gallina.y-9};
		fillpoly(3, vec);
		//ALA 0
		setcolor(0);
		arc(gallina.x+1, gallina.y+7, 180, 350, 21);
		arc(gallina.x+18, gallina.y+5, 250, 60, 8);
		arc(gallina.x+17, gallina.y+2, 260, 65, 7);
		//OJO 0
		setcolor(0);
		setfillstyle(1, 15);
		fillellipse(gallina.x-30, gallina.y-17, 5, 5);
		setfillstyle(1, 0);
		fillellipse(gallina.x-32, gallina.y-17, 3, 5);
		}
	}else
		{
			if(tiempo==1 && dir == 3)
			{
				{//CRESTA 1 
				setcolor(4);
				setfillstyle(1, 4); 
				fillellipse(gallina.x-28, gallina.y-30, 7, 8);
				fillellipse(gallina.x-18, gallina.y-33, 7, 8);
				fillellipse(gallina.x-9, gallina.y-30, 7, 8);
				//PICO 1
				setcolor(14);
				int vec0[6]={gallina.x-48,gallina.y-14,gallina.x-36,gallina.y-7,gallina.x-34,gallina.y-17};
				setfillstyle(1, 14);
				fillpoly(3, vec0);
				//CUERPO 1
				setcolor(15);
				setfillstyle(1, 15);
				fillellipse(gallina.x-21, gallina.y-15, 16, 16);
				fillellipse(gallina.x+4, gallina.y+17, 38, 28);
				fillellipse(gallina.x-30, gallina.y, 8, 28);
				fillellipse(gallina.x+35, gallina.y+2, 8, 8);
				fillellipse(gallina.x+33, gallina.y-5, 8, 8);
				int vec1[6]={gallina.x+36,gallina.y-12,gallina.x+10,gallina.y-10,gallina.x+22,gallina.y};
				int vec2[6]{gallina.x+43,gallina.y+5,gallina.x+40,gallina.y+15,gallina.x+35,gallina.y+10};
				fillpoly(3, vec1);
				fillpoly(3, vec2);
				//BARBILLA 1
				setcolor(4);
				setfillstyle(1, 4);
				fillellipse(gallina.x-42, gallina.y+2, 3, 3);
				fillellipse(gallina.x-36, gallina.y+2, 3, 3);
				int vec[6]{gallina.x-44,gallina.y+1,gallina.x-34,gallina.y+1,gallina.x-39,gallina.y-9};
				fillpoly(3, vec);
				//ALA 1
				setcolor(0);
				setfillstyle(1, 15);
				fillellipse(gallina.x+30, gallina.y-19, 8, 4);	
				fillellipse(gallina.x+34, gallina.y-15, 8, 4);	
				fillellipse(gallina.x+34, gallina.y-10, 8, 4);	
				fillellipse(gallina.x+32, gallina.y-5, 8, 4);	
				fillellipse(gallina.x+28, gallina.y, 8, 4);	
				setcolor(15);
				fillellipse(gallina.x+15, gallina.y-8, 20, 15);
				int vec10[6]={gallina.x+29,gallina.y-23,gallina.x+17,gallina.y-22,gallina.x+20,gallina.y-10};
				fillpoly(3, vec10);
				//OJO 1
				setcolor(0);
				setfillstyle(1, 15);
//The Cake is a Lie
				fillellipse(gallina.x-30, gallina.y-17, 5, 5);
				setfillstyle(1, 0);
				fillellipse(gallina.x-32, gallina.y-17, 3, 5);
				}	
			}else{
				if(tiempo==0 && dir==4)
				{
					{//CRESTA 2
					setcolor(4);
					setfillstyle(1, 4); 
					fillellipse(gallina.x-28*(-1), gallina.y-30, 7, 8);
					fillellipse(gallina.x-18*(-1), gallina.y-33, 7, 8);
					fillellipse(gallina.x-9*(-1), gallina.y-30, 7, 8);
					//PICO 2
					setcolor(14);
					int vec0[6]={gallina.x-48*(-1),gallina.y-14,gallina.x-36*(-1),gallina.y-7,gallina.x-34*(-1),gallina.y-17};
					setfillstyle(1, 14);
					fillpoly(3, vec0);
					//CUERPO 2
					setcolor(15);
					setfillstyle(1, 15);
					fillellipse(gallina.x-21*(-1), gallina.y-15, 16, 16);
					fillellipse(gallina.x+4*(-1), gallina.y+17, 38, 28);
					fillellipse(gallina.x-30*(-1), gallina.y, 8, 28);
					fillellipse(gallina.x+35*(-1), gallina.y+2, 8, 8);
					int vec2[6]={gallina.x+43*(-1),gallina.y+5,gallina.x+40*(-1),gallina.y+15,gallina.x+35*(-1),gallina.y+10};
					fillpoly(3, vec2);
					//BARBILLA 2
					setcolor(4);
					setfillstyle(1, 4);
					fillellipse(gallina.x-42*(-1), gallina.y+2, 3, 3);
					fillellipse(gallina.x-36*(-1), gallina.y+2, 3, 3);
					int vec[6]={gallina.x-44*(-1),gallina.y+1,gallina.x-34*(-1),gallina.y+1,gallina.x-39*(-1),gallina.y-9};
					fillpoly(3, vec);
					//ALA 2
					setcolor(0);
					setfillstyle(1, 15);
					fillellipse(gallina.x+30*(-1), gallina.y-19, 8, 4);	
					fillellipse(gallina.x+34*(-1), gallina.y-15, 8, 4);	
					fillellipse(gallina.x+34*(-1), gallina.y-10, 8, 4);	
					fillellipse(gallina.x+32*(-1), gallina.y-5, 8, 4);	
					fillellipse(gallina.x+28*(-1), gallina.y, 8, 4);	
					setcolor(15);
					fillellipse(gallina.x+15*(-1), gallina.y-8, 20, 15);
					int vec1[6]={gallina.x+29*(-1),gallina.y-23,gallina.x+17*(-1),gallina.y-22,gallina.x+20*(-1),gallina.y-10};
					fillpoly(3, vec1);
					//OJO 2
					setcolor(0);
					setfillstyle(1, 15);
					fillellipse(gallina.x-30*(-1), gallina.y-17, 5, 5);
					setfillstyle(1, 0);
					fillellipse(gallina.x-32*(-1), gallina.y-17, 3, 5);
					}	
				}else{
					if(tiempo==1 && dir==4)
					{
						{//CRESTA 3
						setcolor(4);
						setfillstyle(1, 4); 
						fillellipse(gallina.x-28*(-1), gallina.y-30, 7, 8);
						fillellipse(gallina.x-18*(-1), gallina.y-33, 7, 8);
						fillellipse(gallina.x-9*(-1), gallina.y-30, 7, 8);
						//PICO 3
						setcolor(14);
						int vec0[6]={gallina.x-48*(-1),gallina.y-14,gallina.x-36*(-1),gallina.y-7,gallina.x-34*(-1),gallina.y-17};
						setfillstyle(1, 14);
						fillpoly(3, vec0);
						//CUERPO 3
						setcolor(15);
						setfillstyle(1, 15);
						fillellipse(gallina.x-21*(-1), gallina.y-15, 16, 16);
						fillellipse(gallina.x+4*(-1), gallina.y+17, 38, 28);
						fillellipse(gallina.x-30*(-1), gallina.y, 8, 28);
						fillellipse(gallina.x+35*(-1), gallina.y+2, 8, 8);
						fillellipse(gallina.x+33*(-1), gallina.y-5, 8, 8);
						int vec1[6]={gallina.x+36*(-1),gallina.y-12,gallina.x+10*(-1),gallina.y-10,gallina.x+22*(-1),gallina.y};
						int vec2[6]={gallina.x+43*(-1),gallina.y+5,gallina.x+40*(-1),gallina.y+15,gallina.x+35*(-1),gallina.y+10};
						fillpoly(3, vec1);
						fillpoly(3, vec2);
						//BARBILLA 3
						setcolor(4);
						setfillstyle(1, 4);
						fillellipse(gallina.x-42*(-1), gallina.y+2, 3, 3);
						fillellipse(gallina.x-36*(-1), gallina.y+2, 3, 3);
						int vec[6]={gallina.x-44*(-1),gallina.y+1,gallina.x-34*(-1),gallina.y+1,gallina.x-39*(-1),gallina.y-9};
						fillpoly(3, vec);
						//ALA 3
						setcolor(0);
						arc(gallina.x+1*(-1), gallina.y+7, 190, 360, 21);
						arc(gallina.x+18*(-1), gallina.y+5, 150, 280, 8);
						arc(gallina.x+17*(-1), gallina.y+2, 110, 275, 7);	
						//OJO 3
						setcolor(0);
						setfillstyle(1, 15);
						fillellipse(gallina.x-30*(-1), gallina.y-17, 5, 5);
						setfillstyle(1, 0);
						fillellipse(gallina.x-32*(-1), gallina.y-17, 3, 5);
						}
					}
				}
			}
		}
	
	
}

void goldchik(gamer gallina, int tiempo,int dir)
{
	setbkcolor(BLACK);
    setcolor(WHITE);
    if (dir == 0){
    	{//CRESTA 0
		setcolor(RED);
		setfillstyle(1, RED); 
		fillellipse(gallina.x-28, gallina.y-30, 7, 8);
		fillellipse(gallina.x-18, gallina.y-33, 7, 8);
		fillellipse(gallina.x-9, gallina.y-30, 7, 8);
		//PICO 0
		setcolor(6);
		int vec0[6]={gallina.x-48,gallina.y-14,gallina.x-36,gallina.y-7,gallina.x-34,gallina.y-17};
		setfillstyle(1, 6);
		fillpoly(3, vec0);
		//CUERPO 0
		setcolor(14);
		setfillstyle(1, 14);
		fillellipse(gallina.x-21, gallina.y-15, 16, 16);
		fillellipse(gallina.x+4, gallina.y+17, 38, 28);
		fillellipse(gallina.x-30, gallina.y, 8, 28);
		fillellipse(gallina.x+35, gallina.y+2, 8, 8);
		fillellipse(gallina.x+33, gallina.y-5, 8, 8);
		int vec1[6]={gallina.x+36,gallina.y-12,gallina.x+10,gallina.y-10,gallina.x+22,gallina.y};
		setfillstyle(1, 14);
		fillpoly(3, vec1);
		int vec2[6]{gallina.x+43,gallina.y+5,gallina.x+40,gallina.y+15,gallina.x+35,gallina.y+10};
		setfillstyle(1, 14);
		fillpoly(3, vec2);
		//BARBILLA 0
		setcolor(RED);
		setfillstyle(1, RED);
		fillellipse(gallina.x-42, gallina.y+2, 3, 3);
		fillellipse(gallina.x-36, gallina.y+2, 3, 3);
		int vec[6]{gallina.x-44,gallina.y+1,gallina.x-34,gallina.y+1,gallina.x-39,gallina.y-9};
		setfillstyle(1, RED);
		fillpoly(3, vec);
		//ALA 0
		setcolor(BLACK);
		arc(gallina.x+1, gallina.y+7, 180, 350, 21);
		arc(gallina.x+18, gallina.y+5, 250, 60, 8);
		arc(gallina.x+17, gallina.y+2, 260, 65, 7);
		//OJO 0
		setcolor(BLACK);
		setfillstyle(1, WHITE);
		fillellipse(gallina.x-30, gallina.y-17, 5, 5);
		setfillstyle(1, BLACK);
		fillellipse(gallina.x-32, gallina.y-17, 3, 5);
		}
	}
    if(tiempo==0 && dir == 3)
    {
    	{//CRESTA 0
		setcolor(RED);
		setfillstyle(1, RED); 
		fillellipse(gallina.x-28, gallina.y-30, 7, 8);
		fillellipse(gallina.x-18, gallina.y-33, 7, 8);
		fillellipse(gallina.x-9, gallina.y-30, 7, 8);
		//PICO 0
		setcolor(6);
		int vec0[6]={gallina.x-48,gallina.y-14,gallina.x-36,gallina.y-7,gallina.x-34,gallina.y-17};
		setfillstyle(1, 6);
		fillpoly(3, vec0);
		//CUERPO 0
		setcolor(14);
		setfillstyle(1, 14);
		fillellipse(gallina.x-21, gallina.y-15, 16, 16);
		fillellipse(gallina.x+4, gallina.y+17, 38, 28);
		fillellipse(gallina.x-30, gallina.y, 8, 28);
		fillellipse(gallina.x+35, gallina.y+2, 8, 8);
		fillellipse(gallina.x+33, gallina.y-5, 8, 8);
		int vec1[6]={gallina.x+36,gallina.y-12,gallina.x+10,gallina.y-10,gallina.x+22,gallina.y};
		setfillstyle(1, 14);
		fillpoly(3, vec1);
		int vec2[6]{gallina.x+43,gallina.y+5,gallina.x+40,gallina.y+15,gallina.x+35,gallina.y+10};
		setfillstyle(1, 14);
		fillpoly(3, vec2);
		//BARBILLA 0
		setcolor(RED);
		setfillstyle(1, RED);
		fillellipse(gallina.x-42, gallina.y+2, 3, 3);
		fillellipse(gallina.x-36, gallina.y+2, 3, 3);
		int vec[6]{gallina.x-44,gallina.y+1,gallina.x-34,gallina.y+1,gallina.x-39,gallina.y-9};
		setfillstyle(1, RED);
		fillpoly(3, vec);
		//ALA 0
		setcolor(BLACK);
		arc(gallina.x+1, gallina.y+7, 180, 350, 21);
		arc(gallina.x+18, gallina.y+5, 250, 60, 8);
		arc(gallina.x+17, gallina.y+2, 260, 65, 7);
		//OJO 0
		setcolor(BLACK);
		setfillstyle(1, WHITE);
		fillellipse(gallina.x-30, gallina.y-17, 5, 5);
		setfillstyle(1, BLACK);
		fillellipse(gallina.x-32, gallina.y-17, 3, 5);
		}
	}else
		{
			if(tiempo==1 && dir == 3)
			{
				{//CRESTA 1 
				setcolor(RED);
				setfillstyle(1, RED); 
				fillellipse(gallina.x-28, gallina.y-30, 7, 8);
				fillellipse(gallina.x-18, gallina.y-33, 7, 8);
				fillellipse(gallina.x-9, gallina.y-30, 7, 8);
				//PICO 1
				setcolor(6);
				int vec0[6]={gallina.x-48,gallina.y-14,gallina.x-36,gallina.y-7,gallina.x-34,gallina.y-17};
				setfillstyle(1, 6);
				fillpoly(3, vec0);
				//CUERPO 1
				setcolor(14);
				setfillstyle(1, 14);
				fillellipse(gallina.x-21, gallina.y-15, 16, 16);
				fillellipse(gallina.x+4, gallina.y+17, 38, 28);
				fillellipse(gallina.x-30, gallina.y, 8, 28);
				fillellipse(gallina.x+35, gallina.y+2, 8, 8);
				fillellipse(gallina.x+33, gallina.y-5, 8, 8);
				int vec1[6]={gallina.x+36,gallina.y-12,gallina.x+10,gallina.y-10,gallina.x+22,gallina.y};
				setfillstyle(1, 14);
				fillpoly(3, vec1);
				int vec2[6]{gallina.x+43,gallina.y+5,gallina.x+40,gallina.y+15,gallina.x+35,gallina.y+10};
				setfillstyle(1, 14);
				fillpoly(3, vec2);
				//BARBILLA 1
				setcolor(RED);
				setfillstyle(1, RED);
				fillellipse(gallina.x-42, gallina.y+2, 3, 3);
				fillellipse(gallina.x-36, gallina.y+2, 3, 3);
				int vec[6]{gallina.x-44,gallina.y+1,gallina.x-34,gallina.y+1,gallina.x-39,gallina.y-9};
				setfillstyle(1, RED);
				fillpoly(3, vec);
				//ALA 1
				setcolor(BLACK);
				setfillstyle(1, 14);
				fillellipse(gallina.x+30, gallina.y-19, 8, 4);	
				fillellipse(gallina.x+34, gallina.y-15, 8, 4);	
				fillellipse(gallina.x+34, gallina.y-10, 8, 4);	
				fillellipse(gallina.x+32, gallina.y-5, 8, 4);	
				fillellipse(gallina.x+28, gallina.y, 8, 4);	
				setcolor(14);
				setfillstyle(1, 14);
				fillellipse(gallina.x+15, gallina.y-8, 20, 15);
				int vec11[6]={gallina.x+29,gallina.y-23,gallina.x+17,gallina.y-22,gallina.x+20,gallina.y-10};
				setfillstyle(1, 14);
				fillpoly(3, vec11);
				//OJO 1
				setcolor(BLACK);
				setfillstyle(1, 15);
				fillellipse(gallina.x-30, gallina.y-17, 5, 5);
				setfillstyle(1, BLACK);
				fillellipse(gallina.x-32, gallina.y-17, 3, 5);
				}	
			}else{
				if(tiempo==0 && dir==4)
				{
					{//CRESTA 2
					setcolor(RED);
					setfillstyle(1, RED); 
					fillellipse(gallina.x-28*(-1), gallina.y-30, 7, 8);
					fillellipse(gallina.x-18*(-1), gallina.y-33, 7, 8);
					fillellipse(gallina.x-9*(-1), gallina.y-30, 7, 8);
					//PICO 2
					setcolor(6);
					int vec0[6]={gallina.x-48*(-1),gallina.y-14,gallina.x-36*(-1),gallina.y-7,gallina.x-34*(-1),gallina.y-17};
					setfillstyle(1, 6);
					fillpoly(3, vec0);
					//CUERPO 2
					setcolor(14);
					setfillstyle(1, 14);
					fillellipse(gallina.x-21*(-1), gallina.y-15, 16, 16);
					fillellipse(gallina.x+4*(-1), gallina.y+17, 38, 28);
					fillellipse(gallina.x-30*(-1), gallina.y, 8, 28);
					fillellipse(gallina.x+35*(-1), gallina.y+2, 8, 8);
					int vec2[6]={gallina.x+43*(-1),gallina.y+5,gallina.x+40*(-1),gallina.y+15,gallina.x+35*(-1),gallina.y+10};
					setfillstyle(1, 14);
					fillpoly(3, vec2);
					//BARBILLA 2
					setcolor(RED);
					setfillstyle(1, RED);
					fillellipse(gallina.x-42*(-1), gallina.y+2, 3, 3);
					fillellipse(gallina.x-36*(-1), gallina.y+2, 3, 3);
					int vec[6]={gallina.x-44*(-1),gallina.y+1,gallina.x-34*(-1),gallina.y+1,gallina.x-39*(-1),gallina.y-9};
					setfillstyle(1, RED);
					fillpoly(3, vec);
					//ALA 2
					setcolor(BLACK);
					setfillstyle(1, 14);
					fillellipse(gallina.x+30*(-1), gallina.y-19, 8, 4);	
					fillellipse(gallina.x+34*(-1), gallina.y-15, 8, 4);	
					fillellipse(gallina.x+34*(-1), gallina.y-10, 8, 4);	
					fillellipse(gallina.x+32*(-1), gallina.y-5, 8, 4);	
					fillellipse(gallina.x+28*(-1), gallina.y, 8, 4);	
					setcolor(14);
					setfillstyle(1, 14);
					fillellipse(gallina.x+15*(-1), gallina.y-8, 20, 15);
					int vec1[6]={gallina.x+29*(-1),gallina.y-23,gallina.x+17*(-1),gallina.y-22,gallina.x+20*(-1),gallina.y-10};
					setfillstyle(1, 14);
					fillpoly(3, vec1);	
					//OJO 2
					setcolor(BLACK);
					setfillstyle(1, WHITE);
					fillellipse(gallina.x-30*(-1), gallina.y-17, 5, 5);
					setfillstyle(1, BLACK);
					fillellipse(gallina.x-32*(-1), gallina.y-17, 3, 5);
					}	
				}else{
					if(tiempo==1 && dir==4)
					{
						{//CRESTA 3
						setcolor(RED);
						setfillstyle(1, RED); 
						fillellipse(gallina.x-28*(-1), gallina.y-30, 7, 8);
						fillellipse(gallina.x-18*(-1), gallina.y-33, 7, 8);
						fillellipse(gallina.x-9*(-1), gallina.y-30, 7, 8);
						//PICO 3
						setcolor(6);
						int vec0[6]={gallina.x-48*(-1),gallina.y-14,gallina.x-36*(-1),gallina.y-7,gallina.x-34*(-1),gallina.y-17};
						setfillstyle(1, 6);
						fillpoly(3, vec0);
						//CUERPO 3
						setcolor(14);
						setfillstyle(1, 14);
						fillellipse(gallina.x-21*(-1), gallina.y-15, 16, 16);
						fillellipse(gallina.x+4*(-1), gallina.y+17, 38, 28);
						fillellipse(gallina.x-30*(-1), gallina.y, 8, 28);
						fillellipse(gallina.x+35*(-1), gallina.y+2, 8, 8);
						fillellipse(gallina.x+33*(-1), gallina.y-5, 8, 8);
						int vec1[6]={gallina.x+36*(-1),gallina.y-12,gallina.x+10*(-1),gallina.y-10,gallina.x+22*(-1),gallina.y};
						setfillstyle(1, 14);
						fillpoly(3, vec1);
						int vec2[6]={gallina.x+43*(-1),gallina.y+5,gallina.x+40*(-1),gallina.y+15,gallina.x+35*(-1),gallina.y+10};
						setfillstyle(1, 14);
						fillpoly(3, vec2);
						//BARBILLA 3
						setcolor(RED);
						setfillstyle(1, RED);
						fillellipse(gallina.x-42*(-1), gallina.y+2, 3, 3);
						fillellipse(gallina.x-36*(-1), gallina.y+2, 3, 3);
						int vec[6]={gallina.x-44*(-1),gallina.y+1,gallina.x-34*(-1),gallina.y+1,gallina.x-39*(-1),gallina.y-9};
						setfillstyle(1, RED);
						fillpoly(3, vec);
						//ALA 3
						setcolor(BLACK);
						arc(gallina.x+1*(-1), gallina.y+7, 190, 360, 21);
						arc(gallina.x+18*(-1), gallina.y+5, 150, 280, 8);
						arc(gallina.x+17*(-1), gallina.y+2, 110, 275, 7);	
						//OJO 3
						setcolor(BLACK);
						setfillstyle(1, WHITE);
						fillellipse(gallina.x-30*(-1), gallina.y-17, 5, 5);
						setfillstyle(1, BLACK);
						fillellipse(gallina.x-32*(-1), gallina.y-17, 3, 5);
						}
					}
				}
			}
		}
}

void ironchik(gamer gallina, int tiempo,int dir)
{
	setbkcolor(BLACK);
    setcolor(WHITE);
    if (dir == 0){
    	{//CRESTA 0
		setcolor(4);
		setfillstyle(1, 14); 
		fillellipse(gallina.x-28, gallina.y-30, 7, 8);
		fillellipse(gallina.x-18, gallina.y-33, 7, 8);
		fillellipse(gallina.x-9, gallina.y-30, 7, 8);
		//PICO 0
		setcolor(14);
		int vec0[6]={gallina.x-48,gallina.y-14,gallina.x-36,gallina.y-7,gallina.x-34,gallina.y-17};
		setfillstyle(1, 4);
		fillpoly(3, vec0);
		//CUERPO 0
		setcolor(14);
		setfillstyle(1, 4);
		fillellipse(gallina.x-21, gallina.y-15, 16, 16);
		fillellipse(gallina.x+4, gallina.y+17, 38, 28);
		fillellipse(gallina.x-30, gallina.y, 8, 28);
		fillellipse(gallina.x+35, gallina.y+2, 8, 8);
		fillellipse(gallina.x+33, gallina.y-5, 8, 8);
		int vec1[6]={gallina.x+36,gallina.y-12,gallina.x+10,gallina.y-10,gallina.x+22,gallina.y};
		setfillstyle(1, 4);
		fillpoly(3, vec1);
		int vec2[6]{gallina.x+43,gallina.y+5,gallina.x+40,gallina.y+15,gallina.x+35,gallina.y+10};
		setfillstyle(1, 4);
		fillpoly(3, vec2);
		setcolor(14);
		setfillstyle(1,15);
		fillellipse(gallina.x-31,gallina.y+21,4,6);
		//BARBILLA 0
		setcolor(4);
		setfillstyle(1, 14);
		fillellipse(gallina.x-42, gallina.y+2, 3, 3);
		fillellipse(gallina.x-36, gallina.y+2, 3, 3);
		int vec[6]{gallina.x-44,gallina.y+1,gallina.x-34,gallina.y+1,gallina.x-39,gallina.y-9};
		setfillstyle(1, 14);
		fillpoly(3, vec);
		//ALA 0
		setcolor(14);
		arc(gallina.x+1, gallina.y+7, 180, 350, 21);
		arc(gallina.x+18, gallina.y+5, 250, 60, 8);
		arc(gallina.x+17, gallina.y+2, 260, 65, 7);
		//OJO 0
		setcolor(1);
		setfillstyle(1, 9);
		fillellipse(gallina.x-30, gallina.y-17, 5, 3);
		setfillstyle(1, 3);
		fillellipse(gallina.x-32, gallina.y-17, 2, 3);
		}
	}
    if(tiempo==0 && dir == 3)
    {
    	{//CRESTA 0
		setcolor(4);
		setfillstyle(1, 14); 
		fillellipse(gallina.x-28, gallina.y-30, 7, 8);
		fillellipse(gallina.x-18, gallina.y-33, 7, 8);
		fillellipse(gallina.x-9, gallina.y-30, 7, 8);
		//PICO 0
		setcolor(4);
		int vec0[6]={gallina.x-48,gallina.y-14,gallina.x-36,gallina.y-7,gallina.x-34,gallina.y-17};
		setfillstyle(1, 14);
		fillpoly(3, vec0);
		//CUERPO 0
		setcolor(14);
		setfillstyle(1, 4);
		fillellipse(gallina.x-21, gallina.y-15, 16, 16);
		fillellipse(gallina.x+4, gallina.y+17, 38, 28);
		fillellipse(gallina.x-30, gallina.y, 8, 28);
		fillellipse(gallina.x+35, gallina.y+2, 8, 8);
		fillellipse(gallina.x+33, gallina.y-5, 8, 8);
		int vec1[6]={gallina.x+36,gallina.y-12,gallina.x+10,gallina.y-10,gallina.x+22,gallina.y};
		setfillstyle(1, 4);
		fillpoly(3, vec1);
		int vec2[6]{gallina.x+43,gallina.y+5,gallina.x+40,gallina.y+15,gallina.x+35,gallina.y+10};
		setfillstyle(1, 4);
		fillpoly(3, vec2);
		setcolor(14);
		setfillstyle(1,15);
		fillellipse(gallina.x-31,gallina.y+21,4,6);
		//BARBILLA 0
		setcolor(4);
		setfillstyle(1, 14);
		fillellipse(gallina.x-42, gallina.y+2, 3, 3);
		fillellipse(gallina.x-36, gallina.y+2, 3, 3);
		int vec[6]{gallina.x-44,gallina.y+1,gallina.x-34,gallina.y+1,gallina.x-39,gallina.y-9};
		setfillstyle(1, 14);
		fillpoly(3, vec);
		//ALA 0
		setcolor(14);
		arc(gallina.x+1, gallina.y+7, 180, 350, 21);
		arc(gallina.x+18, gallina.y+5, 250, 60, 8);
		arc(gallina.x+17, gallina.y+2, 260, 65, 7);
		//OJO 0
		setcolor(1);
		setfillstyle(1, 9);
		fillellipse(gallina.x-30, gallina.y-17, 5, 3);
		setfillstyle(1, 3);
		fillellipse(gallina.x-32, gallina.y-17, 2, 3);
		}
	}else
		{
			if(tiempo==1 && dir == 3)
			{
				{//CRESTA 1 
				setcolor(4);
				setfillstyle(1, 14); 
				fillellipse(gallina.x-28, gallina.y-30, 7, 8);
				fillellipse(gallina.x-18, gallina.y-33, 7, 8);
				fillellipse(gallina.x-9, gallina.y-30, 7, 8);
				//PICO 1
				setcolor(4);
				int vec0[6]={gallina.x-48,gallina.y-14,gallina.x-36,gallina.y-7,gallina.x-34,gallina.y-17};
				setfillstyle(1, 14);
				fillpoly(3, vec0);
				//CUERPO 1
				setcolor(14);
				setfillstyle(1, 4);
				fillellipse(gallina.x-21, gallina.y-15, 16, 16);
				fillellipse(gallina.x+4, gallina.y+17, 38, 28);
				fillellipse(gallina.x-30, gallina.y, 8, 28);
				fillellipse(gallina.x+35, gallina.y+2, 8, 8);
				fillellipse(gallina.x+33, gallina.y-5, 8, 8);
				int vec1[6]={gallina.x+36,gallina.y-12,gallina.x+10,gallina.y-10,gallina.x+22,gallina.y};
				setfillstyle(1, 4);
				fillpoly(3, vec1);
				int vec2[6]{gallina.x+43,gallina.y+5,gallina.x+40,gallina.y+15,gallina.x+35,gallina.y+10};
				setfillstyle(1, 4);
				fillpoly(3, vec2);
				setcolor(14);
				setfillstyle(1,15);
				fillellipse(gallina.x-31,gallina.y+21,4,6);
				//BARBILLA 1
				setcolor(4);
				setfillstyle(1, 14);
				fillellipse(gallina.x-42, gallina.y+2, 3, 3);
				fillellipse(gallina.x-36, gallina.y+2, 3, 3);
				int vec[6]{gallina.x-44,gallina.y+1,gallina.x-34,gallina.y+1,gallina.x-39,gallina.y-9};
				setfillstyle(1, 14);
				fillpoly(3, vec);
				//ALA 1
				setcolor(14);
				setfillstyle(1, 4);
				fillellipse(gallina.x+30, gallina.y-19, 8, 4);	
				fillellipse(gallina.x+34, gallina.y-15, 8, 4);	
				fillellipse(gallina.x+34, gallina.y-10, 8, 4);	
				fillellipse(gallina.x+32, gallina.y-5, 8, 4);	
				fillellipse(gallina.x+28, gallina.y, 8, 4);	
				setcolor(4);
				setfillstyle(1, 4);
				fillellipse(gallina.x+15, gallina.y-8, 20, 15);
				int vec11[6]={gallina.x+29,gallina.y-23,gallina.x+17,gallina.y-22,gallina.x+20,gallina.y-10};
				setfillstyle(1, 4);
				fillpoly(3, vec11);
				//OJO 1
				setcolor(1);
				setfillstyle(1, 9);
				fillellipse(gallina.x-30, gallina.y-17, 5, 3);
				setfillstyle(1, 3);
				fillellipse(gallina.x-32, gallina.y-17, 2, 3);
				}	
			}else{
				if(tiempo==0 && dir==4)
				{
					{//CRESTA 2
					setcolor(4);
					setfillstyle(1, 14); 
					fillellipse(gallina.x-28*(-1), gallina.y-30, 7, 8);
					fillellipse(gallina.x-18*(-1), gallina.y-33, 7, 8);
					fillellipse(gallina.x-9*(-1), gallina.y-30, 7, 8);
					//PICO 2
					setcolor(4);
					int vec0[6]={gallina.x-48*(-1),gallina.y-14,gallina.x-36*(-1),gallina.y-7,gallina.x-34*(-1),gallina.y-17};
					setfillstyle(1, 14);
					fillpoly(3, vec0);
					//CUERPO 2
					setcolor(14);
					setfillstyle(1, 4);
					fillellipse(gallina.x-21*(-1), gallina.y-15, 16, 16);
					fillellipse(gallina.x+4*(-1), gallina.y+17, 38, 28);
					fillellipse(gallina.x-30*(-1), gallina.y, 8, 28);
					fillellipse(gallina.x+35*(-1), gallina.y+2, 8, 8);
					int vec2[6]={gallina.x+43*(-1),gallina.y+5,gallina.x+40*(-1),gallina.y+15,gallina.x+35*(-1),gallina.y+10};
					setfillstyle(1, 4);
					fillpoly(3, vec2);
					setcolor(14);
					setfillstyle(1,15);
					fillellipse(gallina.x+31,gallina.y+21,4,6);
					//BARBILLA 2
					setcolor(4);
					setfillstyle(1, 14);
					fillellipse(gallina.x-42*(-1), gallina.y+2, 3, 3);
					fillellipse(gallina.x-36*(-1), gallina.y+2, 3, 3);
					int vec[6]={gallina.x-44*(-1),gallina.y+1,gallina.x-34*(-1),gallina.y+1,gallina.x-39*(-1),gallina.y-9};
					setfillstyle(1, 14);
					fillpoly(3, vec);
					//ALA 2
					setcolor(14);
					setfillstyle(1, 4);
					fillellipse(gallina.x+30*(-1), gallina.y-19, 8, 4);	
					fillellipse(gallina.x+34*(-1), gallina.y-15, 8, 4);	
					fillellipse(gallina.x+34*(-1), gallina.y-10, 8, 4);	
					fillellipse(gallina.x+32*(-1), gallina.y-5, 8, 4);	
					fillellipse(gallina.x+28*(-1), gallina.y, 8, 4);	
					setcolor(4);
					setfillstyle(1, 4);
					fillellipse(gallina.x+15*(-1), gallina.y-8, 20, 15);
					int vec1[6]={gallina.x+29*(-1),gallina.y-23,gallina.x+17*(-1),gallina.y-22,gallina.x+20*(-1),gallina.y-10};
					setfillstyle(1, 4);
					fillpoly(3, vec1);	
					//OJO 2
					setcolor(1);
					setfillstyle(1, 9);
					fillellipse(gallina.x-30*(-1), gallina.y-17, 5, 3);
					setfillstyle(1, 3);
					fillellipse(gallina.x-32*(-1), gallina.y-17, 2, 3);
					}	
				}else{
					if(tiempo==1 && dir==4)
					{
						{//CRESTA 3
						setcolor(4);
						setfillstyle(1, 14); 
						fillellipse(gallina.x-28*(-1), gallina.y-30, 7, 8);
						fillellipse(gallina.x-18*(-1), gallina.y-33, 7, 8);
						fillellipse(gallina.x-9*(-1), gallina.y-30, 7, 8);
						//PICO 3
						setcolor(4);
						int vec0[6]={gallina.x-48*(-1),gallina.y-14,gallina.x-36*(-1),gallina.y-7,gallina.x-34*(-1),gallina.y-17};
						setfillstyle(1, 14);
						fillpoly(3, vec0);
						//CUERPO 3
						setcolor(14);
						setfillstyle(1, 4);
						fillellipse(gallina.x-21*(-1), gallina.y-15, 16, 16);
						fillellipse(gallina.x+4*(-1), gallina.y+17, 38, 28);
						fillellipse(gallina.x-30*(-1), gallina.y, 8, 28);
						fillellipse(gallina.x+35*(-1), gallina.y+2, 8, 8);
						fillellipse(gallina.x+33*(-1), gallina.y-5, 8, 8);
						int vec1[6]={gallina.x+36*(-1),gallina.y-12,gallina.x+10*(-1),gallina.y-10,gallina.x+22*(-1),gallina.y};
						setfillstyle(1, 4);
						fillpoly(3, vec1);
						int vec2[6]={gallina.x+43*(-1),gallina.y+5,gallina.x+40*(-1),gallina.y+15,gallina.x+35*(-1),gallina.y+10};
						setfillstyle(1, 4);
						fillpoly(3, vec2);
						setcolor(14);
						setfillstyle(1,15);
						fillellipse(gallina.x+31,gallina.y+21,4,6);	
						//BARBILLA 3
						setcolor(4);
						setfillstyle(1, 14);
						fillellipse(gallina.x-42*(-1), gallina.y+2, 3, 3);
						fillellipse(gallina.x-36*(-1), gallina.y+2, 3, 3);
						int vec[6]={gallina.x-44*(-1),gallina.y+1,gallina.x-34*(-1),gallina.y+1,gallina.x-39*(-1),gallina.y-9};
						setfillstyle(1, 14);
						fillpoly(3, vec);
						//ALA 3
						setcolor(14);
						arc(gallina.x+1*(-1), gallina.y+7, 190, 360, 21);
						arc(gallina.x+18*(-1), gallina.y+5, 150, 280, 8);
						arc(gallina.x+17*(-1), gallina.y+2, 110, 275, 7);	
						//OJO 3
						setcolor(1);
						setfillstyle(1, 9);
						fillellipse(gallina.x-30*(-1), gallina.y-17, 5, 3);
						setfillstyle(1, 3);
						fillellipse(gallina.x-32*(-1), gallina.y-17, 2, 3);
						}
					}
				}
			}
		}
}

void Iam_chik(gamer gallina, int tiempo,int dir)
{
	setbkcolor(BLACK);
    setcolor(WHITE);
    if (dir == 0){
    	{//CRESTA 0
		setcolor(2);
		setfillstyle(1, 2); 
		fillellipse(gallina.x-28, gallina.y-30, 7, 8);
		fillellipse(gallina.x-18, gallina.y-33, 7, 8);
		fillellipse(gallina.x-9, gallina.y-30, 7, 8);
		//PICO 0
		setcolor(14);
		int vec0[6]={gallina.x-42,gallina.y-14,gallina.x-36,gallina.y-7,gallina.x-34,gallina.y-17};
		setfillstyle(1, 14);
		fillpoly(3, vec0);
		//CUERPO 0
		setcolor(6);
		setfillstyle(1, 6);
		fillellipse(gallina.x-21, gallina.y-15, 16, 16);
		fillellipse(gallina.x+4, gallina.y+17, 38, 28);
		fillellipse(gallina.x-30, gallina.y, 8, 28);
		fillellipse(gallina.x+35, gallina.y+2, 8, 8);
		fillellipse(gallina.x+33, gallina.y-5, 8, 8);
		int vec1[6]={gallina.x+36,gallina.y-12,gallina.x+10,gallina.y-10,gallina.x+22,gallina.y};
		setfillstyle(1, 6);
		fillpoly(3, vec1);
		int vec2[6]{gallina.x+43,gallina.y+5,gallina.x+40,gallina.y+15,gallina.x+35,gallina.y+10};
		setfillstyle(1, 6);
		fillpoly(3, vec2);
		//BARBILLA 0
		setcolor(10);
		setfillstyle(1, 10);
		fillellipse(gallina.x-42, gallina.y+2, 3, 3);
		fillellipse(gallina.x-36, gallina.y+2, 3, 3);
		int vec[6]{gallina.x-44,gallina.y+1,gallina.x-34,gallina.y+1,gallina.x-39,gallina.y-9};
		setfillstyle(1, 10);
		fillpoly(3, vec);
		//ALA 0
		setcolor(8);
		arc(gallina.x+1, gallina.y+7, 180, 350, 21);
		arc(gallina.x+18, gallina.y+5, 250, 60, 8);
		arc(gallina.x+17, gallina.y+2, 260, 65, 7);
		//OJO 0
		setcolor(0);
		setfillstyle(1, 0);
		fillellipse(gallina.x-28, gallina.y-15, 7, 7);
		setfillstyle(1, 15);
		fillellipse(gallina.x-32, gallina.y-20, 2, 2);
		}
	}
    if(tiempo==0 && dir == 3)
    {
    	{//CRESTA 0
		setcolor(2);
		setfillstyle(1, 2); 
		fillellipse(gallina.x-28, gallina.y-30, 7, 8);
		fillellipse(gallina.x-18, gallina.y-33, 7, 8);
		fillellipse(gallina.x-9, gallina.y-30, 7, 8);
		//PICO 0
		setcolor(14);
		int vec0[6]={gallina.x-42,gallina.y-14,gallina.x-36,gallina.y-7,gallina.x-34,gallina.y-17};
		setfillstyle(1, 14);
		fillpoly(3, vec0);
		//CUERPO 0
		setcolor(6);
		setfillstyle(1, 6);
		fillellipse(gallina.x-21, gallina.y-15, 16, 16);
		fillellipse(gallina.x+4, gallina.y+17, 38, 28);
		fillellipse(gallina.x-30, gallina.y, 8, 28);
		fillellipse(gallina.x+35, gallina.y+2, 8, 8);
		fillellipse(gallina.x+33, gallina.y-5, 8, 8);
		int vec1[6]={gallina.x+36,gallina.y-12,gallina.x+10,gallina.y-10,gallina.x+22,gallina.y};
		int vec2[6]{gallina.x+43,gallina.y+5,gallina.x+40,gallina.y+15,gallina.x+35,gallina.y+10};
		setfillstyle(1, 6);
		fillpoly(3, vec1);
		fillpoly(3, vec2);	
		//BARBILLA 0
		setcolor(10);
		setfillstyle(1, 10);
		fillellipse(gallina.x-42, gallina.y+2, 3, 3);
		fillellipse(gallina.x-36, gallina.y+2, 3, 3);
		int vec[6]{gallina.x-44,gallina.y+1,gallina.x-34,gallina.y+1,gallina.x-39,gallina.y-9};
		setfillstyle(1, 10);
		fillpoly(3, vec);
		//ALA 0
		setcolor(8);
		arc(gallina.x+1, gallina.y+7, 180, 350, 21);
		arc(gallina.x+18, gallina.y+5, 250, 60, 8);
		arc(gallina.x+17, gallina.y+2, 260, 65, 7);
		//OJO 0
		setcolor(0);
		setfillstyle(1, 0);
		fillellipse(gallina.x-28, gallina.y-15, 7, 7);
		setfillstyle(1, 15);
		fillellipse(gallina.x-32, gallina.y-20, 2, 2);
		}
	}else
		{
			if(tiempo==1 && dir == 3)
			{
				{//CRESTA 1 
				setcolor(2);
				setfillstyle(1, 2); 
				fillellipse(gallina.x-28, gallina.y-30, 7, 8);
				fillellipse(gallina.x-18, gallina.y-33, 7, 8);
				fillellipse(gallina.x-9, gallina.y-30, 7, 8);
				//PICO 1
				setcolor(14);
				int vec0[6]={gallina.x-42,gallina.y-14,gallina.x-36,gallina.y-7,gallina.x-34,gallina.y-17};
				setfillstyle(1, 14);
				fillpoly(3, vec0);
				//CUERPO 1
				setcolor(6);
				setfillstyle(1, 6);
				fillellipse(gallina.x-21, gallina.y-15, 16, 16);
				fillellipse(gallina.x+4, gallina.y+17, 38, 28);
				fillellipse(gallina.x-30, gallina.y, 8, 28);
				fillellipse(gallina.x+35, gallina.y+2, 8, 8);
				fillellipse(gallina.x+33, gallina.y-5, 8, 8);
				int vec1[6]={gallina.x+36,gallina.y-12,gallina.x+10,gallina.y-10,gallina.x+22,gallina.y};
				setfillstyle(1, 6);
				int vec2[6]{gallina.x+43,gallina.y+5,gallina.x+40,gallina.y+15,gallina.x+35,gallina.y+10};
				fillpoly(3, vec1);
				fillpoly(3, vec2);
				//BARBILLA 1
				setcolor(10);
				setfillstyle(1, 10);
				fillellipse(gallina.x-42, gallina.y+2, 3, 3);
				fillellipse(gallina.x-36, gallina.y+2, 3, 3);
				int vec[6]{gallina.x-44,gallina.y+1,gallina.x-34,gallina.y+1,gallina.x-39,gallina.y-9};
				setfillstyle(1, 10);
				fillpoly(3, vec);
				//ALA 1
				setcolor(8);
				setfillstyle(1, 6);
				fillellipse(gallina.x+30, gallina.y-19, 8, 4);	
				fillellipse(gallina.x+34, gallina.y-15, 8, 4);	
				fillellipse(gallina.x+34, gallina.y-10, 8, 4);	
				fillellipse(gallina.x+32, gallina.y-5, 8, 4);	
				fillellipse(gallina.x+28, gallina.y, 8, 4);	
				setcolor(6);
				fillellipse(gallina.x+15, gallina.y-8, 20, 15);
				int vec11[6]={gallina.x+29,gallina.y-23,gallina.x+17,gallina.y-22,gallina.x+20,gallina.y-10};
				fillpoly(3, vec11);
				//OJO 1
				setcolor(0);
				setfillstyle(1, 0);
				fillellipse(gallina.x-28, gallina.y-15, 7, 7);
				setfillstyle(1, 15);
				fillellipse(gallina.x-32, gallina.y-20, 2, 2);
				}	
			}else{
				if(tiempo==0 && dir==4)
				{
					{//CRESTA 2
					setcolor(2);
					setfillstyle(1, 2); 
					fillellipse(gallina.x-28*(-1), gallina.y-30, 7, 8);
					fillellipse(gallina.x-18*(-1), gallina.y-33, 7, 8);
					fillellipse(gallina.x-9*(-1), gallina.y-30, 7, 8);
					//PICO 2
					setcolor(14);
					int vec0[6]={gallina.x-42*(-1),gallina.y-14,gallina.x-36*(-1),gallina.y-7,gallina.x-34*(-1),gallina.y-17};
					setfillstyle(1, 14);
					fillpoly(3, vec0);
					//CUERPO 2
					setcolor(6);
					setfillstyle(1, 6);
					fillellipse(gallina.x-21*(-1), gallina.y-15, 16, 16);
					fillellipse(gallina.x+4*(-1), gallina.y+17, 38, 28);
					fillellipse(gallina.x-30*(-1), gallina.y, 8, 28);
					fillellipse(gallina.x+35*(-1), gallina.y+2, 8, 8);
					int vec2[6]={gallina.x+43*(-1),gallina.y+5,gallina.x+40*(-1),gallina.y+15,gallina.x+35*(-1),gallina.y+10};
					fillpoly(3, vec2);
					//BARBILLA 2
					setcolor(10);
					setfillstyle(1, 10);
					fillellipse(gallina.x-42*(-1), gallina.y+2, 3, 3);
					fillellipse(gallina.x-36*(-1), gallina.y+2, 3, 3);
					int vec[6]={gallina.x-44*(-1),gallina.y+1,gallina.x-34*(-1),gallina.y+1,gallina.x-39*(-1),gallina.y-9};
					fillpoly(3, vec);
					//ALA 2
					setcolor(8);
					setfillstyle(1, 6);
					fillellipse(gallina.x+30*(-1), gallina.y-19, 8, 4);	
					fillellipse(gallina.x+34*(-1), gallina.y-15, 8, 4);	
					fillellipse(gallina.x+34*(-1), gallina.y-10, 8, 4);	
					fillellipse(gallina.x+32*(-1), gallina.y-5, 8, 4);	
					fillellipse(gallina.x+28*(-1), gallina.y, 8, 4);	
					setcolor(6);
					fillellipse(gallina.x+15*(-1), gallina.y-8, 20, 15);
					int vec1[6]={gallina.x+29*(-1),gallina.y-23,gallina.x+17*(-1),gallina.y-22,gallina.x+20*(-1),gallina.y-10};
					fillpoly(3, vec1);	
					//OJO 2
					setcolor(0);
					setfillstyle(1, 0);
					fillellipse(gallina.x+28, gallina.y-15, 7, 7);
					setfillstyle(1, 15);
					fillellipse(gallina.x-32*(-1), gallina.y-20, 2, 2);
					}	
				}else{
					if(tiempo==1 && dir==4)
					{
						{//CRESTA 3
						setcolor(2);
						setfillstyle(1, 2); 
						fillellipse(gallina.x-28*(-1), gallina.y-30, 7, 8);
						fillellipse(gallina.x-18*(-1), gallina.y-33, 7, 8);
						fillellipse(gallina.x-9*(-1), gallina.y-30, 7, 8);
						//PICO 3
						setcolor(14);
						int vec0[6]={gallina.x-42*(-1),gallina.y-14,gallina.x-36*(-1),gallina.y-7,gallina.x-34*(-1),gallina.y-17};
						setfillstyle(1, 14);
						fillpoly(3, vec0);
						//CUERPO 3
						setcolor(6);
						setfillstyle(1, 6);
						fillellipse(gallina.x-21*(-1), gallina.y-15, 16, 16);
						fillellipse(gallina.x+4*(-1), gallina.y+17, 38, 28);
						fillellipse(gallina.x-30*(-1), gallina.y, 8, 28);
						fillellipse(gallina.x+35*(-1), gallina.y+2, 8, 8);
						fillellipse(gallina.x+33*(-1), gallina.y-5, 8, 8);
						int vec1[6]={gallina.x+36*(-1),gallina.y-12,gallina.x+10*(-1),gallina.y-10,gallina.x+22*(-1),gallina.y};
						int vec2[6]={gallina.x+43*(-1),gallina.y+5,gallina.x+40*(-1),gallina.y+15,gallina.x+35*(-1),gallina.y+10};
						fillpoly(3, vec1);
						fillpoly(3, vec2);
						//BARBILLA 3
						setcolor(10);
						setfillstyle(1, 10);
						fillellipse(gallina.x-42*(-1), gallina.y+2, 3, 3);
						fillellipse(gallina.x-36*(-1), gallina.y+2, 3, 3);
						int vec[6]={gallina.x-44*(-1),gallina.y+1,gallina.x-34*(-1),gallina.y+1,gallina.x-39*(-1),gallina.y-9};
						fillpoly(3, vec);
						//ALA 3
						setcolor(8);
						arc(gallina.x+1*(-1), gallina.y+7, 190, 360, 21);
						arc(gallina.x+18*(-1), gallina.y+5, 150, 280, 8);
						arc(gallina.x+17*(-1), gallina.y+2, 110, 275, 7);	
						//OJO 3
						setcolor(0);
						setfillstyle(1, 0);
						fillellipse(gallina.x+28, gallina.y-15, 7, 7);
						setfillstyle(1, 15);
						fillellipse(gallina.x-32*(-1), gallina.y-20, 2, 2);
						}
					}
				}
			}
		}
}


void pacman(gamer pacman, int tiempo,int dir)
{
	
	int cf=9;
	setcolor(14);
    setfillstyle(1,14);
    if (dir == 0){
    	//CUERPO 0
    	fillellipse(pacman.x,pacman.y,50,50);
    	setcolor(cf);    
		setfillstyle(1,cf);
    	int pm[6]={pacman.x,pacman.y,pacman.x-50,pacman.y-50,pacman.x-50,pacman.y+50};
    	fillpoly(3,pm);
	}
    if(tiempo==0 && dir == 3){
		//CUERPO 0
    	fillellipse(pacman.x,pacman.y,50,50);
    	setcolor(cf);
    	setfillstyle(1,cf);
    	int pm[6]={pacman.x,pacman.y,pacman.x-50,pacman.y-50,pacman.x-50,pacman.y+50};
    	fillpoly(3,pm);
	}else{
			if(tiempo==1 && dir == 3){
				//CUERPO 1
		    	fillellipse(pacman.x,pacman.y,50,50);
		    	setcolor(cf);
		    	setlinestyle(0,3,1);
		    	line(pacman.x,pacman.y,pacman.x-50,pacman.y);
			}else{
				if(tiempo==0 && dir==4){
					//CUERPO 2
					setcolor(14);
			    	setfillstyle(1,14);
			    	fillellipse(pacman.x,pacman.y,50,50);
			    	setcolor(cf);
			    	setlinestyle(0,3,1);
			    	line(pacman.x,pacman.y,pacman.x+50,pacman.y);
				}else{
					if(tiempo==1 && dir==4){
						//CUERPO 3
				    	fillellipse(pacman.x,pacman.y,50,50);
				    	setcolor(cf);
				    	setfillstyle(1,cf);
				    	int pm[6]={pacman.x,pacman.y,pacman.x+50,pacman.y-50,pacman.x+50,pacman.y+50};
				    	fillpoly(3,pm);
					}
				}
			}
		}	
}


void chicorn(gamer gallina, int tiempo,int dir)
{
	setbkcolor(0);
    setcolor(15);
    if (dir == 0){
    	{//CRESTA 0
		setcolor(13);
		setfillstyle(1, 13); 
		fillellipse(gallina.x-28, gallina.y-30, 7, 8);
		setcolor(14);
		setfillstyle(1, 14); 		
		fillellipse(gallina.x-18, gallina.y-33, 7, 8);
		setcolor(11);
		setfillstyle(1, 11); 		
		fillellipse(gallina.x-9, gallina.y-30, 7, 8);
		//CUERNO
		setcolor(6);
		setfillstyle(1,14);
		int cr[6]={gallina.x-42, gallina.y-38, gallina.x-28, gallina.y-29, gallina.x-33, gallina.y-22};
		fillpoly(3, cr);
		//PICO 0
		setcolor(14);
		setfillstyle(1, 14);
		int vec0[6]={gallina.x-48,gallina.y-14,gallina.x-36,gallina.y-7,gallina.x-34,gallina.y-17};
		fillpoly(3, vec0);
		//CUERPO 0
		setcolor(15);
		setfillstyle(1, 15);
		fillellipse(gallina.x-21, gallina.y-15, 16, 16);
		fillellipse(gallina.x+4, gallina.y+17, 38, 28);
		fillellipse(gallina.x-30, gallina.y, 8, 28);
		fillellipse(gallina.x+35, gallina.y+2, 8, 8);
		fillellipse(gallina.x+33, gallina.y-5, 8, 8);
		int vec1[6]={gallina.x+36,gallina.y-12,gallina.x+10,gallina.y-10,gallina.x+22,gallina.y};
		int vec2[6]{gallina.x+43,gallina.y+5,gallina.x+40,gallina.y+15,gallina.x+35,gallina.y+10};
		fillpoly(3, vec1);
		fillpoly(3, vec2);
		//BARBILLA 0
		setcolor(5);
		setfillstyle(1, 5);
		fillellipse(gallina.x-42, gallina.y+2, 3, 3);
		fillellipse(gallina.x-36, gallina.y+2, 3, 3);
		int vec[6]{gallina.x-44,gallina.y+1,gallina.x-34,gallina.y+1,gallina.x-39,gallina.y-9};
		fillpoly(3, vec);
		//ALA 0
		setcolor(0);
		arc(gallina.x+1, gallina.y+7, 180, 350, 21);
		arc(gallina.x+18, gallina.y+5, 250, 60, 8);
		arc(gallina.x+17, gallina.y+2, 260, 65, 7);
		//OJO 0
		setcolor(0);
		setfillstyle(1, 15);
		fillellipse(gallina.x-30, gallina.y-17, 5, 5);
		setfillstyle(1, 10);
		fillellipse(gallina.x-32, gallina.y-17, 3, 5);
		}
	}
    if(tiempo==0 && dir == 3)
    {
		{//CRESTA 0
		setcolor(13);
		setfillstyle(1, 13); 
		fillellipse(gallina.x-28, gallina.y-30, 7, 8);
		setcolor(14);
		setfillstyle(1, 14); 		
		fillellipse(gallina.x-18, gallina.y-33, 7, 8);
		setcolor(11);
		setfillstyle(1, 11); 		
		fillellipse(gallina.x-9, gallina.y-30, 7, 8);
		//CUERNO
		setcolor(6);
		setfillstyle(1,14);
		int cr[6]={gallina.x-42, gallina.y-38, gallina.x-28, gallina.y-29, gallina.x-33, gallina.y-22};
		fillpoly(3,cr);
		//PICO 0
		setcolor(14);
		setfillstyle(1, 14);
		int vec0[6]={gallina.x-48,gallina.y-14,gallina.x-36,gallina.y-7,gallina.x-34,gallina.y-17};
		fillpoly(3, vec0);
		//CUERPO 0
		setcolor(15);
		setfillstyle(1, 15);
		fillellipse(gallina.x-21, gallina.y-15, 16, 16);
		fillellipse(gallina.x+4, gallina.y+17, 38, 28);
		fillellipse(gallina.x-30, gallina.y, 8, 28);
		fillellipse(gallina.x+35, gallina.y+2, 8, 8);
		fillellipse(gallina.x+33, gallina.y-5, 8, 8);
		int vec1[6]={gallina.x+36,gallina.y-12,gallina.x+10,gallina.y-10,gallina.x+22,gallina.y};
		int vec2[6]{gallina.x+43,gallina.y+5,gallina.x+40,gallina.y+15,gallina.x+35,gallina.y+10};
		fillpoly(3, vec1);
		fillpoly(3, vec2);
		//BARBILLA 0
		setcolor(5);
		setfillstyle(1, 5);
		fillellipse(gallina.x-42, gallina.y+2, 3, 3);
		fillellipse(gallina.x-36, gallina.y+2, 3, 3);
		int vec[6]{gallina.x-44,gallina.y+1,gallina.x-34,gallina.y+1,gallina.x-39,gallina.y-9};
		fillpoly(3, vec);
		//ALA 0
		setcolor(0);
		arc(gallina.x+1, gallina.y+7, 180, 350, 21);
		arc(gallina.x+18, gallina.y+5, 250, 60, 8);
		arc(gallina.x+17, gallina.y+2, 260, 65, 7);
		//OJO 0
		setcolor(0);
		setfillstyle(1, 15);
		fillellipse(gallina.x-30, gallina.y-17, 5, 5);
		setfillstyle(1, 10);
		fillellipse(gallina.x-32, gallina.y-17, 3, 5);
		}
	}else
		{
			if(tiempo==1 && dir == 3)
			{
				{//CRESTA 1 
				setcolor(13);
				setfillstyle(1, 13); 
				fillellipse(gallina.x-28, gallina.y-30, 7, 8);
				setcolor(14);
				setfillstyle(1, 14); 		
				fillellipse(gallina.x-18, gallina.y-33, 7, 8);
				setcolor(11);
				setfillstyle(1, 11); 		
				fillellipse(gallina.x-9, gallina.y-30, 7, 8);
				//CUERNO
				setcolor(6);
				setfillstyle(1,14);
				int cr[6]={gallina.x-42, gallina.y-38, gallina.x-28, gallina.y-29, gallina.x-33, gallina.y-22};
				fillpoly(3,cr);
				//PICO 1
				setcolor(14);
				int vec0[6]={gallina.x-48,gallina.y-14,gallina.x-36,gallina.y-7,gallina.x-34,gallina.y-17};
				setfillstyle(1, 14);
				fillpoly(3, vec0);
				//CUERPO 1
				setcolor(15);
				setfillstyle(1, 15);
				fillellipse(gallina.x-21, gallina.y-15, 16, 16);
				fillellipse(gallina.x+4, gallina.y+17, 38, 28);
				fillellipse(gallina.x-30, gallina.y, 8, 28);
				fillellipse(gallina.x+35, gallina.y+2, 8, 8);
				fillellipse(gallina.x+33, gallina.y-5, 8, 8);
				int vec1[6]={gallina.x+36,gallina.y-12,gallina.x+10,gallina.y-10,gallina.x+22,gallina.y};
				int vec2[6]{gallina.x+43,gallina.y+5,gallina.x+40,gallina.y+15,gallina.x+35,gallina.y+10};
				fillpoly(3, vec1);
				fillpoly(3, vec2);
				//BARBILLA 1
				setcolor(5);
				setfillstyle(1, 5);
				fillellipse(gallina.x-42, gallina.y+2, 3, 3);
				fillellipse(gallina.x-36, gallina.y+2, 3, 3);
				int vec[6]{gallina.x-44,gallina.y+1,gallina.x-34,gallina.y+1,gallina.x-39,gallina.y-9};
				fillpoly(3, vec);
				//ALA 1
				setcolor(0);
				setfillstyle(1, 15);
				fillellipse(gallina.x+30, gallina.y-19, 8, 4);	
				fillellipse(gallina.x+34, gallina.y-15, 8, 4);	
				fillellipse(gallina.x+34, gallina.y-10, 8, 4);	
				fillellipse(gallina.x+32, gallina.y-5, 8, 4);	
				fillellipse(gallina.x+28, gallina.y, 8, 4);	
				setcolor(15);
				fillellipse(gallina.x+15, gallina.y-8, 20, 15);
				int vec10[6]={gallina.x+29,gallina.y-23,gallina.x+17,gallina.y-22,gallina.x+20,gallina.y-10};
				fillpoly(3, vec10);
				//OJO 1
				setcolor(0);
				setfillstyle(1, 15);
				fillellipse(gallina.x-30, gallina.y-17, 5, 5);
				setfillstyle(1, 10);
				fillellipse(gallina.x-32, gallina.y-17, 3, 5);
				}	
			}else{
				if(tiempo==0 && dir==4)
				{
					{//CRESTA 2
					setcolor(13);
					setfillstyle(1, 13); 
					fillellipse(gallina.x-28*(-1), gallina.y-30, 7, 8);
					setcolor(14);
					setfillstyle(1, 14); 		
					fillellipse(gallina.x-18*(-1), gallina.y-33, 7, 8);
					setcolor(11);
					setfillstyle(1, 11);
					fillellipse(gallina.x-9*(-1), gallina.y-30, 7, 8);	
					//CUERNO
					setcolor(6);
					setfillstyle(1,14);
					int cr[6]={gallina.x+42, gallina.y-38, gallina.x+28, gallina.y-29, gallina.x+33, gallina.y-22};		
					fillpoly(3,cr);
					//PICO 2
					setcolor(14);
					int vec0[6]={gallina.x-48*(-1),gallina.y-14,gallina.x-36*(-1),gallina.y-7,gallina.x-34*(-1),gallina.y-17};
					setfillstyle(1, 14);
					fillpoly(3, vec0);
					//CUERPO 2
					setcolor(15);
					setfillstyle(1, 15);
					fillellipse(gallina.x-21*(-1), gallina.y-15, 16, 16);
					fillellipse(gallina.x+4*(-1), gallina.y+17, 38, 28);
					fillellipse(gallina.x-30*(-1), gallina.y, 8, 28);
					fillellipse(gallina.x+35*(-1), gallina.y+2, 8, 8);
					int vec2[6]={gallina.x+43*(-1),gallina.y+5,gallina.x+40*(-1),gallina.y+15,gallina.x+35*(-1),gallina.y+10};
					fillpoly(3, vec2);
					//BARBILLA 2
					setcolor(5);
					setfillstyle(1, 5);
					fillellipse(gallina.x-42*(-1), gallina.y+2, 3, 3);
					fillellipse(gallina.x-36*(-1), gallina.y+2, 3, 3);
					int vec[6]={gallina.x-44*(-1),gallina.y+1,gallina.x-34*(-1),gallina.y+1,gallina.x-39*(-1),gallina.y-9};
					fillpoly(3, vec);
					//ALA 2
					setcolor(0);
					setfillstyle(1, 15);
					fillellipse(gallina.x+30*(-1), gallina.y-19, 8, 4);	
					fillellipse(gallina.x+34*(-1), gallina.y-15, 8, 4);	
					fillellipse(gallina.x+34*(-1), gallina.y-10, 8, 4);	
					fillellipse(gallina.x+32*(-1), gallina.y-5, 8, 4);	
					fillellipse(gallina.x+28*(-1), gallina.y, 8, 4);	
					setcolor(15);
					fillellipse(gallina.x+15*(-1), gallina.y-8, 20, 15);
					int vec1[6]={gallina.x+29*(-1),gallina.y-23,gallina.x+17*(-1),gallina.y-22,gallina.x+20*(-1),gallina.y-10};
					fillpoly(3, vec1);
					//OJO 2
					setcolor(0);
					setfillstyle(1, 15);
					fillellipse(gallina.x-30*(-1), gallina.y-17, 5, 5);
					setfillstyle(1, 10);
					fillellipse(gallina.x-32*(-1), gallina.y-17, 3, 5);
					}	
				}else{
					if(tiempo==1 && dir==4)
					{
						{//CRESTA 3
						setcolor(13);
						setfillstyle(1, 13); 
						fillellipse(gallina.x-28*(-1), gallina.y-30, 7, 8);
						setcolor(14);
						setfillstyle(1, 14); 		
						fillellipse(gallina.x-18*(-1), gallina.y-33, 7, 8);
						setcolor(11);
						setfillstyle(1, 11);
						fillellipse(gallina.x-9*(-1), gallina.y-30, 7, 8);	
						//CUERNO
						setcolor(6);
						setfillstyle(1,14);
						int cr[6]={gallina.x+42, gallina.y-38, gallina.x+28, gallina.y-29, gallina.x+33, gallina.y-22};
						//PICO 3
						setcolor(14);
						int vec0[6]={gallina.x-48*(-1),gallina.y-14,gallina.x-36*(-1),gallina.y-7,gallina.x-34*(-1),gallina.y-17};
						setfillstyle(1, 14);
						fillpoly(3, vec0);
						fillpoly(3,cr);
						//CUERPO 3
						setcolor(15);
						setfillstyle(1, 15);
						fillellipse(gallina.x-21*(-1), gallina.y-15, 16, 16);
						fillellipse(gallina.x+4*(-1), gallina.y+17, 38, 28);
						fillellipse(gallina.x-30*(-1), gallina.y, 8, 28);
						fillellipse(gallina.x+35*(-1), gallina.y+2, 8, 8);
						fillellipse(gallina.x+33*(-1), gallina.y-5, 8, 8);
						int vec1[6]={gallina.x+36*(-1),gallina.y-12,gallina.x+10*(-1),gallina.y-10,gallina.x+22*(-1),gallina.y};
						int vec2[6]={gallina.x+43*(-1),gallina.y+5,gallina.x+40*(-1),gallina.y+15,gallina.x+35*(-1),gallina.y+10};
						fillpoly(3, vec1);
						fillpoly(3, vec2);
						//BARBILLA 3
						setcolor(5);
						setfillstyle(1, 5);
						fillellipse(gallina.x-42*(-1), gallina.y+2, 3, 3);
						fillellipse(gallina.x-36*(-1), gallina.y+2, 3, 3);
						int vec[6]={gallina.x-44*(-1),gallina.y+1,gallina.x-34*(-1),gallina.y+1,gallina.x-39*(-1),gallina.y-9};
						fillpoly(3, vec);
						//ALA 3
						setcolor(0);
						arc(gallina.x+1*(-1), gallina.y+7, 190, 360, 21);
						arc(gallina.x+18*(-1), gallina.y+5, 150, 280, 8);
						arc(gallina.x+17*(-1), gallina.y+2, 110, 275, 7);	
						//OJO 3
						setcolor(0);
						setfillstyle(1, 15);
						fillellipse(gallina.x-30*(-1), gallina.y-17, 5, 5);
						setfillstyle(1, 10);
						fillellipse(gallina.x-32*(-1), gallina.y-17, 3, 5);
						}
					}
				}
			}
		}
	
	
}


void cactus(gamer cactus, int tiempo,int dir)
{
	
	setcolor(2);
    setfillstyle(1,2);
    if (dir == 0){
    	//Cactus 0
    	fillellipse(cactus.x,cactus.y,43,35);
    	fillellipse(cactus.x,cactus.y,23,35);
    	setcolor(10);   
		setfillstyle(1,10);
		fillellipse(cactus.x,cactus.y,33,35);
		fillellipse(cactus.x,cactus.y,13,35);
		//MACETA 0
		setcolor(12);   
		setfillstyle(1,12);
    	int m0[8]={cactus.x-44,cactus.y+5,cactus.x-40,cactus.y+20,cactus.x+40,cactus.y+20,cactus.x+44,cactus.y+5};
    	fillpoly(4,m0);
    	setcolor(4);   
		setfillstyle(1,4);
    	int m1[8]={cactus.x-35,cactus.y+20,cactus.x+35,cactus.y+20,cactus.x+25,cactus.y+45,cactus.x-25,cactus.y+45};
    	fillpoly(4,m1);
    	//CARA 0
    	setcolor(0);   
		setfillstyle(1,0);
    	fillellipse(cactus.x-15,cactus.y+30,5,5);
    	fillellipse(cactus.x+15,cactus.y+30,5,5);
    	line(cactus.x-3,cactus.y+30,cactus.x+3,cactus.y+30);
		setfillstyle(1,15);
    	fillellipse(cactus.x-17,cactus.y+27,2,2);
    	fillellipse(cactus.x+13,cactus.y+27,2,2);
	}
    if(tiempo==0 && dir == 3){
		//Cactus 0
    	fillellipse(cactus.x,cactus.y,43,35);
    	setcolor(10);   
		setfillstyle(1,10);
		fillellipse(cactus.x,cactus.y,33,35);
		setcolor(2);   
		setfillstyle(1,2);
    	fillellipse(cactus.x,cactus.y,23,35);
    	setcolor(10);   
		setfillstyle(1,10);
		fillellipse(cactus.x,cactus.y,13,35);
		//MACETA 0
		setcolor(12);   
		setfillstyle(1,12);
    	int m0[8]={cactus.x-44,cactus.y+5,cactus.x-40,cactus.y+20,cactus.x+40,cactus.y+20,cactus.x+44,cactus.y+5};
    	fillpoly(4,m0);
    	setcolor(4);   
		setfillstyle(1,4);
    	int m1[8]={cactus.x-35,cactus.y+20,cactus.x+35,cactus.y+20,cactus.x+25,cactus.y+45,cactus.x-25,cactus.y+45};
		fillpoly(4,m1);
    	//CARA 0
    	setcolor(0);   
		setfillstyle(1,0);
    	fillellipse(cactus.x-15,cactus.y+30,5,5);
    	fillellipse(cactus.x+15,cactus.y+30,5,5);
    	line(cactus.x-3,cactus.y+30,cactus.x+3,cactus.y+30);
		setfillstyle(1,15);
    	fillellipse(cactus.x-17,cactus.y+27,2,2);
    	fillellipse(cactus.x+13,cactus.y+27,2,2);
	}else{
			if(tiempo==1 && dir == 3){
				//Cactus 1
		    	fillellipse(cactus.x,cactus.y,43,35);
		    	setcolor(10);   
				setfillstyle(1,10);
				fillellipse(cactus.x,cactus.y,33,35);
				setcolor(2);   
				setfillstyle(1,2);
		    	fillellipse(cactus.x,cactus.y,23,35);
		    	setcolor(10);   
				setfillstyle(1,10);
				fillellipse(cactus.x,cactus.y,13,35);
				//MACETA 1
				setcolor(12);   
				setfillstyle(1,12);
		    	int m0[8]={cactus.x-44,cactus.y+5,cactus.x-40,cactus.y+20,cactus.x+40,cactus.y+20,cactus.x+44,cactus.y+5};
    			fillpoly(4,m0);
    			setcolor(4);   
				setfillstyle(1,4);
    			int m1[8]={cactus.x-35,cactus.y+20,cactus.x+35,cactus.y+20,cactus.x+25,cactus.y+45,cactus.x-25,cactus.y+45};
		    	fillpoly(4,m1);
		    	//CARA 1
		    	setcolor(0);   
				setfillstyle(1,0);
		    	fillellipse(cactus.x,cactus.y+33,3,4);
		    	int m2[6]={cactus.x-20,cactus.y+25,cactus.x-10,cactus.y+30,cactus.x-20,cactus.y+35};
		    	int m3[6]={cactus.x+20,cactus.y+25,cactus.x+10,cactus.y+30,cactus.x+20,cactus.y+35};
				drawpoly(3,m2);
				drawpoly(3,m3);
			}else{
				if(tiempo==0 && dir==4){
					//Cactus 2
			    	fillellipse(cactus.x,cactus.y,43,35);
			    	setcolor(10);   
					setfillstyle(1,10);
					fillellipse(cactus.x,cactus.y,33,35);
					setcolor(2);   
					setfillstyle(1,2);
			    	fillellipse(cactus.x,cactus.y,23,35);
			    	setcolor(10);   
					setfillstyle(1,10);
					fillellipse(cactus.x,cactus.y,13,35);
					//MACETA 2
					setcolor(12);   
					setfillstyle(1,12);
			    	int m0[8]={cactus.x-44,cactus.y+5,cactus.x-40,cactus.y+20,cactus.x+40,cactus.y+20,cactus.x+44,cactus.y+5};
			    	fillpoly(4,m0);
			    	setcolor(4);   
					setfillstyle(1,4);
			    	int m1[8]={cactus.x-35,cactus.y+20,cactus.x+35,cactus.y+20,cactus.x+25,cactus.y+45,cactus.x-25,cactus.y+45};
			    	fillpoly(4,m1);
			    	//CARA 2
			    	setcolor(0);   
					setfillstyle(1,0);
			    	fillellipse(cactus.x-15,cactus.y+30,5,5);
			    	fillellipse(cactus.x+15,cactus.y+30,5,5);
			    	line(cactus.x-3,cactus.y+30,cactus.x+3,cactus.y+30);
					setfillstyle(1,15);
			    	fillellipse(cactus.x+17,cactus.y+27,2,2);
			    	fillellipse(cactus.x-13,cactus.y+27,2,2);
				}else{
					if(tiempo==1 && dir==4){
						//Cactus 3
				    	fillellipse(cactus.x,cactus.y,43,35);
				    	setcolor(10);   
						setfillstyle(1,10);
						fillellipse(cactus.x,cactus.y,33,35);
						setcolor(2);   
						setfillstyle(1,2);
				    	fillellipse(cactus.x,cactus.y,23,35);
				    	setcolor(10);   
						setfillstyle(1,10);
						fillellipse(cactus.x,cactus.y,13,35);
						//MACETA 3
						setcolor(12);   
						setfillstyle(1,12);
				    	int m0[8]={cactus.x-44,cactus.y+5,cactus.x-40,cactus.y+20,cactus.x+40,cactus.y+20,cactus.x+44,cactus.y+5};
				    	fillpoly(4,m0);
				    	setcolor(4);   
						setfillstyle(1,4);
				    	int m1[8]={cactus.x-35,cactus.y+20,cactus.x+35,cactus.y+20,cactus.x+25,cactus.y+45,cactus.x-25,cactus.y+45};
				    	fillpoly(4,m1);
				    	//CARA 3
				    	setcolor(0);   
						setfillstyle(1,0);
				    	fillellipse(cactus.x,cactus.y+33,3,4);
				    	int m2[6]={cactus.x-20,cactus.y+25,cactus.x-10,cactus.y+30,cactus.x-20,cactus.y+35};
				    	int m3[6]={cactus.x+20,cactus.y+25,cactus.x+10,cactus.y+30,cactus.x+20,cactus.y+35};
						drawpoly(3,m2);
						drawpoly(3,m3);
					}
				}
			}
		}	
}



void ghost(gamer ghost, int tiempo,int dir)
{
    if (dir == 0){
    	//CUERPO 0
    	setcolor(4);
    	setfillstyle(1,4);
    	fillellipse(ghost.x,ghost.y-7,43,43);
    	int gh[18]={ghost.x-43,ghost.y-8,ghost.x+43,ghost.y-8,ghost.x+43,ghost.y+45,ghost.x+25,ghost.y+36,ghost.x+13,ghost.y+45,ghost.x,ghost.y+36,ghost.x-13,ghost.y+45,ghost.x-25,ghost.y+36,ghost.x-43,ghost.y+45};
    	fillpoly(9,gh);
		//OJOS 0
    	setcolor(15);
    	setfillstyle(1,15);
    	fillellipse(ghost.x+10,ghost.y-11,12,12);
    	fillellipse(ghost.x-25,ghost.y-11,12,12);
    	setcolor(1);
    	setfillstyle(1,1);
    	fillellipse(ghost.x+5,ghost.y-10,6,6);
    	fillellipse(ghost.x-30,ghost.y-10,6,6);
	}
    if(tiempo==0 && dir == 3){
		//CUERPO 0
    	setcolor(4);
    	setfillstyle(1,4);
    	fillellipse(ghost.x,ghost.y-7,43,43);
    	int gh[18]={ghost.x-43,ghost.y-8,ghost.x+43,ghost.y-8,ghost.x+43,ghost.y+45,ghost.x+25,ghost.y+36,ghost.x+13,ghost.y+45,ghost.x,ghost.y+36,ghost.x-13,ghost.y+45,ghost.x-25,ghost.y+36,ghost.x-43,ghost.y+45};
    	fillpoly(9,gh);
		//OJOS 0
    	setcolor(15);
    	setfillstyle(1,15);
    	fillellipse(ghost.x+10,ghost.y-11,12,12);
    	fillellipse(ghost.x-25,ghost.y-11,12,12);
    	setcolor(1);
    	setfillstyle(1,1);
    	fillellipse(ghost.x+5,ghost.y-10,6,6);
    	fillellipse(ghost.x-30,ghost.y-10,6,6);
	}else{
			if(tiempo==1 && dir == 3){
			//CUERPO 1
	    	setcolor(14);
	    	setfillstyle(1,14);
	    	fillellipse(ghost.x,ghost.y-7,43,43);
	    	int gh[18]={ghost.x-43,ghost.y-8,ghost.x+43,ghost.y-8,ghost.x+43,ghost.y+45,ghost.x+25,ghost.y+36,ghost.x+13,ghost.y+45,ghost.x,ghost.y+36,ghost.x-13,ghost.y+45,ghost.x-25,ghost.y+36,ghost.x-43,ghost.y+45};
	    	fillpoly(9,gh);
			//OJOS 1
	    	setcolor(15);
	    	setfillstyle(1,15);
	    	fillellipse(ghost.x+10,ghost.y-11,12,12);
	    	fillellipse(ghost.x-25,ghost.y-11,12,12);
	    	setcolor(1);
	    	setfillstyle(1,1);
	    	fillellipse(ghost.x+5,ghost.y-10,6,6);
	    	fillellipse(ghost.x-30,ghost.y-10,6,6);	
			}else{
				if(tiempo==0 && dir==4){
					//CUERPO 2
			    	setcolor(3);
			    	setfillstyle(1,3);
			    	fillellipse(ghost.x,ghost.y-7,43,43);
			    	int gh[18]={ghost.x-43,ghost.y-8,ghost.x+43,ghost.y-8,ghost.x+43,ghost.y+45,ghost.x+25,ghost.y+36,ghost.x+13,ghost.y+45,ghost.x,ghost.y+36,ghost.x-13,ghost.y+45,ghost.x-25,ghost.y+36,ghost.x-43,ghost.y+45};
			    	fillpoly(9,gh);
					//OJOS 2
			    	setcolor(15);
			    	setfillstyle(1,15);
			    	fillellipse(ghost.x-10,ghost.y-11,12,12);
			    	fillellipse(ghost.x+25,ghost.y-11,12,12);
			    	setcolor(1);
			    	setfillstyle(1,1);
			    	fillellipse(ghost.x-5,ghost.y-10,6,6);
			    	fillellipse(ghost.x+30,ghost.y-10,6,6);
				}else{
					if(tiempo==1 && dir==4){
						//CUERPO 3
				    	setcolor(13);
				    	setfillstyle(1,13);
				    	fillellipse(ghost.x,ghost.y-7,43,43);
				    	int gh[18]={ghost.x-43,ghost.y-8,ghost.x+43,ghost.y-8,ghost.x+43,ghost.y+45,ghost.x+25,ghost.y+36,ghost.x+13,ghost.y+45,ghost.x,ghost.y+36,ghost.x-13,ghost.y+45,ghost.x-25,ghost.y+36,ghost.x-43,ghost.y+45};
				    	fillpoly(9,gh);
						//OJOS 3
				    	setcolor(15);
				    	setfillstyle(1,15);
				    	fillellipse(ghost.x-10,ghost.y-11,12,12);
				    	fillellipse(ghost.x+25,ghost.y-11,12,12);
				    	setcolor(1);
				    	setfillstyle(1,1);
				    	fillellipse(ghost.x-5,ghost.y-10,6,6);
				    	fillellipse(ghost.x+30,ghost.y-10,6,6);
					}
				}
			}
		}	
}

void puma(gamer puma, int tiempo,int dir)
{
    if (dir == 0){
		setcolor(1);
	    setfillstyle(1,1);
		fillellipse(puma.x,puma.y,50,50);
    	setcolor(14);    
		setfillstyle(1,14);
    	fillellipse(puma.x,puma.y-5,34,36);
    	int unam0[8]={puma.x-34,puma.y-3,puma.x-15,puma.y-4,puma.x-20,puma.y+26,puma.x-27,puma.y+28};
    	int unam1[8]={puma.x+34,puma.y-3,puma.x+15,puma.y-4,puma.x+20,puma.y+26,puma.x+27,puma.y+28};
    	fillpoly(4,unam0);
    	fillpoly(4,unam1);
    	setcolor(1);    
		setfillstyle(1,1);
		fillellipse(puma.x-13,puma.y-14,11,13);
    	fillellipse(puma.x+13,puma.y-14,11,13);
    	int unam2[8]={puma.x-15,puma.y-13,puma.x+15,puma.y-13,puma.x+20,puma.y+32,puma.x-20,puma.y+32};
    	fillpoly(4,unam2);
    	setcolor(14);    
		setfillstyle(1,14);
    	fillellipse(puma.x-31,puma.y-22,11,13);
    	fillellipse(puma.x+31,puma.y-22,11,13);
    	fillellipse(puma.x-25,puma.y+26,3,3);
    	fillellipse(puma.x+25,puma.y+26,3,3);
    	fillellipse(puma.x-14,puma.y+26,3,3);
    	fillellipse(puma.x+14,puma.y+26,3,3);
    	fillellipse(puma.x-11,puma.y+41,3,5);
    	fillellipse(puma.x+11,puma.y+41,3,5);
    	int unam3[8]={puma.x-10,puma.y-11,puma.x+10,puma.y-11,puma.x+13,puma.y+14,puma.x-13,puma.y+14};
    	int unam4[8]={puma.x+29,puma.y-34,puma.x+25,puma.y-11,puma.x-25,puma.y-11,puma.x-29,puma.y-34};
    	int unam5[8]={puma.x-25,puma.y+23,puma.x-14,puma.y+23,puma.x-14,puma.y+29,puma.x-25,puma.y+29};
    	int unam6[8]={puma.x+25,puma.y+23,puma.x+14,puma.y+23,puma.x+14,puma.y+29,puma.x+25,puma.y+29};
    	int unam7[8]={puma.x-11,puma.y+36,puma.x+11,puma.y+36,puma.x+11,puma.y+46,puma.x-11,puma.y+46};
    	fillpoly(4,unam3);
    	fillpoly(4,unam4);
    	fillpoly(4,unam5);
    	fillpoly(4,unam6);
    	fillpoly(4,unam7);
    	int unam8[6]={puma.x-40,puma.y-15,puma.x-32,puma.y-15,puma.x-32,puma.y+4};
    	int unam9[6]={puma.x+40,puma.y-15,puma.x+32,puma.y-15,puma.x+32,puma.y+4};
    	int unam10[6]={puma.x-7,puma.y-39,puma.x-32,puma.y-34,puma.x-7,puma.y-34};
    	int unam11[6]={puma.x+7,puma.y-39,puma.x+32,puma.y-34,puma.x+7,puma.y-34};
    	fillpoly(3,unam8);
    	fillpoly(3,unam9);
    	fillpoly(3,unam10);
    	fillpoly(3,unam11);		
	}
	else{
	    if(tiempo==0 && dir == 3){
	    	setcolor(1);
		    setfillstyle(1,1);
			fillellipse(puma.x,puma.y,50,50);
			setcolor(14);    
			setfillstyle(1,14);
	    	fillellipse(puma.x,puma.y-5,34,36);
	    	int unam0[8]={puma.x-34,puma.y-3,puma.x-15,puma.y-4,puma.x-20,puma.y+26,puma.x-27,puma.y+28};
	    	int unam1[8]={puma.x+34,puma.y-3,puma.x+15,puma.y-4,puma.x+20,puma.y+26,puma.x+27,puma.y+28};
	    	fillpoly(4,unam0);
	    	fillpoly(4,unam1);
	    	setcolor(1);    
			setfillstyle(1,1);
			fillellipse(puma.x-13,puma.y-14,11,13);
	    	fillellipse(puma.x+13,puma.y-14,11,13);
	    	int unam2[8]={puma.x-15,puma.y-13,puma.x+15,puma.y-13,puma.x+20,puma.y+32,puma.x-20,puma.y+32};
	    	fillpoly(4,unam2);
	    	setcolor(14);    
			setfillstyle(1,14);
	    	fillellipse(puma.x-31,puma.y-22,11,13);
	    	fillellipse(puma.x+31,puma.y-22,11,13);
	    	fillellipse(puma.x-25,puma.y+26,3,3);
	    	fillellipse(puma.x+25,puma.y+26,3,3);
	    	fillellipse(puma.x-14,puma.y+26,3,3);
	    	fillellipse(puma.x+14,puma.y+26,3,3);
	    	fillellipse(puma.x-11,puma.y+41,3,5);
	    	fillellipse(puma.x+11,puma.y+41,3,5);
	    	int unam3[8]={puma.x-10,puma.y-11,puma.x+10,puma.y-11,puma.x+13,puma.y+14,puma.x-13,puma.y+14};
	    	int unam4[8]={puma.x+29,puma.y-34,puma.x+25,puma.y-11,puma.x-25,puma.y-11,puma.x-29,puma.y-34};
	    	int unam5[8]={puma.x-25,puma.y+23,puma.x-14,puma.y+23,puma.x-14,puma.y+29,puma.x-25,puma.y+29};
	    	int unam6[8]={puma.x+25,puma.y+23,puma.x+14,puma.y+23,puma.x+14,puma.y+29,puma.x+25,puma.y+29};
	    	int unam7[8]={puma.x-11,puma.y+36,puma.x+11,puma.y+36,puma.x+11,puma.y+46,puma.x-11,puma.y+46};
	    	fillpoly(4,unam3);
	    	fillpoly(4,unam4);
	    	fillpoly(4,unam5);
	    	fillpoly(4,unam6);
	    	fillpoly(4,unam7);
	    	int unam8[6]={puma.x-40,puma.y-15,puma.x-32,puma.y-15,puma.x-32,puma.y+4};
	    	int unam9[6]={puma.x+40,puma.y-15,puma.x+32,puma.y-15,puma.x+32,puma.y+4};
	    	int unam10[6]={puma.x-7,puma.y-39,puma.x-32,puma.y-34,puma.x-7,puma.y-34};
	    	int unam11[6]={puma.x+7,puma.y-39,puma.x+32,puma.y-34,puma.x+7,puma.y-34};
	    	fillpoly(3,unam8);
	    	fillpoly(3,unam9);
	    	fillpoly(3,unam10);
	    	fillpoly(3,unam11);		
		}
		else{
			if(tiempo==1 && dir == 3){
				setcolor(14);
			    setfillstyle(1,14);
				fillellipse(puma.x,puma.y,50,50);
				setcolor(1);    
				setfillstyle(1,1);
		    	fillellipse(puma.x,puma.y-5,34,36);
		    	int unam0[8]={puma.x-34,puma.y-3,puma.x-15,puma.y-4,puma.x-20,puma.y+26,puma.x-27,puma.y+28};
		    	int unam1[8]={puma.x+34,puma.y-3,puma.x+15,puma.y-4,puma.x+20,puma.y+26,puma.x+27,puma.y+28};
		    	fillpoly(4,unam0);
		    	fillpoly(4,unam1);
		    	setcolor(14);    
				setfillstyle(1,14);
				fillellipse(puma.x-13,puma.y-14,11,13);
		    	fillellipse(puma.x+13,puma.y-14,11,13);
		    	int unam2[8]={puma.x-15,puma.y-13,puma.x+15,puma.y-13,puma.x+20,puma.y+32,puma.x-20,puma.y+32};
		    	fillpoly(4,unam2);
		    	setcolor(1);    
				setfillstyle(1,1);
		    	fillellipse(puma.x-31,puma.y-22,11,13);
		    	fillellipse(puma.x+31,puma.y-22,11,13);
		    	fillellipse(puma.x-25,puma.y+26,3,3);
		    	fillellipse(puma.x+25,puma.y+26,3,3);
		    	fillellipse(puma.x-14,puma.y+26,3,3);
		    	fillellipse(puma.x+14,puma.y+26,3,3);
		    	fillellipse(puma.x-11,puma.y+41,3,5);
		    	fillellipse(puma.x+11,puma.y+41,3,5);
		    	int unam3[8]={puma.x-10,puma.y-11,puma.x+10,puma.y-11,puma.x+13,puma.y+14,puma.x-13,puma.y+14};
		    	int unam4[8]={puma.x+29,puma.y-34,puma.x+25,puma.y-11,puma.x-25,puma.y-11,puma.x-29,puma.y-34};
		    	int unam5[8]={puma.x-25,puma.y+23,puma.x-14,puma.y+23,puma.x-14,puma.y+29,puma.x-25,puma.y+29};
		    	int unam6[8]={puma.x+25,puma.y+23,puma.x+14,puma.y+23,puma.x+14,puma.y+29,puma.x+25,puma.y+29};
		    	int unam7[8]={puma.x-11,puma.y+36,puma.x+11,puma.y+36,puma.x+11,puma.y+46,puma.x-11,puma.y+46};
		    	fillpoly(4,unam3);
		    	fillpoly(4,unam4);
		    	fillpoly(4,unam5);
		    	fillpoly(4,unam6);
		    	fillpoly(4,unam7);
		    	int unam8[6]={puma.x-40,puma.y-15,puma.x-32,puma.y-15,puma.x-32,puma.y+4};
		    	int unam9[6]={puma.x+40,puma.y-15,puma.x+32,puma.y-15,puma.x+32,puma.y+4};
		    	int unam10[6]={puma.x-7,puma.y-39,puma.x-32,puma.y-34,puma.x-7,puma.y-34};
		    	int unam11[6]={puma.x+7,puma.y-39,puma.x+32,puma.y-34,puma.x+7,puma.y-34};
		    	fillpoly(3,unam8);
		    	fillpoly(3,unam9);
		    	fillpoly(3,unam10);
		    	fillpoly(3,unam11);		
				}
			else{
				if(tiempo==0 && dir==4){
					setcolor(14);
				    setfillstyle(1,14);
					fillellipse(puma.x,puma.y,50,50);
					setcolor(1);    
					setfillstyle(1,1);
			    	fillellipse(puma.x,puma.y-5,34,36);
			    	int unam0[8]={puma.x-34,puma.y-3,puma.x-15,puma.y-4,puma.x-20,puma.y+26,puma.x-27,puma.y+28};
			    	int unam1[8]={puma.x+34,puma.y-3,puma.x+15,puma.y-4,puma.x+20,puma.y+26,puma.x+27,puma.y+28};
			    	fillpoly(4,unam0);
			    	fillpoly(4,unam1);
			    	setcolor(14);    
					setfillstyle(1,14);
					fillellipse(puma.x-13,puma.y-14,11,13);
			    	fillellipse(puma.x+13,puma.y-14,11,13);
			    	int unam2[8]={puma.x-15,puma.y-13,puma.x+15,puma.y-13,puma.x+20,puma.y+32,puma.x-20,puma.y+32};
			    	fillpoly(4,unam2);
			    	setcolor(1);    
					setfillstyle(1,1);
			    	fillellipse(puma.x-31,puma.y-22,11,13);
			    	fillellipse(puma.x+31,puma.y-22,11,13);
			    	fillellipse(puma.x-25,puma.y+26,3,3);
			    	fillellipse(puma.x+25,puma.y+26,3,3);
			    	fillellipse(puma.x-14,puma.y+26,3,3);
			    	fillellipse(puma.x+14,puma.y+26,3,3);
			    	fillellipse(puma.x-11,puma.y+41,3,5);
			    	fillellipse(puma.x+11,puma.y+41,3,5);
			    	int unam3[8]={puma.x-10,puma.y-11,puma.x+10,puma.y-11,puma.x+13,puma.y+14,puma.x-13,puma.y+14};
			    	int unam4[8]={puma.x+29,puma.y-34,puma.x+25,puma.y-11,puma.x-25,puma.y-11,puma.x-29,puma.y-34};
			    	int unam5[8]={puma.x-25,puma.y+23,puma.x-14,puma.y+23,puma.x-14,puma.y+29,puma.x-25,puma.y+29};
			    	int unam6[8]={puma.x+25,puma.y+23,puma.x+14,puma.y+23,puma.x+14,puma.y+29,puma.x+25,puma.y+29};
			    	int unam7[8]={puma.x-11,puma.y+36,puma.x+11,puma.y+36,puma.x+11,puma.y+46,puma.x-11,puma.y+46};
			    	fillpoly(4,unam3);
			    	fillpoly(4,unam4);
			    	fillpoly(4,unam5);
			    	fillpoly(4,unam6);
			    	fillpoly(4,unam7);
			    	int unam8[6]={puma.x-40,puma.y-15,puma.x-32,puma.y-15,puma.x-32,puma.y+4};
			    	int unam9[6]={puma.x+40,puma.y-15,puma.x+32,puma.y-15,puma.x+32,puma.y+4};
			    	int unam10[6]={puma.x-7,puma.y-39,puma.x-32,puma.y-34,puma.x-7,puma.y-34};
			    	int unam11[6]={puma.x+7,puma.y-39,puma.x+32,puma.y-34,puma.x+7,puma.y-34};
			    	fillpoly(3,unam8);
			    	fillpoly(3,unam9);
			    	fillpoly(3,unam10);
			    	fillpoly(3,unam11);		
					}
					else{
						if(tiempo==1 && dir==4){
								setcolor(14);    
								setfillstyle(1,14);
						    	fillellipse(puma.x,puma.y-5,34,36);
						    	int unam0[8]={puma.x-34,puma.y-3,puma.x-15,puma.y-4,puma.x-20,puma.y+26,puma.x-27,puma.y+28};
						    	int unam1[8]={puma.x+34,puma.y-3,puma.x+15,puma.y-4,puma.x+20,puma.y+26,puma.x+27,puma.y+28};
						    	fillpoly(4,unam0);
						    	fillpoly(4,unam1);
						    	setcolor(1);    
								setfillstyle(1,1);
								fillellipse(puma.x-13,puma.y-14,11,13);
						    	fillellipse(puma.x+13,puma.y-14,11,13);
						    	int unam2[8]={puma.x-15,puma.y-13,puma.x+15,puma.y-13,puma.x+20,puma.y+32,puma.x-20,puma.y+32};
						    	fillpoly(4,unam2);
						    	setcolor(14);    
								setfillstyle(1,14);
						    	fillellipse(puma.x-31,puma.y-22,11,13);
						    	fillellipse(puma.x+31,puma.y-22,11,13);
						    	fillellipse(puma.x-25,puma.y+26,3,3);
						    	fillellipse(puma.x+25,puma.y+26,3,3);
						    	fillellipse(puma.x-14,puma.y+26,3,3);
						    	fillellipse(puma.x+14,puma.y+26,3,3);
						    	fillellipse(puma.x-11,puma.y+41,3,5);
						    	fillellipse(puma.x+11,puma.y+41,3,5);
						    	int unam3[8]={puma.x-10,puma.y-11,puma.x+10,puma.y-11,puma.x+13,puma.y+14,puma.x-13,puma.y+14};
						    	int unam4[8]={puma.x+29,puma.y-34,puma.x+25,puma.y-11,puma.x-25,puma.y-11,puma.x-29,puma.y-34};
						    	int unam5[8]={puma.x-25,puma.y+23,puma.x-14,puma.y+23,puma.x-14,puma.y+29,puma.x-25,puma.y+29};
						    	int unam6[8]={puma.x+25,puma.y+23,puma.x+14,puma.y+23,puma.x+14,puma.y+29,puma.x+25,puma.y+29};
						    	int unam7[8]={puma.x-11,puma.y+36,puma.x+11,puma.y+36,puma.x+11,puma.y+46,puma.x-11,puma.y+46};
						    	fillpoly(4,unam3);
						    	fillpoly(4,unam4);
						    	fillpoly(4,unam5);
						    	fillpoly(4,unam6);
						    	fillpoly(4,unam7);
						    	int unam8[6]={puma.x-40,puma.y-15,puma.x-32,puma.y-15,puma.x-32,puma.y+4};
						    	int unam9[6]={puma.x+40,puma.y-15,puma.x+32,puma.y-15,puma.x+32,puma.y+4};
						    	int unam10[6]={puma.x-7,puma.y-39,puma.x-32,puma.y-34,puma.x-7,puma.y-34};
						    	int unam11[6]={puma.x+7,puma.y-39,puma.x+32,puma.y-34,puma.x+7,puma.y-34};
						    	fillpoly(3,unam8);
						    	fillpoly(3,unam9);
						    	fillpoly(3,unam10);
						    	fillpoly(3,unam11);		
						}
					}
			}
		}
	}	
}
//skins

void dibujojugador(gamer player, int tiempo, int dir, int skiner){
	//rectangle(player.x-20,player.y-50,player.x+20,player.y+50);
	/*
	dibujaGallina(gamer gallina, int tiempo,int dir);  1
	chiken(gamer gallina, int tiempo,int dir)
	goldchik(gamer gallina, int tiempo,int dir)		2
	ironchik(gamer gallina, int tiempo,int dir)		8
	Iam_chik(gamer gallina, int tiempo,int dir)		7
	pacman(gamer pacman, int tiempo,int dir)		4
	chicorn(gamer gallina, int tiempo,int dir)		6
	cactus(gamer cactus, int tiempo,int dir)		3
	ghost(gamer ghost, int tiempo,int dir)		5
	puma(gamer puma, int tiempo,int dir)		9
	*/
	switch(skiner){
		case 1:
			chiken(player,tiempo,dir);
			break;
		case 2:
			goldchik(player,tiempo,dir);
			break;
		case 3:
			cactus(player,tiempo,dir);
			break;
		case 4:
			pacman(player,tiempo,dir);
			break;
		case 5:
			ghost(player,tiempo,dir);
			break;
		case 6:
			chicorn(player,tiempo,dir);
			break;
		case 7:
			Iam_chik(player,tiempo,dir);
			break;
		case 8:
			ironchik(player,tiempo,dir);
			break;
		case 9:
			puma(player,tiempo,dir);
			break;
	}
	
	
}

void mover(gamer *player,int dir,int nivel){
	
	nivel -= 5;
	if (nivel < 0){
		nivel = 0;
	}
	
	switch(dir){
			case 1:
				player->y-=25;
				break;
			case 2:
				player->y+=25;
				break;
			case 3:
				player->x-=15+nivel;
				break;
			case 4:
				player->x+=15+nivel;
				break;
			
		}
}

void detectar(int *dir){
	char alfa;
	alfa = kbhit();
	
	if (alfa == 1){
		alfa = getch();
		switch(alfa){
			case up:
				//*dir =1;
				break;
			case down:
				//*dir =2;
				break;
			case left:
				*dir =3;
				break;
			case derecha:
				*dir =4;
				break;
			case enter:
				//*dir = 10;
				break;
			
		}
	}
	fflush(stdin);
}

void detener(gamer *player){
	if(player->x <= 350){
		player->x = 350;
	}
	if(player->x >= 750){
		player->x = 750;
	}
	if(player->y <= 50){
		player->activo = 0;
	}
}


void generar(gamer *globo)
{
	//300-800
	int alfa;
	switch(globo->tipo){
		case 1:
			alfa = rand()%15;
			break;
		case 2:
			alfa = rand()%20;
			break;
		case 3:
			alfa = rand()%50;
			break;
		case 4:
			alfa = rand()%55;
			
	}
	if(globo->activo == 0 && alfa != 0){
		globo->x = 0;
   		globo->y = 0;
	}
	
	if (globo->activo == 0 && !alfa){
		globo->x = 360 + (rand()%8)*50;
   		globo->y = 650;
   		globo->activo = 1;
	}
}


void dibujaGlobo(gamer globo, int color, int tiempo)
{
	
	if(globo.activo){
	
	
	setcolor(7);
	circle(globo.x,globo.y+10,40);
	setfillstyle(1,color);
	fillellipse(globo.x, globo.y+10, 40, 40);
	floodfill (globo.x+2,globo.y+2,7);
	
	int vect[20];
	vect[0]= globo.x;
	vect[1]= globo.y+50;
	
	vect[2]= globo.x-4;
	vect[3]= globo.y+53;
	
	vect[4]= globo.x-5;
	vect[5]= globo.y+54;
	
	vect[6]= globo.x-5;
	vect[7]= globo.y+55;
	
	vect[8]= globo.x-4; 
	vect[9]= globo.y+56;
	
	vect[10]= globo.x+4;
	vect[11]= globo.y+56;
	
	vect[12]= globo.x+5;
	vect[13]= globo.y+55;
	
	vect[14]= globo.x+5;
	vect[15]= globo.y+54;
	
	vect[16]= globo.x+4;
	vect[17]= globo.y+53;
	
	vect[18]= vect[0];
	vect[19]= vect[1];
	
	setcolor(color);
	fillpoly(9, vect);

	if(tiempo)
	{
		int vec1[16];
		vec1[0]= globo.x;
		vec1[1]= globo.y+56;
		vec1[2]= globo.x;
		vec1[3]= globo.y+58;
		vec1[4]= globo.x-2;
		vec1[5]= globo.y+60;
		vec1[6]= globo.x-2;
		vec1[7]= globo.y+63;
		vec1[8]= globo.x+2; 
		vec1[9]= globo.y+67;
		vec1[10]= globo.x+2;
		vec1[11]= globo.y+70;
		vec1[12]= globo.x;
		vec1[13]= globo.y+72;
		vec1[14]= globo.x;
		vec1[15]= globo.y+75;
		setcolor(color);
		setfillstyle(0,color);
		fillpoly(8, vec1);
		setcolor(getbkcolor());
		line(globo.x, globo.y+59, globo.x, globo.y+65); 
		line(globo.x, globo.y+66, globo.x, globo.y+72);	
	}else{
		int vec2[16];
		vec2[0]= globo.x;
		vec2[1]= globo.y+56;
		vec2[2]= globo.x;
		vec2[3]= globo.y+58;
		vec2[4]= globo.x+2;
		vec2[5]= globo.y+60;
		vec2[6]= globo.x+2;
		vec2[7]= globo.y+63;
		vec2[8]= globo.x-2; 
		vec2[9]= globo.y+67;
		vec2[10]= globo.x-2;
		vec2[11]= globo.y+70;
		vec2[12]= globo.x;
		vec2[13]= globo.y+72;
		vec2[14]= globo.x;
		vec2[15]= globo.y+75;
		setcolor(color);
		setfillstyle(0,color);
		fillpoly(8, vec2);
		setcolor(getbkcolor());
		line(globo.x, globo.y+59, globo.x, globo.y+65); 
		line(globo.x, globo.y+66, globo.x, globo.y+72);
	}
		}
			}


void mensaje(int nivel){
	char msg[20];
	settextstyle(3,0,5);

	setbkcolor(6);
	setcolor(WHITE);
	strcpy(msg,"");
	sprintf(msg,"Puntos: %d",nivel);
	outtextxy(850,50,msg);
	setbkcolor(BLACK);
}

int choque(gamer *globo,gamer player){
	int x0,y0,dista;
	x0 = globo->x;
	y0 = globo->y;
	y0+= 10;
	
	x0-=player.x;
	y0-=player.y;
	dista = sqrt(pow(x0,2)+pow(y0,2));
	
	if(dista <= 90){
		globo->activo = 0;
		return 1;
	}else{
		return 0;
	}
}

int juego(int skiner){
	
	gamer player,globo1,globo2,globo3;
   gamer malo1,malo2,malo3;
   gamer bonus,castigo;
   
   
   player.x = 500;
   player.y = 200;
   
   
   globo1.activo = 0;
   globo2.activo = 0;
   globo3.activo = 0;
   globo1.tipo = 1;
   globo2.tipo = 1;
   globo3.tipo = 1;
   
   
   malo1.activo = 0;
   malo2.activo = 0;
   malo3.activo = 0;
   malo1.tipo = 2;
   malo2.tipo = 2;
   malo3.tipo = 2;
   
   bonus.activo = 0;
   bonus.tipo = 3;
   
   castigo.activo =0;
   castigo.tipo = 3;
   
   //int puntos=0;
   int tiempo,ganar = 1,dir=0;
   int puntos = 0,aux = 0;
   
   
//   getch();
	while (ganar){
   	granpantalla();
	detectar(&dir);
   	
	if (dir == 10){
		ganar = 0;
	}
	muro(tiempo%2);
//	dibujojugador(player);


	generar(&globo1);
	generar(&globo2);
	generar(&globo3);
	generar(&malo1);
	generar(&malo2);
	generar(&malo3);
	
	
	if(puntos > 15){
		generar(&bonus);
	}
	if(puntos > 18){
		generar(&castigo);
	}
	
	mover(&player,dir,skiner + 6);
	mover(&globo1,1,puntos);
	mover(&globo2,1,puntos);
	mover(&globo3,1,puntos);
	mover(&malo1,1,puntos);
	mover(&malo2,1,puntos);
	mover(&malo3,1,puntos);
	
	if(bonus.activo){
		mover(&bonus,1,puntos);
	}
	if(castigo.activo){
		mover(&castigo,1,puntos);
	}
	
	
	
	detener(&player);
	detener(&globo1);
	detener(&globo2);
	detener(&globo3);
	detener(&malo1);
	detener(&malo2);
	detener(&malo3);
	if(bonus.activo){
		detener(&bonus);
	}
	if(castigo.activo){
		detener(&castigo);
	}
	
	
	
	dibujaGlobo(globo1,BLUE,tiempo%2);
	dibujaGlobo(globo2,BLUE,tiempo%2);
	dibujaGlobo(globo3,BLUE,tiempo%2);
	dibujaGlobo(malo1,RED,tiempo%2);
	dibujaGlobo(malo2,RED,tiempo%2);
	dibujaGlobo(malo3,RED,tiempo%2);
	
	dibujaGlobo(bonus,GREEN,tiempo%2);
	dibujaGlobo(castigo,BLACK,tiempo%2);
	
	
	//dibujaGallina(player,tiempo%2,dir);
	dibujojugador(player,tiempo%2,dir,skiner);
	puntos += choque(&globo1,player);
	puntos += choque(&globo2,player);
	puntos += choque(&globo3,player);
	
	
	if(bonus.activo){
	//	detener(&bonus);
		puntos += 5*choque(&bonus,player);
	}
	if(castigo.activo){
	//	detener(&castigo);
		puntos -= 7*choque(&castigo,player);
	}
	
	aux += choque(&malo1,player);
	aux += choque(&malo2,player);
	aux += choque(&malo3,player);
	
	if(aux){
		ganar = 0;
	}
	
	mensaje(puntos);
	
	Sleep(100);
	cleardevice();
	tiempo++;
	}
   
//   getch();
	
	return puntos;
}

void director(){
	int error;
	FILE *doc;
	error = system("cd c:/Gallina");
	if (error != 0){
//		printf("no existes :v");
		system("cd c:/ && md Gallina");
		
		doc = fopen("c:/Gallina/puntos.txt", "w");
	
	fprintf(doc,"Yoyo 0\nJoraso 0\nxo 0");
    fclose(doc);
		director();
//		break; //nota******
	}else{
//		printf("holi");
		system("cd c:/Gallina && attrib puntos.txt -h");
		doc = fopen("c:/Gallina/puntos.txt", "r");
	if(doc == NULL){
//		printf("NELSON");
		fclose(doc);	
		doc = fopen("c:/Gallina/puntos.txt", "w");
	
	fprintf(doc,"Yoyo 0\nJoraso 0\nxo 0");
    fclose(doc);
		
		
	}else{
	fclose(doc); 

	}
	
	}
	
	
}


int gameover(char name[10], int punt){
	char nombre[3][10],msg[20];
	int puntos[3],i;
	FILE *archi;
	
	muro(0);
	setbkcolor(9);
	setcolor(YELLOW);
	settextstyle(1,0, 5);
//	outtextxy(409,350,"Score");
//	outtextxy(415,280,"High");
	outtextxy(409,80,"Your");
	outtextxy(415,130,"Score");
	Sleep(500);
	
	setcolor(WHITE);
	settextstyle(1,0, 1);
	
	strcpy(msg,"");
	sprintf(msg,"%s\t --- %d",name,punt);
	outtextxy(430,250,msg);
	Sleep(1000);
	
	setcolor(YELLOW);
	settextstyle(1,0, 5);
	outtextxy(415,350,"High");
	outtextxy(409,400,"Score");
	Sleep(1000);
	
	setcolor(WHITE);
	settextstyle(1,0, 1);
	
	archi = fopen("c:/Gallina/puntos.txt","r");
	for(i=0;i<3;i++){
		fscanf(archi,"%s %d\n",&nombre[i],&puntos[i]);
		strcpy(msg,"");
		sprintf(msg,"%s\t --- %d",nombre[i],puntos[i]);
		outtextxy(430, 450+i*53,msg);
		Sleep(1000);
	}
	
	fclose(archi);
	archi = fopen("c:/Gallina/firma.txt","w");
	fprintf(archi,"Este juego fue hecho por:\nArturo \
	Arellano Bautista(Yoyo)\nJose Ramon Solorzano Roa(Joraso)\
	\n\tGrupo 2203\n\tUniversidad Nacional Autonoma de Mexico\
	\n\tFES Acatlan\n\tGracias por jugar uwu");
	fclose(archi);
	
	setbkcolor(6);
	setcolor(YELLOW);
	settextstyle(1,0, 5);
	outtextxy(120,280,"Play");
	outtextxy(120,330,"Again");
//	outtextxy(415,280,"High");
	outtextxy(800,280,"Change");
	outtextxy(800,330,"Name");
	outtextxy(120,500,"Exit");
	settextstyle(1,0, 1);
//	outtextxy(828,350,"to");
	setcolor(WHITE);
	settextstyle(1,0, 1);
	outtextxy(120,400,"(Press space)");
	outtextxy(120,550,"(Press esc)");	
	outtextxy(800,400,"(Press into)");
	
//	getch();
}



void wardar(char auxn[40],int auxp){
	
	char nombre[3][10];
	int puntos[3],i;
	FILE *archi;
	archi = fopen("c:/Gallina/puntos.txt","r");
	for(i=0;i<3;i++){
		fscanf(archi,"%s %d\n",&nombre[i],&puntos[i]);
	}
	fclose(archi);
/*	for(i=0;i<3;i++){
		
	printf("%s %d \n",nombre[i],puntos[i]);
	}
*/
/*	char auxn[10];
	int auxp;*/
	
/*	fflush(stdin);
	gets(auxn);
	scanf("%d",&auxp);
	printf("\n\n");*/
	archi = fopen("c:/Gallina/puntos.txt","w");
	if(auxp > puntos[0]){
		fprintf(archi,"%s %d\n",auxn,auxp);
		fprintf(archi,"%s %d\n",nombre[0],puntos[0]);
		fprintf(archi,"%s %d\n",nombre[1],puntos[1]);
	}else if(auxp > puntos[1]){
		fprintf(archi,"%s %d\n",nombre[0],puntos[0]);
		fprintf(archi,"%s %d\n",auxn,auxp);
		fprintf(archi,"%s %d\n",nombre[1],puntos[1]);
	}else if(auxp > puntos[2]){
		fprintf(archi,"%s %d\n",nombre[0],puntos[0]);
		fprintf(archi,"%s %d\n",nombre[1],puntos[1]);
		fprintf(archi,"%s %d\n",auxn,auxp);
	}else{
		for(i=0;i<3;i++){
		
	fprintf(archi,"%s %d\n",nombre[i],puntos[i]);
	}
	}
		
	fclose(archi);
	
	gameover(auxn,auxp);
	
	system("cd c:/Gallina && attrib puntos.txt +h");
	
}

//prueba

int menu(char name[20])
{
setcolor(CYAN);
	rectangle(50, 50, 1050, 650);
	int v[8]={50,50,1050,50,1050,650,50,650};
	setfillstyle(1,CYAN);
	fillpoly(4,v);
	setbkcolor(CYAN);
	int gdcx,gdcy=535;
	{//C
	setcolor(15);
	setfillstyle(1,15);
	fillellipse(200,170,88,90);
	setcolor(getbkcolor());
	setfillstyle(1,getbkcolor());
	fillellipse(200,170,60,57);
	int A0[8]={238,130,290,80,290,260,238,210};
	fillpoly(4,A0);
	setcolor(YELLOW);
	}
	{//h
	setcolor(15);
	int B0[8]={270,118,295,118,295,260,270,260};
	int B1[8]={332,178,357,178,357,260,332,260};
	setfillstyle(1,15);
	fillpoly(4,B0);	
	fillpoly(4,B1);
	fillellipse(318,194,42,47);
	
	setcolor(getbkcolor());
	setfillstyle(1,getbkcolor());
	fillellipse(314,184,19,23);
	int B2[8]={295,260,332,260,332,178,295,178};
	int B3[8]={357,175,370,175,370,260,357,260};
	fillpoly(4,B2);
	fillpoly(4,B3);
	}
	{//i
	setcolor(15);
	int C0[8]={363,159,387,159,387,260,363,260};
	setfillstyle(1,15);
	fillpoly(4,C0);
	fillellipse(375,137,13,13);	
	}
	{//k
	int D0[8]={395,119,420,119,420,260,395,260};
	int D1[12]={412,204,453,155,490,155,444,204,495,260,465,260};
	setfillstyle(1,15);
	fillpoly(4,D0);	
	fillpoly(6,D1);
	}
	{//e
	int h=540,k=208;
	setcolor(RED);
	setfillstyle(1,RED);
	fillellipse(h-49,k-25,6,5);
	fillellipse(h-50,k-28,6,5);
	fillellipse(h-45,k-32,6,5);
	
	setcolor(15);
	setfillstyle(1,15);
	fillellipse(h,k,54,54);
	setcolor(getbkcolor());
	setfillstyle(1,getbkcolor());
	fillellipse(h,k,30,32);
	int E0[6]={h+3,k-2,h-57,k-2,h-50,k-25};
	fillpoly(3,E0);
	setcolor(YELLOW);
	int E1[6]={h-31,k-14,h-25,k-23,h-20,k-12};
	setfillstyle(1,YELLOW);	
	fillpoly(3,E1);
	setcolor(15);
	setfillstyle(1,15);	
	fillellipse(h-38,k-22,12,12);
	int E2[8]={h-33,k+32,h+33,k+32,h+33,k-1,h-33,k-1};
	fillpoly(4,E2);
	}
	{//n
	int F0[8]={600,155,625,155,625,260,600,260};
	int F1[8]={662,188,687,188,687,260,662,260};
	setfillstyle(1,15);
	fillpoly(4,F0);	
	fillpoly(4,F1);
	fillellipse(648,204,42,47);
	
	setcolor(getbkcolor());
	setfillstyle(1,getbkcolor());
	fillellipse(644,194,19,23);
	int F2[8]={625,260,662,260,662,188,625,188};
	int F3[8]={687,175,700,175,700,260,687,260};
	fillpoly(4,F2);
	fillpoly(4,F3);	
	}
	{//F
	setcolor(15);
	int G0[20]={700,80,790,80,790,110,730,110,730,150,790,150,790,180,730,180,730,260,700,260};
	setfillstyle(1,15);
	fillpoly(10,G0);	
	}
	{//a
	fillellipse(839,210,48,54);
	setfillstyle(1,15);	
	int H0[8]={872,158,898,158,898,260,872,260};
	fillpoly(4,H0);
	setcolor(getbkcolor());
	setfillstyle(1,getbkcolor());
	fillellipse(846,210,28,31);
	}
	{//l
	setfillstyle(1,15);	
	int I0[8]={905,118,930,118,930,260,905,260};
	int I1[14]={939,118,964,118,964,250,972,250,952,275,931,250,939,250};
	fillpoly(4,I0);
	fillpoly(7,I1);
	}
	char nombre[3][20];
	char msg[30];
	int puntos[3],i;
	FILE *archi;
	
	settextstyle(3,0,3);
	setcolor(WHITE);
	
	archi = fopen("c:/Gallina/puntos.txt","r");
	for(i=0;i<3;i++){
		fscanf(archi,"%s %d\n",&nombre[i],&puntos[i]);
		//sprintf(arr,"%s %d",nombre[i],puntos[i]);
		strcpy(msg,"");
		sprintf(msg,"%s\t --- %d",nombre[i],puntos[i]);
		outtextxy(430, 450+i*53,msg);
	}
	fclose(archi);	

	
	setcolor(YELLOW);
	settextstyle(1,0, 8);
	outtextxy(135,280,"Play");
	outtextxy(409,350,"score");
	outtextxy(415,280,"High");
	outtextxy(708,280,"How");
	outtextxy(728,350,"play");
	settextstyle(1,0, 1);
	outtextxy(828,350,"to");
	setcolor(WHITE);
	settextstyle(1,0, 1);
	outtextxy(145,350,"(Press space)");	
	outtextxy(761,420,"(Press into)");
	char player[30];
	sprintf(player,"Player: %s",name);
	outtextxy(411, 612, player);		
	setcolor(WHITE);
	gamer g1;
	g1.x = 262;
	g1.y = 535;
	dibujaGallina(g1,1,4);
	g1.x = 842;
	dibujaGallina(g1,1,3);
	setcolor(WHITE);	
	rectangle(123, 280, 401, 630);
	setcolor(YELLOW);
	rectangle(411, 280, 698, 630);
	setcolor(WHITE);
	rectangle(708, 280, 975, 630);
	
	return puntos[0];

}
//prueba 


void instrucciones(){
	
	int f1[16]={350,100,380,80,380,90,450,90,450,110,380,110,380,120,350,100};
	int f2[16]={750,100,730,80,730,90,650,90,650,110,730,110,730,120,750,100};
	gamer player,globo1;
	gamer malo1;
	gamer bonus,castigo;
   
   
   player.x = 500;
   player.y = 200;
   
   
   globo1.activo = 1;
   globo1.tipo = 1;   
   globo1.x=350;
   globo1.y=300;
   
   malo1.activo = 1;
   malo1.tipo = 2;
   malo1.x = 350;
   malo1.y = 400;
   
      
   bonus.activo = 1;
   bonus.tipo = 3;
   bonus.x = 350;
   bonus.y = 500;
   
   
   castigo.activo =1;
   castigo.tipo = 3;
   castigo.x = 350;
   castigo.y = 600;
   
   muro(0);
   setfillstyle(1,BLACK);
   fillpoly(7,f1);
   fillpoly(7,f2);
   
   dibujaGlobo(globo1,BLUE,1);
//   dibujaGlobo(globo3,BLUE,tiempo%2);
	dibujaGlobo(malo1,RED,1);
//	dibujaGlobo(malo2,RED,tiempo%2);
//	dibujaGlobo(malo3,RED,tiempo%2);
	
	dibujaGlobo(bonus,GREEN,1);
	dibujaGlobo(castigo,BLACK,1);
   
   
   dibujaGallina(player,0,3);
   	setbkcolor(LIGHTBLUE);
   	setcolor(BLACK);
   	outtextxy(450,50,"Usa las flechas");
   	outtextxy(450,100,"para moverte");
   	outtextxy(600,200,"Este eres tu");
   	
   	setcolor(BLUE);
   	outtextxy(450,300,"Si tocas este globo\n, ganas 1 punto");
   	
   	setcolor(RED);
   	outtextxy(450,400,"Si tocas este globo\n, pierdes el juego");

   	setcolor(GREEN);
   	outtextxy(450,500,"Si tocas este globo\n, ganas 5 puntos ");
   	
   	setcolor(BLACK);
   	outtextxy(450,600,"Si tocas este globo\n, pierdes 7 puntos");
   	
   	setcolor(BLACK);
   	outtextxy(50,630,"Preciona lo que sea para jugar");
   	
   	
   	setbkcolor(BLACK);
	
}

//menu skins
void def(int x, int y)
{
	setbkcolor(9);
	setcolor(0);
	settextstyle(1,0, 1);
	outtextxy(x-75,y-80,"?????");
	outtextxy(x-75,y+55,"?????");
	setcolor(0);
	setfillstyle(1, 0); 
	fillellipse(x-28, y-30, 7, 8);
	fillellipse(x-18, y-33, 7, 8);
	fillellipse(x-9, y-30, 7, 8);
	int vec0[6]={x-48,y-14,x-36,y-7,x-34,y-17};
	fillpoly(3, vec0);
	fillellipse(x-21, y-15, 16, 16);
	fillellipse(x+4, y+17, 38, 28);
	fillellipse(x-30, y, 8, 28);
	fillellipse(x+35, y+2, 8, 8);
	fillellipse(x+33, y-5, 8, 8);
	int vec1[6]={x+36,y-12,x+10,y-10,x+22,y};
	int vec2[6]={x+43,y+5,x+40,y+15,x+35,y+10};
	fillpoly(3, vec1);
	fillpoly(3, vec2);
	fillellipse(x-42, y+2, 3, 3);
	fillellipse(x-36, y+2, 3, 3);
	int vec[6]{x-44,y+1,x-34,y+1,x-39,y-9};
	fillpoly(3, vec);
	setcolor(15);
	setbkcolor(0);
	outtextxy(x-10,y-10,"?");
}

void uno(int x, int y)
{
	setcolor(0);
	settextstyle(1,0, 1);
	outtextxy(x-75,y-80,"Chiken");
	outtextxy(x-75,y+55,"Press 1");
	setcolor(4);
	setfillstyle(1, 4); 
	fillellipse(x-28, y-30, 7, 8);
	fillellipse(x-18, y-33, 7, 8);
	fillellipse(x-9, y-30, 7, 8);
	setcolor(14);
	setfillstyle(1, 14);
	int vec0[6]={x-48,y-14,x-36,y-7,x-34,y-17};
	fillpoly(3, vec0);
	setcolor(15);
	setfillstyle(1, 15);
	fillellipse(x-21, y-15, 16, 16);
	fillellipse(x+4, y+17, 38, 28);
	fillellipse(x-30, y, 8, 28);
	fillellipse(x+35, y+2, 8, 8);
	fillellipse(x+33, y-5, 8, 8);
	int vec1[6]={x+36,y-12,x+10,y-10,x+22,y};
	int vec2[6]={x+43,y+5,x+40,y+15,x+35,y+10};
	fillpoly(3, vec1);
	fillpoly(3, vec2);
	setcolor(4);
	setfillstyle(1, 4);
	fillellipse(x-42, y+2, 3, 3);
	fillellipse(x-36, y+2, 3, 3);
	int vec[6]{x-44,y+1,x-34,y+1,x-39,y-9};
	fillpoly(3, vec);
	setcolor(0);
	arc(x+1, y+7, 180, 350, 21);
	arc(x+18, y+5, 250, 60, 8);
	arc(x+17, y+2, 260, 65, 7);
	setfillstyle(1, 15);
	fillellipse(x-30, y-17, 5, 5);
	setfillstyle(1, 0);
	fillellipse(x-32, y-17, 3, 5);
}

void dos(int x, int y)
{
	setcolor(0);
	settextstyle(1,0, 1);
	outtextxy(x-75,y-80,"Gold-Chik");
	outtextxy(x-75,y+55,"Press 2");
	setcolor(RED);
	setfillstyle(1, RED); 
	fillellipse(x-28, y-30, 7, 8);
	fillellipse(x-18, y-33, 7, 8);
	fillellipse(x-9, y-30, 7, 8);
	setcolor(6);
	int vec0[6]={x-48,y-14,x-36,y-7,x-34,y-17};
	setfillstyle(1, 6);
	fillpoly(3, vec0);
	setcolor(14);
	setfillstyle(1, 14);
	fillellipse(x-21, y-15, 16, 16);
	fillellipse(x+4, y+17, 38, 28);
	fillellipse(x-30, y, 8, 28);
	fillellipse(x+35, y+2, 8, 8);
	fillellipse(x+33, y-5, 8, 8);
	int vec1[6]={x+36,y-12,x+10,y-10,x+22,y};
	setfillstyle(1, 14);
	fillpoly(3, vec1);
	int vec2[6]{x+43,y+5,x+40,y+15,x+35,y+10};
	setfillstyle(1, 14);
	fillpoly(3, vec2);
	setcolor(RED);
	setfillstyle(1, RED);
	fillellipse(x-42, y+2, 3, 3);
	fillellipse(x-36, y+2, 3, 3);
	int vec[6]{x-44,y+1,x-34,y+1,x-39,y-9};
	setfillstyle(1, RED);
	fillpoly(3, vec);
	setcolor(BLACK);
	arc(x+1, y+7, 180, 350, 21);
	arc(x+18, y+5, 250, 60, 8);
	arc(x+17, y+2, 260, 65, 7);
	setcolor(BLACK);
	setfillstyle(1, WHITE);
	fillellipse(x-30, y-17, 5, 5);
	setfillstyle(1, BLACK);
	fillellipse(x-32, y-17, 3, 5);
}

void tre(int x, int y)
{
	setcolor(0);
	settextstyle(1,0, 1);
	outtextxy(x-75,y-80,"Kktus");
	outtextxy(x-75,y+55,"Press 3");
	setcolor(2);
    setfillstyle(1,2);
	fillellipse(x,y,43,35);
	setcolor(10);   
	setfillstyle(1,10);
	fillellipse(x,y,33,35);
	setcolor(2);
    setfillstyle(1,2);
	fillellipse(x,y,23,35);
	setcolor(10);   
	setfillstyle(1,10);
	fillellipse(x,y,13,35);
	setcolor(12);   
	setfillstyle(1,12);
	int m0[8]={x-44,y+5,x-40,y+20,x+40,y+20,x+44,y+5};
	fillpoly(4,m0);
	setcolor(4);   
	setfillstyle(1,4);
	int m1[8]={x-35,y+20,x+35,y+20,x+25,y+45,x-25,y+45};
	fillpoly(4,m1);
	setcolor(0);   
	setfillstyle(1,0);
	fillellipse(x-15,y+30,5,5);
	fillellipse(x+15,y+30,5,5);
	line(x-3,y+30,x+3,y+30);
	setfillstyle(1,15);
	fillellipse(x-17,y+27,2,2);
	fillellipse(x+13,y+27,2,2);
}

void cua(int x, int y)
{
	setcolor(0);
	settextstyle(1,0, 1);
	outtextxy(x-75,y-80,"Pac-man");
	outtextxy(x-75,y+55,"Press 4");
	setcolor(14);
	setfillstyle(1,14);
	fillellipse(x,y,50,50);
	setcolor(9);    
	setfillstyle(1,9);
	int pm[6]={x,y,x-50,y-50,x-50,y+50};
	fillpoly(3,pm);
}

void cin(int x, int y)
{
	setcolor(0);
	settextstyle(1,0, 1);
	outtextxy(x-75,y-80,"Ghost");
	outtextxy(x-75,y+55,"Press 5");
	setcolor(4);
	setfillstyle(1,4);
	fillellipse(x,y-7,43,43);
	int gh[18]={x-43,y-8,x+43,y-8,x+43,y+45,x+25,y+36,x+13,y+45,x,y+36,x-13,y+45,x-25,y+36,x-43,y+45};
	fillpoly(9,gh);
	setcolor(15);
	setfillstyle(1,15);
	fillellipse(x+10,y-11,12,12);
	fillellipse(x-25,y-11,12,12);
	setcolor(1);
	setfillstyle(1,1);
	fillellipse(x+5,y-10,6,6);
	fillellipse(x-30,y-10,6,6);
}

void sei(int x, int y)
{
	setcolor(0);
	settextstyle(1,0, 1);
	outtextxy(x-75,y-80,"Chikorn");
	outtextxy(x-75,y+55,"Press 6");
	setcolor(13);
	setfillstyle(1, 13); 
	fillellipse(x-28, y-30, 7, 8);
	setcolor(14);
	setfillstyle(1, 14); 		
	fillellipse(x-18, y-33, 7, 8);
	setcolor(11);
	setfillstyle(1, 11); 		
	fillellipse(x-9, y-30, 7, 8);
	setcolor(6);
	setfillstyle(1,14);
	int cr[6]={x-42, y-38, x-28, y-29, x-33, y-22};
	setcolor(14);
	setfillstyle(1, 14);
	fillpoly(3, cr);
	int vec0[6]={x-48,y-14,x-36,y-7,x-34,y-17};
	fillpoly(3, vec0);
	setcolor(15);
	setfillstyle(1, 15);
	fillellipse(x-21, y-15, 16, 16);
	fillellipse(x+4, y+17, 38, 28);
	fillellipse(x-30, y, 8, 28);
	fillellipse(x+35, y+2, 8, 8);
	fillellipse(x+33, y-5, 8, 8);
	int vec1[6]={x+36,y-12,x+10,y-10,x+22,y};
	int vec2[6]{x+43,y+5,x+40,y+15,x+35,y+10};
	fillpoly(3, vec1);
	fillpoly(3, vec2);
	setcolor(5);
	setfillstyle(1, 5);
	fillellipse(x-42, y+2, 3, 3);
	fillellipse(x-36, y+2, 3, 3);
	int vec[6]{x-44,y+1,x-34,y+1,x-39,y-9};
	fillpoly(3, vec);
	setcolor(0);
	arc(x+1, y+7, 180, 350, 21);
	arc(x+18, y+5, 250, 60, 8);
	arc(x+17, y+2, 260, 65, 7);
	setcolor(0);
	setfillstyle(1, 15);
	fillellipse(x-30, y-17, 5, 5);
	setfillstyle(1, 10);
	fillellipse(x-32, y-17, 3, 5);
}

void sie(int x, int y)
{
	setcolor(0);
	settextstyle(1,0, 1);
	outtextxy(x-75,y-80,"I'm  chiken");
	outtextxy(x-75,y+55,"Press 7");
	setcolor(2);
	setfillstyle(1, 2); 
	fillellipse(x-28, y-30, 7, 8);
	fillellipse(x-18, y-33, 7, 8);
	fillellipse(x-9, y-30, 7, 8);
	setcolor(14);
	int vec0[6]={x-42,y-14,x-36,y-7,x-34,y-17};
	setfillstyle(1, 14);
	fillpoly(3, vec0);
	setcolor(6);
	setfillstyle(1, 6);
	fillellipse(x-21, y-15, 16, 16);
	fillellipse(x+4, y+17, 38, 28);
	fillellipse(x-30, y, 8, 28);
	fillellipse(x+35, y+2, 8, 8);
	fillellipse(x+33, y-5, 8, 8);
	int vec1[6]={x+36,y-12,x+10,y-10,x+22,y};
	setfillstyle(1, 6);
	fillpoly(3, vec1);
	int vec2[6]{x+43,y+5,x+40,y+15,x+35,y+10};
	setfillstyle(1, 6);
	fillpoly(3, vec2);
	setcolor(10);
	setfillstyle(1, 10);
	fillellipse(x-42, y+2, 3, 3);
	fillellipse(x-36, y+2, 3, 3);
	int vec[6]{x-44,y+1,x-34,y+1,x-39,y-9};
	setfillstyle(1, 10);
	fillpoly(3, vec);
	setcolor(8);
	arc(x+1, y+7, 180, 350, 21);
	arc(x+18, y+5, 250, 60, 8);
	arc(x+17, y+2, 260, 65, 7);
	setcolor(0);
	setfillstyle(1, 0);
	fillellipse(x-28, y-15, 7, 7);
	setfillstyle(1, 15);
	fillellipse(x-32, y-20, 2, 2);
}

void och(int x, int y)
{
	setcolor(0);
	settextstyle(1,0, 1);
	outtextxy(x-75,y-80,"Iron-Chik");
	outtextxy(x-75,y+55,"Press 8");
	setcolor(4);
	setfillstyle(1, 14); 
	fillellipse(x-28, y-30, 7, 8);
	fillellipse(x-18, y-33, 7, 8);
	fillellipse(x-9, y-30, 7, 8);
	setcolor(14);
	int vec0[6]={x-48,y-14,x-36,y-7,x-34,y-17};
	setfillstyle(1, 4);
	fillpoly(3, vec0);
	setcolor(14);
	setfillstyle(1, 4);
	fillellipse(x-21, y-15, 16, 16);
	fillellipse(x+4, y+17, 38, 28);
	fillellipse(x-30, y, 8, 28);
	fillellipse(x+35, y+2, 8, 8);
	fillellipse(x+33, y-5, 8, 8);
	int vec1[6]={x+36,y-12,x+10,y-10,x+22,y};
	setfillstyle(1, 4);
	fillpoly(3, vec1);
	int vec2[6]{x+43,y+5,x+40,y+15,x+35,y+10};
	setfillstyle(1, 4);
	fillpoly(3, vec2);
	setcolor(14);
	setfillstyle(1,15);
	fillellipse(x-31,y+21,4,6);
	setcolor(4);
	setfillstyle(1, 14);
	fillellipse(x-42, y+2, 3, 3);
	fillellipse(x-36, y+2, 3, 3);
	int vec[6]{x-44,y+1,x-34,y+1,x-39,y-9};
	setfillstyle(1, 14);
	fillpoly(3, vec);
	setcolor(14);
	arc(x+1, y+7, 180, 350, 21);
	arc(x+18, y+5, 250, 60, 8);
	arc(x+17, y+2, 260, 65, 7);
	setcolor(1);
	setfillstyle(1, 9);
	fillellipse(x-30, y-17, 5, 3);
	setfillstyle(1, 3);
	fillellipse(x-32, y-17, 2, 3);
}

void nue(int x, int y)
{
	setcolor(0);
	settextstyle(1,0, 1);
	outtextxy(x-75,y-80,"Puma");
	outtextxy(x-75,y+55,"Press 9");
	setcolor(1);
    setfillstyle(1,1);
	fillellipse(x,y,50,50);
	setcolor(14);    
	setfillstyle(1,14);
	fillellipse(x,y-5,34,36);
	int unam0[8]={x-34,y-3,x-15,y-4,x-20,y+26,x-27,y+28};
	int unam1[8]={x+34,y-3,x+15,y-4,x+20,y+26,x+27,y+28};
	fillpoly(4,unam0);
	fillpoly(4,unam1);
	setcolor(1);    
	setfillstyle(1,1);
	fillellipse(x-13,y-14,11,13);
	fillellipse(x+13,y-14,11,13);
	int unam2[8]={x-15,y-13,x+15,y-13,x+20,y+32,x-20,y+32};
	fillpoly(4,unam2);
	setcolor(14);    
	setfillstyle(1,14);
	fillellipse(x-31,y-22,11,13);
	fillellipse(x+31,y-22,11,13);
	fillellipse(x-25,y+26,3,3);
	fillellipse(x+25,y+26,3,3);
	fillellipse(x-14,y+26,3,3);
	fillellipse(x+14,y+26,3,3);
	fillellipse(x-11,y+41,3,5);
	fillellipse(x+11,y+41,3,5);
	int unam3[8]={x-10,y-11,x+10,y-11,x+13,y+14,x-13,y+14};
	int unam4[8]={x+29,y-34,x+25,y-11,x-25,y-11,x-29,y-34};
	int unam5[8]={x-25,y+23,x-14,y+23,x-14,y+29,x-25,y+29};
	int unam6[8]={x+25,y+23,x+14,y+23,x+14,y+29,x+25,y+29};
	int unam7[8]={x-11,y+36,x+11,y+36,x+11,y+46,x-11,y+46};
	fillpoly(4,unam3);
	fillpoly(4,unam4);
	fillpoly(4,unam5);
	fillpoly(4,unam6);
	fillpoly(4,unam7);
	int unam8[6]={x-40,y-15,x-32,y-15,x-32,y+4};
	int unam9[6]={x+40,y-15,x+32,y-15,x+32,y+4};
	int unam10[6]={x-7,y-39,x-32,y-34,x-7,y-34};
	int unam11[6]={x+7,y-39,x+32,y-34,x+7,y-34};
	fillpoly(3,unam8);
	fillpoly(3,unam9);
	fillpoly(3,unam10);
	fillpoly(3,unam11);		
}
void Egg()
{
	muro(0);
	int w=550,z=350;
	setcolor(14);
	setfillstyle(1,14);
	fillellipse(w,z+60,140,160);
	fillellipse(w,z,120,200);	
	int c[8]={w+131,z,w-131,z,w-91,z-130,w+91,z-130};
	fillpoly(4,c);
	int i=0, s;
	for(i;i<3;i++){
		s=1+rand()%15;
		setcolor(15);
		setfillstyle(1,s);
		fillellipse(w-40+i*40,z-170,8,8);
	}
	i=0;
	for(i;i<5;i++){
		s=1+rand()%15;
		setcolor(14);
		setfillstyle(1,s);
		fillellipse(w-80+i*40,z-130,12,12);
	}
	i=0;
	for(i;i<6;i++){
		s=1+rand()%15;
		setcolor(14);
		setfillstyle(1,s);
		fillellipse(w-100+i*40,z-80,8,8);
	}
	i=0;
	for(i;i<6;i++){
		s=1+rand()%15;
		setcolor(14);
		setfillstyle(1,s);
		fillellipse(w-110+i*40,z-30,12,12);
	}
	i=0;
	for(i;i<7;i++){
		s=1+rand()%15;
		setcolor(14);
		setfillstyle(1,s);
		fillellipse(w-125+i*40,z+20,8,8);
	}
	i=0;
	for(i;i<7;i++){
		s=1+rand()%15;
		setcolor(14);
		setfillstyle(1,s);
		fillellipse(w-130+i*40,z+70,12,12);
	}
	i=0;
	for(i;i<6;i++){
		s=1+rand()%15;
		setcolor(14);
		setfillstyle(1,s);
		fillellipse(w-120+i*40,z+120,8,8);
	}
	i=0;
	for(i;i<5;i++){
		s=1+rand()%15;
		setcolor(14);
		setfillstyle(1,s);
		fillellipse(w-85+i*40,z+170,12,12);
	}
	float fx;
	for (float q=0;q<=18.5;q+=0.01)
	{
	fx=(1+cos(q))*40+200;
	putpixel(412+q*15,160+fx,13);
	}
	for (float u=0;u<=15;u+=0.01)
	{
	fx=(1+sin(u))*40+200;
	putpixel(440+u*15,30+fx,3);
	}
	for (float q=0;q<=18.5;q+=0.01)
	{
	fx=(1+cos(q))*40+200;
	putpixel(412.4+q*15,160+fx,13);
	}
	for (float u=0;u<=15;u+=0.01)
	{
	fx=(1+sin(u))*40+200;
	putpixel(440.4+u*15,30+fx,3);
	}
	for (float q=0;q<=18.5;q+=0.01)
	{
	fx=(1+cos(q))*40+200;
	putpixel(412.8+q*15,160+fx,13);
	}
	for (float u=0;u<=15;u+=0.01)
	{
	fx=(1+sin(u))*40+200;
	putpixel(440.8+u*15,30+fx,3);
	}
}
int main();
int menuSkins(int puntajes)
{
	setbkcolor(9);
	muro(1);
	int cx,cy;
	char alfa;
	int limite;
	int caso=0;
	if(puntajes<10){
		limite = 10;	
		cy=205;
		cx=380;
		uno(cx,cy);
		cx=550;
		def(cx,cy);
		cx=720;
		def(cx,cy);
		cy=375;
		cx=380;
		def(cx,cy);
		cx=550;
		def(cx,cy);
		cx=720;
		def(cx,cy);
		cy=555;
		cx=380;
		def(cx,cy);
		cx=550;
		def(cx,cy);
		cx=720;
		def(cx,cy);
	}else{
		if(puntajes<20){
			limite = 20;	
			cy=205;
			cx=380;
			uno(cx,cy);
			cx=550;
			dos(cx,cy);
			cx=720;
			def(cx,cy);
			cy=375;
			cx=380;
			def(cx,cy);
			cx=550;
			def(cx,cy);
			cx=720;
			def(cx,cy);
			cy=555;
			cx=380;
			def(cx,cy);
			cx=550;
			def(cx,cy);
			cx=720;
			def(cx,cy);
		}else{
			if(puntajes<30){
				limite = 30;	
				cy=205;
				cx=380;
				uno(cx,cy);
				cx=550;				
				dos(cx,cy);
				cx=720;
				tre(cx,cy);
				cy=375;
				cx=380;
				def(cx,cy);
				cx=550;
				def(cx,cy);
				cx=720;
				def(cx,cy);
				cy=555;
				cx=380;
				def(cx,cy);
				cx=550;
				def(cx,cy);
				cx=720;
				def(cx,cy);
			}else{
				if(puntajes<40){
					limite = 40;	
					cy=205;
					cx=380;
					uno(cx,cy);
					cx=550;				
					dos(cx,cy);
					cx=720;
					tre(cx,cy);
					cy=375;
					cx=380;
					cua(cx,cy);
					cx=550;
					def(cx,cy);
					cx=720;
					def(cx,cy);
					cy=555;
					cx=380;
					def(cx,cy);
					cx=550;
					def(cx,cy);
					cx=720;
					def(cx,cy);
				}else{
					if(puntajes<50){
						limite = 50;	
						cy=205;
						cx=380;
						uno(cx,cy);
						cx=550;				
						dos(cx,cy);
						cx=720;
						tre(cx,cy);
						cy=375;
						cx=380;
						cua(cx,cy);
						cx=550;
						cin(cx,cy);
						cx=720;
						def(cx,cy);
						cy=555;
						cx=380;
						def(cx,cy);
						cx=550;
						def(cx,cy);
						cx=720;
						def(cx,cy);
					}else{
						if(puntajes<60){
							limite = 60;	
							cy=205;
							cx=380;
							uno(cx,cy);
							cx=550;				
							dos(cx,cy);
							cx=720;
							tre(cx,cy);
							cy=375;
							cx=380;
							cua(cx,cy);
							cx=550;
							cin(cx,cy);
							cx=720;
							sei(cx,cy);
							cy=555;
							cx=380;
							def(cx,cy);
							cx=550;
							def(cx,cy);
							cx=720;
							def(cx,cy);
						}else{
							if(puntajes<70){
								limite = 70;	
								cy=205;
								cx=380;
								uno(cx,cy);
								cx=550;				
								dos(cx,cy);
								cx=720;
								tre(cx,cy);
								cy=375;
								cx=380;
								cua(cx,cy);
								cx=550;
								cin(cx,cy);
								cx=720;
								sei(cx,cy);
								cy=555;
								cx=380;
								sie(cx,cy);
								cx=550;
								def(cx,cy);
								cx=720;
								def(cx,cy);
							}else{
								if(puntajes<80){
									limite = 80;	
									cy=205;
									cx=380;
									uno(cx,cy);
									cx=550;				
									dos(cx,cy);
									cx=720;
									tre(cx,cy);
									cy=375;
									cx=380;
									cua(cx,cy);
									cx=550;
									cin(cx,cy);
									cx=720;
									sei(cx,cy);
									cy=555;
									cx=380;
									sie(cx,cy);
									cx=550;
									och(cx,cy);
									cx=720;
									def(cx,cy);
								}else{
									limite = 90;
									cy=205;
									cx=380;
									uno(cx,cy);
									cx=550;				
									dos(cx,cy);
									cx=720;
									tre(cx,cy);
									cy=375;
									cx=380;
									cua(cx,cy);
									cx=550;
									cin(cx,cy);
									cx=720;
									sei(cx,cy);
									cy=555;
									cx=380;
									sie(cx,cy);
									cx=550;
									och(cx,cy);
									cx=720;
									nue(cx,cy);			
								}
							}
						}
					}
				}
			}
		}
	}
	limite++;
	setcolor(15);
	rectangle(300,120,460,280);
	rectangle(300,290,460,460);
	rectangle(300,470,460,640);
	rectangle(470,120,630,280);
	rectangle(470,290,630,460);
	rectangle(470,470,630,640);
	rectangle(640,120,800,280);
	rectangle(640,290,800,460);
	rectangle(640,470,800,640);
	setbkcolor(9);
	setcolor(0);
	settextstyle(1,0, 5);
	outtextxy(310,55,"Select an option");
//	limte = puntajes;
	fflush(stdin);
	alfa = getch();
	switch(alfa){
		case n1:
//			if(limite < 15){
				return 1;
//			}else{
//				return menuSkins(puntajes);
//			}
			break;
		case n2:
			if(limite > 15){
				return 2;
			}else{
				return menuSkins(puntajes);
				}
			break;
		case n3:
			if(limite > 25){
				return 3;
			}else{
				return menuSkins(puntajes);
				}
			break;
		case n4:
			if(limite > 35){
				return 4;
			}else{
				return menuSkins(puntajes);
				}
			break;
		case n5:
			if(limite > 45){
				return 5;
			}else{
				return menuSkins(puntajes);
				}
			break;
		case n6:
			if(limite > 55){
				return 6;
			}else{
				return menuSkins(puntajes);
				}
			break;
		case n7:
			if(limite > 65){
				return 7;
			}else{
				return menuSkins(puntajes);
				}
			break;
		case n8:
			if(limite > 75){
				return 8;
			}else{
				return menuSkins(puntajes);
				}
			break;
		case n9:
			if(limite > 85){
				return 9;
			}else{
				return menuSkins(puntajes);
				}
			break;
		default:
			return menuSkins(puntajes);
			break;
	}
}
//menu skins
void resto(char nombre[40]){
	director();
	int res=0;
	srand(time(NULL));
	int max,aux2;
	char aux;
	int papa=1;
   while(papa){
   	granpantalla();
   max = menu(nombre);
   aux = getch();
   	if(aux == enter){
			instrucciones();
			papa = 0;
			getch();
	   }
	if(aux == 'g'){
		Egg();
		Sleep(3000);
	}
	if(aux == ' '){
		papa = 0;
	}
	   
   }
//   do{
   aux2 = menuSkins(max);
//   getch();
	setbkcolor(BLACK);
   res = juego(aux2);
   
   //getch();
   Sleep(500);
   
   system("cls");
   wardar(nombre,res);
   fflush(stdin);
   papa = 1;
   while(papa){
   aux = getch();
   if(aux == ' '){
   	papa = 0;
 //  closegraph();	
   	resto(nombre);
   }
   if(aux == enter){
   		closegraph();
   		papa = 0;
	   main();
   }
   if(aux == esc){
   	papa = 0;
   	closegraph();
   }
   
   }
   
   
   
//	}while(aux != esc);
   Sleep(1000);
   //printf("Felicidades, conseguiste %d puntos",res);
   //system("pause");
 
}
int main(){
	system("title ChikenFall");
	director();
	
	char nombre[40];
	system("cls");
	printf("Bienvenido, como te llamas?:\n");
	fflush(stdin);
	gets(nombre);
	fflush(stdin);
	printf("Hola %s\nEspera un segundo...",nombre);
	Sleep(1000);
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");
   
	
	
	resto(nombre);
	
	system("c:/Gallina/firma.txt");
   return 1010;
   }
