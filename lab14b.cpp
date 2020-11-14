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

class node{

private:
int identify;
node *next;

public:
void func(int id, node *ext);
void print();
};

//------------main function-------
int main(){
node n1;
node n2;
node n3;

n1.func(1,&n2);
n2.func(2,&n3);
n3.func(3,NULL);

n1.print();
}


//------function definitions--------
void node::func(int id, node *ext){
identify=id;
next=ext;

}

void node::print(){
//By simply moving the cout statement I was able to print in reverse simple modification that did not require a new function
//cout<<ID << endl;
if(next!=NULL){
      next->print();
      }
cout<< identify<<endl;
}

