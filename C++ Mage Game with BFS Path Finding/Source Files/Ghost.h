#include <time.h>
#include <stdlib.h>

class Ghost{
	private:
		int g1;
		int size;
		int lose;
	public:
		Ghost(int, int);
		~Ghost();
		int getg1(){
			return g1;
		}
		void addGhost(char*&);
		int moveGhost(char*&,BFS&);
	
};

Ghost::Ghost(int size,int lose){
	this->size=size;
	this->lose=lose;
}

Ghost::~Ghost(){
}

void Ghost::addGhost(char *&pin){
	int RandIndex = rand() % size;
	while (pin[RandIndex]!='.'){
		RandIndex = rand() % size;
	}
	this->g1=RandIndex;
	pin[g1]='M';
}

int Ghost::moveGhost(char*& pin, BFS& bfsObj){
	if (pin[bfsObj.head->Value]=='#'){
		return -1;
	}
	if (pin[bfsObj.head->Value]=='L'){
		bfsObj.bfsObjAlgorithm(this->g1,pin);
	}
	pin[g1]='.';
	pin[bfsObj.head->Value]='M';
	this->g1=bfsObj.head->Value;
	if(bfsObj.head->next!=NULL){
		bfsObj.head=bfsObj.head->next;
	}
	else{
		bfsObj.bfsObjAlgorithm(this->g1,pin);
	}
	return 0;
}
