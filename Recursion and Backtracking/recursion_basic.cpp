#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
void printNRec(int i, int n)
{
    if (i > n)
        return;
    cout << i;
    printNRec(i + 1, n);
}
void printNBacktrack(int i, int n)
{
    if (i < 1)
        return;
    printNBacktrack(i - 1, n);
    cout << i;
}
void fromNto1Backtrack(int i, int n)
{
    if (i > n)
        return;

    fromNto1Backtrack(i + 1, n);
    cout << i;
}
int main()
{
    int n;
    cin >> n;

    printNRec(1, n);
    cout << endl;
    printNBacktrack(n, n);
    cout << endl;
    fromNto1Backtrack(1, n);
    return 0;
}