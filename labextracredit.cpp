/*
Michael Alberda
4/24/2018
cs120 extra credit lab assignment
Jia Song
*/
#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

//variables
int width=40;
int height=30;


//matrices


//functions
void printarray(string newmatrix[30][40]);
void find(string newmatrix[30][40], string target, int x, int y);

//int main

int main(){
string matrix[30][40];

int yinput;
int xinput;
string input;

for(int i=0;i<30;i++){
for(int o=0;o<40;o++){
matrix[i][o]="a";
}}

for(int i=0;i<10;i++){
cout<<"input a y coordinate and an x coordinate, followed by a character."<<endl;

do{
cin>>yinput;
cin>>xinput;
cin>>input;
if(yinput>40||xinput>30||yinput<0||xinput<0)
cout<<"invalid input try again"<<endl;

}while(yinput>40||xinput>30||yinput<0||xinput<0);
matrix[yinput][xinput]=input;

}

printarray(matrix);

cout<<"which letter would you like to find?"<<endl;
cin>>input;
find(matrix, input, width, height);




}



void printarray(string newmatrix[30][40]){

for(int i=0;i<30;i++){
for(int o=0;o<40;o++){
cout<<newmatrix[i][o] <<" ";
}
cout<<endl;}

}



void find(string newmatrix[30][40], string target, int x, int y){

for(int i=0;i<30;i++){
for(int o=0;o<40;o++){
if(newmatrix[i][o]==target)
cout<<"the location is "<<i<< " by "<<o<<" where the letter "<<target<<" can be found"<<endl;
}}


}

