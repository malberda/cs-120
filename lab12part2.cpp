/*
Michael Alberda
4/17/2018
cs120 lab12
Jia Song
*/
#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<cstdio>
using namespace std;


int xinput;
int yinput;
int size=10;
int mines[10][10];
char field[10][10];
int winfield[10][10];
int nearbymines[10][10];
int winnum;
int playermove(int y, int x);
int check(int y, int x);
void nearbycheck();
void multiclear(int a, int b);
int nearby=0;


int main()
{
int random;
int win=1;
srand(time(NULL));




							//create random mine placement
for(int i=0;i<size;i++){
	for(int o=0;o<size;o++){
	random=rand()%10;
		nearbymines[i][o]=0;
	if(random<=2)
		mines[i][o]=1;
	else
		mines[i][o]=0;	
	cout<<mines[i][o];
	
	winfield[i][o]=mines[i][o];
	
	}//end o for loop
	cout<<endl;
}//end i for loop

							//set up nearby matrix
nearbycheck();

							//set up display field
for(int i=0;i<size;i++){
        for(int o=0; o<size;o++){
		field[i][o]='+';
                }//end for loop
}//end for loop

							//display field

do{
for(int i=0;i<size;i++){
        for(int o=0;o<size;o++){
		cout<<field[i][o]<<" ";
        }//end o for loop
        cout<<endl;
}//end i for loop

							//accept input from player

cout<<"enter your coordinates, y first then x measured from 0 to 9 ";
cout<<"measuring from the top down and left to right"<<endl;
int legalmove=1;
do{
cin>>yinput;
cin>>xinput;

winfield[yinput][xinput]=1;
							//invalid input
if(yinput>=size||yinput<0||xinput>=size||xinput<0){
cout<<"that was an illegal move, try again"<<endl;
legalmove=0;}
else
legalmove=1;
}while(legalmove==0);

win=playermove(yinput,xinput);

							//check winstate

for(int i=0;i<size;i++){
	for(int o=0;o<size;o++){
	if(winfield[i][o]!=0)
	winnum++;
	}
}


if(winnum==(size*size))
{
cin.ignore();
cout << "\nPress enter to win the game. \n";
cin.ignore();
return 0;}

else
winnum=0;

}while(win!=0);

cout<<"you have lost, try again later!"<<endl;
return 0;
}//end int main()


							//playermove function



int playermove(int y, int x){
if(mines[y][x]==1)
return 0;
else{
if(nearbymines[y][x]==0)
{field[y][x]='0';
multiclear(y,x);
}
if(nearbymines[y][x]==1)
field[y][x]='1';
if(nearbymines[y][x]==2)
field[y][x]='2';
if(nearbymines[y][x]==3)
field[y][x]='3';
if(nearbymines[y][x]==4)
field[y][x]='4';
if(nearbymines[y][x]==5)
field[y][x]='5';
if(nearbymines[y][x]==6)
field[y][x]='6';
if(nearbymines[y][x]==7)
field[y][x]='7';
if(nearbymines[y][x]==8)
field[y][x]='8';


winfield[y][x]=nearbymines[y][x];
cout<<"there are "<<nearbymines[y][x]<<" mines nearby."<<endl;

return 1;

}//end else statement

}//end playermove()

							//check surroundings function
int check(int q, int w){
nearby=0;
for(int i=0;i<3;i++){
	for(int o=0; o<3;o++){
		if ((mines[q-1+i][w-1+o]==1)&&((q-1+i)>=0)&&((q-1+i)<size)&&((w-1+o)>=0)&&((w-1+o)<size))
		nearby++;


		}//end for loop
}//end for loop
return nearby;
}//end check()

							//check nearby mines
void nearbycheck(){
for(int i=0;i<10;i++){
        for(int o=0; o<10;o++){
                nearbymines[i][o]=check(i,o);
		cout<<nearbymines[i][o]<<" ";
                }//end for loop
cout<<endl;
}//end for loop


}

							//extra credit clear function
void multiclear(int a, int b){

int j=0;
int k=0;


for(int i=0;i<3;i++){
        for(int o=0; o<3;o++){
        j=(a-1+i);
        k=(b-1+o);

	if((j!=a)||(k!=b))
	{
	if(((j)>=0)&&((j)<10)&&((k)>=0)&&((k)<10)&&(field[j][k]=='+'))	
	{
	if(nearbymines[j][k]==0)
	{field[j][k]='0';
	multiclear(j,k);}

	if(nearbymines[j][k]==1){
		winfield[j][k]=1;
                field[j][k]='1';}
        if(nearbymines[j][k]==2){
                winfield[j][k]=1;
                field[j][k]='2';}
        if(nearbymines[j][k]==3){
                winfield[j][k]=1;
                field[j][k]='3';}
        if(nearbymines[j][k]==4){
                winfield[j][k]=1;
                field[j][k]='4';}
        if(nearbymines[j][k]==5){
                winfield[j][k]=1;
                field[j][k]='5';}
        if(nearbymines[j][k]==6){
                winfield[j][k]=1;
                field[j][k]='6';}
        if(nearbymines[j][k]==7){
                winfield[j][k]=1;
                field[j][k]='7';}
        if(nearbymines[j][k]==8){
                winfield[j][k]=1;
                field[j][k]='8';}



	}
	}
                }//end for loop
}//end for loop

}//end multiclear

