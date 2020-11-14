/*
Michael Alberda
4/25/2018
cs120 lab13
Jia Song
*/
#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

int min(int matrix[5]);
int ave(int matrix[5]);
void swap(int matrix[5]);
void swapptr();

//variables


//int main
int main(){

int num[5];
int multtable[10][10];

int average;
int minimum;
int input;
int x;
int y;


for(int i=0;i<5;i++){
do{
cout<<"enter a number between 1 and 8."<<endl;
cin>>input;
if(input>8||input<1)
cout<<"error in input, try again."<<endl;
}while(input>8||input<1);
num[i]=input;
}

multtable[0][0]=1;
for(int i=0;i<10;i++){
multtable[i][0]=i+1;
}for(int o=0;o<10;o++){
multtable[0][o]=o+1;
}

for(int i=0;i<10;i++){
for(int o=0;o<10;o++){
multtable[i][o]=((i+1)*(o+1));
cout<<multtable[i][o]<<"    ";
}cout<<endl;}

minimum=min(num);

cout<<"the smallest number is "<<minimum<<endl;

average=ave(num);

swap(num);


}//end int main()


int min(int matrix[5]){
int minnum=100;
for(int i=0;i<5;i++){
if(minnum>matrix[i])
{minnum=matrix[i];}
}
return minnum;
}
int ave(int matrix[5]){
double average=0;
for(int i=0;i<5;i++){
average=average+matrix[i];
}
average=average/5;
cout<<"the average is "<<average<<endl;
}
void swap(int matrix[5]){
int standby;
int input;
int choice;

for(int i=0;i<5;i++){
cout<<matrix[i];
cout<<endl;}

cout<<"enter the coordinates of the two numbers you would like to switch"<<endl;
cin>>input;
cin>>choice;
standby=matrix[input];
matrix[input]=matrix[choice];
matrix[choice]=standby;

for(int i=0;i<5;i++){
cout<<matrix[i];
cout<<endl;}

}

