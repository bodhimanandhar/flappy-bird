#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<time.h>
#include<stdlib.h>



class Bird
{
int width;
int Pipe_x,Pipe_y;
int gap; 	
int Bird_x,Bird_y;
int egg_x,egg_y;
int var;
int drawBuffer;
int displayBuffer;
char key;
int value;
int dx = 15;
int dy = 2;
int score;
char *p;

public:

Bird()
{	score=0;
	width=40;
	Pipe_x=400,Pipe_y=200;
	gap=125;
	Bird_x=70;
	Bird_y=240;	
	egg_x=200;
    egg_y=100;
	drawBuffer = 0;
	displayBuffer = 1;
	dx = 15;
    dy = 2;
}

void draw_bird()
{

	setbkcolor(LIGHTBLUE);
	while (1) {
        
        cleardevice();
		
        // Update the position of the object
        if (kbhit())
	 	{
        key = getch();
    	value=key;
        if (value == 72) 
			{
			Bird_y-=dy+15;
			
			if((Bird_x +1 >= egg_x && Bird_x - 4 <= egg_x) &&
                ((Bird_y - 4 <=egg_y) || (Bird_y + 4 >=egg_y)))
			// if((Bird_x==egg_x)&&egg_y+1<=Bird_y<=egg_y-1)
	 		  {
	   			score=score+1;
	   			var=rand()%200;
				egg_x=400;
	  		 }
	   	
			}
		else if(value==27)
			{
				cleardevice();
				show_menu();
			}	
		}
        Bird_y+=dy;

        
        
        if (Bird_y < 0 || Bird_y > 480) {
            dy = -dy;
        } 

        // Draw the object on the drawing buffer
        setfillstyle(1,score);  
  		fillellipse(Bird_x,Bird_y,25,25);  
		setcolor(0);
		circle(Bird_x,Bird_y, 25);
		
        setcolor(LIGHTRED);
		setfillstyle(1,12);  
  		fillellipse(Bird_x-10,Bird_y+8,20,5);
		setcolor(BLACK);  
    	ellipse(Bird_x-10,Bird_y+8,0,360,20,5);
	
		setcolor(WHITE);
		setfillstyle(1,15);  
  		fillellipse(Bird_x+8,Bird_y-10,7,7);
		setcolor(BLACK);    
		circle(Bird_x+8,Bird_y-10,7);
		
		setcolor(YELLOW);
		setfillstyle(1,14);  
  		fillellipse(Bird_x+25,Bird_y,8,4);
		setcolor(BLACK);    
    	ellipse(Bird_x+25,Bird_y,0,360,8,4);
    	Bird_y+=2;
        
       
        
		
        
        setcolor(3);
        rectangle(Pipe_x,0,Pipe_x+width,Pipe_y);      
        setfillstyle(1,3);
        floodfill(Pipe_x+3,Pipe_y-2,3);
        rectangle(Pipe_x,Pipe_y+gap,Pipe_x+width,Pipe_y+getmaxy());  
        floodfill(Pipe_x+3,Pipe_y+gap+3,3);
		
		Pipe_x-=10;
		
		  
		if(Pipe_x<0)
		{
			Pipe_x=400;
			Pipe_y=rand()%100+100;
			delay(100);
		}
		setcolor(YELLOW);
		setfillstyle(1,14);  
  		fillellipse(egg_x+var,egg_y+var,5,10);
		ellipse(egg_x+var,egg_y+var,0,360,5,10);
    	egg_x-=10;
    	
    	if(egg_x<-10)
		{
			var=rand()%200;
			egg_x=400;
		}
		
		if((Bird_x + 10 >= Pipe_x && Bird_x - 10 <= Pipe_x + width) &&
                ((Bird_y - 10 <= Pipe_y) || (Bird_y + 10 >= Pipe_y + gap)))
		{
			
			cleardevice();  
			settextstyle(8,0,5);
			  
			outtextxy(150,40,"GAME OVER");
			std::cout<<"Score ="<<score<<"\n";
			value=getch();	
		
			if(value==27)
			{
		
			show_menu();
			}
			
		}
		  
  		setcolor(10); 
		settextstyle(8,0,4);    
  		//ltoa(score,p,10);
		outtextxy(500,40,"SCORE: ");  
		//outtextxy(520, 50,p);	
  		
			
		
        // Swap the buffers to show the image on the screen
        setactivepage(drawBuffer);
        setvisualpage(displayBuffer);

        // Wait for a short time to control the frame rate
        delay(10);

        // Swap the buffers again for the next frame
        drawBuffer = displayBuffer;
        displayBuffer = (displayBuffer + 1) % 2;
        delay(100);
		}
	
	
	
}

void show_instructions()
{
	cleardevice();
	setlinestyle(0,1,3);  
	setcolor(15);  
	rectangle(20,20,getmaxx()-15,getmaxy()-15); 
	
	
	setcolor(4);
	settextstyle(0,0,0);
	outtextxy(50,110,"Press the up arrow key to make the bird dodge obstacles.");
	value=getch();
	if(value==27) {
		show_menu();
	}
	
	
}


void show_menu()
{
	fflush(stdin);	
	cleardevice();  
	setcolor(4);
	rectangle(20,20,getmaxx()-15,getmaxy()-15); 
	
	setlinestyle(0,1,3);  
	setcolor(2);  
	
	setcolor(4);  
	settextstyle(1,0,5);
	outtextxy(getmaxx()/2-150,50,"Flappy Bird");   
	
	setcolor(6);
	settextstyle(8,0,1);
	outtextxy(getmaxx()/2-50,160,"1. Start");
	outtextxy(getmaxx()/2-50,210,"2. Instruction");
	outtextxy(getmaxx()/2-50,270,"3. Exit");
	
		

	value=getch();
	switch(value)
	{
		case 49:
		draw_bird();
		
		case 50:
		show_instructions();	
	}
	
	getch();
}	
	
	
};

int main()
{
	initwindow(640,480,"Flappy");
	//int d=0,m,i,j;
	//initgraph(&d,&m,"c:\\turboc3\\bgi");
	Bird b;
	b.show_menu();
	
	closegraph();
	
	
}
