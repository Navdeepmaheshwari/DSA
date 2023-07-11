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
    int curi;
    TreeNode*build(vector<int>& inorder, vector<int>& postorder,int st,int end){
        if(st > end) return NULL;
        TreeNode*root=new TreeNode(postorder[curi]); //root
        //finding the root index in inorder using map
        int i=mp[root->val]; 
        curi--;  
        
        //postorder:  left>right>root 
        //so we start from curr=n-1;
        root->right=build(inorder,postorder,i+1,end);
        root->left=build(inorder,postorder,st,i-1);
      
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
       curi=postorder.size()-1;
        for(int i=0;i<inorder.size();++i){
            mp[inorder[i]]=i;
        }
        
        return build(inorder,postorder,0,inorder.size()-1);
    }
};