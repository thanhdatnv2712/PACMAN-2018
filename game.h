#ifndef _GAME_H
#define _GAME_H
#include <iostream>
#include "console.h"
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include "backgrow.h"
using namespace std;
char MAP[100][100];
char X[100][100];
int Map_X,Map_Y;
DiChuyen ham[2],ghost[4];
PacMan pac;
int soDot = 0;
void Init(){
	int x,y;
	ifstream ifs("PA1.txt",ios::in);
	ifs>>Map_X>>Map_Y;
	ifs>>x>>y;ham[0].setX(x);ham[0].setY(y);
	ifs>>x>>y;ham[1].setX(x);ham[1].setY(y);
	for(int i=1;i<=Map_X;i++){
		for(int j=1;j<=Map_Y;j++){
			char a;
			ifs>>a;
			X[i][j] = a;
			if(X[i][j] == '1' || X[i][j] == '2')
			{
				MAP[i][j] = '#';
			}
			else MAP[i][j] = a;
			if(MAP[i][j]=='*'||MAP[i][j]=='.') soDot++;
		}
	}
	for(int i=0;i<4;i++){
		ifs>>x>>y;
		ghost[i].setX(x);
		ghost[i].setY(y);
	}
}
void dieukhien(){
	if(kbhit()){
		char a = getch();
		if(a == 'a') pac.setTrangThai('a');
		if(a == 'd') pac.setTrangThai('d');
		if(a == 's') pac.setTrangThai('s');
		if(a == 'w') pac.setTrangThai('w');
	}
}
void MAPP(){
	for(int i=1;i<=Map_X;i++){
		for(int j=1;j<=Map_Y;j++){
			gotoxy(j,i);
			if(MAP[i][j]=='+') cout<<" ";
			else if(MAP[i][j]=='#' && X[i][j] == '1'){
				setcolor(25);
				//cout<<MAP[i][j];
				cout<<(char)219;
				setcolor(15);
			}
			else if(MAP[i][j]=='#' && X[i][j] == '2')
			{
				setcolor(25);
				//cout<<MAP[i][j];
				cout<<(char)219;
				setcolor(15);				
			}
			else cout<<MAP[i][j];
		}
	}
}
void veGhost(){
	for(int i=0;i<4;i++){
		gotoxy(ghost[i].getY(),ghost[i].getX());
		if(i==0) setcolor(12);
		else if(i==1) setcolor(90);
		else if(i==2) setcolor(15);
		else setcolor(61);
		cout<<(char)232;
		setcolor(15);
	}
}
void xoaGhost(){
	for(int i=0;i<4;i++){
		gotoxy(ghost[i].getY(),ghost[i].getX());
		cout<<" ";
	}
}
void chantuong(){
	if(MAP[pac.getX()][pac.getY()]=='#'){
		if(pac.getFlag()==1) pac.right();
		if(pac.getFlag()==2) pac.left();
		if(pac.getFlag()==3) pac.down();
		if(pac.getFlag()==4) pac.up();
		pac.stop();
	}
}
int diem=0;
void andot(){
	if(MAP[pac.getX()][pac.getY()]=='.'){
		diem+=5;
		MAP[pac.getX()][pac.getY()]='+';
		soDot--;
	}
	if(MAP[pac.getX()][pac.getY()]=='*'){
		diem+=40;
		MAP[pac.getX()][pac.getY()]='+';
		soDot--;
	}
}
void chuiham(){
	if(pac.getX()==ham[0].getX()&&pac.getY()==ham[0].getY()){
		pac.setX(ham[1].getX());
		pac.setY(ham[1].getY());
		return ;
	}
	if(pac.getX()==ham[1].getX()&&pac.getY()==ham[1].getY()){
		pac.setX(ham[0].getX());
		pac.setY(ham[0].getY());
		return ;
	}
	for(int i=0;i<4;i++){
		if(ghost[i].getX()==ham[0].getX()&&ghost[i].getY()==ham[0].getY()){
			ghost[i].setX(ham[1].getX());
			ghost[i].setY(ham[1].getY());
			return ;
		}
		if(ghost[i].getX()==ham[1].getX()&&ghost[i].getY()==ham[1].getY()){
			ghost[i].setX(ham[0].getX());
			ghost[i].setY(ham[0].getY());
			return ;
		}
	}
}
bool die(){
	if(soDot==0) return true;
	for(int i=0;i<4;i++){
		if(pac.DIE(ghost[i])) return true;
	}
	return false;
}
void vedot(){
	for(int i=0;i<4;i++){
		gotoxy(ghost[i].getY(),ghost[i].getX());
		if(MAP[ghost[i].getX()][ghost[i].getY()]=='+') cout<<" ";
		else cout<< MAP[ghost[i].getX()][ghost[i].getY()];
	}
}
void ghostdichuyen(){
	int x_xq[4] = {1,-1,0,0};
	int y_xq[4] = {0,0,1,-1};
	for(int i=0;i<4;i++){
		vector <DiChuyen> di;
		for(int j=0;j<4;j++){
			if(MAP[ghost[i].getX()+x_xq[j]][ghost[i].getY()+y_xq[j]]!='#'&&MAP[ghost[i].getX()+x_xq[j]][ghost[i].getY()+y_xq[j]]!='o'){
				DiChuyen tmp;
				tmp.setX(ghost[i].getX()+x_xq[j]);
				tmp.setY(ghost[i].getY()+y_xq[j]);
				di.push_back(tmp);
			}
		}
		int k;
		k=rand()%di.size();
		ghost[i].setX(di[k].getX());
		ghost[i].setY(di[k].getY());
	}
}
void GameOver(){
	Nocursortype();
	setcolor(100);
	gotoxy(5,5); cout<<"GAME OVER!";
	string Lost = "Your Score: ";
	for(int i=0;i<Lost.length();i++){
		gotoxy(5,6);
		for(int j=0;j<=i;j++) cout<<Lost[j];
		Sleep(250);
	}
	cout<<diem;
	Sleep(250);
	gotoxy(5,7);cout<<"Press Space!!";
	while(1){
		if(kbhit()){
			char a = getch();
			if(a==' ') break;
		}
	}
}
void Start(){
	srand(time(NULL));
	Nocursortype();
	MAPP();
	gotoxy(30,2);cout<<". = 5 point";
	gotoxy(30,3);cout<<"* = 40 point";
	while(1){
		gotoxy(30,1);cout<<"Your Score: "<<diem;
		gotoxy(30,4);cout<<"Number of dot: ";
//		gotoxy(29, 5);cout<<"UP: w";
//		gotoxy(29, 6);cout<<"DOWN: s";
//		gotoxy(29, 7);cout<<"LEFT: a";
//		gotoxy(29, 8);cout<<"RIGHT: d";
		if(soDot<=9) cout<<"00"<<soDot;
		else if(soDot<=99) cout<<"0"<<soDot;
		else cout<<soDot;
		chuiham();
		dieukhien();
		pac.dichuyen();
		chantuong();
		pac.vePacman();
		andot();
		if(die()){
			clrscr();
			GameOver();
			Sleep(2000);
			gotoxy(10,10); cout<<"Ban co muon choi lai: [1].Yes     [2].No    [3].Exit";
			Init();
			pac.reset();
			diem = 0;
			while(1){
				if(kbhit()){
					char a = getch();
					if(a=='1'){
						clrscr();
						Start();
					}
					else if(a=='2'){
						clrscr();
						return;
					}
					else{
						Init();
						Background();
						Start();
					}
				}
			}
		}
		ghostdichuyen();
		veGhost();
		Sleep(90);
		xoaGhost();
		vedot();
		pac.xoaPacman();
	}
	clrscr();
}
#endif
