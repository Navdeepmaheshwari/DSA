#include <bits/stdc++.h>
using namespace std;
const int CHAR = 256;

// 2-Traversal
// O(n)--Time
// O(1)--Space

int leftMost(string s)
{
    int count[CHAR] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        count[s[i]]++;
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (count[s[i]] > 1)
            return i;
    }
    return -1;
}
int main()
{
    string s = "abccbd";
    int ans = leftMost(s);
    cout << ans << " " << s[ans] << endl;
}