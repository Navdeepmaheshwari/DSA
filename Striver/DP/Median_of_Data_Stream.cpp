#include <bits/stdc++.h>
using namespace std;

priority_queue<int> leftNums;                             // max
priority_queue<int, vector<int>, greater<int>> rightNums; // min

void addNum(int num)
{
    if (leftNums.empty() || leftNums.top() >= num)
    {

        leftNums.push(num);
    }
    else
    {
        rightNums.push(num);
    }

    if (leftNums.size() > rightNums.size() + 1)
    {

        int temp = leftNums.top();
        leftNums.pop();
        rightNums.push(temp);
    }
    else if (rightNums.size() > leftNums.size())
    {
        int temp = rightNums.top();
        leftNums.push(temp);
        rightNums.pop();
    }
}

double findMedian()
{

    if (leftNums.size() > rightNums.size())
    {
        return leftNums.top();
    }
    else
    {
        return (leftNums.top() + rightNums.top()) / 2.0;
    }
}

int main()
{
    addNum(5);
    addNum(1);
    double ans = findMedian();
    cout << ans << endl;
    addNum(8);
    ans = findMedian();
    cout << ans << endl;
    return 0;
}