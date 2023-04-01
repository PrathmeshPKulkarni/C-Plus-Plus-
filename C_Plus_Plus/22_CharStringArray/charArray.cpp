/*
char a='s';
char a[10] abcdef;
'\0' terminator end of string
*/
#include<iostream>
using namespace std;
int stringLength(char arr[]);
void reverseString(char arr[],int strlen);
bool pallindrome(char str[],int strlen);
void diffStringChar();
int main()
{
    // char ch[12]="madam";
    // int strlen;
    // bool pallindrom;
    // cout<<ch<<endl;
    // strlen=stringLength(ch);
    // cout<<strlen<<endl;
    // reverseString(ch,strlen);
    // pallindrom=pallindrome(ch,strlen);
    // cout<<"String is="<<pallindrom<<endl;
    diffStringChar();
    return 0;
}

int stringLength(char ch[])
{
    unsigned int uicount;
    uicount=0;
    for(int i=0;ch[i]!='\0';i++)
    {
        cout<<ch[i]<<endl;
        uicount++;
    }
    return uicount;
    // cout<<"Length of string="<<uicount<<endl;
}

void reverseString(char arr[],int strlen)
{
    int start,end;
    start=0;
    end=strlen-1;
    int temp;
    while (start<end)
    {
        // swap(arr[start++],arr[end--]);
        temp= arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
        
    }
    cout<<"Reverse String="<<arr<<endl;
    
}

bool pallindrome(char str[],int strlen)
{
    int s,e;
    s=0;
    e= strlen-1;
    while (s<e)
    {
        if(str[s]!=str[e])
        {
            return 0;
        }
        else
        {
            s++;
            e--;
        }
        
    }
    return 1;
}

void diffStringChar()
{
    char a[]={'a','b','c','d','e','f','g','h','\0'};
    cout<<a<<endl;
    string str= "Prathmesh";
    cout<<str<<endl;
}