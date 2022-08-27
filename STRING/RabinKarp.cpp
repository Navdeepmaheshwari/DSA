#include <bits/stdc++.h>
using namespace std;
// d is the number of characters
// in the input alphabet
#define d 256

void RabinSearch(string txt, string pat, int q)
{
    int n = txt.length();
    int m = pat.length();
    int h = 1;
    for (int i = 0; i < m - 1; i++)
    {
        h = (h * d) % q;
    }

    int p = 0; // hash value for pattern
    int t = 0; // hash value for txt

    // Calculate the hash value of pattern and first
    // window of text
    for (int i = 0; i < m; i++)
    {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    for (int i = 0; i <= n - m; i++)
    {

        // Check the hash values of current window of text
        // and pattern. If the hash values match then only
        // check for characters on by one
        if (p == t)
        {
            bool flag = true;
            /* Check for characters one by one */
            for (int j = 0; j < m; j++)
            {
                if (txt[i + j] != pat[j])
                {
                    flag = false;
                    break;
                }
            }

            if (flag == true)
                printf("Pattern found at index %d \n", i);
        }

        if (i < n - m)
        {
            t = (d * (t - txt[i] * h) + txt[i + m]) % q;

            if (t < 0)
                t = (t + q);
        }
    }
}
int main()
{
    string txt = "GEEKS FOR GEEKS. A computer science portal for GEEKS";
    string pat = "GEEKS";
    int q = 101;
    RabinSearch(txt, pat, q);
}