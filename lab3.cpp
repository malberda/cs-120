
#include <iostream>

using namespace std;

int main()
{
	cout << "This program will allow you to enter two values, value 1 and value 2. After this the program will ask for a number from 1 to 4, in the order of addition, subtraction, multiplication, and division. the program will then apply this to the two value" << endl;
	//define values and integers
	double value1;
	double value2;
	double boolean;
	double answer;
	
	//give numbers to the values	
	cout << "Enter the first value ";
	cin >> value1;
	cout << "Enter the second value ";
	cin >> value2;
	cout << "Press 1 for addition, 2 for subtraction, 3 for multiplication, or 4 for division. ";
	cin >> boolean;


//calculate answer

if (boolean == 1)
{
	cout<< "You chose addition" <<endl;
	answer = (value1+value2);
	cout << answer <<endl;
}
else if (boolean == 2)
{
	cout<< "You chose subtraction" <<endl;
	answer = (value1 - value2);
	cout << answer <<endl;  
} 

else if (boolean == 3)
{
	cout<< "You chose multiplication" <<endl;
	answer = (value1 * value2);
	cout << answer <<endl;
}
else if (boolean ==4)
{
	cout<< "You chose division" <<endl;
	answer = (value1/value2);
	cout << answer <<endl;
}
else
{
	cout<< "You chose squaring both numbers and adding them" <<endl;
	answer = ((value1*value1) + (value2*value2));
	cout << answer <<endl;
}
}

