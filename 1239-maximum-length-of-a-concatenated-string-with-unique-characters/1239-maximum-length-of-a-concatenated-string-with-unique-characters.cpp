class Solution {
public:
   void printVis(vector<int> &vis)
    {
        for(auto i : vis)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }

    void rec(int idx, int temp, int &ans, vector<string> &arr, int n, vector<int> &vis)
    {
        if(idx>=n)
            return;
        ans = max(temp, ans);
        for(int i=idx+1;i<n;i++)
        {
            bool repeated = 0;
            for(auto j : arr[i])//Mark visit
            {
                vis[j-'a']++;
            }
            for(auto k : vis)
            {
                if(k>1)
                {
                    repeated = 1;
                    break;
                }
            }
            if(!repeated)
            {
                rec(i, temp+arr[i].size(), ans, arr, n, vis);
            }
            for(auto j : arr[i])//unvisit current
            {
                vis[j-'a']--;
            }
        }
    }

    int maxLength(vector<string>& arr) {
        int n = arr.size();
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            vector<int>vis(26,0);
            int temp = arr[i].size();
            for(auto j : arr[i])//mark the visits for the current
            {
                vis[j-'a']++;
                if(vis[j-'a']>1)//If any character in the same string is repeated
                {
                    temp = 0;
                }
            }
            rec(i, temp, ans, arr, n, vis);
        }
        return ans;
    }
};