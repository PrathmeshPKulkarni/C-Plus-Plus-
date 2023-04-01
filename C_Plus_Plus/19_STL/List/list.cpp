#include<iostream>
#include<list>
using namespace std;
int main()
{
    list<int> l;
    list<int> a(l); //copy list to another list
    list<int> c(5,12); //to initilize first 5 element are 5
    l.push_back(4);
    l.push_back(5);
    for(int i:l)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    l.erase(l.begin());
        for(int i:l)
    {
        cout<<i<<" ";
    }
    l.push_front(7);
        for(int i:l)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    l.pop_front();
        for(int i:l)
    {
        cout<<i<<" ";
    }
    cout<<"B list"<<endl;
    for(int i:c)
    {
        cout<<i<<" ";
    }
}