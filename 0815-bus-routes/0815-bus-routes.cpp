class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        
      if(source==target)return 0;
  
        int n=routes.size();

        set<int>st[n];
        for(int i=0;i<n;i++)
            for(int j=0;j<routes[i].size();j++)
            {
                int city=routes[i][j];
               st[i].insert(city);
            }

        queue<int>q;
          vector<int>ans(n,INT_MAX);
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++)
            if(st[i].find(source)!=st[i].end()){
                q.push(i);
                ans[i]=1;
            }
        while(!q.empty())
        {
            int tp=q.front();
            q.pop();
            if(vis[tp])continue;
            vis[tp]=true;
            for(int i=0;i<n;i++)
            {
                if(vis[i]||i==tp)continue;
                for(auto j:st[i])
                {
                    if(st[tp].find((j))!=st[tp].end()&&ans[i]>ans[tp]+1)
                    {
                        ans[i]=ans[tp]+1;
                        q.push(i);
                        break;
                    }  
                }
            }
        }
        int mn=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(st[i].find(target)!=st[i].end())mn=min(mn,ans[i]);
        }
        if(mn==INT_MAX)return -1;
        return mn;
        
    }
};