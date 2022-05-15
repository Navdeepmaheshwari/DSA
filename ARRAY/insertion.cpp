#include <bits/stdc++.h>
using namespace std;
int insert(int arr[],int n, int x, int pos, int cap)
{
    // int n=sizeof(arr)/sizeof(arr[0]);
    if (n == cap)
    {
        return n;
    }
    int index = pos - 1;
    for (int i = n - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i]; // shifting array values
    }
    arr[index] = x;
    n++;
    return n;
}
int main()
{
    int N = 5;
    int arr[N] = {1,2,3};
    int x = 7;   // value we want to insert
    int pos = 2; // at position we want insertion
    int n=3;
    // cout<<sizeof(arr)/sizeof(arr[0])<<endl;
    
   int size= insert(arr,n, x, pos, N);
    cout<<"No of Elements="<<size<<endl;
    cout<<"Array Elements"<<endl;
    for (int i = 0; i < size; i++)
    {
       cout<<arr[i]<<endl;
    }
    
    return 0;
}