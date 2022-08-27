// using Binary search
#include <bits/stdc++.h>
using namespace std;

int sqroot(int x)
{
    int low = 1, high = x, ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int midsqr = mid * mid;
        if (midsqr == x)
        {
            return mid;
        }
        else if (midsqr > x)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
            ans = mid;
        }
    }
    return ans;
}

int main()
{

    int x = 17; // no of which we have to find square root

    cout << "square root of " << x << " is " << sqroot(x) << endl;
}