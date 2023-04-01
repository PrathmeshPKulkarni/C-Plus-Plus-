/*


*/

#include<iostream>
#include<deque>
using namespace std;
int main()
{
    deque<int> d;
    d.push_back(1);
    d.push_front(2);
    d.push_front(5);
    for(int i:d)
    {
        cout<<i<<" ";
    }
    // cout<<"next"<<endl;
    // d.pop_back();
    // for(int i:d)
    // {
    //     cout<<i<<" ";
    // }    
    // cout<<"next"<<endl;
    // d.pop_front();
    // for(int i:d)
    // {
    //     cout<<i<<" ";
    // }
    cout<<"Element at first Index="<<d.at(0)<<endl;
    cout<<"first = "<<d.front()<<endl;
    cout<<"Last = "<<d.back()<<endl;
    cout<<"Empty or not= "<<d.empty()<<endl;
    cout<<"Before erase = "<<d.size()<<endl;
    d.erase(d.begin(),d.begin()+1);
    cout<<"After erase = "<<d.size()<<endl;
        for(int i:d)
    {
        cout<<i<<" ";
    }
}