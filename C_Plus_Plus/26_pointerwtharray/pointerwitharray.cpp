/*
int arr[6]={1,2,3,4,5,6}
arr indicate first location of array
*/
#include<iostream>
using namespace std;
void arraypointer();
void charArray();
int main()
{
    // arraypointer();
    charArray();
    return 0;
}

void arraypointer()
{
    //address of array are not reassignable we can not reassign address of array
    int arr[5]={1,2,3,4,5};
    cout<<"Print address of arr[0]="<<arr<<endl;
    cout<<"Print size of arr ="<<sizeof(arr)<<endl; // print size of whole array 5x4 =20
    cout<<"Print size of arr[0] ="<<sizeof(*arr)<<endl;
    cout<<"Print size of arr[0]="<<sizeof(arr[0])<<endl;
    cout<<"Print address of arr[1]="<<arr+1<<endl;
    cout<<"Print address of arr[0]="<<&arr[0]<<endl;
    cout<<"Print address of arr[1]="<<&arr[1]<<endl;
    cout<<"Print value of arr[2]="<<arr[2]<<endl;

    cout<<"Print print value of arr[0]="<<*arr<<endl;   //dereferencing return value
    cout<<"Print print value of arr[1]+1="<<*arr+1<<endl;
    cout<<"Print print value of arr[1]="<<*(arr+1)<<endl;  // value at 1st location
    //      or
    cout<<"Print print value of arr[1]="<<1[arr]<<endl;
    // or
    int i=3;
    cout<<"Print print value of arr[1]="<<i[arr]<<endl;
    //error
    // arr=arr+1;
    int *ptr =&arr[0];
    cout<<"ptr="<<ptr<<endl;
    ptr = ptr+1;
    cout<<"ptr="<<ptr<<endl;
    //formulae
    /*     arr[i]= *(arr+i)
                or
            i[arr]=*(i+arr)
               
     */


}

void charArray()
{
    //Implementation is different in cout
    int arr[6]={1,2,3,4,5,6};

    char ch[8]="abc\0de";   // 1 extra for null(\0) character

    // char *cptr = "xyzcv";   do not do this
    // cout<<cptr<<endl;      
    cout<<"integer Array ="<<arr<<endl;  //it print address of first location
    cout<<"Char array= "<<ch<<endl;   //it print whole array

    char *c=&ch[0];
    cout<<"print entire string"<<c<<endl; //print entire string 
    char temp ='z';
    char *p =&temp;
    cout<<"\n p="<<p<<endl; //it print the value until null character
    
}