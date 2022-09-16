/*
?  Given an array nums[] of size n, construct a Product Array P (of same size n)
?  such that P[i] is equal to the product of all the elements of nums except nums[i]
*/

#include <bits/stdc++.h>
using namespace std;
vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
{

    vector<long long int> ans;
    long long int mul = 1;
    long long int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
            flag++;
        else
            mul *= nums[i];
    }

    for (int i = 0; i < n; i++)
    {
        long long int temp;
        if (flag > 1)
            temp = 0;

        else if (flag == 0)
            temp = mul / nums[i];

        else if (flag == 1 && nums[i] != 0)
            temp = 0;

        else
            temp = mul;
        ans.push_back(temp);
    }
    return ans;
}
int main()
{
    vector<long long int> arr = {10, 3, 5, 6, 2};
    vector<long long int> ans = productExceptSelf(arr, arr.size());
    for (auto i : ans)
        cout << i << " ";
    return 0;
}