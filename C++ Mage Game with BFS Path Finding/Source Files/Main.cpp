#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <iostream>
#include <new>
#include <conio.h>
#include <cstddef>
#include <time.h>
#include "Maze.h"
#include "BFS.h"
#include "Player.h"
#include "Ghost.h"
#include "Menu.h"

using namespace std;


int main(int argc, char *argv[]){
	char c;
	char *pin;
	int size=1;
	int collum=0;
	int rows=0;
	int flag=0;
	string line;
	string fileName;
	srand(time(0));
	fileName = argv[1];
	fileName += ".txt";
	ifstream maze (fileName.c_str());
	if (maze.is_open()) {
		maze.get(c);
		while (!(maze.eof())) {
	    	if (c != '*' && c != '.' && c != '\n'){
				cout << "Invalid character :" << c <<endl;
	    		cout << "maze must only has stars and dots"  <<endl <<endl;
	    		system("PAUSE");
	    		exit(1);
			}
			maze.get(c);
	    }
	    maze.clear();
	    maze.seekg(0);
		maze.get(c);
	    while (c !='\n') {
	    	collum+=1;
			maze.get(c);
	    }
	    collum+=1;
		while (getline(maze,line)) {
	        rows+=1;
	    }
	    rows+=1;
	    size=rows*collum-1;
	    maze.clear();
	    maze.seekg(0);
	    pin=new char[size];
	    for (int i=0;i<size;i++) {
			maze.get(c);
			pin[i]=c;
	    }
		maze.close();
		int upr=0,lowr,lefcol,rigcol;
		while (upr<collum-1){
			if (pin[upr]!='*'){
				cout << flush;
				system("CLS");
				cout << '\t' << '\t' << '\t' << '\t' << "MAP WARNING" << endl << endl;
				cout << '\t' << '\t' << '\t' << "    MAZE MUST BE CLOSED" << endl;
				system("PAUSE");
				exit(1);
			}
			upr++;
		}
		lowr=size-collum;
		while (lowr<size-1){
			lowr++;
			if (pin[lowr]!='*'){
				cout << flush;
				system("CLS");
				cout << '\t' << '\t' << '\t' << '\t' << "MAP WARNING" << endl << endl;
				cout << '\t' << '\t' << '\t' << "    MAZE MUST BE CLOSED" << endl;
				system("PAUSE");
				exit(1);
			}
		}
		while (lefcol<size-collum*2){
			lefcol+=collum;
			if (pin[lefcol]!='*'){
				cout << flush;
				system("CLS");
				cout << '\t' << '\t' << '\t' << '\t' << "MAP WARNING" << endl << endl;
				cout << '\t' << '\t' << '\t' << "    MAZE MUST BE CLOSED" << endl;
				system("PAUSE");
				exit(1);
			}
		}
		rigcol=collum-2;
		while (rigcol<=size){
			if (pin[rigcol]!='*'){
				cout << flush;
				system("CLS");
				cout << '\t' << '\t' << '\t' << '\t' << "MAP WARNING" << endl << endl;
				cout << '\t' << '\t' << '\t' << "    MAZE MUST BE CLOSED" << endl;
				system("PAUSE");
				exit(1);
			}
			rigcol+=collum;
		}
	}
	Maze Maze(size);
	Menu Menu(flag,size);
	BFS BFS(size,collum);
	Player Player(size,collum);
	Ghost Ghost(size,flag);
	while(flag != -2){
		Menu.menu();
		Maze.setMap(pin);
		Menu.runfirst(Maze,Player,Ghost,BFS);
		flag=0;
		while(( flag != 1 && flag != -1) && Menu.checkesc()){
			flag=Menu.run(Maze,Player,Ghost,BFS);
		}
	}
	delete [] pin;
	return 1;
}
