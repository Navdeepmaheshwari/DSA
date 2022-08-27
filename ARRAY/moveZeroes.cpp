 #include <bits/stdc++.h>
using namespace std;
 void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0 ){
               nums[res]=nums[i];
                res++;
            }
        }
        for (int i = res; i < n; i++)
        {
           nums[i]=0;
        }
        
    }

int main(){
    vector<int> nums={0,1};
    moveZeroes(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout<<nums[i]<<" ";
    }
    return 0;
}