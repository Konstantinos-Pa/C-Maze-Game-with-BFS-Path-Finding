
class Menu {
	private:
		int flag;
		int size;
	public:
		Menu(int,int);
		~Menu();
		void menu();
		int getflag();
		void setflag(int);
		void runfirst(Maze&, Player&, Ghost&, BFS&);
		int run(Maze&, Player&, Ghost&, BFS&);
		int checkwin();
		int checklose();
		int checkesc();
};

Menu::Menu(int flag,int size){
	this->flag=flag;
	this->size=size;
}

Menu::~Menu(){
}

int Menu::getflag(){
	return this->flag;
}

void Menu::setflag(int flag){
	this->flag=flag;
}

void Menu::menu(){
	cout << flush;
	system("CLS");
	cout << endl << endl << endl << endl << endl << endl << endl;
	cout << '\t' << '\t'  << '\t'  << '\t' << "Wellcome to The Search of the Magic Gem" << endl;
	cout << '\t' << '\t'  << '\t'  << '\t' <<  '\t' << "You are Loukas Malfoi(L)" << endl;
	cout << '\t' << '\t'  << '\t'  << '\t' <<  ' ' <<  ' ' <<  ' ' <<  ' ' <<  ' ' <<  ' ' <<  ' ' <<  ' ' << "Take the Gem (#) to win" << endl;
	cout << '\t' << '\t'  << '\t' <<  ' ' <<  ' ' <<  ' ' <<  ' ' <<  ' ' << "But carefull of Mpamphs Poteridhs (M) he is smart" << endl;
	cout << endl << endl << endl << endl << endl << endl << endl;
	system("PAUSE");
}

void Menu::runfirst(Maze &mazeMap, Player& player, Ghost& ghost, BFS& bfsObj){
	
	int ty,whileFlag;
	mazeMap.addGem();
	char *pin=new char[size];
	strcpy(pin,mazeMap.getMap());
	do{
		whileFlag=0;
		ty=0;
		do{
			player.addPlayer(pin);
			bfsObj.bfsObjAlgorithm(player.getp(),pin);
			if (bfsObj.head->Value==player.getp()){
				pin[player.getp()]='.';
			}
			ty++;
			if(ty>(size*size)){
				mazeMap.mapWarning();
			}
		}while (bfsObj.head->Value==player.getp());
		ty=0;
		do{
			ghost.addGhost(pin);
			bfsObj.bfsObjAlgorithm(ghost.getg1(),pin);
			if (bfsObj.head->Value==ghost.getg1()){
				pin[ghost.getg1()]='.';
			}
			ty++;
			if(ty>(size*size)){
				mazeMap.mapWarning();
			}
		}while (bfsObj.head->Value==ghost.getg1());
		if ((bfsObj.bfsObjAlgorithm(player.getp(),pin) && bfsObj.head->Value==player.getp()) || (bfsObj.bfsObjAlgorithm(ghost.getg1(),pin) && bfsObj.head->Value==ghost.getg1()) ){
			pin[player.getp()]='.';
			pin[ghost.getg1()]='.';
			whileFlag=1;
		}
		
	}while (whileFlag);
	mazeMap.setMap(pin);
	delete[] pin;
}
	
int Menu::run(Maze& mazeMap, Player& player, Ghost& ghost, BFS& bfsObj){
	mazeMap.display();
	char *pin=new char[size];
	strcpy(pin,mazeMap.getMap());
	this->setflag(player.movePlayer(pin));
	if (this->getflag()==0){
		this->setflag(ghost.moveGhost(pin,bfsObj));
	}
	this->checkwin();
	this->checklose();
	mazeMap.setMap(pin);
	delete [] pin;
	return this->getflag();
}

int Menu::checkwin(){
	if(flag==1){
		cout << flush;
		system("CLS");
		cout << endl << endl << endl << endl << endl << '\t' << '\t' << '\t' << "YOU WON" << endl << endl << endl << endl << endl ;
		cout << "WOW you actually did it too bad you won't be joining us" << endl;
		system("PAUSE");
		cout << flush;
		system("CLS");
	}
}

int Menu::checklose(){
	if(flag==-1){
		cout << flush;
		system("CLS");
		cout << endl << endl << endl << endl << endl<< '\t' << '\t' << '\t' << '\t' << "GAME OVER" << endl << endl << endl << endl << endl ;
		cout << "Welcome to the club you lost and have to do it again next semester" << endl;
		system("PAUSE");
		cout << flush;
		system("CLS");
	}
}

int Menu::checkesc(){
	if(flag==-2){
		cout << endl << "Hope we won't see you next semester\n";
		system("PAUSE");
		return 0;
	}
	else{
		return 1;
	}
}

