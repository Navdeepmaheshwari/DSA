class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& he) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    int n=he.size();
    int m=he[0].size();
    vector<vector<int>>dist(n,vector<int>(m,1e9));
    dist[0][0]=0;
    pq.push({0,{0,0}});
    int dro[]={-1,0,1,0};
    int dco[]={0,1,0,-1};
    
    while(!pq.empty()){
        int diff=pq.top().first;
        int ro=pq.top().second.first;
        int co=pq.top().second.second;
        pq.pop();
        
        if(ro==n-1 && co==m-1) return diff;
        for(int i=0;i<4;i++){
            int nro=ro+dro[i];
            int nco=co+dco[i];
            
            if(nro>=0&&nro<n &&nco>=0&&nco<m ){
                int effort=max(abs(he[nro][nco]-he[ro][co]),diff);
                if(effort<dist[nro][nco]){
                    dist[nro][nco]=effort;
                    pq.push({effort,{nro,nco}});
                }
            }
        }
    }
    return 0;

    }
};