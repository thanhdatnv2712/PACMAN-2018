#ifndef _
#define _
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "console.h"

using namespace std;


void Background() {    //khoi tao nen bat dau
	Nocursortype();
	for(int i=3;i<=70;i++)
	{
	if(i%4==0)
		{
		setcolor(94);
		gotoxy(i,6); cout<<"       ********       ";
		gotoxy(i,7); cout<<"    ****@*****@***     ";
		gotoxy(i,8); cout<<"  ******************    ";
		gotoxy(i,9); cout<<" ********************    ";
		gotoxy(i,10);cout<<" ********************    ";
		gotoxy(i,11);cout<<" ********************     ";
		gotoxy(i,12);cout<<"  ******************      ";
		gotoxy(i,13);cout<<"    **************      ";
		gotoxy(i,14);cout<<"      *********           ";
		Sleep(100);
		clrscr();
		}
		if(i%4==1)
		{
		setcolor(94);
		gotoxy(i,6); cout<<"       ********       ";
		gotoxy(i,7); cout<<"    ****@****@****     ";
		gotoxy(i,8); cout<<"  ******************    ";
		gotoxy(i,9); cout<<" ********************   ";
		gotoxy(i,10);cout<<" ****************               ";
		gotoxy(i,11);cout<<" ********************     ";
		gotoxy(i,12);cout<<"  ******************      ";
		gotoxy(i,13);cout<<"    **************      ";
		gotoxy(i,14);cout<<"      *********           ";
		Sleep(100);
		clrscr();
			}
		if(i%4==2)
		{
			setcolor(94);
		gotoxy(i,6); cout<<"       ********       ";
		gotoxy(i,7); cout<<"    ****@****@****     ";
		gotoxy(i,8); cout<<"  ******************    ";
		gotoxy(i,9); cout<<" ***************        ";
		gotoxy(i,10);cout<<" ***********          ";
		gotoxy(i,11);cout<<" ***************         ";
		gotoxy(i,12);cout<<"  ******************      ";
		gotoxy(i,13);cout<<"    **************      ";
		gotoxy(i,14);cout<<"      *********           ";
		Sleep(100);
		clrscr();
	
		}
		if(i%4==3)
		{
			setcolor(94);
		gotoxy(i,6); cout<<"       ********       ";
		gotoxy(i,7); cout<<"    ****@****@****     ";
		gotoxy(i,8); cout<<"  ******************    ";
		gotoxy(i,9); cout<<" ********************   ";
		gotoxy(i,10);cout<<" ****************               ";
		gotoxy(i,11);cout<<" ********************     ";
		gotoxy(i,12);cout<<"  ******************      ";
		gotoxy(i,13);cout<<"    **************      ";
		gotoxy(i,14);cout<<"      *********           ";
		Sleep(100);
		clrscr();
			}
	}
	setcolor(94);
		gotoxy(20,6); cout<<"       ********       ";
		gotoxy(20,7); cout<<"    ****@****@****     ";
		gotoxy(20,8); cout<<"  ******************    ";
		gotoxy(20,9); cout<<" ***************   ";
		gotoxy(20,10);cout<<" ***********    ";
		gotoxy(20,11);cout<<" ***************     ";
		gotoxy(20,12);cout<<"  ******************      ";
		gotoxy(20,13);cout<<"    **************      ";
		gotoxy(20,14);cout<<"      *********           "<<endl;
		setcolor(100);
		gotoxy(20,16); cout<<"-_ P A C M A N _-";
		setcolor(90);
		gotoxy(15,17); cout<<"[1]:open game     ";
		setcolor(89);
		cout<<"[2]:close";
		
	while(1){
		if(_kbhit()){
			char a = getch();
			if(a=='2'){
				break;
			}
			if(a=='1'){
				clrscr();
				int i=0;
				while(i<=100){
					gotoxy(20,10);
					cout<<"Loading..........";
					setcolor(i);
					gotoxy(20,11);
					cout<<"    "<<i<<"%";
					if(i==100) Sleep(2000);
					Sleep(50);
					i++;
				}
				break;
			}
		}
	}
	clrscr();

}

#endif
