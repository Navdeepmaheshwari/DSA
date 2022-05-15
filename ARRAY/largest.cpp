#include <bits/stdc++.h>
using namespace std;
int largest(int arr[], int n)
{
    int i;
    int result=0;
    for ( i = 0; i < n; i++)
    {
        if(arr[i]>arr[result]){
            result=i;
        }
    }
    return result; // return index of largest elem.
    
}
int main()
{
    int N = 5;
    int arr[] = {1, 20, 3, 77, 9};
    int x = 7; // value we want to delete

    int n = sizeof(arr)/sizeof(arr[0]);
    
 int mxm = largest(arr, n);
    cout << "Maximum Element in Array is :" << arr[mxm] << endl;
    return 0;
}