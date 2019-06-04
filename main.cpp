#include <iostream>
#include <windows.h>
#include <conio.h>
#include "console.h"
#include "DiChuyen.h"
#include "game.h"
#include "backgrow.h"
using namespace std;
int main(int argc, char** argv) {
	settitle("SKYNET VISION by NGUYEN VIET THANH DAT");
	resizecsl(50, 55);
	Background();
	Init();
	Start();
//	GameOver();
//	for(int i=0;i<=100;i++){
//		if(i%10==0) cout<<endl;
//		setcolor(i);
//		cout<<i;
//	}
//for(int i = 0; i < 257; i++) cout<<i<<" "<<(char)i<<endl;
//	return 0;
}
