#ifndef _DICHUYEN_H
#define _DICHUYEN_H
#include <iostream>
#include "console.h"
using namespace std;
class DiChuyen{
	private:
		int x;
		int y;
	public:
		void setX(int x){
			this->x = x;
		}
		void setY(int y){
			this->y = y;
		}
		int getX(){
			return x;
		}
		int getY(){
			return y;
		}
		void up(){
			x--;
		}
		void down(){
			x++;
		}
		void right(){
			y++;
		}
		void left(){
			y--;
		}
		void stop(){
		}
};
class PacMan:public DiChuyen{
	private:
		char trangthai;
		int flag = 0;
	public:
		PacMan(){
			setX(24);
			setY(14);
			trangthai = 'a';
		}
		void reset(){
			setX(24);
			setY(14);
			trangthai = 'a';
		}
		int getFlag(){
			return flag;
		}
		void dichuyen(){
			if(trangthai == 'a'){
				left();
				flag = 1;
			}
			if(trangthai == 'd'){
				right();
				flag = 2;
			}
			if(trangthai == 'w'){
				up();
				flag = 3;
			}
			if(trangthai == 's'){
				down();
				flag = 4;
			}
			if(trangthai == 'p'){
				stop();
				flag = 5;
			}
		}
		void vePacman(){
			setcolor(30);
			gotoxy(getY(),getX());
			cout<<(char)240;
			setcolor(15);
		}
		void xoaPacman(){
			gotoxy(getY(),getX());
			cout<<" ";
		}
		bool DIE(DiChuyen b){
			if(getX()==b.getX()&&getY()==b.getY()) return true;
			return false;
		}
		void setTrangThai(char tt){
			trangthai = tt;
		}
		char getTrangThai(){
			return trangthai;
		}
};
#endif
