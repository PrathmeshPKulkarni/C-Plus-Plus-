/* Insertion Sort
First fix first element and compare with other element and sort
In insertion sort we have to shft element not swap
i=1 because we assume that zeroth element is already sorted 
*/

#include<iostream>
using namespace std;
void insertionSort(int arr[], int n);
void printArray(int arr[],int n);
int main()
{
    unsigned int uiN=10;
    int arr[uiN]={12,11,10,9,8,7,5,2,1,3};
    // int arr[uiN]={1,2,3,5,7,8,9,10,11,12};
    cout<<"unsorted Array"<<endl;
    printArray(arr,uiN);
    insertionSort(arr,uiN);
    cout<<endl;
    cout<<"Sorted Array"<<endl;
    printArray(arr,uiN);
    return 0;
}
void insertionSort(int arr[], int n)
{
    bool bSwapped;
    for(int i=1;i<n;i++)
    {
        int j=i-1;
        int temp=arr[i];
        for(;j>=0;j--)
        {
          if(arr[j]>temp)
          {
            // shift
            arr[j+1]=arr[j];
          }
          else
          {
            break;
          }
            
        }
        arr[j+1]=temp;
        // cout<<i<<endl;
    }
}

void printArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<"\t"<<arr[i];
    }
}