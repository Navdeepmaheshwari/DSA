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
    d = d % n;             //* if d>n
    revers(arr, 0, d - 1); // reverse first d element
    revers(arr, d, n - 1); // reverse remaning element
    revers(arr, 0, n - 1); // reverse the whole array
}
// END //
int main()
{
    int N = 5;
    int arr[] = {25, 6, 20, 55, 69, 5, 50, 63, 61, 41, 87, 80, 2, 96, 77, 70, 12, 43, 31, 8, 64, 41, 68, 18, 95, 79, 52, 74, 1, 98, 3, 26, 3, 74, 32, 23, 79, 81, 37, 39, 21, 24, 18, 22, 71, 47, 44};

    int n = sizeof(arr) / sizeof(arr[0]);
    int d = 77; // no of times we want to rotate

    cout << "Array : ";
    // printArray(arr, n);
    leftRotate(arr, n, d);
    cout << "Left Rotate Array by " << d << " times : \n";
    printArray(arr, n);
    return 0;
}