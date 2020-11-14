/*
Michael Alberda
CS 120-02
2/7/2018
assignment 3
*/

#include<iostream>     // include two libraries
#include<cstdlib>
#include<ctime>
using namespace std;
//variables
int room_value=1;
int health=200;
int ham=0;
int knife=0;
int sledgehammer=0;
int action=1;
int demonlife=1;
int slimelife=1;
int egg=0;
int scissorlife=1;
int choice;

int main()             // main() starts the actual program 
{
		
//define function for fight easy
double fighteasy(int monhealth, int mondamage, int knife, int sledgehammer, int health);
double choices(int action, int choice, int room_value);
//seed random
srand(time(NULL));
int slices=rand()%100;

//introduction
	cout<<"for each room you enter you will get to investigate, move on, or attack, if there is an opponent"<< endl;
	cout<<"you have a limited amount of health, and if you die you will have to restart"<<endl;
	cout<<"when you investigate you can take items to help later"<<endl;

//knife and ham room
if (room_value==1)
	{
	do{
		room_value=choices(action,choice,room_value);
}while(room_value==1);
cout<<"you see two doors: a red door (2) and a blue door(3), which do you open"<<endl;
cin>>choice;
room_value=choice;
cout<<room_value<<endl;
}
cout<<room_value<<endl;
//first monster room
if (room_value==2)
	{
	cout<<"as you enter the room a demonic figure charges at you"<<endl;
	room_value=choices(action,choice,room_value);
	do{
		//after fight
			cout<<"you have slayed the beast"<<endl;
			cout<<"it turns to dust and the blue door behind it opens"<<endl<<"you go throught the door"<<endl; 
			room_value=3;
	}while(room_value==2);
}
//sledgehammer room
if (room_value==3)
{
			cout<<"you enter a room with one wall covered in a layer of a crystal substance, and a chest off to the side, in front of which is a slime"<<endl;
			cout<<"press 1 to investigate, 2 to attack, or 3 to move on."<<endl;
			cin>>action;


room_value=choices(action,choice,room_value);
room_value=4;
}
//dragon room
if (room_value==4)
{
			cout<<"as you enter the room, you see a giant dragon sitting atop something shiny and he speaks:"<<endl;
			cout<<"what is it that you wish to do to the scissorman? he has given me many shiny gifts to kill you"<<endl;

room_value=choices(action,choice,room_value);
room_value=5;
}
//health room
if (room_value==5)
{
	cout<<"the room is full of magical energy that revitalizes you fully"<<endl;
	health=health+100;
	cout<<"you gain 100 health"<<endl;
	cout<<"the final door looms before you, its ghastly presense draws you in"<<endl;;
	cout<<"as you touch the door, it opens, revealing a hunched man, around 4'11''"<<endl;
	cout<<"he withdraws a giant pair of hot pink scissors to kill you"<<endl;
	cout<<"and your final fight begins"<<endl;
	room_value=6;
}
//final boss
if (room_value==6)
room_value==choices(action,choice,room_value);
}

//define fight fuctions
double fighteasy(int monhealth, int mondamage, int knife, int sledgehammer, int health){
	srand(time(NULL)); 
	int choice;
	int defense=0;
	int attack=0;
		cout<<"when you fight, the best weapon will be chosen. you will choose 1 or 2 to attack or defend."<<endl;
		cout<<"if you attack you have an 85 percent chance of being hit and will do a random amount of damage."<<endl;
		cout<<"if you defend the monster will have a 50 percent chance of hitting itself instead of you."<<endl;

do
{


cout<<"press 1 for attack and 2 for defend"<<endl;
cin>>choice;
        if (choice==1)
        {
                if(sledgehammer==1)
                	monhealth=monhealth-rand()%25;
                else if(knife==1)
                	monhealth=monhealth-rand()%15;
                else
                	monhealth=monhealth-rand()%10;
		
      			attack=rand()%100;
        	if(attack>15)
        		health=(health-mondamage);
        }

        else if (choice==2)
        	attack=rand()%100;
        if (attack>50)
        	health=(health-rand() % mondamage+5);
        else if (attack<=50)
        	monhealth=(monhealth-mondamage);         

	if(health<=0){
			cout<<"game over scrub"<<endl;
			break;}
		cout<<"you have "<<health<<" health left"<< " and the monster has "<<monhealth<<" health left"<<endl;

}while(monhealth>0);
return health;}

//define choices fuction

int choices(int action, int choice, int room_value){
	srand(time(NULL));
	int slices=rand()%100;

if(room_value==1){
 do{                	//investigate

                        cout<<"you see a basic kitchen area, with a knife rack, a fridge, and a stove."<<endl;
                        cout<<"press 1 to investigate, 2 to attack, or 3 to move on."<<endl;
                        cin>>action;
		if(action==1){
		do{
                                cout<<"you see a rusty knife(1), some ham slices(2), and an egg(3)."<<endl;
				cout<<"to pick one up you can press the corresponding number and enter"<<endl;
                                cin>>choice;
                        if(choice==1)
                        {
                                //knife
                                cout<<"you took the knife"<<endl;
                                knife=1;
                        }
                        else if(choice==2)
                        {
                                cout<<"you took " << slices <<" slices of ham" <<endl;
                                ham=1;
                        }
                        else if(choice==3)
                        {
                                cout<<"you tried to take the egg, but it broke in your hand"<<endl;
                                cout<<"would you like to keep the egg goo?"<<endl;
                                cin>>egg;
                                cout<<"okay"<<endl;
                        }
                                cout<<"would you like to continue investigating, 1 for yes 0 for no"<<endl;
                                cin>>action;
                }while(action==1);
        }
	if(action==2)//attack choice
                cout<<"there is nothing to attack"<<endl;

	if(action==3)
		return 0;

}while(action!=3);




}else if(room_value==2){

 do{
		cout<<"what would you like to do, investigate(1), attack(2), or try to escape(3)?"<<endl;
		cin>>action;

                        if (action==1)
                                cout<<"now's not the right time for that"<<endl;
                        else if(action==2)
                                {health=fighteasy(40,5,knife,sledgehammer,health);
                                demonlife=0;}
                        else if(action==3)
                                cout<<"cant do that right now"<<endl;
}while(action!=2);


}if(room_value==3){

do{
                        if (action==1)
                                if(slimelife==1)
                                        {cout<<"you will have to fight through the slime to get to the chest"<<endl;
                                        health=fighteasy(45,10,knife,sledgehammer,health);
                                        cout<<"in the chest is a sledgehammer, which you pick up"<<endl;}
                                if (slimelife==0)
                                        {cout<<"in the chest is a sledgehammer, which you pick up"<<endl;
                                        sledgehammer=1;
                                        slimelife=0;}
                        else if((action==2)&&(slimelife==1))
                                {health=fighteasy(35,10,knife,sledgehammer,health);
                                slimelife=0;}
                        else if(action==3)
                                cout<<"you can't do that right now"<<endl;
        cout<<"there is a wall in front of you covered in crystal, what would you like to do?"<<endl;
                do{
                        sledgehammer=1;
                if(knife==1)
                        cout<<"stab it with a knife (1)"<<endl;
                if(sledgehammer==1)
                        cout<<"hit it with a hammer (2)"<<endl;
                if(ham==1)
                        cout<<"throw some ham at it (3)"<<endl;
                if(sledgehammer==0)
                        {cout<<"you forgot something, try again"<<endl;
			cin.ignore();
                        cout << "\nPress enter to quit. you lost\n";
                        cin.ignore();
                        return 0;}


        cin>>action;
                if (action==1)
                        {cout<<"the knife broke"<<endl;
                        knife=0;}
                if (action==2)
                        cout<<"the hammer broke the crystal"<<endl;
                if (action==3)
                        cout<<"the ham did nothing, why would ham do anything?"<<endl;

                }while(action!=2);

}while((action!=2)&& (sledgehammer!=1));


}if(room_value==4){

 do{
                        cout<<"what do you want to do, investigate (1), attack (2), or bargain (3)"<<endl;
                        cin>>action;
                if (action==1)
                        cout<<"there is a dragon sitting on top of what looks like a solid gold toilet filled with solid gold droppings"<<endl;
                else if(action==2)
                        health=fighteasy(100,15,knife,sledgehammer,health);
                else if(action==3)
                        cout<<"he doesn't seem interested in talking with you"<<endl;
        if(health<=0)
                { cin.ignore();
                  cout << "\nPress enter to quit. you lost\n";
                  cin.ignore();
                  return 0;}

}while(action!=2);

                cout<<"do you want to reach into the gold toilet(1) or not (0)"<< endl;
                cin>>action;
        if (action==1)
                {cout<<"you reach into the toilet and it turns out to just be an illusion of the light that the droppings were gold. you throw up and take damage"<<endl;
                health=health-1;
                cout<<"you take 1 damage"<<endl;
                }
        else
                cout<<"you smartly choose not to touch the droppings"<<endl;
                cout<<"you proceed through the next door"<<endl;
                room_value=5;

return 5;

}if(room_value==5){



}if(room_value==6){


do{
 cout<<"what would you like to do, use an item(1), fight(2), cry(3), drop out of college because you cant compile code(4), or cry(5)?"<<endl;
                cin>>action;

                        if(action==1){
                                cout<<"what item would you like to use, the egg(1), the ham(2), the poop(3), or nothing(4)"<<endl;
                                cin>>choice;
                do{

                                if(choice==1)
                                        cout<<"nothing happens"<<endl;
                                if(choice==2){
                                        cout<<"you throw "<<slices<<" slices of ham at the scissorman"<<endl;
                                        cout<<"ham is a scissorman's weakness, and it kills him instantly"<<endl;
                                        scissorlife=0;}
                                if(choice==3)
                                        cout<<"he is disgusted but nothing happens"<<endl;
                                if(choice==4){
                                        cout<<"he kills you"<<endl;
                                        health=0;}

		}while((choice!=2)&&(choice!=4));

                        if(choice==2){
                                cout<<"good job you won the game. play again sometime? im so lonely."<<endl;
                                return 0;}
                
                if(action==2){
                        health=fighteasy(1000,20,knife,sledgehammer,health);
                }
                if(action==3)
                        {cout<<"you start crying because, juse like everything else in your life, the poop from before fell apart because of your carelessness"<<endl;
                        cout<<"the scissorman kills you because you weren't paying attention."<<endl;
                        health=0;}
                if(action==4)
                        {cout<<"you drop out of college irl and even though dad is dissapointed in you, he accepts that mcdonalds is where you were meant to work"<<endl<<"game over"<<endl;
                        health=0;}                }
                if(action==5){
                        cout<<"you start crying because, juse like everyone else in your life, he will end up leaving you."<<endl;
                        cout<<"the scissorman kills you because you weren't paying attention."<<endl;
                        health=0;}

}while((health>0)&&(scissorlife!=1));
                        if (health<=0)
                                {cin.ignore();
                                cout << "\nPress enter to quit. you lost\n";
                                cin.ignore();
                                return 0;}
                        else
                                cout<<"great job"<<endl;

}



				/*
                                  cin.ignore();
                                  cout << "\nPress enter to quit.\n";
                                  cin.ignore();
                                  return 0;
				*/


}


