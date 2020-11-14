/*
Michael Alberda
4/23/2018
cs120 tictactoe extra credit
Jia Song
*/
#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

//variable time
int winstate=0;
int playernum=1;

//matrices
char displayboard[3][3];
int win[2];

//functions
int playermove(int y, int x);
int compmove(int playery, int playerx);
int printboard();
int check(int a, int b);

//main
int main(){
int choice;
int yinput;
int xinput;
srand(time(NULL));




do{

for(int i=0; i<3;i++){
        for(int o=0; o<3; o++){
                displayboard[i][o]='+';
        }
}
printboard();

cout<<"welcome to tic tac toe. who is playing, a player and a computer(1), or two players(1)?"<<endl;

cin>>choice;

if (choice==1){
do{
	
	if(playernum==1){
	cout<<"player number "<< playernum << " enter your move:"<<endl;
	cin>>yinput;
	cin>>xinput;
	winstate=playermove(yinput, xinput);
	}
	if(playernum==2)
	winstate=compmove(yinput, xinput);
printboard();
if(playernum==1)
playernum=2;
else
playernum=1;

}while (winstate!=1);



}//end if
else if(choice==2){

do{

	cout<<"player number "<< playernum << " enter your move:"<<endl;
        cin>>yinput>>xinput;
        winstate=playermove(yinput, xinput);
	
	if(playernum==1)
	playernum=2;
	else
	playernum=1;
	
	printboard();

}while (winstate!=1);

}//end if



if(playernum==1)
playernum=2;
else
playernum=1;
cout<<"player "<<playernum<<" has won"<<endl;
win[playernum-1]++;
cout<<"player one has "<<win[0]<<" and player 2 has "<<win[1]<<" points."<<endl;
cout<<"would you like to play again? press 1 for yes and 0 for no."<<endl;
cin>>choice;

}while (choice!=0);


}//end int main


int playermove(int y, int x){

if(playernum==1){
displayboard[y][x]='X';
}
if(playernum==2){
displayboard[y][x]='O';
}
return check(y,x);
}



int compmove(int playery, int playerx){ 
int ymove;
int xmove;
srand(time(NULL));


for(int i=0;i<3;i++){
for(int o=0;o<3;o++){

if(displayboard[i][o]!='+'){
	
	if(displayboard[i][o]==displayboard[i-1][o]&&i+1<3&&i+1>=0&&displayboard[i+1][o]=='+')
	{ymove=i+1;
	xmove=o;}
	else if(displayboard[i][o]==displayboard[i+1][o]&&i-1<3&&i-1>=0&&displayboard[i-1][o]=='+')
        {ymove=i-1;
        xmove=o;}
	else if(displayboard[i][o]==displayboard[i+1][o+1]&&i-1<3&&o-1<3&&i-1>=0&&o-1>=0&&displayboard[i-1][o-1]=='+')
        {ymove=i-1;
        xmove=o-1;}
	else if(displayboard[i][o]==displayboard[i-1][o-1]&&i+1<3&&o+1<3&&i+1>=0&&o+1>=0&&displayboard[i+1][o+1]=='+')
        {ymove=i+1;
        xmove=o+1;}
	else if(displayboard[i][o]==displayboard[i][o+1]&&o-1<3&&o-1>=0&&displayboard[i][o-1]=='+')
        {ymove=i;
        xmove=o-1;}
	else if(displayboard[i][o]==displayboard[i][o-1]&&o+1<3&&o+1>=0&&displayboard[i][o+1]=='+')
        {ymove=i;
        xmove=o+1;}
	else if(displayboard[i][o]==displayboard[i+1][o-1]&&i-1<3&&o+1<3&&i-1>=0&&o+1>=0&&displayboard[i-1][o+1]=='+')
        {ymove=i-1;
        xmove=o+1;}
	else if(displayboard[i][o]==displayboard[i-1][o+1]&&i+1<3&&o-1<3&&i+1>=0&&o-1>=0&&displayboard[i+1][o-1]=='+')
        {ymove=i+1;
        xmove=o-1;}
	else{
	do{
	ymove=rand()%3;
	xmove=rand()%3;
	}while(ymove>2||ymove<0||xmove>2||xmove<0||displayboard[ymove][xmove]!='+');

	}

		
}
	
}}//end for loops

cout<<"the player chooses " << ymove << " down and "<< xmove <<" over"<<endl;
displayboard[ymove][xmove]='O';
winstate=check(ymove,xmove);

}


int printboard(){
cout<<" ";
for(int i=0; i<3;i++){
cout<<"_";}
cout<<endl;
for(int i=0; i<3;i++){
        cout<<"|";
	for(int o=0; o<3; o++){
         
	       cout<<displayboard[i][o];
        }
	cout<<"|";
cout<<endl;
}

}

int check(int a, int b){


for(int i=0;i<3;i++){
for(int o=0;o<3;o++){

if(displayboard[i][o]!='+'){


if(displayboard[i][o]==displayboard[i-1][o]&&displayboard[i][o]==displayboard[i+1][o])
return 1;

if(displayboard[i][o]==displayboard[i][o-1]&&displayboard[i][o]==displayboard[i][o+1])
return 1;

if(displayboard[i][o]==displayboard[i-1][o-1]&&displayboard[i][o]==displayboard[i+1][o+1])
return 1;

if(displayboard[i][o]==displayboard[i-1][o+1]&&displayboard[i][o]==displayboard[i+1][o-1])
return 1;


}}//end for loops



}


}


