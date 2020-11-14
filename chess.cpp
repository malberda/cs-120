#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;


//variables
string characterboard[9][9];
string optionboard[9][9];
string blankboard[9][9];
int board[9][9];
int xinput;
int yinput;
int kingstate1=1;
int kingstate2=1;
int playernum=1;

/*
p#=pawn
K#=king
b#=bishop
k#=knight
r#=rook
q#=queen
++=blank space
+-=possible movement
*/

//function definitions
void playermove(int y, int x);
void printboard();
void printoptionboard();
void initboard();
void pawn1move(int y, int x);
void pawn2move(int y, int x);
void bishopmove(int y, int x);
void knightmove(int y, int x);
void rookmove(int y, int x);
void queenmove(int y, int x);
void kingmove(int y, int x);






//main

int main(){


initboard();
do{
	cout<<"it is player "<<playernum<<"'s turn"<<endl;
	cout<<"what piece would you like to move?"<<endl;
	cin>>yinput;
	cin>>xinput;
	playermove(yinput, xinput);
	printboard();


	}while((kingstate1==1)&&(kingstate2==1));

}


void playermove(int y, int x){

	if(characterboard[y][x]=="p1")
		pawn1move(y, x);
	else if(characterboard[y][x]=="p2")
		pawn2move(y, x);
	else if(characterboard[y][x]=="r1")
		rookmove(y, x);
	else if(characterboard[y][x]=="b1")
		bishopmove(y, x);
	else if(characterboard[y][x]=="k1")
		knightmove(y, x);
	else if(characterboard[y][x]=="q1")
		queenmove(y, x);
	else if(characterboard[y][x]=="K1")
		kingmove(y, x);
	




};



void pawn1move(int y, int x){
	optionboard[y-1][x]="+-";
	optionboard[y-1][x-1]="+-";
	optionboard[y-1][x+1]="+-";
	cout<<"where would you  like to move the piece"<<endl;
	cin>>yinput;
	cin>>yinput;

};
void pawn2move(int y, int x){
	optionboard[y+1][x]="+-";
	optionboard[y+1][x-1]="+-";
	optionboard[y+1][x+1]="+-";
	cout<<"where would you  like to move the piece"<<endl;
	cin>>yinput;
	cin>>yinput;
};

void bishopmove(int y, int x){
for(int i=0;i<15;i++){
	optionboard[y-i][x-i]="+-";
	optionboard[y+i][x-i]="+-";
	optionboard[y-i][x+i]="+-";
	optionboard[y+i][x+i]="+-";
	cout<<"where would you  like to move the piece"<<endl;
	cin>>yinput;
	cin>>yinput;
}
};
void knightmove(int y, int x){
	optionboard[y-2][x-1]="+-";
	optionboard[y-2][x+1]="+-";
	optionboard[y+2][x-1]="+-";
	optionboard[y+2][x+1]="+-";
	optionboard[y-1][x-2]="+-";
	optionboard[y-1][x+2]="+-";
	optionboard[y+1][x-2]="+-";
	optionboard[y+1][x+2]="+-";
	cout<<"where would you  like to move the piece"<<endl;
	cin>>yinput;
	cin>>yinput;

};
void rookmove(int y, int x){
for(int i=0;i<9;i++){
	optionboard[y+i][x]="+-";
	optionboard[y-i][x]="+-";
	optionboard[y][x+i]="+-";
	optionboard[y][x-i]="+-";
	cout<<"where would you  like to move the piece"<<endl;
	cin>>yinput;
	cin>>yinput;
}
};
void queenmove(int y, int x){
	for(int i=0;i<15;i++){
	optionboard[y+i][x]="+-";
	optionboard[y-i][x]="+-";
	optionboard[y][x+i]="+-";
	optionboard[y][x-i]="+-";
	optionboard[y-i][x-i]="+-";
	optionboard[y+i][x-i]="+-";
	optionboard[y-i][x+i]="+-";
	optionboard[y+i][x+i]="+-";
	cout<<"where would you  like to move the piece"<<endl;
	cin>>yinput;
	cin>>yinput;
}
};
void kingmove(int y, int x){

	optionboard[y+1][x]="+-";
	optionboard[y-1][x]="+-";
	optionboard[y][x+1]="+-";
	optionboard[y][x-1]="+-";
	optionboard[y-1][x-1]="+-";
	optionboard[y+1][x-1]="+-";
	optionboard[y-1][x+1]="+-";
	optionboard[y+1][x+1]="+-";
	cout<<"where would you  like to move the piece"<<endl;
	cin>>yinput;
	cin>>yinput;
};


void printoptionboard(){

	for(int i=0;i<9;i++){
			for(int o=0;o<9;o++){
				if(i=0)
					cout<<board[i][o];
				else if (o=0)
					cout<<board[i][o];
				else{
					if(optionboard[i][o]!="+-")
					optionboard[i][o]=blankboard[i][o];
					cout<<optionboard[i][o];
				}


		}cout<<endl;
				
	}

};









void printboard(){
cout<<"  ";
	for(int i=0;i<9;i++){
			for(int o=0;o<9;o++){
			
			if(board[i][o]!=0){	
			if(i==0)
			cout<<" ";	
			

			if((board[i][o]!=1000)&&(characterboard[i][o]!="1000")){
				cout<<board[i][o]<<"  ";
			}
			else
				if(characterboard[i][o]=="1000")
				cout<<blankboard[i][o]<<"  ";
				else
				cout<<characterboard[i][o]<<"  ";
			}}
		cout<<endl<<endl;
		}

};


void initboard(){

		for(int i=0;i<9;i++){
		for(int o=0;o<9;o++){
			if(o==0)
				board[i][o]=i;
			else if(i==0)
				board[i][o]=o;
			else{
				blankboard[i][o]="++";
				board[i][o]=1000;
				characterboard[i][o]="1000";
				}
				


		}

	}


//pawns
for(int i=1;i<9;i++){
	characterboard[2][i]="p2";
	characterboard[7][i]="p1";
}
//rooks
characterboard[1][1]="r2";
characterboard[1][8]="r2";
characterboard[8][1]="r1";
characterboard[8][8]="r1";
//knights
characterboard[1][2]="k2";
characterboard[1][7]="k2";
characterboard[8][2]="k1";
characterboard[8][7]="k1";
//bishops
characterboard[1][3]="b2";
characterboard[1][6]="b2";
characterboard[8][3]="b1";
characterboard[8][6]="b1";
//queens
characterboard[1][5]="q2";
characterboard[8][4]="q2";

//kings
characterboard[1][4]="K2";
characterboard[8][5]="K2";

}