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
    void path(TreeNode* root, int targetSum, vector<vector<int>>&ans,vector<int>curr){
       if(!root)return;
       if(!root->left && !root->right){
            curr.push_back(root->val);
            if(targetSum == root->val)  ans.push_back(curr);
            return;
        }
        
        curr.push_back(root->val);

        path(root->left,targetSum-root->val,ans,curr);
        path(root->right,targetSum-root->val,ans,curr);

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>curr;
        path(root,targetSum,ans,curr);
        return ans;
    }
};