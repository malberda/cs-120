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

//class

class node{

private:
int x;
int y;
int heading;
double energy;
node *next;

public:
void firstconstructor(int a, int b, int c, double d, node *other);
void constructor(int a, int b, int c, double d);	
void print();
void move();



};




int main(){
srand(time(NULL));
node first;
		
	cout<<"vagina";
	int q=rand()%2000-1000; 
	int w=rand()%2000-1000; 
	int e=rand()%4;
	double r=100;
	first.firstconstructor(q,w,e,r,NULL);
	
	q=rand()%2000-1000; 
	w=rand()%2000-1000; 
	e=rand()%4;
	r=100;
	first.constructor(q,w,e,r);
	q=rand()%2000-1000; 
	w=rand()%2000-1000; 
	e=rand()%4;
	r=100;
	first.constructor(q,w,e,r);	
cout<<"penis";
	first.print();
	

}


void node::firstconstructor(int a, int b, int c, double d,node *other){
x=a;
y=b;
heading=c;
energy=d;
next=other;
}


void node::constructor(int a, int b, int c, double d){
if(next==NULL){
	next=new node;
	next->constructor(a, b, c, d);
	}
	else{
		next->print();
	}
}

void node::print(){
	cout<<x<<endl<<y<<endl<<heading<<endl<<energy<<endl;
	if(next!=NULL)
		next->print();
}

void node::move(){
	energy=energy-.1;
	heading++;
	if(heading==4)
		heading=0;
	if(heading==0)
		y++;
	if(heading==1)
		y--;		
	if(heading==2)
		x++;
	if(heading==3)
		x--;

	
}


