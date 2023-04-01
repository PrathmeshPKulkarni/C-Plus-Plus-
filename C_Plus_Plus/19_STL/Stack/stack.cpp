#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int main()
{
    stack<int> a;

    queue<string> q; //first in first out

    a.push(5);
    a.push(4);
    a.push(6);
    a.push(7);
    cout<<"Top Element="<<a.top()<<endl; //last element is first  LIFO

    //Queue
    q.push("Prathmesh");
    q.push("Raju");
    q.push("Banti");
    q.push("Vishal");
    cout<<"Top Element="<<q.front()<<endl; //FIFO

}