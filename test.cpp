#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> res;
void subseq(int index, vector<int> &arr, vector<int> &ans)
{
     if (index >= arr.size())
     {
          res.push_back(ans);
          return;
     }

     ans.push_back(arr[index]);
     subseq(index + 1, arr, ans);
     ans.pop_back();

     subseq(index + 1, arr, ans);
}
int main()
{
     vector<int> arr = {3, 1, 2};
     vector<int> ans;
     subseq(0, arr, ans);

     for (auto x : res)
     {

          for (auto y : x)
          {
               cout << y << " ";
          }
          cout << endl;
     }
     return 0;
}