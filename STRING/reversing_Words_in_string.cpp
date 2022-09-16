//? Reverse words in a given string

#include <bits/stdc++.h>
using namespace std;
string reverseWords(string S)
{
    string res;
    int i = 0, n = S.length();

    while (i < n)
    {

        while (i < n && S[i] == '.')
            i++;

        if (i >= n)
            break;

        int j = i;
        while (j < n && S[j] != '.')
            j++;

        string sub = S.substr(i, j - i);
        if (res.length() == 0)
            res = sub;
        else
            res = sub + "." + res;
        i = j + 1;
    }

    return res;
}
int main()
{
    string s = "i.like.this.program.very.much";
    string revrse = reverseWords(s);
    cout << revrse << endl;
    return 0;
}