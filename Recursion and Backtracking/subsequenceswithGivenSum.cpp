//* Print all the Subsequences of an array

#include <bits/stdc++.h>
using namespace std;

void printSubseq(int arr[], int n, vector<int> &subse, int ind, int sum, int curr_sum)
{
    if (ind == n)
    {
        if (sum == curr_sum)
        {
            cout << "{ ";
            for (auto i : subse)
            {
                cout << i << " ";
            }
            cout << "}";
            cout << endl;
        }

        return;
    }

    //? Not pick or not take condition ,this element not add in subsequence
    printSubseq(arr, n, subse, ind + 1, sum, curr_sum);

    //? Take or pick the particular index element in subsequence
    subse.push_back(arr[ind]);
    curr_sum += arr[ind];
    printSubseq(arr, n, subse, ind + 1, sum, curr_sum);
    curr_sum -= arr[ind];
    subse.pop_back();
}
int main()
{
    int arr[] = {1, 2, 1};
    int n = 3;
    vector<int> subse;
    int sum = 2;
    printSubseq(arr, n, subse, 0, sum, 0);
    return 0;
}