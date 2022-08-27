// check is S2 is subsquence of S1 or not
#include <bits/stdc++.h>
using namespace std;

bool isSubsqence(string s1, string s2)
{
    int n1 = s1.length();
    int n2 = s2.length();

    if (n1 < n2)
        return false;
    int j = 0;
    for (int i = 0; j < n2 && i < n1; i++)
    {
        if (s1[i] == s2[j])
            j++;
    }
    return (j == n2);
}
int main()
{
    string s1 = "ABCBA";
    string s2 = "BA";
    bool ans = isSubsqence(s1, s2);
    if (ans)
        cout << "S2 is Subsqence of S1" << endl;
    else
    {
        cout << "NO" << endl;
    }
}