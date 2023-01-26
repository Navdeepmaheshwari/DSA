/*
todo -  Minimum characters to be added at front to make string palindrome.                                       Given string str of length N. The task is to find the minimum characters to be added at the front to make string palindrome.
*/
#include <bits/stdc++.h>
using namespace std;
int minChar(string str)
{
    // Write your code here
    int i = 0, j = str.length() - 1;
    int last = j;
    int res = 0;

    while (i <= j)
    {

        if (str[i] == str[j])
        {
            i++;
            j--;
        }
        else
        {
            res++;
            i = 0;
            last--;
            j = last;
        }
    }

    return res;
}
int main()
{
    string s = "abc";
    int cnt = minChar(s);
    cout << cnt << endl;

    return 0;
}