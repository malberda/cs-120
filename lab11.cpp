/*
Michael Alberda
CS 120-02
3/26/2018
lab 11
*/

#include <iostream> 
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>

using namespace std;

//variables
string names[2000];
int lengths[10];
int namelength();
int namefinder();
int present=0;
string searchname;

int main(){


ifstream infile;
infile.open("lab11.txt");

for(int i=0;i<2000;i++){
	infile>>names[i];
}//end first for loop


//cout<<names[8].length()<<"help";

cout<<"what name would you like to search for? ";
cin>>searchname;

present=namefinder();
if (present!=-1)
cout<<"the name you entered is present at "<<present<<endl;
if (present==-1)
cout<<"the name you entered is not present. "<<endl;

namelength();

}//end int main


int namefinder(){

for(int i=0;i<2000;i++){
if(searchname == names[i]){
return i;
cout<<"searchname"<<endl;
}//end if statement

}//end 2nd for loop


}//end namefinder

int namelength(){

for(int i=0;i<2000;i++){
	for(int o=0;o<15;o++){
		if(names[i].length()==o)
		lengths[o]++;
	}
}
for(int i=2;i<12;i++){
cout<<"there are "<<lengths[i]<<" names of length "<<i<<endl;

}//end for
}//end namelength
