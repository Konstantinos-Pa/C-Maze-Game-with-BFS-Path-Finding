class Player{
	private:
		int p;
		int size;
		int collum;
	public:
		Player(int,int);
		~Player();
		int getp();
		void setp(int);
		void addPlayer(char*&);
		int movePlayer(char*&);
		
		
};

Player::Player(int size,int collum){
	this->size=size;
	this->collum=collum;
}

Player::~Player(){
}

Player::getp(){
	return p;
}

void Player::setp(int pos){
	this->p=pos;
}

void Player::addPlayer(char *&pin){
	int RandIndex = rand() % size;
	while(pin[RandIndex]!='.'){
		RandIndex = rand() % size;
	}
	this->setp(RandIndex);
	pin[p]='L';
}

int Player::movePlayer(char*& pin){
	int ch;
	ch = getch ();
	if(ch=='\e'){
		return -2;
	}
	if (ch == 224){
		ch = getch();
		switch(ch){
			case 72:
				if (pin[p-collum]=='.'){
					pin[p]='.';
					pin[p-collum]='L';
					this->setp(p-collum);
				}
				else if(pin[p-collum]=='#'){
					pin[p]='.';
					pin[p-collum]='L';
					this->setp(p-collum);
					return 1;
				}
				break;
			case 80:
				if (pin[p+collum]=='.'){
					pin[p]='.';
					pin[p+collum]='L';
					this->setp(p+collum);
				}
				else if(pin[p+collum]=='#'){
					pin[p]='.';
					pin[p+collum]='L';
					this->setp(p+collum);
					return 1;
				}
				break;
			case 75:
				if (pin[p-1]=='.'){
					pin[p]='.';
					pin[p-1]='L';
					this->setp(p-1);
				}
				else if(pin[p-1]=='#'){
					pin[p]='.';
					pin[p-1]='L';
					this->setp(p-1);
					return 1;
				}
				break;
			case 77:
				if (pin[p+1]=='.'){
					pin[p]='.';
					pin[p+1]='L';
					this->setp(p+1);
				}
				else if(pin[p+1]=='#'){
					pin[p]='.';
					pin[p+1]='L';
					this->setp(p+1);
					return 1;
				}
				break;
		}
	}
	return 0;
}
