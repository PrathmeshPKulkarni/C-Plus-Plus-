// STL remianing after queue 32.10 timespan
#include<iostream>
#include<array>
#include<vector>
using namespace std;
int main()
{
    // STL array
    // array<int,4> arr = {1,2,3,4};
    // int size = arr.size();
    // for(int i=0;i<size;i++)
    // {
    //     cout<<arr[i]<<endl;
    // }
    // // Array operations in stl
    // cout<<"2nd position element="<<arr.at(2)<<endl;
    // cout<<"Array is empty or not ="<<arr.empty()<<endl;  // return boolean
    // cout<<"First Element="<<arr.front()<<endl;
    // cout<<"Last Element="<<arr.back()<<endl;

    //####################--------------Vector------------#########################################

    vector<int> v;
    vector<int> arr(5,2); // 5 size of vector and 2 initialize all element with 2
    vector<int> last(arr); //copy arr vector last vector 
    cout<<"Size of vector="<<v.capacity()<<endl;
    v.push_back(1);
    cout<<"Size of vector="<<v.capacity()<<endl;
    v.push_back(2);
    cout<<"Size of vector="<<v.capacity()<<endl;
    v.push_back(3);
    cout<<"Size of vector="<<v.capacity()<<endl;
    v.push_back(4);    
    cout<<"Size of vector="<<v.capacity()<<endl;
    v.push_back(5);    
    cout<<"Size of vector="<<v.capacity()<<endl; 
    // capacity told the space allocated to the vector if vector is full then it double the size
    cout<<"size of Vector"<<v.size()<<endl; //5 element present so size=5
    cout<<"Element at 2nd position="<<v.at(2)<<endl;
    cout<<"First Element="<<v.front()<<endl;
    cout<<"Last Element="<<v.back()<<endl;  
    
    cout<<"before pop"<<endl;
    for(int i:v)
    {
        cout<<i<<" "<<endl;
    }
    cout<<endl;
    v.pop_back();
    cout<<"after pop"<<endl;
    for(int i:v)
    {
        cout<<i<<endl;
    }
    cout<<endl;

    // clear function size will be zero capcity not zero
    cout<<"before clear"<<endl;
    for(int i:v)
    {
        cout<<i<<" "<<endl;
    }
    cout<<endl;
    v.clear();
    cout<<"after clear"<<endl;
    for(int i:v)
    {
        cout<<i<<endl;
    }
    cout<<endl;
    cout<<"size of vector="<<v.size()<<endl;
    cout<<"size of capacity="<<v.capacity()<<endl;   
    // capcity means how memory assing to this vector and size means how many element 
    // stored in this vector
    cout<<"Initialize all 2"<<endl;
    for(int i:arr)
    {
        cout<<i<<endl;
    }

    cout<<"Copy arr vector to last vector"<<endl;
    for(int i:last)
    {
        cout<<i<<endl;
    }
    return 0;
}