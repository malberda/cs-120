/*
Michael Alberda
CS 120-02
3/6/2018
assignment 6b
*/

#include<iostream>     // include two libraries
#include<cstdlib>
#include<ctime>
using namespace std;

//variables
int room_value=1;
int health;
int action=1;
int choice;
int monhealth;
int lootchance;
int gold;
int armor;
int bow=0;
int sword=0;
int knife=0;
int hammer=0;
double damage;
int basedmg;
int speed;
int room_max;
struct character;

//structures
struct character{
int basehealth;
int basespeed;
int basedmg;
int basearmor;
};
struct updatedcharacter{
int health;
int speed;
int basedmg;
int armor;
};

character initcharacter();
void print (character);

updatedcharacter initupdatedcharacter();
void print (updatedcharacter);

int main()             // main() starts the actual program 
{
		
//define function for fight easy
double fighteasy(int monhealth, int mondamage, int mondefense);
double room(int gold, int armor, int health);
double choices(int action, int choice, int room_value);

//choose class and race
cout<<"you will now choose your race from the list"<<endl;
cout<<"(1)dwarf, (2)human, (3) elf,(4) orc, (5)dragonborn"<<endl;
cout<<"then you will pick your class"<<endl;
cout<<"(1)bard, (2)rougue, (3)knight, (4)thief, (5)barbarian"<<endl;
cin>>choice;
cin>>action;


character player=initcharacter();
print(player);
cout<<endl;



//room stuff
	cout<<"how many rooms would you like to traverse through (10) is recommended"<<endl;
	cin>>room_max;
	
	
//seed random
	srand(time(NULL));

//introduction
	cout<<"for each room you enter you will get to investigate or try to run through, with a low success rate"<< endl;
	cout<<"when you investigate, you will find items to heal or gain armor, and may find monsters or gold."<<endl;
	cout<<"you have a limited amount of health, and if you die you will have to restart"<<endl;
	cout<<"when you investigate you can take items to help later"<<endl;

//first room
do{
	cout<<"you enter your first room of the dungeon, what do you do?"<<endl;
		choices(action,choice,room_value);
		room_value=2;
		cout<<"you enter the next room"<<endl;

}while (room_value==1);
	
	

do{

updatedcharacter player1=initupdatedcharacter();

print(player1);
cout<<endl;


//first major room
if (room_value<room_max){
	
	do{
		choices(action, choice, room_value);
		room_value=room_value+1;
		cout<<"the room is "<<room_value<<" and the max is "<<room_max<<endl;
        print(player1);
        cout<<endl;


	}while(room_value!=room_max);}
	

	
//boss room
else if (room_value==room_max){
	cout<<"you see a giant dragon who speaks to you"<<endl;
	cout<<"he says: why are you tresspassing?"<<endl;
	cout<<"because i want money(1)"<<endl<<"because i want to kill you"<<endl<<"idk bro"<<endl<<"why not"<<endl;
	cin>>choice;
		fighteasy(300, 50, 50);}	

        print(player1);
        cout<<endl;
	cout<<"conglaturation !!!"<<endl<<"you have completed a great game."<<endl<<"and prooved the justice of our culture"<<endl<<"now go and rest our heroes"<<endl;
	room_value=room_value+1;
	
//end int main()

}while(room_value<=room_max);
}

//define fight fuctions
double fighteasy(int monhealth, int mondamage, int mondefense){
	srand(time(NULL)); 
	int choice;
	int attack=0;
	
	if(room_value==1){
		cout<<"when you fight, the best weapon will be chosen. you will choose 1 or 2 to attack or defend."<<endl;
		cout<<"if you attack you have an 85 percent chance of being hit and will do a random amount of damage."<<endl;
		cout<<"if you defend the monster will have a 50 percent chance of hitting itself instead of you."<<endl;}

do
{


cout<<"press 1 for fist attack, or 2 for defend";
if(bow==1)
cout<<", or 3 for bow attack";
if(hammer==1)
cout<<", or 4 for hammer attack";
if(sword==1)
cout<<", or 5 for sword attack";
if(knife==1)
cout<<", or 6 for knife attack";

cout<<", or 7 to attempt to escape";

cout<<endl;

cin>>choice;
        
	attack=rand()%100;
	if(attack<(100-mondefense))
	{
	
		if (choice==1){
		damage=rand()%(basedmg+5)+5;
		monhealth=monhealth-damage;}
	
		else if (choice==2){
		damage=0;
	        monhealth=monhealth-damage;}
		
		else if ((choice==3)&&(bow==1)){
		damage=rand()%(25+basedmg)+5;
	        monhealth=monhealth-damage;}
		
                else if ((choice==4)&&(hammer==1)){
		damage=rand()%(35+basedmg)+5;
	        monhealth=monhealth-damage;}
	
                else if ((choice==5)&&(sword==1)){
		damage=rand()%(25+basedmg)+5;
	        monhealth=monhealth-damage;}
		
                else if ((choice==6)&&(knife==1)){
		damage=rand()%(20+basedmg)+5;
	        monhealth=monhealth-damage;}
	
		else if (choice==7){
		attack=rand()%100;
			if(damage<(15+speed))
			return 0;
		}
	
	}

//monster attack phase

	if(choice==2)
	{attack=25;}
	else{
	attack=rand()%100;	
	if(speed<=attack)
	health=(health-(rand()%mondamage+5)+armor);
	else
	monhealth=monhealth-(mondamage+mondamage);}
	

//check for death
	if(health<=0){
			cout<<"game over scrub"<<endl;
			break;}
		cout<<"you have "<<health<<" health left"<< " and the monster has "<<monhealth<<" health left"<<endl;

//end fight loop if monster is dead
}while(monhealth>0);

//end fighteasy
}

//define choices fuction

int room(int gold, int armor, int item){

			lootchance=(rand()%100);
	//gold
		gold=gold+lootchance;
		cout<<"you got "<<lootchance<<" pieces of gold"<<endl;


			lootchance=(rand()%100);
	//weapon

		
		if((bow!=1)&&(lootchance<=100)&&(lootchance>80))
		{cout<<"you found a bow"<<endl;
		bow=1;}
		
		if((knife!=1)&&(lootchance<=80)&&(lootchance>60))
                {cout<<"you found a knife"<<endl;
                knife=1;}
		
		if((hammer!=1)&&(lootchance<=60)&&(lootchance>40))
                {cout<<"you found a hammer"<<endl;
                hammer=1;}
		
		if((sword!=1)&&(lootchance<=40)&&(lootchance>20))
                {cout<<"you found a sword"<<endl;
                sword=1;}
		
		if(lootchance<=20)
                {cout<<"you found no weapon"<<endl;}
	
		
	                        lootchance=(rand()%100);	
	//armor

		if((lootchance<100)&&(lootchance>66))
                cout<<"you found no armor"<<endl;
		
                if((lootchance<=66)&&(lootchance>33))
                {cout<<"you found a piece of leather armor"<<endl;
		armor=armor+1;}
		
                if((lootchance<=33)&&(lootchance>3))
                {cout<<"you found a piece of chain mail armor"<<endl;
		armor=armor+2;}
				
		if(lootchance<=3)
		{cout<<"you found a piece of mythril armor"<<endl;
		armor=(armor+5);}
		

                        lootchance=(rand()%100);
	//item
		
		if((lootchance<100)&&(lootchance>66))
                cout<<"you found no items"<<endl;

                if((lootchance<=66)&&(lootchance>33))
                {cout<<"you found a well of healing and drank from it"<<endl;
                health=health+50;
		cout<<"you feel better"<<endl;}

                if((lootchance<=33)&&(lootchance>3))
                {cout<<"you found a pair of magical boots"<<endl;
                speed=speed+5;}

                if(lootchance<=3)
                {cout<<"you found a set of magical brass knuckles"<<endl;
                basedmg=50;}

		
                        lootchance=(rand()%100);
	//monster chances

		if((lootchance<=100)&&(lootchance>85))
                {cout<<"a dragon appears before you"<<endl;
		fighteasy(100, 25, 2);}
		
		if((lootchance<=85)&&(lootchance>70))
                {cout<<"a demon appears before you"<<endl;
		fighteasy(80,15, 15);}
		
		if((lootchance<=70)&&(lootchance>55))
                {cout<<"a minotaur appears before you"<<endl;
		fighteasy(50,15, 10);}
		
		if((lootchance<=55)&&(lootchance>40))
		{cout<<"a slime is in the room with you"<<endl;
		fighteasy(25,10, 5);}
                
		if((lootchance<=40)&&(lootchance>25))
		{cout<<"an explosive monster appears before you"<<endl;
		fighteasy(10,100,0);}
		
		else
		cout<<"there was no enemy in this room"<<endl;
		
//end room function		
}		
		
int choices(int action, int choice, int room_value){
	srand(time(NULL));

if(room_value=1)
cout<<"press 1 to investigate or 2 to attempt to run through the room"<<endl;
cin>>action;
	if(action==2){
	damage=rand()%100;
		if(damage<(95-speed))
		room(gold,armor,health);
	}
	else
	room(gold,armor,health);

room_value=room_value+1;	
//end choices function
}
	
//player data sheet and print info
	
character initcharacter(){
character player;
	if(choice==1){
		player.basehealth=500;
		player.basespeed=0;
		player.basedmg=5;
		player.basearmor=5;}
        else if(choice==2){
        	player.basehealth=350;
        	player.basespeed=5;
        	player.basedmg=10;
        	player.basearmor=0;}
        else if(choice==3){
        	player.basehealth=450;
        	player.basespeed=10;
	       	player.basedmg=10;
        	player.basearmor=0;}
        else if(choice==4){
        	player.basehealth=700;
        	player.basespeed=0;
        	player.basedmg=25;
        	player.basearmor=0;}
        else if(choice==5){
        	player.basehealth=650;
        	player.basespeed=0;
        	player.basedmg=25;
        	player.basearmor=20;}
        if(action==1){
        	player.basehealth=player.basehealth+0;
        	player.basespeed=player.basespeed+0;
        	player.basedmg=player.basedmg+0;
        	player.basearmor=player.basearmor+0;}
        else if(action==2){
                player.basehealth=player.basehealth+0;
                player.basespeed=player.basespeed+15;
                player.basedmg=player.basedmg+5;
                player.basearmor=player.basearmor+0;}
        else if(action==3){
                player.basehealth=player.basehealth+50;
                player.basespeed=player.basespeed+0;
                player.basedmg=player.basedmg+10;
                player.basearmor=player.basearmor+10;}
        else if(action==4){
                player.basehealth=player.basehealth+0;
                player.basespeed=player.basespeed+20;
                player.basedmg=player.basedmg+0;
                player.basearmor=player.basearmor+0;}
        else if(action==5){
                player.basehealth=player.basehealth+100;
                player.basespeed=player.basespeed+0;
                player.basedmg=player.basedmg+15;
                player.basearmor=player.basearmor+0;}


health=player.basehealth;
speed=player.basespeed;
armor=player.basearmor;
basedmg=player.basedmg;

return player;

}

//updated character

updatedcharacter initupdatedcharacter(){
updatedcharacter player1;

player1.health=health;
player1.speed=speed;
player1.armor=armor;
player1.basedmg=basedmg;
return player1;
}

//define print
void print(character x){
cout<<"you have "<<x.basehealth<<" health points"<<endl;
cout<<"you have a speed of "<<x.basespeed<<endl;
cout<<"your base damage is "<<x.basedmg<<endl;
cout<<"your armor rating is "<<x.basearmor<<endl;
}


//define other print
void print(updatedcharacter player1){
cout<<"you have "<<player1.health<<" health points"<<endl;
cout<<"you have a speed of "<<player1.speed<<endl;
cout<<"your base damage is "<<player1.basedmg<<endl;
cout<<"your armor rating is "<<player1.armor<<endl;
}



