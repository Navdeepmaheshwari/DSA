#include <bits/stdc++.h>
using namespace std;
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int mid_ind = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[mid_ind])
            {
                mid_ind = j;
            }
        }
        if (mid_ind != i)
            swap(arr[i], arr[mid_ind]);

        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout<<endl;
    }
}

int main()
{
    int arr[] = {10, 5, 8, 20, 2, 18};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before Selection Sorting" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout<<"STEPS"<<endl;
    selectionSort(arr, n);
    cout << "After Selection Sorting" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}