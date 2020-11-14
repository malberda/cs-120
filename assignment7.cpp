/*
Michael Alberda
3/21/2018
cs120 assignment7
Jia Song
*/
#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<cstdio>
using namespace std;
// declaration of the pet class
      string type;
//srand(time(NULL));
int chance;
class pet{
   private:
      int hunger;           // private data member
      string name1;          // private data member
      string name2;
      string name3;
      int happy;            // private data member
      int sleepnum;
      int choice;
   public:
      pet();                // constructor
      void play();          // public member function
      void feed();          // public member function
      void sleep();
      void print();         // public member function
      int check_health();   // public member function
};
int main()
{
srand(time(NULL));

   pet pet1;
   int choice;
   int health_check;
cout<<"what kind of pet would you like, a dragon(1), a dog(2), or a bird(3)?"<<endl;
        cin>>choice;
        if(choice==1)
        type="dragon";
        else if(choice==2)
        type="dog";
        else if(choice==3)
        type="bird";
   do{
       pet1.print();
	
       cout << "What would you like to do with your pet?\n";
       cout << " Play (1) \n Feed (2) \n Take a nap(3) \n Exit (0) \n";
       cin >> choice;
       switch(choice){
       case 1:
           pet1.play();
           break;
       case 2:
           pet1.feed();
           break;
	case 3:
		pet1.sleep();
		break;
      }
      health_check = pet1.check_health();


   }while(choice != 0 && health_check != 1);
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
     cout << "Pet's name? (three single words) ";
     cin >> name1>>name2>>name3;
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

	chance=(rand()%100);
        if((chance<100)&&(chance>=85))
                {cout<<"your pet fell asleep"<<endl;
                sleepnum-=15;
        }else if((chance<85)&&(chance>=75))
                {cout<<"your pet found some food"<<endl;
                hunger-=5;
        }else if((chance<75)&&(chance>=65))
                {cout<<"your pet found another"<<type<<"to play with"<<endl;
                happy+=10;
        }else if((chance<65)&&(chance>=55))
                {cout<<"your pet has miraculously become happier"<<endl;
                happy+=20;}

         break;
    case(2):
         happy += 5;
         hunger += 1;
         break;
    default:
         cout << "Not a valid choice." << endl;
   }
}
void pet::sleep(){
    cout<<"your pet "<<type<<" "<<name1<<" "<<name2<<" "<<name3<<endl;
    sleepnum-=10;
    hunger+=2;
    happy+=5;
}

/* Member function feed(), allows the user to feed a pet. */
void pet::feed(){
    
	//adding more output text
	
	cout<<"what do you want to feed your "<<type<<" "<<name1<<" "<<name2<<" "<<name3;
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
    cout << "\nYour "<<type<<" " << name1<<" "<<name2<<" "<<name3 << " is ";
    cout << "Happy: " << happy << endl;
    cout << "Hungry: " << hunger << endl;
    cout << "sleepyness: " << sleepnum <<endl;
}

/* Member function check_health(), checks the health of a pet. */
int pet::check_health(){
    if(hunger >= 100){
         cout << "\nYour pet has starved.\n";
         return 1;
    }
    if(happy <= 0){
         cout << "\nYour pet has died of a broken heart.\n";
         return 1;
    }
    return 0;
}
