#include <bits/stdc++.h>
using namespace std;
int delet(int arr[], int n, int x)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == x)
            break;
    }
    if(i==n)
    return n;
    for (int j = i; j < n-1; j++)
    {
        arr[j]=arr[j+1];
    }
    
    n--;
    return n;
}
int main()
{
    int N = 5;
    int arr[] = {1, 2, 3, 7, 9};
    int x = 7; // value we want to delete

    int n = sizeof(arr)/sizeof(arr[0]);
    // cout<<sizeof(arr)/sizeof(arr[0])<<endl;

    int size = delet(arr, n, x);
    cout << "No of Elements=" << size << endl;
    cout << "Array Elements" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}