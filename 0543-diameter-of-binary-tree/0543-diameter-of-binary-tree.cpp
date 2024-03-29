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
    int diameter=0;
    int dfs(TreeNode*root){
        if(!root)return 0;
        int l=dfs(root->left);
        int r=dfs(root->right);
        // cout<<l<<" "<<r<<endl;
        diameter=max(diameter,l+r);
        return max(l,r)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        dfs(root);
        return diameter;
    }
};