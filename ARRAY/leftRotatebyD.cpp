#include <bits/stdc++.h>
using namespace std;
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
/// REVERSAL ALGORITHM///
// START//
void revers(int arr[], int low, int high)
{
    while (low < high)
    {
        swap(arr[low], arr[high]);
        low++;
        high--;
    }
}

void leftRotate(int arr[], int n, int d)
{
    revers(arr, 0, d - 1); // reverse first d element
    revers(arr, d, n - 1); // reverse remaning element
    revers(arr, 0, n - 1); // reverse the whole array
}
// END //
int main()
{
    int N = 5;
    int arr[] = {1, 2, 3, 4, 5};

    int n = sizeof(arr) / sizeof(arr[0]);
    int d = 2; // no of times we want to rotate
    cout << "Array : ";
    printArray(arr, n);
    leftRotate(arr, n, d);
    cout << "Left Rotate Array by " << d << " times : ";
    printArray(arr, n);
    return 0;
}