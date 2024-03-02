

using namespace std;

typedef struct _cell {
	int Value;
	struct _cell *next;
} cell;

class BFS{
	private:
		int* visitedBFSMap;
		int size;
		int collum;
	public:
		BFS(int,int);
		~BFS();
		cell *head,*tmp,*last;	
		void pushback(int);
		int bfsObjAlgorithm(int,char*);
		int bfsObj(const char*,int*&,cell*&,int,int &);
};

BFS::BFS(int size,int collum){
	this->size=size;
	this->collum=collum;
	this->visitedBFSMap=new int [size];
	this->head=this->last=NULL;
}

BFS::~BFS(){
	delete [] this->visitedBFSMap;
}

void BFS::pushback(int x){
	cell *tmp=new cell;
	tmp->Value=x;
	tmp->next=this->head;
	this->head=tmp;
}

int BFS::bfsObj(const char *arr,int* &v,cell* &head,int w,int &f){
	int last=-1;
	
	
	if (v[w]==0 && f==0){
		if (arr[w]=='*' || arr[w]=='M' || arr[w]=='L'){
			v[w]=1;
			return -1;
		}
		if (arr[w]=='#'){
			v[w]=1;
			f=1;
			return w;
		}
		else if (arr[w]=='.'){
			v[w]=1;
			last=bfsObj(arr,v,this->head,w+1,f);
			if (last!= -1){
				pushback(last);
				return w;
			}
			last=bfsObj(arr,v,this->head,w-1,f);
			if (last!= -1){
				pushback(last);
				return w;
			}
			last=bfsObj(arr,v,this->head,w+collum,f);
			if (last!= -1){
				pushback(last);
				return w;
			}
			last=bfsObj(arr,v,this->head,w-collum,f);
			if (last!= -1){
				pushback(last);
				return w;
			}
		}
	}
	return -1;
}

int BFS::bfsObjAlgorithm(int dir,char *pin){
	for(tmp=this->head; tmp!=NULL; tmp=tmp->next){
		this->head=this->head->next;
	}
	this->last=this->head;
	int w =dir;
	for (int i=0; i<size; i++){
		visitedBFSMap[i] = 0;
	}
	visitedBFSMap[w] = 1;
	int last=-1,f=0;
	last=this->bfsObj(pin,visitedBFSMap,this->head,w+1,f);
	if (last!= -1){
		pushback(last);
	}
	last=this->bfsObj(pin,visitedBFSMap,this->head,w-1,f);
	if (last!= -1){
		pushback(last);
	}
	last=this->bfsObj(pin,visitedBFSMap,this->head,w+collum,f);
	if (last!= -1){
		pushback(last);
	}
	last=this->bfsObj(pin,visitedBFSMap,this->head,w-collum,f);
	if (last!= -1){
		pushback(last);
	}
	if (this->head==NULL){
		pushback(dir);
	}
	return 1;
}
