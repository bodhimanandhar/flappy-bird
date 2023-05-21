#include <iostream>
#include <graphics.h>
#include <conio.h>
const int WIDTH = 640;
const int HEIGHT = 480;
int width;
int Pipe_x,Pipe_y;
int gap; 
int main() {
    initwindow(WIDTH, HEIGHT, "Moving Object");
	
	width=40;
	Pipe_x=400,Pipe_y=200;
	gap=120;
    // Create two buffers for double buffering
    int drawBuffer = 0;
    int displayBuffer = 1;
    setactivepage(drawBuffer);
    setvisualpage(displayBuffer);

    int x =70;
    int y = HEIGHT / 2;
    
    char key;
    int value;

    int dx = 15;
    int dy = 2;

    // Main game loop
    while (1) {
        // Clear the drawing buffer
        cleardevice();
		setbkcolor(LIGHTBLUE);
        // Update the position of the object
        if (kbhit())
	 	{
        key = getch();
    	value=key;
        if (value == 72) 
		{
			y-=dy+10;
		}
		}
        y +=dy;

        /* Check if the object has hit the edge of the screen
        if (x < 0 || x > WIDTH) {
            dx = -dx;
        }
        if (y < 0 || y > HEIGHT) {
            dy = -dy;
        } */

        // Draw the object on the drawing buffer
        setfillstyle(1,4);  
  		fillellipse(x,y,20,20);  
		setcolor(0);
		circle(x, y, 20);
        
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
			
		}
		
		
		
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

    closegraph();

    return 0;
}
