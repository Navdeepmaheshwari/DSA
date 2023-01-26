#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> a = {3, 29, 77, 2, 5, 9, 4};

    sort(a.begin(), a.end());

    auto it = lower_bound(a.begin(), a.end(), 6);
    auto it1 = upper_bound(a.begin(), a.end(), 3);

    if (it == a.end() || it1 == a.end())
    {
        cout << "Not Found";
    }

    cout << *it << endl;
    cout << *it1 << endl;
    return 0;
}