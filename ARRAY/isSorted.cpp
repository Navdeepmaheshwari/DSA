#include <bits/stdc++.h>
using namespace std;
bool isSorted(int arr[], int n)   // TIME COMPLEXITY--> O(n)
{
    int i;

    for (i = 1; i < n; i++)
    {
        if (arr[i - 1] > arr[i])
        {
            return false;
        }
    }
    return true; 
}
int main()
{
    int N = 5;
    int arr[] = {1, 2, 3, 7, 9};

    int n = sizeof(arr) / sizeof(arr[0]);

   if( isSorted(arr, n)){
       cout<<"Array is Sorted"<<endl;
   }
   else{
       cout<<"Array is not Sorted"<<endl;
   }

    return 0;
}