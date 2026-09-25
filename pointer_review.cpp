#include <iostream>
using namespace std;

int main()
{
    int x = 10;  //normal variable
    int*p;      //pointer variable 

    cout << "current value of pointer *p is the adress of " << p << endl;
    cout << "address of x at this point is " << &x << endl;

    p = &x;    //sotring address of x to pointer p,  *p shows the current value pointed by p

    cout << "\nNow the new value of pointer *p is the adress of " << p << endl;
    cout << "Value of x: " << x << endl;
    cout << "address of x at this point is " << &x << endl;
    cout << "Value point inside p: " << *p << endl;
    
    *p = 20;    //chnaging the value of p;
    cout << "New value of x: " << x << endl;
    cout << "New value pointed by p: " << *p << endl; 

    

    return 0;
}