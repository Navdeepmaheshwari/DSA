#include <bits/stdc++.h>
using namespace std;

stack<pair<int, int>> s;
int minimu(int a, int b) { return a > b ? b : a; }
/*returns min element from stack*/
int getMin()
{
    int min_elem;
    if (!s.empty())
        min_elem = s.top().second;
    else
        min_elem = -1;
    return min_elem;
}

/*returns poped element from stack*/
int pop()
{
    int pop_item;

    if (s.empty() == false)
    {

        pop_item = s.top().first;
        s.pop();
    }
    else
    {

        pop_item = -1;
    }
    return pop_item;
}

/*push element x into the stack*/
void push(int x)
{

    // Write your code here
    int nmin;

    nmin = s.empty() == true ? x : minimu(x, s.top().second);
    s.push({x, nmin});
}
stack<int> st;
int main()
{

    st.push(-1);
    st.push(10);
    
    st.push(-4);
    st.push(0);
    st.pop();
    int min = getMin();
    cout << min;

    return 0;
}