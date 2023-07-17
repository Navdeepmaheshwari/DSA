class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n=s.size();
        vector<int>ans;
        vector<int>cnt(n,0);
        vector<int>left(n,-1),right(n,-1);
       
        for(int i=0;i<n;i++){
            
            if(i==0){
                if(s[i]=='*')cnt[i]=1;
                if(s[i]=='|')left[i]=i;
            }
            else{
                if(s[i]=='*'){
                    cnt[i]=1+cnt[i-1];
                }else{
                    cnt[i]=0+cnt[i-1];
                }
                
                if(s[i]=='|'){
                    left[i]=i;
                }else{
                 left[i]=left[i-1];
                }
            }
            
        }
        
        for(int i=n-1;i>=0;i--){
            if(i==n-1){
                if(s[i]=='|')right[i]=i;
            }
            else{
                
                if(s[i]=='|')right[i]=i;
                else right[i]=right[i+1];
            }
        }
        
//         for(int i=0;i<n;i++){
//             cout<<left[i]<<" "<<right[i]<<" "<<cnt[i]<<endl;
//             // cout<<left[i]<<" "<<cnt[i]<<endl;

//         }
        
        for(auto x:queries){
            int start=right[x[0]];
            int end=left[x[1]];
            if(start==-1||end==-1||start>=end)ans.push_back(0);
            else ans.push_back(cnt[end]-cnt[start]);
        }
       
        
        return ans;
    }
};