// **********MAJORITY ELEMENT*************
// Element that appear more than half of the size of array size (element_count > n/2).

#include <bits/stdc++.h>
using namespace std;

// MOORE'S VOTING ALGORITHM
int findMajority(int arr[], int n)
{
    int res = 0, count = 1;
    // find candidate
    for (int i = 1; i < n; i++)
    {
        if (arr[res] == arr[i])
        {
            count++;
        }
        else
        {
            count--;
        }
        if (count == 0)
        {
            res = i;
            count = 1;
        }
    }

    // Check if the candidate is Majority or Not

    count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[res] == arr[i])
        {
            count++;
        }
    }
    if (count <= n / 2)
    {
        res = -1;
    }

    return res;
}

int main()
{
    int arr[] = {6, 4, 8, 8, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Majority Element is: " << arr[findMajority(arr, n)] << endl;
}