/*
Michael Alberda 
4/3/2018
cs120 assignment8
Jia Song
*/
#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<cstdio>
using namespace std;
// declaration of the pet class
//srand(time(NULL));
int chance;
int choice;
string petinfo[4][2];
int petnum;
int health[4];
class pet{
   private:
      int hunger;           // private data member
      int happy;            // private data member
      int sleepnum;
      int choice;
   public:
      pet();                // constructor
      void play();          // public member function
      void feed();          // public member function
      void sleep();
      void print();         // public member function
      void chance();
      int check_health();   // public member function
};
int main()
{
srand(time(NULL));

cout<<"what kind of pets do you have, a dragon(1), a dog(2), or a bird(3)?"<<endl;
cout<<"enter four pet types, one for each of your 4 pets."<<endl;
for(int i=0;i<4;i++){
  cin>>choice;
        if(choice==1)
        petinfo[i][0]="dragon";
        else if(choice==2)
        petinfo[i][0]="dog";
        else if(choice==3)
        petinfo[i][0]="bird";
}//end for loop

cout<<"what would you like their names to be? enter the 4 names."<<endl;

for(int i=0;i<4;i++){
  cin>>petinfo[i][1];}



   pet pet1;
   pet pet2;
   pet pet3;
   pet pet4;
   int choice;
   int health_check;
   do{
        petnum=0;
	pet1.print();
	petnum=1;
	pet2.print();
	petnum=2;
        pet3.print();
	petnum=3;
        pet4.print();

	
       cout <<"which pet would you like to play with: ";
	petnum=0;
        health[0]=pet1.check_health();
	petnum=1;
        health[1]=pet2.check_health();
	petnum=2;
        health[2]=pet3.check_health();
	petnum=3;
        health[3]=pet4.check_health();
	

	for(int i=0;i<4;i++){
	if(health[i]==1)
	cout<<petinfo[i][1]<<" ("<<i<<") ";
	
	}//end for loop
       cin>>(petnum);
	cout<<"what would you like to do with your pet?"<<endl;
	cout << " Play (1) \n Feed (2) \n Take a nap(3) \n Exit (0) \n";
       cin >> choice;
       switch(choice){
       case 1:
		switch(petnum){
		case 0:
		pet1.play();
		break;
		case 1:
		pet2.play();
		break;
		case 2:
		pet3.play();
		break;
		case 3:
		pet4.play();
		break;}
	break;

       case 2:
                switch(petnum){
                case 0:
                pet1.feed();
                break;
                case 1:
                pet2.feed();
                break;
                case 2:
                pet3.feed();
                break;
                case 3:
                pet4.feed();
                break;}

           break;
	case 3:

                switch(petnum){
                case 0:
                pet1.sleep();
                break;
                case 1:
                pet2.sleep();
                break;
                case 2:
                pet3.sleep();
                break;
                case 3:
                pet4.sleep();
                break;}


	   break;
	
      }

	chance=rand()%10;
	if((chance<10)&&(chance>=8)){
	petnum=0;
	pet1.chance();
        }if((chance<8)&&(chance>=6)){
	petnum=1;
        pet2.chance();        
        }if((chance<6)&&(chance>=4)){
	petnum=2;
        pet3.chance();
        }if((chance<4)&&(chance>=2)){
        petnum=3;
	pet4.chance();}

        health[0]=pet1.check_health();
        health[1]=pet2.check_health();
        health[2]=pet3.check_health();
        health[3]=pet4.check_health();

	
   }while(health[0]==1||health[1]==1||health[2]==1||health[3]==1);
   cin.ignore();
   cout << "Press enter to exit." << endl;
   cin.ignore();
   return 0;
}

/* Constructor, creates a new pet with starting values. */
pet::pet(){
     hunger = 50;
     happy = 50;
     sleepnum = 50;
}
/* Member function play(), allows playing with a pet. */
void pet::play(){
    int choice = 0;
    cout << "What should we play?\n";
    cout << " Fetch (1) \n Roll over (2) \n";
    cin >> choice;
    switch(choice){
    case(1):
         happy += 10;
         hunger += 5;
         break;
    case(2):
         happy += 5;
         hunger += 1;
         break;
    default:
         cout << "Not a valid choice." << endl;
   }
}

void pet::chance(){
cout<<"your pet "<<petinfo[petnum][0]<<" "<<petinfo[petnum][1]<<"has found another ";
cout<<petinfo[petnum][0]<<" to play with and some food to eat"<<endl;
happy+=10;
hunger-=10;


}

void pet::sleep(){
    cout<<"your pet "<<petinfo[petnum][0]<<" "<<petinfo[petnum][1]<<endl;
    sleepnum-=10;
    hunger+=2;
    happy+=5;
}

/* Member function feed(), allows the user to feed a pet. */
void pet::feed(){
    
	//adding more output text
	
	cout<<"what do you want to feed your "<<petinfo[petnum][0]<<" "<<petinfo[petnum][1];
	cout<<" candy(1), pizza(2), or salad(3)?";
	cin>>choice;
	
	if(choice==1)
	happy+=5;
	if(choice==2)
        {happy+=3;
	hunger-=3;}
	if(choice==3)
        hunger-=5;

    if((hunger<=50)&&(hunger>35))
    cout<< "Thanks!"<<endl;
    if((hunger<=35)&&(hunger>15))
    cout<< "MMM Delicious!"<<endl;
    if((hunger<=15)&&(hunger>0))
    cout<< "Im almost full!"<<endl;
}    


/* Member function print(), prints information about a pet. */
void pet::print(){

    cout << "\nYour "<<petinfo[petnum][0]<<" "<<petinfo[petnum][1]<<" has: "<<endl;;
    cout << "Happy: " << happy << endl;
    cout << "Hungry: " << hunger << endl;
    cout << "sleepyness: " << sleepnum <<endl;
}

/* Member function check_health(), checks the health of a pet. */
int pet::check_health(){
   
    if(hunger >= 100){
         cout << "\nYour pet "<<petinfo[petnum][1]<<" has starved.\n";
         return 0;
    }
    if(happy <= 0){
         cout << "\nYour pet "<<petinfo[petnum][1]<<" has died of a broken heart.\n";
         return 0;
    }
	return 1;    
}
