/*
Michael Alberda
5/2/2018
assignment11
cs120-02
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
string name;
int ID;
node *next;

public:
void func(string data, int id, node *other);
void print();
string find(int target);
void function(string name, int identification);
};


//main

int main(){
node first;

first.func("alice",12, NULL);
first.function("Bob",34);
first.function("Charlie",56);
first.function("Dave",78);

first.print();
cout<<"searched name: "<<first.find(56)<<endl;

}


//function definitions
void node::func(string data, int id, node *other){
name=data;
ID=id;
next=other;
}

void node::print(){
cout<<name<< endl<< ID<<endl;
if(next!=NULL)
next->print();
}

string node::find(int target){
if(target==ID)
return name;

else if(next!=NULL)
return next->find(target);

else
return "";
}

void node::function(string name, int identification){
if(next==NULL){
	next=new node;
	next->func(name,identification,NULL);
}else
next->function(name,identification);

}







