/*
Michael Alberda
5/4/2018
cs120 lab14a
Jia Song
*/
#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

//class

class animal{

private:
int x;
int y;
int heading;
double energy;


public:
animal();
void print();
double move();


};


int main(){
	int a=1;
	animal first;
		do{
			first.print();
			first.move();
			cin.ignore();
		}while(a=1);
}


animal::animal(){
	x=rand()%2000-1000;
	y=rand()%2000-1000;
	heading=rand()%4;
	energy=100;
}

void animal::print(){
	cout<<x<<endl<<y<<endl<<heading<<endl<<energy<<endl;
 }


double animal::move(){

energy=energy-.1;

	if(heading==1)
		y--;
	if(heading==2)
		x--;
	if(heading==3)
		x++;
	if(heading==0)	
		y++;
	heading=rand()%4;

}
