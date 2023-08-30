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
    void solve(TreeNode*root,int&cnt,int&ans,int k){
        if(!root)return;
       
        solve(root->left,cnt,ans,k);
        cnt++;
        
        if(cnt==k){
            ans=root->val;
            return;
        }
        
        solve(root->right,cnt,ans,k);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt=0;
        int ans;
        
        solve(root,cnt,ans,k);
        return ans;
    }
    
//      void inorder(TreeNode* root,vector<int> &v){
//             if(root==NULL)return;
//             inorder(root->left,v);
//             v.push_back(root->val);
//             inorder(root->right,v);
//     }
//     int kthSmallest(TreeNode* root, int k) {
//         vector<int> v;
//         inorder(root,v);
        
//         return v[k-1];
        
//     }
};