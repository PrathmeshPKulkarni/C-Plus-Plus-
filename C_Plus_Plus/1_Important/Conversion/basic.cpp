#include<iostream>
using namespace std;
int main()
{
    int i;
    for(i=5;i<=100;i++)
    {
        i=i+4;
        int b;
        b=5&i;
        cout<<"i="<<i<<endl;
        cout<<"b="<<b<<endl;
    }
    // int a,b;
    // a=5;
    // b=20;
    // int c;
    // c=a&b;
    // cout<<c<<endl;
    return 0;
}