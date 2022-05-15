// Maximum sum of  SubArrays
#include <bits/stdc++.h>
using namespace std;
int mxmSum(int arr[], int n)
{
   int res=arr[0];
   int maxEnd=arr[0];
   for (int i = 1; i < n; i++)
   {
       maxEnd=max(maxEnd+arr[i],arr[i]);
       res=max(maxEnd,res);
   }
   return res;
}
int main()
{
    // int N = 5;
   
    int arr[] = {-3, 8, -2, 4, -5, 6};

    int n = sizeof(arr) / sizeof(arr[0]);
   int sum= mxmSum(arr, n);
   cout<<"Max Sum of Subarray: "<<sum<<endl;
    return 0;
}