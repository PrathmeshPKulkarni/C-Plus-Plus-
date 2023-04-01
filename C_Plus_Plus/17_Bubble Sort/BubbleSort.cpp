/*  Bubble Sort
no. of round is n-1
Example
arr[7]={10,1,7,6,10,9,14}
Compare each element and swap
if element is greater then swap

Put particular element in ith largest position
Which Sorting Algorithms are In-Place and which are not? In Place:
Ans-: Bubble sort, Selection Sort, Insertion Sort, Heapsort
*/
// Eg. Sort the following array

#include<iostream>
using namespace std;
void bubbleSort(int arr[], int n);
void printArray(int arr[],int n);
int main()
{
    unsigned int uiN=10;
    // int arr[uiN]={12,11,10,9,8,7,5,2,1,3};
    int arr[uiN]={1,2,3,5,7,8,9,10,11,12};
    cout<<"unsorted Array"<<endl;
    printArray(arr,uiN);
    bubbleSort(arr,uiN);
    cout<<endl;
    cout<<"Sorted Array"<<endl;
    printArray(arr,uiN);
    return 0;
}
void bubbleSort(int arr[], int n)
{
    bool bSwapped;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                bSwapped=true;
            }
            
        }
        if(bSwapped==false)
        {
            break;
        }
        cout<<i<<endl;
    }
}

void printArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<"\t"<<arr[i];
    }
}