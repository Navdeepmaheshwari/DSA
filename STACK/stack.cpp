#include<bits/stdc++.h>
using namespace std;

int main(){
    stack<int>s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout<<s.size()<<endl;
    cout<<s.top()<<endl;
    cout<<s.empty()<<endl;

    //Travesing Stack
    //Print in Reverse Order
    while (s.empty()!=true)
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
   return 0; 
}