#include<iostream>

using namespace std;
int main()
{
    int ans;
    ans=0;
    int arr[6]={2,3,4,5,2,6};
    for(int i=0;i<6;i++)
    {
        ans = ans^arr[i];
    }
    for(int i=1;i<6;i++)
    {
        ans =ans^i;
    }
    cout<<ans;
    
}

int duplicate()
{
    int i,j;
    int arr[10]={2,1,3,2,5,7,3,5,8,10};
    for(i=0;i<10;i++)
    {
        for(j=i+1;j<10;j++)
        {
            if(arr[i]==arr[j])
            {
            cout<<" "<<arr[i];
            }
        }
        
    }
}