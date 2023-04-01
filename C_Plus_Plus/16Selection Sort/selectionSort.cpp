/*     Selection Sort
Example  n=5 total round = n-1
arr[]=    {64,25,12,22,11} //Put minimum value in particular location
Round 1 = {11,25,12,22,64}
Round 2 = {11,12,25,22,64}
Round 3 = {11,12,22,25,64}
Round 4 = {11,12,22,25,64}
Complexicity
Space - O(1) Because of you take only variable
Time -  O(n^2)
Best Case-
Worst Case-
If array size is small the selection sort is best

*/

#include<iostream>
using namespace std;
void selectionSort(int arr[],int n);
void printArray(int arr[],int n);
int main()
{
    int n=5;
    int arr[n]={64,25,12,22,11};
    cout<<"Unsorted Array"<<endl;
    printArray(arr,n);
    selectionSort(arr,n);
    cout<<"Sorted Array"<<endl;
    printArray(arr,n);

}

void selectionSort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int minIndex=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[minIndex])
            {
                minIndex=j;
            }
        }
        swap(arr[minIndex],arr[i]);
    }
}

void printArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
}