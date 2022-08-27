#include <bits/stdc++.h>
using namespace std;
void reverse(char s[], int low, int high)
{
    while (low <= high)
    {
        swap(s[low], s[high]);
        low++;
        high--;
    }
}
void reverseWord(char s[], int n)
{
    int start = 0;
    for (int end = 0; end < n; end++)
    {
        if (s[end] == ' ')
        {
            reverse(s, start, end - 1);
            start = end + 1;
        }
    }
    reverse(s, start, n - 1);
    reverse(s, 0, n - 1);
}
int main()
{
    char str[] = "Navdeep Maheshwari IIIT Surat";
    int n = sizeof(str) / sizeof(str[0]);
    cout << n << endl;
    reverseWord(str, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << str[i];
    }
}