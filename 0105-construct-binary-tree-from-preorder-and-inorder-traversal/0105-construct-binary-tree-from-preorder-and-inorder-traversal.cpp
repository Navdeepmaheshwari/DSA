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
    unordered_map<int,int>mp;
    int curr=0;
      TreeNode*build(vector<int>& inorder, vector<int>& preorder,int st,int end){
          if(st>end)return NULL;
          TreeNode*root=new TreeNode(preorder[curr]);
          curr++;
          int ind=mp[root->val];
          
           //preorder:  root>left>right  
          //so we start from curr=0;
         root->left=build(inorder,preorder,st,ind-1);
        root->right=build(inorder,preorder,ind+1,end);
          return root;
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        for(int i=0;i<n;++i){
            mp[inorder[i]]=i;
        }
      return build(inorder,preorder,0,n-1);
    }
};