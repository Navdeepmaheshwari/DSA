class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool>ans;
        int n=l.size();
        for(int i=0;i<n;i++){
            
            int start=l[i];
            int end=r[i];
            bool res=true;
           vector<int>temp(nums.begin()+start,nums.begin()+end+1);
            sort(temp.begin(),temp.end());
            int j=0;
            for(j=2;j<temp.size();j++){
                
                if(temp[j]-temp[j-1] != temp[1]-temp[0]){
                    res=false;
                }
            }
            
            ans.push_back(res);
        }
        return ans;
    }
};