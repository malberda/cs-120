#include<iostream>
#include<cstdlib>

using namespace std;


struct player;

struct player{
int healingpot;
int health;
int armor;
};

player initplayer();
void print (player);

int main(){


player player1=initplayer();
print (player1);
cout<<endl;
player player2=initplayer();
print (player2);
cout<<endl;
}
//end intmain


player initplayer(){
player player1;
player1.healingpot=5;
player1.health=100;
player1.armor=2;
return player1;
player player2;
player2.healingpot=2;
player2.health=50;
player2.armor=3;
return player1;
//return player2;
}



void print(player x){
cout<<"amount of potions: "<<x.healingpot<<endl;
cout<<"health is: "<<x.health<<endl;
cout<<"armor is: "<<x.armor<<endl;
}



