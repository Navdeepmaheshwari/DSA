// 721. Accounts Merge

#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
public:
    vector<int> rank, size, parent;
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        size.resize(n + 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    // find Parent Function PATH COMPRESSION
    int findParent(int node)
    {

        if (node == parent[node])
            return node;

        return parent[node] = findParent(parent[node]);
    }

    // UNION BY RANK

    void unionByRank(int u, int v)
    {
        int ulp_u = findParent(u); // ultimate parent of u
        int ulp_v = findParent(v);

        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    // UNION BY SIZE
    void unionBySize(int u, int v)
    {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

vector<vector<string>> accountsMerge(vector<vector<string>> &details)
{

    int n = details.size();
    DisjointSet ds(n);
    unordered_map<string, int> mp;

    for (int i = 0; i < n; i++)
    {

        for (int j = 1; j < details[i].size(); j++)
        {
            string mail = details[i][j];
            if (mp.find(mail) == mp.end())
            {
                mp[mail] = i;
            }
            else
            {
                ds.unionBySize(mp[mail], i);
            }
        }
    }
    vector<string> mails[n];
    for (auto it : mp)
    {
        string mail = it.first;
        int node = it.second;
        // we always take ultimate parent of node so
        node = ds.findParent(node);
        mails[node].push_back(mail);
    }

    vector<vector<string>> ans;
    for (int i = 0; i < n; i++)
    {
        if (mails[i].size() == 0)
            continue;
        sort(mails[i].begin(), mails[i].end());
        vector<string> temp;
        temp.push_back(details[i][0]);
        for (auto x : mails[i])
            temp.push_back(x);
        ans.push_back(temp);
    }
    return ans;
}
int main()
{

    vector<vector<string>> accounts = {{"John", "j1@com", "j2@com", "j3@com"},
                                       {"John", "j4@com"},
                                       {"Raj", "r1@com", "r2@com"},
                                       {"John", "j1@com", "j5@com"},
                                       {"Raj", "r2@com", "r3@com"},
                                       {"Mary", "m1@com"}};

    vector<vector<string>> ans = accountsMerge(accounts);
    for (auto acc : ans)
    {
        cout << acc[0] << ":";
        int size = acc.size();
        for (int i = 1; i < size; i++)
        {
            cout << acc[i] << " ";
        }
        cout << endl;
    }
    return 0;
}