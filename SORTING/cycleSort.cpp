
#include <bits/stdc++.h>
using namespace std;

int cycleSort(int arr[], int n)
{

    int writes = 0;

    for (int cycle_start = 0; cycle_start <= n - 2; cycle_start++)
    {

        int item = arr[cycle_start];

        int pos = cycle_start;
        for (int i = cycle_start + 1; i < n; i++)
            if (arr[i] < item)
                pos++;

        if (pos == cycle_start)
            continue;

        // ignore  duplicate
        while (item == arr[pos])
            pos += 1;

        if (pos != cycle_start)
        {
            swap(item, arr[pos]);
            writes++;
        }

        while (pos != cycle_start)
        {
            pos = cycle_start;

            for (int i = cycle_start + 1; i < n; i++)
                if (arr[i] < item)
                    pos += 1;

            // ignore  duplicate
            while (item == arr[pos])
                pos += 1;

            if (item != arr[pos])
            {
                swap(item, arr[pos]); 
                writes++;
            }
        }
    }

    return writes;
}

int main()
{
    int arr[] = {1, 8, 4, 3, 9, 10, 10, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before sort : " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    int memory_writes = cycleSort(arr, n);

    cout << "\nAfter sort : " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\nMemory Writes Required = " << memory_writes << endl;
    return 0;
}
