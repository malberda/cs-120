//Tanner Hahn
//assignment 11
//section 2
//4/20/18

#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;




//-------------------------------classes---------------------
class node{

private:
string name;
int ID;
node *next; 

public:
void setFunct( string n, int id, node *ext); 
void print();
string search(int target);
void QFunc(string names, int ids);
};


//-------------------------------main program-----------------

int main(){
node n1;

n1.setFunct("Alice",123,NULL);
n1.QFunc("Bob",234);
n1.QFunc("Charlie",678);
n1.QFunc("Dave",789);

n1.print();
cout<<"Searched name: " <<n1.search(679)<< endl;

}



//------------------------------function definitions------------
void  node:: setFunct(string n, int id, node *ext){
name=n;
ID=id;
next=ext;
}

void node::print(){
cout<< name << endl<< ID<< endl;
if(next!=NULL){
	next->print();
	}

}


string node::search(int target){
if(target==ID){
return name;

}else if(next!=NULL){
return next->search(target);

}else{
return "";
}
}

void node::QFunc(string n, int i){
if( next==NULL){
	next =new node;
	next->setFunct(n,i,NULL);
}else {
next->QFunc(n,i);

}
}
