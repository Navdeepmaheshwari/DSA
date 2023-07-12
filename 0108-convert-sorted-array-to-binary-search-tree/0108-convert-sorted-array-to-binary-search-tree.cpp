/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode*solve(vector<int>& nums,int lo,int hi){
        
        if(lo<=hi){
            int mid=lo+(hi-lo)/2;
            TreeNode*root=new TreeNode(nums[mid]);
            
            root->left=solve(nums,lo,mid-1);
            root->right=solve(nums,mid+1,hi); 
         return root;
        }
        return NULL;
       
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
       return solve(nums,0,n-1);
    }
};