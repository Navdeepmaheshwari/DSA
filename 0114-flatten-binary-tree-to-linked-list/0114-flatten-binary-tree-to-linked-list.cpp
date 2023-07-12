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
    void flatten(TreeNode* root) {
        if(!root)return;
        stack<TreeNode*>st;
        st.push(root);
        
        while(!st.empty()){
            TreeNode*node=st.top();st.pop();
        
           //first push right and then left because we need left first (pre-order traversal)
            if(node->right)st.push(node->right);
            if(node->left)st.push(node->left);
            
            if(!st.empty())node->right=st.top();
            node->left=NULL;
        }
        
    }
};