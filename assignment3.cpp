/*
Michael Alberda
CS 120-02
2/7/2018
assignment 3
*/

/*  The game of NIM 
 */
#include<iostream>     // include two libraries
#include<cstdlib>
using namespace std;
int main()             // main() starts the actual program 
{


  // declare variables
  int num_objects; 
num_objects= 23; 
  int current_player; 
current_player = 1; 
  int move;
  int min;
  int max;
  int difference;
  int replay=0;
  int score1 =0;
  int score0 =0;
  int num=0; 

cout<<"For this game, you will enter a number between the minimum and max, and that many objects will be removed.";
cout<<"each time you remove an object, the computer will remove between the min and the max as well at random.";
cout<<"the player who removes the last object is the loser"; 
cout<<"input the maximum value" <<endl;
min=1;
cin>>max;
   // actual game
do{	
  do {      
	
	if(replay==1)
	{
	replay=0;
	num_objects=23;
	}

        if(num_objects>17)
                cout<<"let's get this started!"<<endl;

        if((num_objects>13)&&(num_objects<=17))
                cout<<"Here we go!"<<endl;

        if((num_objects>5)&&(num_objects<=13))
                cout<< "almost there!"<<endl;

        if(num_objects<=5)
                cout<< "last few moves!!! Be careful!"<<endl;

	                                
    if (current_player == 1) {    // conditional: if
      cout << "Player 1 enter your move ("<<min<<"-"<<max<<"): ";  // output
      cin >> move;                 // input
      while (move < min || move > max || move > num_objects){
	cout << "Illegal move. \nEnter a new move ("<<min<<"-"<<max<<"): ";
	cin >> move;
      }
   
 }

      else {                          // else part of conditional
      do {
                         // make sure move is legal
	if(num_objects>max)	
	{
	move =  min+ rand() % max;    // random computer move


	}
	else if((num_objects<=max)&&(num_objects>1))
	{
		move=0;
		difference=(num_objects-move);
		for(move=0;difference!=1;move++){
		difference=(num_objects-(move));
	
	}
		move=move--;
	}
	else if (num_objects==1)
	{
	move=1;
		
	}

	//cout<<"move "<<move;
      } while (move < min || move > max || move > num_objects);
      cout << "Computer removed " << move << endl;
    }
	

    num_objects = num_objects - move;  // implement the move
    current_player = (current_player + 1) % 2;  // switch players
			

        for (num=0;(num<num_objects);num++)
        {
        cout<<"#";
        }
cout<<" objects remaining" <<endl;
		
  } while (num_objects > 0);                    
		
		 if(current_player==1)
	        score1++;

	        else if(current_player==0)
        	score0++;

		cout << "Player " << current_player << " defeated the enemy!!!\n";


	        cout<<"would you like to play again? press  1 for yes and 0 for no. ";
	        cin>>replay;
        	cout<<"your score is "<<score1<<" and the computer has "<< score0 << endl;
}while (replay==1);		
		
 
  cin.ignore();
  cout << "\nPress enter to quit.\n";
  cin.ignore();
  return 0;
}
