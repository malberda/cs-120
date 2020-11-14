/*
Michael Alberda
CS 120-02
2/27/2018
lab 7
*/

#include <iostream> 
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>

using namespace std;

//variables
double array1 [31] = {};
double array2 [31] = {};
double array3 [31] = {};
double hightemp(double highesttemp,double high[31]);
double lowtemp(double lowesttemp, double low[31]);
double avehigh(double avehighest, double high[31]);
double avelow(double avelowest, double low[31]);


int main(){

ifstream infile;
infile.open("weather.txt");
int day[31];
double high[31];
double low[31];
double x;
	for(int i=0;i<31;i++)
	{
		infile>>day[i];	
		infile>>high[i];
		infile>>low[i];
	}
	for(int i=0;i<31;i++)
	{
		cout<<day[i]<<" "<< high[i]<<" "<<low[i]<<endl;
	}

hightemp(x,high);
lowtemp(x,low);
avehigh(x,high);
avelow(x,low);
infile.close();

//end int main
}

double hightemp(double highesttemp,double high[31]){

	for(int i=0;i<31;i++)
	{	
		if(high[i]>highesttemp)
			highesttemp=high[i];	
	}
	cout<<"the highest temperature was: "<<highesttemp<<endl;
	
}double lowtemp(double lowesttemp, double low[31]){

	for(int i=0;i<31;i++)
        {
                if(low[i]<lowesttemp)
                        lowesttemp=low[i];
        }
        cout<<"the lowest temperature was: "<<lowesttemp<<endl;


}double avehigh(double avehighest, double high[31]){

	for(int i=0;i<31;i++)
	{
	avehighest=(avehighest+high[i]);
	}
	avehighest=(avehighest/31);
	cout<<"the average of the high temperatures was: "<<avehighest<<endl;
	
	
	
}double avelow(double avelowest, double low[31]){

        for(int i=0;i<31;i++)
        {
        avelowest=(avelowest+low[i]);
        }
        avelowest=(avelowest/31);
        cout<<"the average of the low temperatures was: "<<avelowest<<endl;


}


