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
    int sum(TreeNode*root,int summ){
        if(root==NULL)return 0;
        summ=summ*10+root->val;
        // cout<<summ<<endl;
        if(root->left==NULL&&root->right==NULL){
            return summ;
        }
       
        int left=sum(root->left,summ);
        int right=sum(root->right,summ);
        
        return left+right;
    }
    int sumNumbers(TreeNode* root) {
        int summ=0;
        return sum(root,summ);
    }
};