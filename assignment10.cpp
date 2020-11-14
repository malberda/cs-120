#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
#include "robot.h"
#include "world.h"

int main(){
	world a_world;
	srand(time(NULL));
	a_world.set_up();
	do{
		a_world.update();
		a_world.draw();
	}while(1);
	return 0;	
}
