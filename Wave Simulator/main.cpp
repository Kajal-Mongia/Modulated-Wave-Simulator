#include<iostream>
#include<dos.h>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<bits/stdc++.h>
#include<stdlib.h>
#include<cmath>

#define X0 (getmaxx()/2)
#define Y0 (getmaxy()/6)
#define Y1 (getmaxy()/2)
#define Y2 ((5*getmaxy())/6)

#define X(x) (X0+(x))
#define Y_0(y) (Y0-(y))
#define Y_1(y) (Y1-(y))
#define Y_2(y) (Y2-(y))

#define PI 3.14159265
#define RADIANS(x) (x*(PI/180))
#define DEGREES(x) (x*(180/PI))

#define x_left_border()  (-1*getmaxx()/2+10)
#define x_right_border() (getmaxx()/2-10)

using namespace std;


void ampPlot(int am, int fm, int ac, int fc){
	
    int x=0;
    int y=0;
           

    initwindow(1250,700,"Wave-Simulation");
    setcolor(BLACK);            
    line(0,getmaxy()/6,getmaxx(),getmaxy()/6);
    line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
    line(0,(5*getmaxy())/6,getmaxx(),(5*getmaxy())/6);
    
    for (x = x_left_border(); x < x_right_border(); x += 1) {
	  
	  // Drawing speed 
	    delay(0.4);
		
		//Carrier wave
		y= ac*cos(RADIANS(2*PI*fc*x));
		putpixel(X(x), Y_0(y),0);
		
		//input signal
		y=am*cos(RADIANS(2*PI*fm*x));
		putpixel(X(x), Y_1(y),0);
		
	  	//modulated wave
		y=(ac+(am*cos(RADIANS(2*PI*fm*x))))*cos(RADIANS(2*PI*fc*x));
		putpixel(X(x), Y_2(y),0);
	
	 
	}
    

	getch();
	closegraph();
}

void freqPlot(int am, int fm, int ac, int fc,int kf){
	
    int x=0;
    int y=0;
         
    initwindow(1250,700,"Wave-Simulation");
    setcolor(BLACK);         
    line(0,getmaxy()/6,getmaxx(),getmaxy()/6);
    line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
    line(0,(5*getmaxy())/6,getmaxx(),(5*getmaxy())/6);
    
    float beta=(kf*am)/fm;
    
    for (x = x_left_border(); x < x_right_border(); x += 1) {
	  
	  // Drawing speed 
	    delay(0.4);
		
		//Carrier wave
		y=ac*cos(RADIANS(2*PI*fc*x));
		putpixel(X(x), Y_0(y),0);
		
		//input signal
		y=am*cos(RADIANS(2*PI*fm*x));
		putpixel(X(x), Y_1(y),0);
		
	  	//modulated wave
	    y = ac*cos(RADIANS( (2*PI*fc*x) + (beta*sin(RADIANS((2*PI*fm*x)))) ) );
		putpixel(X(x), Y_2(y),0);
	
	 
	}
    

	getch();
	closegraph();
}

void phasePlot(int am, int fm, int ac, int fc,int kp){
	
    int x=0;
    int y=0;
      

    initwindow(1250,700,"Wave-Simulation");
     setcolor(BLACK);         
    line(0,getmaxy()/6,getmaxx(),getmaxy()/6);
    line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
    line(0,(5*getmaxy())/6,getmaxx(),(5*getmaxy())/6);
    
    int beta=kp*am;
    
    for (x = x_left_border(); x < x_right_border(); x += 1.5) {
	  
	  // Drawing speed 
	    delay(0.4);
		
		//Carrier wave
		y=ac*cos(RADIANS(2*PI*fc*x));
		putpixel(X(x), Y_0(y),0);
		
		//input signal
		y=am*cos(RADIANS(2*PI*fm*x));
		putpixel(X(x), Y_1(y),0);
		
	  	//modulated wave
	    y = ac*cos(RADIANS((2*PI*fc*x) + (beta*cos(RADIANS((2*PI*fm*x))))));
		putpixel(X(x), Y_2(y),0);
	
	 
	}
    

	getch();
	closegraph();
}

int am,ac,fm,fc,kf,kp;
void input(){
	
	cout<<"\nEnter Amplitude of modulating wave : ";
	cin>>am;
	cout<<"Enter Amplitude of carrier wave : ";
	cin>>ac;
	cout<<"Enter Frequency of modulating wave : ";
	cin>>fm;
	cout<<"Enter Frequency of carrier wave : ";
	cin>>fc;
	
}

main(){
	
	initwindow(1250,700,"Wave-Simulation");
    setbkcolor(15);
    closegraph();
	
	cout<<"\t\t\t\t\tWAVE SIMULATOR";
	
	int choice;
	do{
		
		cout<<"\n\n Select a modulation :  "
		<<"\n1. Amplitude Modulation Simulation"
		<<"\n2. Frequency Modulation Simulation"
		<<"\n3. Phase Modulation Simulation"
		<<"\n4. Exit";
		
		cout<<"\nEnter your choice :";
		cin>>choice;
							
		switch(choice){
			
			case 1: input();
					ampPlot(am,fm,ac,fc);
					break;
			case 2: input();
					cout<<"\nEnter frequency sensitivity : ";
					cin>>kf;
					freqPlot(am,fm,ac,fc,kf);
					break;
			case 3: input();
					cout<<"\nEnter phase sensitivity : ";
					cin>>kf;
					phasePlot(am,fm,ac,fc,kp);
					break;
			case 4:exit(0);
		}
	}while(choice!=4);
	
	getch();
}
