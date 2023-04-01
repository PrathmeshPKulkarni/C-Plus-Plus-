/* Array contain similar type of data type
 Array store value in contigious memory location
 we can acces array value by index
int arr[10]; this is declaration of array
- 10 indicate size of array 
- arr indicate first locaton
- index start from zero
- how array acces element eg. arr[3] = arr(starting address) + 3(index) * 4(data type size)

#Initialize of array
int arr[3]={5,2,5}
how to initiaze all element with zero
int arr[1000]={0}; //all element are zero
how to initialize all element with any value
use fill_n(array,100,5)


Intersection means commoon element
solve with two pointer approach
 */
#include<iostream>
#include <climits>
#include<stdlib.h>
using namespace std;
void printArry(int array[],int size);
int getMax(int arr[],int size);
int getMin(int arr[],int size);
void updateArray(int arr[],int n);
int sumofArray(int arr[],int n);
bool linearSerach(int arr[], int key);
int reverseArray(int arr[],int n);
void swapAlternate(int arr[],int n);
int uniqueElement(int arr[],int n);
int findIntersectioninArray(int arr[],int arr1[],int n);
int duplicate(int arr[],int n);
void merge2array();
int main()
{
    merge2array();

        // int i,n,size;
        // //initiasing array   
        // //Do not put size varible in array
        // n=10;
        // int array[n] = {23,1,2,3,3,5,1,2,5,7};
        // int array1[9]= {1,2,3,4,67};

        // ke=35;
        // findIntersectioninArray(array,array1,n);
        // cout<<duplicate(array,n);
        // cout<<"Unique elment="<<uniqueElement(array,9)<<endl;
        // swapAlternate(array,n);
        //  reverseArray(array,10);
        // cout<<"Statement= "<<array[n-1]<<endl;

        // cout<<"Statement= "<<linearSerach(array,ke)<<endl;

        // cout<<"Sum of Array="<<sumofArray(array,n)<<endl;

        // cout<<"In the main function"<<endl;
        // updateArray(array,10);
        //  Important Note
        //I arry case array pass the base address to the function 
        // the value is update in actual array
        // But in variable case the value is not update
        // cout<<"Printing in main function"<<endl;

        // for(int i=0;i<=n;i++)
        // {
        //     cout<<array[i]<<endl;
        // }



        // cout<<"Maximum Value="<<getMax(array,n)<<endl;
        // cout<<"Minimum Value="<<getMin(array,n)<<endl;

        // fill_n(array,100,5); // to initialize any value in all location
        // int array[100] = { [0 ... 99] = -1 };

        // accessing element
        // cout<<"Value at 4th location= "<<array[4]<<endl;
        // Printing the array;

        // Calculate size of array

        // int size= sizeof(array)/sizeof(int);
        // cout<<"Size of Array = "<<size<<endl;

        // printArry(array,n);

}
// Questions -- Swap alternate no. in array eg {1,2,3,45,2,5} olp {2,1,45,3,5,2}
//find unique element in an array
// find duplicate element in an array
// array intersection eg {1,2,3,5} {2,4,6,3} olp {2,3}
//pair sum
//triplet sum
//sort 0 and 1
// Return true if no. of occurance are different in arry
int intersection(int arr1[],int arr2[],int n)
{
    // while()
}

int duplicate(int arr[],int n)
{
    int ans;
    ans=0;
   for(int i=0;i<n;i++)
   {
    ans = ans^arr[i];
    cout<<"answer ="<<ans;

    }

    for(int i=0;i<n;i++)
    {
        ans=ans^i;
        cout<<"answer ="<<ans;
    }
    return ans;
}
   
int findIntersectioninArray(int arr[],int arr1[],int n)
{
    int i,j,element;
    for(i=0; i<n;i++)
    {
        element=arr[i];
        for(j=0;j<n;j++)
        {
            if(element==arr1[j])
            {
                cout<<element<<endl;
                arr1[j]=-3;
                break;
            }
        }
    }

}

int uniqueElement(int arr[],int n)
{
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans=ans^arr[i];
        // cout<<ans<<endl;
    }
    return ans;

}
void swapAlternate(int arr[],int n)
{
    int temp=0;
    cout<<"alternating swap"<<endl;
    for(int i=0;i<n;i+=2)
    {
        
        if(i+1<n)
        {
            // swap(arr[i],arr[i+1]);
            //  Or
            temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
        }
    }
}
int reverseArray(int arr[],int n)
{
    int temp=0;
    int start,end;
    start=0;
    end=n-1;
   while(start<=end)
   {
    swap(arr[start],arr[end]);
    start++;
    end--;
   }
}
bool linearSerach(int arr[], int key)
{
    int n=10;
    // key=3;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==key)
        {
            return 1;

        } 
        
    }
    return 0;
}

int sumofArray(int arr[],int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+arr[i];
        // cout<<sum<<endl;
    }
    return sum;

}
void updateArray(int arr[],int n)
{
    cout<<"Inside the function "<<endl;
    arr[0]=120;
    for(int i=0;i<=n;i++)
    {
        cout<<arr[i]<<endl;
    }
    cout<<"function Over";
}
void printArry(int array[],int size)
{

for(int i=0;i<size;i++)
{
    cout<<"Value at "<< i<< " location  = "<<array[i]<<endl;
    

}

}

// Questions
// Get minimum and maximum value in the array
int getMax(int arr[],int size)
{
    int maxi;
    maxi= INT_MIN;  // this used for minimum value in int range
    for(int i=0;i<=size;i++)
    {
        // if(arr[i]>max)
        // {
        //     maxi=arr[i];
            
        // }
        // or
        maxi = max(maxi,arr[i]);  
    }
    return maxi;
    
}

int getMin(int arr[],int size)
{
    int min;
    min= INT_MAX;  // this used for minimum value in int range
    for(int i=0;i<=size;i++)
    {
        if(arr[i]<min)
        {
            min=arr[i];  //use min(mini, arrr[i]) for minimum
        }
    }
    return min;
    
}

void merge2array()
{
    int arr1[5]={5,6,7,8,9};
    int arr2[5]={1,2,3,4,5};
    int arr3[10];
    int k=0;
    for(int i=0;i<5;i++)
    {
        arr3[k++]=arr1[i];
    }

    for(int i=0;i<5;i++)
    {
        arr3[k++]=arr2[i];
    }  


for(int i=0;i<10;i++)
{
    cout<<"Value at "<< i<< " location  = "<<arr3[i]<<endl;
    
}      
}