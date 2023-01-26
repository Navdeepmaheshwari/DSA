#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity: O(n2) where n is the total number of integers in the given stack.
Auxiliary Space: O(n)
*/

stack<int> sortStack(stack<int> &input)
{
    stack<int> tmpStack;

    while (!input.empty())
    {
        // pop out the first element
        int tmp = input.top();
        input.pop();

        // while temporary stack is not empty and top
        // of stack is greater than temp
        while (!tmpStack.empty() && tmpStack.top() > tmp)
        {
            // pop from temporary stack and push
            // it to the input stack
            input.push(tmpStack.top());
            tmpStack.pop();
        }

        // push temp in temporary of stack
        tmpStack.push(tmp);
    }

    return tmpStack;
}

int main()
{
    stack<int> s;
    s.push(34);
    s.push(3);
    s.push(31);
    s.push(98);
    s.push(92);
    s.push(23);

    stack<int> tmpStack = sortStack(s);
    cout << "Sorted numbers are:\n";

    while (!tmpStack.empty())
    {
        cout << tmpStack.top() << " ";
        tmpStack.pop();
    }
    return 0;
}