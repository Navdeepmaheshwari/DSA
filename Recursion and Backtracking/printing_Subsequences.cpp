//* Print all the Subsequences of an array

#include <bits/stdc++.h>
using namespace std;

void printSubseq(int arr[], int n, vector<int> &subse, int ind)
{
    if (ind == n)
    {
        cout << "{ ";
        for (auto i : subse)
        {
            cout << i << " ";
        }
        cout << "}";

        /*   if (subse.size() == 0)
          {
              cout << "{}";
          } */
        cout << endl;
        return;
    }

    //* Not pick or not take condition ,this element not add in subsequence
    printSubseq(arr, n, subse, ind + 1);

    //*take or pick the particular index element in subsequence
    subse.push_back(arr[ind]);
    printSubseq(arr, n, subse, ind + 1);
    subse.pop_back();
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    vector<int> subse;
    printSubseq(arr, n, subse, 0);
    return 0;
}