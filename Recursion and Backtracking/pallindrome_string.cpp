#include <bits/stdc++.h>
using namespace std;
bool ispalindrome(string s, int n, int i)
{
    if (i >= n / 2)
        return true;
    if (s[i] != s[n - i - 1])
    {
        return false;
    }
    return ispalindrome(s, n, i + 1);
}
int main()
{
    string s = "MADAM";
    int n = s.size();
    bool ans = ispalindrome(s, n, 0);
    if (ans)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 0 << endl;
    }
    return 0;
}