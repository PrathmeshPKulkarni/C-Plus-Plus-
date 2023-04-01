#include<iostream>
using namespace std;
// the values in sorted order in binary search
// complexsity O(logn)
int binaryserch(int arr[],int size,int key);
int main()
{
    int even[6]={2,4,6,8,10,24};
    int odd[6]= {1,3,5,7,11,31};
    cout<<"index="<<binaryserch(even,6,24)<<endl;
    cout<<"index="<<binaryserch(odd,6,7)<<endl;
    
}

int binaryserch(int arr[],int size,int key)
{
    int start =0;
    int end=size-1;
    int mid = (start+end)/2;
    // if start value is = 2^32-1 (out of range_error) for better option write below formulae
    mid= start+((end-start)/2);
    while(start<=end)
    {
        if (arr[mid]==key)
        {
            return mid;
        }
        //goto right part
        if(key>arr[mid])
        {
            start =mid+1;
        }
        //go to left part
        else
        {
            end=mid-1;
        }
        mid = (start+end)/2;

    }
    return -1;

}