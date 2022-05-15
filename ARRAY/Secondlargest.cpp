#include <bits/stdc++.h>
using namespace std;
int secondLargest(int arr[], int n)
{
    int i;
    int result=-1;
    int largest=0;
    for ( i = 1; i < n; i++)
    {
        if(arr[i]>arr[largest]){
           result=largest;
            largest=i;
        }
        else if(arr[i]!=arr[largest]){
            if(result==-1 || arr[i]>arr[result]){
                result=i;
            }
        }
    }
    return result; // return index of second largest elem.
    
}
int main()
{
    int N = 5;
    int arr[] = {1, 20, 3, 77, 9};
    int x = 7; // value we want to delete

    int n = sizeof(arr)/sizeof(arr[0]);
    
 int secondmxm = secondLargest(arr, n);
    cout << "Second Largest Element in Array is :" << arr[secondmxm] << endl;
    return 0;
}