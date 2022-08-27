#include <bits/stdc++.h>
using namespace std;
const int CHAR = 256; // for all if having lowercase then create only of 26
bool isAnagram(string s1, string s2)
{
    int n1 = s1.length();
    int n2 = s2.length();
    if (n1 != n2)
        return false;
    int count[CHAR] = {0};
    for (int i = 0; i < n1; i++)
    {
        count[s1[i]]++; // increse character freq.
        count[s2[i]]--; // decrese character freq
                        // so overall 0 for all
    }
    for (int i = 0; i < CHAR; i++)
    {
        if (count[i] != 0)
            return false;
    }

    return true;
}
int main()
{
    string s1 = "ABCBA";
    string s2 = "BBAAC";
    bool ans = isAnagram(s1, s2);
    if (ans)
        cout << "S2 and S1 are Anagram" << endl;
    else
    {
        cout << "NO" << endl;
    }
}