#include<iostream>
using namespace std;

int func(int, int &);
void func2(int, int []);

int main(){
   int x = 99, y = 55;
   int a[5] = {1,2,3,4,5};
   int *p;
   p = a;
   p++;
   *p = 8;
   p = &a[3];
   *p = 12;   
   p--;
   *p = 11;
   a[0] = func(x,y);
   func2(x,a);
   cout << "x = " << x << endl;
   cout << "y = " << y << endl;
   for(int i = 0; i < 5; i++){
      cout << "a[" << i << "] = " << a[i] << endl;
   }
}

int func(int a, int &b){
   a = 100;
   b = 101;
   return 102;
}

void func2(int a, int b[]){
   a = 123;
   b[4] = 456;
}
