#include <time.h>
#include <stdlib.h>
#include<iostream>

using namespace std;

class Maze{
	private:
		char *map;
		int size;
	public:
		Maze(int);
		~Maze();
		void setMap(char *);
		char* getMap();
		void addGem();
		void display();
		void mapWarning();
};

Maze::Maze(int size){
	this->size=size;
	this->map=new char [size];
	srand(time(0));
}

Maze::~Maze(){
	delete [] this->map;
}

void Maze::setMap(char *map){
	delete [] this->map;
	this->map=new char [size];
	for (int i=0;i<size;i++){
		this->map[i]=map[i];
	}
}

char* Maze::getMap(){
	return this->map;
}

void Maze::addGem(){
	int amount=1;
	while(amount>0){
		int RandIndex = rand() % size;
		while (this->map[RandIndex]!='.'){
			RandIndex = rand() % size;
		}
		this->map[RandIndex]='#';
		amount-=1;
	}
}

void Maze::display(){
	cout << flush;
	system("CLS");
	for(int i=0;i<size;i++){
		cout << this->map[i];
	}
	cout << '\n';
}

void Maze::mapWarning(){
	cout << flush;
	system("CLS");
	cout << '\t' << '\t' << '\t' << '\t' << "MAP WARNING" << endl << endl;
	cout << "WAY TO SMALL POSSIBLE CHARACTER LOCATIONS or NO POSSIBLE VALID CHARACTER LOCATIONS \n" << endl;
	system("PAUSE");
	exit(1);
}
