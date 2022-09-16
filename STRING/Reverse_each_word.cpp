#include <bits/stdc++.h>
using namespace std;
string reverseWords(string str)
{
    stack<char> s;
    string rev = "";

    for (int i = 0; i < str.length(); ++i)
    {
        if (str[i] != '.')
            s.push(str[i]);

        // When we see a space, we print contents
        // of stack.
        else
        {
            while (s.empty() == false)
            {
                rev += s.top();
                s.pop();
            }
            rev += ".";
        }
    }
    while (s.empty() == false)
    {
        rev += s.top();
        s.pop();
    }
    return rev;
}
int main()
{
    string s = "i.like.this.program.very.much";
    string revrse = reverseWords(s);
    cout << revrse << endl;
    return 0;
}