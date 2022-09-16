#include <bits/stdc++.h>
using namespace std;
struct Job
{
    char id;
    int deadline;
    int profit;
};
bool comparison(Job a, Job b)
{
    return (a.profit > b.profit);
}
int mxmProf = 0;
vector<char> mxmProfit(struct Job arr[], int n)
{
    vector<char> ans;
    sort(arr, arr + n, comparison);
    int result[n];
    bool slot[n];

    for (int i = 0; i < n; i++)
        slot[i] = false;

    for (int i = 0; i < n; i++)
    {
        // Find a free slot for this job (Note that we start
        // from the last possible slot)
        for (int j = min(n, arr[i].deadline) - 1; j >= 0; j--)
        {
            // Free slot found
            if (slot[j] == false)
            {
                result[j] = i;  // Add this job to result
                slot[j] = true; // Make this slot occupied
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (slot[i])
        { // cout << arr[result[i]].id << " ";
            ans.push_back(arr[result[i]].id);
            mxmProf += arr[result[i]].profit;
        }
    }
    return ans;
}

int main()
{
    Job arr[] = {{'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, {'d', 1, 25}, {'e', 3, 15}};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<char> res = mxmProfit(arr, n);

    for (char i : res)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "Maximum Profit : " << mxmProf << endl;
    return 0;
}