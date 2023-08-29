class Solution {
public:
  class DisjointSet{
    public:
      vector<int>parent;
      vector<int>size;
   
      DisjointSet(int n){
          parent.resize(n+1);
          size.resize(n+1,1);//inital size=1;
          //mark all as its parent initally
          for(int i=0;i<=n;i++){
              parent[i]=i;
          } 
      }
      
      int findParent(int node){
          
          if(node==parent[node]){
              return node;
          }
          return parent[node]=findParent(parent[node]);
      }
      
      void unionBySize(int u,int v){
          int ulp_u=findParent(u);
          int ulp_v=findParent(v);
          
          if(ulp_u==ulp_v)return;
         
          //chota size wala bdi size wali k attach hoga , chote ka parent bda wala or bde ki size increase;
          //agar size same hui to koi bhi kisi k bhi sath
          if(size[ulp_u]<size[ulp_v]){ 
              parent[ulp_u]=ulp_v;
              size[ulp_v]+=size[ulp_u];
          }
          else{
              parent[ulp_v]=ulp_u;
              size[ulp_u]+=size[ulp_v];
          }
      }   
  };
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        DisjointSet ds(n);
        int cntExtraEdges=0;
        int cntComponents=0;
        
        for(auto x:connections){
            
        //agar dono ka parent same h matalb phle se hi connected h so extra edge h
            if(ds.findParent(x[0])==ds.findParent(x[1])){
                cntExtraEdges++;
            }else{
                ds.unionBySize(x[0],x[1]);
            }
        }
        
        
        //count No of connected Components
        for(int i=0;i<n;i++){
        //agar kisi node ka parent vo khud h to mean vo root h uska component h
            if(ds.parent[i]==i){
                cntComponents++;
            }
        }
        
        int ans=cntComponents-1;
        if(cntExtraEdges>=ans)return ans;
        return -1;
    }
};