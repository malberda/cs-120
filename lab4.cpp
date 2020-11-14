
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
	int again;
	int sum;
	int stopper;
	
		
do
{	
	again=0;
	stopper =0;
	answer =0;
	//give numbers to the values	
	cout << "Enter the first value ";
	cin >> value1;
	cout << "Enter the second value ";
	cin >> value2;
	cout << "Press 1 for addition, 2 for subtraction, 3 for multiplication, 4 for division, or 5 to sum all of the integers between the two values. ";
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
else if (boolean == 5)
{
		cout <<"you chose adding all of the integers between the two values that you entered" <<endl;
	//define sum
	if (value1<value2)
	{
		sum=value1;
	}
	else if (value2<value1)
	{
		sum=value2;
	}
	else
	{
		sum=value1;
	}

	sum++;
	//add the integers
	while (sum<value2)
	{	
		answer=answer+sum;
		sum=sum++;
		//answer=answer+sum;
		
		
		stopper++;
	}
	while ((sum<value1) && (stopper=0))
	{		
		answer=answer+sum
                sum=sum++;
                //answer=answer+sum;
	
	}
	
	cout<<answer<<endl;	
}

else
{
	cout<<"error, enter 1-4"<<endl; 
	again=1;
}

cout << "enter 1 if you would like to perform another calculation, or 0 if you don't want to."<<endl;
cin >> again;

} while (again==1);

}

