/************************************-Bitwise Operator-*******************************/

//storing negative no. in memory we used 2's complement
#include<iostream>
using namespace std;
void bitwise();
void postIncrement();
void preeIncrement();
void sumofNumber();
void fibonacii();
void primeNumber();
void subtractDigit();
void countBit();
int main()
{

    // bitwise();
    // postIncrement();
    // preeIncrement();
    // sumofNumber();
    // fibonacii();
    // primeNumber();
    //  subtractDigit();
     countBit();
    return 0;
}

void bitwise()
{
    int a=6;
    int b =21;
    cout<<"a&b ="<<(a&b)<<endl;
    cout<<"a|b ="<<(a|b)<<endl;
    cout<<"a^b ="<<(a^b)<<endl;
    cout<<"~b  ="<<(~b)<<endl;
    // In left shift operator the no. is multiple of 2
    cout<<"left shift="<<(b<<1)<<endl; 
    // In Right shift operator the no. is divided by 2
    // for positive no the padding is start with zero and for negative no. the padding 
    // is compiler dependant
    cout<<"Right shift="<<(b>>2)<<endl;
}

void postIncrement()
{
    int i=3,a=2;
    int sum;
    sum = a + (i++);
    cout<<"Sum="<<sum<<endl;
    cout<<"i="<<i<<endl;
}
void preeIncrement()
{
    int i=3,a=2;
    int sum;
    sum = a + (++i);
    cout<<"Sum="<<sum<<endl;
    cout<<"i="<<i<<endl;
}

void sumofNumber()
{
    int i,n,sum;
    n=5;
    sum=0;
    //you can write multiple condition in for loop
    for(i=0;i<=n;i++)
    {
        sum=sum+i;
    cout<<sum<<endl;
    }
}

void fibonacii()
{
    int a=0,b=1;
    for(int i=0; i<=10;i++)
    {
        int next = a+b;
        cout<<next<<endl;
        a=b;
        b= next;
    }
}

void primeNumber()
{
    int n,i;
    n=102;
    // cout<<"enter a no."<<endl;
    // cin>>n;
    for(i=2;i<n;++i)
    {
        if(n%i==0)
        {
            cout<<"Not prime"<<endl;
            break;
            
        }
        else
        {
            cout<<" prime"<<endl;
            break;
        
        }
    
    }
}

// Subtract the product and sum of digit  of an integer

void subtractDigit()
{
    int a,digit,sum,product,num;
    int subtract;
    num=234;
    product =1;
    sum=0;
    while(num!=0)
    {
        digit=num%10;
        product = product * digit;
        sum= sum +digit;
        num =num/10;
        
        
    }
    subtract = product-sum;
    cout<<"subtraction="<<subtract<<endl;


}

void countBit()
{
   bool n= 101101;
    int c=0;
    while (n!=0)
    {
        if(n&1)
        {
            c++;
        }
        n=n>>1;
    }
    cout<<"No. of bit= "<<c<<endl;

}