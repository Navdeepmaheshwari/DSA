// Count Frequencies of each character and
//  print character in sorted order with its frequencies

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "iiitsurat";
    int count[26] = {0};

    for (int i = 0; i < s.length(); i++)
    {
        count[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (count[i] > 0)
        {
            cout << (char)(i + 'a') << " " << count[i] << endl;
        }
    }
}