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
    bool chk(TreeNode*root,long long int min,long long int max){
        if(!root)return true;
        int val=root->val;
       
        if(val<=min||max<=val)return false;
        
        return chk(root->left,min,val)&&chk(root->right,val,max);
    }
    bool isValidBST(TreeNode* root) {
        
        long long int min=-2147483649;
        long long int max=2147483648;
        
        return chk(root,min,max);
    }
};