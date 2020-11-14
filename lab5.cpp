/*
Michael Alberda
cs120-02
Lab 5
2/13/2018
*/
/* A simple calculator program,
controlled by a menu and 
divided into separate functions */

#include<iostream>
#include<cmath>
using namespace std;

//---------- Function Prototypes -----------
void print_menu();
double get_value();
double divide(double,double);
int type;
double get_value2();
int math_type;
double surfcyl(double,double);
double surfcon(double,double);
double volcyl(double,double);
double radius;
double height;
//--------------  Main -------------------
int main()
{
  double operand1, operand2, answer;
  int choice, valid_choice;
  do{
    print_menu();
    cin >> choice;
    valid_choice = 1;           // assume choice is valid
    switch(choice){
    case 0:                    // program will exit
      valid_choice = 0;
      break;
    case 1:                    // addition
//addition
      operand1 = get_value();
      operand2 = get_value();
      answer = operand1 + operand2;
      type = 1;
      break;
    case 2:                    // division
//division
      operand1 = get_value();
      operand2 = get_value();
      answer = divide(operand1,operand2);
      type = 2;
      break;
   case 3:
//subtraction
	operand1=get_value();
	operand2=get_value();
	answer=(operand1-operand2);
	type=3;
   break;	
   case 4:
//surface area of a cylinder
	operand1=get_value2();
	operand2=get_value2();
	answer=(surfcyl(operand1,operand2));
	type=4;
	
   break;
   case 5:
//volume of a cylinder
        operand1=get_value2();
        operand2=get_value2();
        answer=(volcyl(operand1,operand2));
        type=5;
   break;
   case 6:
//surface area of a cone
        operand1=get_value2();
        operand2=get_value2();
        answer=(surfcon(operand1,operand2));
        type=6;
   break;
   default:
      valid_choice = 0;   // choice is invalid
      cout << "Invalid Choice." << endl;

    }
//results
	if(valid_choice==1)
	{
       		if(type==1){
        	cout << endl << operand1<< " + "<<operand2 << " = " << answer << endl;
		}
		else if(type==2){
		cout << endl << operand1<< " / "<<operand2 << " = " << answer << endl;
		}
		else if (type==3){
		cout<< endl<< operand1<< " - "<<operand2<< " = "<<answer<<endl;
		}
		else if ((type==4)||(type==6)){
		cout<<"The surface area is "<< answer<< endl;
		}
		else if(type==5){
		cout<<"The volume is "<< answer<< endl;
		}
	}
	
    
  }while(choice != 0);    // if not 0, loop back to start
  return 0;
}

//--------------  Functions -------------------
double divide(double dividend, double divisor){
  if(divisor == 0){
    return 0;  // avoids divide by zero errors
}

  else
    return (dividend/divisor);
}
//function for surface area of cylinder
double surfcyl(double radius,double height){
return((2*3.14*radius*height)+(2*3.14*radius*height));
}
//function for volume of a cylinder
double volcyl(double radius, double height)
{
return(3.14*radius*radius*height);
}
//funcion for surface of a cone
double surfcon(double radius, double height)
{
return(3.14*radius*(radius+(sqrt(height*height+radius*radius))));
}

//----------------- get_value function ----------------
double get_value(){
  double temp_value;
  cout << "Please, enter a value: ";
  cin >> temp_value;
  cout << "Thanks." << endl;
  return temp_value;
}

double get_value2(){
  double temp_value2;
  cout<<"please enter a value for radius, and then height: ";
  cin>>temp_value2;
  cout<<"Thanks." <<endl;
  
    
}

//-------------------- print_menu function -------------
void print_menu(){
  cout << endl;
  cout << "Add (1)" << endl;
  cout << "Divide (2)" << endl;
  cout << "Subrtract (3)" << endl;
  cout << "Surface area of a circular cylinder (4)"<< endl;
  cout << "Volume of a circular cylinder (5)"<< endl;
  cout << "Surface area of a circular cone (6)"<< endl;
  cout << "Enter your choice: ";
}
//end int full
int second(){
cout<<"hello";
}

