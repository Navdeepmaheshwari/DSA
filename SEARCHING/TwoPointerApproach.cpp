// Gven a Sorted Array and a Sum.
// Find is there is a Pair with given Sum or not.
#include <bits/stdc++.h>
using namespace std;

bool isPair(int arr[], int n, int x)
{
    int left=0,right=n-1;
    while(left<right){
        if(arr[left]+arr[right]==x){
            return true;
        }
        else if(arr[left]+arr[right]>x){
            right--;
        }
        else{
            left++;
        }
    }
    return false;
}

int main()
{
    int arr[] = {2, 4, 8, 9, 11, 12, 20, 30};
    int x = 6;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"is Pair is Present? "<<isPair(arr, n, x)<<endl;
}