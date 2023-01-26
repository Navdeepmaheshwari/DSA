/*
*Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language.
!Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string returned.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> topoSort(int V, vector<int> adj[])
{
    // code here
    vector<int> indegree(V, 0);
    vector<int> topo;
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        for (auto x : adj[i])
        {
            indegree[x]++;
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        { // push node whose indegree is 0;
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (auto x : adj[node])
        {
            indegree[x]--; // decrease indegree of adjacent nodes by 1
            if (indegree[x] == 0)
            { // if indegree of adjacent node become 0 push it in queue
                q.push(x);
            }
        }
    }
    return topo;
}
string findOrder(string dict[], int N, int K)
{
    // code here
    vector<int> adj[K];
    for (int i = 0; i < N - 1; i++)
    {

        string str1 = dict[i];
        string str2 = dict[i + 1];
        int n = min(str1.size(), str2.size());
        for (int j = 0; j < n; j++)
        {

            if (str1[j] != str2[j])
            {
                adj[str1[j] - 'a'].push_back(str2[j] - 'a'); // store as 0 1 2.....
                break;
            }
        }
    }
    vector<int> topo = topoSort(K, adj);
    string ans = "";
    for (auto x : topo)
    {
        ans += (x + 'a');
    }
    return ans;
}
int main()
{
    int K = 4;
    int N = 5;
    string dict[N] = {"baa",
                      "abcd",
                      "abca",
                      "cab",
                      "cad"};

    string ans = findOrder(dict, N, K);
    cout << ans;

    return 0;
}