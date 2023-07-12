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
    TreeNode* bst(vector<int>&pre,int &ind,int min,int max){
        
        if(ind>=pre.size())return NULL;
        int val=pre[ind];
        if(val>=max || val<=min)return NULL;
        
        TreeNode*root=new TreeNode(val);
       ind=ind+1;
        root->left=bst(pre,ind,min,val);
        root->right=bst(pre,ind,val,max);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
      int ind=0;
        return bst(preorder,ind,INT_MIN,INT_MAX);
        
    }
};