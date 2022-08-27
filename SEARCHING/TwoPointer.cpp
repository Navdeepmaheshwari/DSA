// Gven a Sorted Array and a Sum.
// Find is there is a Triplet with given Sum or not.
#include <bits/stdc++.h>
using namespace std;

bool isPair(int arr[], int left, int right, int sum)
{
    // int left=0,right=n-1;
    while (left < right)
    {
        if (arr[left] + arr[right] == sum)
        {
            return true;
        }
        else if (arr[left] + arr[right] > sum)
        {
            right--;
        }
        else
        {
            left++;
        }
    }
    return false;
}

int main()
{
    int arr[] = {2, 3, 4, 8, 9, 20, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 9;
    for (int i = 0; i < n; i++)
    {
        if (isPair(arr, i + 1, n - 1, (x - arr[i])))
        {
            cout << "Triplet is Present" << endl;
            return true;
        }
    }
    cout << " Triplet is not Present" << endl;
    return false;

    // cout<<"is Pair is Present? "<<isPair(arr, , x)<<endl;
}
