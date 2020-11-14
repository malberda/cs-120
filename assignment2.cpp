#include <iostream>

using namespace std;
//Michael Alberda Section 2 assignment 2
int main()
{
//create variables
	double alicerate;
	double alicemoney;
	double alicetotal;
	double bobrate;
	double bobmoney;
	double bobtotal;
	double year;

//input variables
	cout<<"input alice's money and then bob's money" << endl;
	cin>>alicemoney;
	cin>>bobmoney;

//test if inputs worked
	//cout << alicemoney << endl;
	//cout << bobmoney << endl;

//multiplication/interest
bobrate = 0.03;
if (alicemoney >= 1 && alicemoney <=99)
{
	alicerate = 0.07;
}

else if (alicemoney >= 100 && alicemoney <= 299)
{
	alicerate = .08;
}

else if(alicemoney >= 300 && alicemoney <=499)
{
	alicerate = 0.09;
}

else if(alicemoney >= 500 && alicemoney <= 1000)
{
	alicerate = 0.1; 
}

else if(alicemoney > 1000)
{
	alicerate = .11;
}

cout << alicerate << endl;
cout << bobrate << endl;
//actual math stuff;
bobtotal = bobmoney;
alicetotal = alicemoney;
year = 0;


while (bobtotal <= alicetotal)
{
	bobtotal = (bobtotal + (bobrate*bobtotal));
	alicetotal = (alicetotal + (alicerate*alicemoney));
	year++;
	
	
}
cout <<"the year is "<< year <<endl;
cout <<"bob has "<< bobtotal << endl; 
cout <<"alice has " << alicetotal << endl;
}
