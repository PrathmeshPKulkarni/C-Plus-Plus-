#include<iostream>
#include<math.h>
using namespace std;
void binary(int n);
void power();
void bitwiseOperator();
int main()
{
    int n=6;
    // binary(n);
    int ans=0;
    // ans = 2*2;
    // cout<<ans<<endl;
    // power();
    bitwiseOperator();
    return 0;
}

void binary(int n)
{
    int ans=0;
    int i=1;
    int power;
    while (n!=0)
    {
    int bit = n&1;
    // power =10;
     ans =(bit* pow(10,i))+ans;
    
    // power=pow(10,i);
    
    // cout<<power<<endl;
     n=n >> 1;
     i++;
    // power function gives wrong output
    }

    cout<<"answer="<< ans <<endl;
    

}

void decimal(int n)
{
    int ans =0,i;
    while(n!=0)
    {
        int digit;
        digit= n&1;
        if(digit)
        {
            ans=2^i;
        }
    }
}

void power()
{
    // pow(2,3);

    cout<<"Power="<<pow(10,0);
}

void bitwiseOperator()
{
    int n=5;
    n= n<<5;
    cout<<"n="<<n;
}


