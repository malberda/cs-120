/*
Michael Alberda
CS 120-02
3/26/2018
lab 9
*/

#include <iostream> 
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>

using namespace std;

//variables
string arraytest[35][11] = {};
string arrayanswers[11]={};
string arrayresults[35][11]={};
int percent[35];
double average=0;
int highest=0;
int lowest=100;
int score=0;

void grading();
void print();

int main(){

ifstream infile;
infile.open("test.txt");

for(int i=0;i<35;i++){
	for(int o=0;o<11;o++){
	infile>>arraytest[i][o];

	}//end second for loop

}//end first for loop

		//print each score

cout<<"enter the 10 correct letters, one at a time. "<<endl;

for(int i=1;i<11;i++){
cin>>arrayanswers[i];
}//end for loop

print();
grading();
}//end int main


void print(){

for(int i=0;i<35;i++){
        for(int o=0;o<11;o++){
		cout<<arraytest[i][o]<<" ";
        }//end second for loop
cout<<endl;
}//end first for loop

}

void grading(){

for(int i=0;i<35;i++){

        for(int o=1;o<11;o++){

        if(arraytest[i][o]==arrayanswers[o])
        score=1;
        else
        score=0;

        percent[i]=((percent[i]+score));
        }//end for loop
}//end for loop

for(int i=0;i<35;i++){
cout<<"student number "<<i+1<<" got a "<<percent[i]<<" percent."<<endl;
}//end for loop


for(int i=0;i<35;i++){
average=average+percent[i];
}
average=(average/35);
cout<<"the average score was "<<average<<" percent."<<endl;


//highest score

for(int i=0;i<35;i++){
if(percent[i]>=highest)
highest=percent[i];
}
cout<<"the highest score was "<<highest<<" percent."<<endl;

//lowest score

for(int i=0;i<35;i++){
if(percent[i]<=lowest)
lowest=percent[i];
}
cout<<"the lowest score was "<<lowest<<" percent."<<endl;

}

