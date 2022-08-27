#include <bits/stdc++.h>
using namespace std;
// Time-->O(n)
// Space-->O(1)
bool ispalindrome(string s)
{
    int start = 0;
    int end = s.length() - 1;

    while (start <= end)
    {
        if (s[start] != s[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}
int main()
{
    string s = "ABCBA";
    bool ans = ispalindrome(s);
    if (ans)
        cout << "Palindrome" << endl;
}