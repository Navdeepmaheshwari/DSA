class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& ast) {
        sort(ast.begin(),ast.end());
        int n=ast.size();
        long long curr=mass;
        for(int i=0;i<n;i++){
            if(ast[i]<=curr){
                curr+=ast[i];
            }
            else return false;
        }
        return true;
    }
};