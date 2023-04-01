/*
Recursion: Function calls itself called recursion
void recusion()
{
    Base condition   //if not base condition then segmentation fault error occured
                     // because of stackoverflow
    return //mandetory
   recusion(); 
}
Head Recursion
void recursion()
{
    Base Condition
    Recursive Relation
    Processing
}

Tail Recursion
void recursion()
{
    Base Condition
    Processing
    Recursive Relation
}

*/
int factorial(int n);
int power(int n);
#include<iostream>
using namespace std;
int main()
{
    // cout<<"\n Factorial="<<factorial(5);
    cout<<"\n Power="<<power(5);
    return 0;
}

int factorial(int n)
{
    int a;
    if(n==0)
    {
        return 1;
    }
    a=n*factorial(n-1);
    cout<<"Infunc="<<a<<endl;
    return a;
    
}

int power(int n) //this fuction for 2 power
{
    // Base Condition
        if(n==0)
        {
            return 1;
        }

     //Recursive Relation
    //  int smallProblem = power(n-1);
    //  int biggerProblem= 2*smallProblem;
     return   2*power(n-1);
}