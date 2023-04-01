/*      Questions
1 make calculator using switch statement
2 Note problem 1330 how many notes required for 1330 notes of 100,50 20,1
*/
#include<iostream>
using namespace std;
int noteCalculator();
void passbyvalue(int n);
int  update(int a);
int main()
{
   int n =15;
   int a=10;
   // noteCalculator();
   
   // passbyvalue(n);
   // cout<<"Number="<<n;
   // n= update(a);  //  a value of type "void" cannot be assigned to an entity of type "int"C/C++(513
   // cout<<"Number="<<n;
   a=update(a);
   cout<<"Number="<<a;
}
//fuction flow 
// it only create copy of n does not pass location or address
void passbyvalue(int n)
{
   n++;
   cout<<"Number="<<n<<endl;
}
int update(int a)
{
   a=a/2;
   // return a;
}

int noteCalculator()
{
   int number =551;
   int count,count1,count2,count3;
   count= number/100;
   cout<<"100 notes ="<<count<<endl;
   number=number-count*100;
   count1 =number/50;
   cout<<"50 notes ="<<count1<<endl;
   number=number-count1*50;
   count2 = number/20;
   cout<<"20 notes ="<<count2<<endl;
   number=number-count2*20;
   count3 = number/1;
   cout<<"1  notes ="<<count3<<endl;

}

   void switchcase()
    {
    char ch = 67;
    int num=1;
    while(1)
    {
    switch (ch)
    {
    case 'A':
        cout<<"first statement"<<endl;
        break;
     case 'C': switch (num)
     {
     case 1:
        cout<<"Number statement"<<endl;
        exit(0); // this statement used for exit in switch case in infinite loop
        break;
     
     default:
        cout<<"default for number"<<endl;
        break;
     }   
     
     break;
    case 'B':
        cout<<"Second Statement"<<endl;
        break;
    default:
        cout<<"Default Statement"<<endl;
        break;
        
    }
    
    }
    }