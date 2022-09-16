#include <bits/stdc++.h>
using namespace std;

/*
    Expected Time Complexity : O(N*LogN)
    Expected Auxilliary Space : O(N)
*/
int maxMeetings(int start[], int end[], int n)
{
    pair<int, int> arr[n + 1];
    for (int i = 0; i < n; i++)
    {
        arr[i].first = end[i];
        arr[i].second = i;
    }
    sort(arr, arr + n);

    int sol = arr[0].first;
    vector<int> res;
    res.push_back(arr[0].second + 1);
    for (int i = 1; i < n; i++)
    {

        if (start[arr[i].second] > sol)
        {
            res.push_back(arr[i].second + 1);

            sol = arr[i].first;
        }
    }

    return res.size();
}

int main()
{
    // Starting time
    int s[] = {1, 3, 0, 5, 8, 5};

    // Finish time
    int f[] = {2, 4, 6, 7, 9, 9};

    // Number of meetings.
    int N = sizeof(s) / sizeof(s[0]);

    // Function call
    int ans = maxMeetings(s, f, N);
    cout << ans;

    return 0;
}
