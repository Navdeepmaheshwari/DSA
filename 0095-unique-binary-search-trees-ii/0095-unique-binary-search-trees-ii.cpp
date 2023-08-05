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
    vector<TreeNode*>solve(int s,int e){
        vector<TreeNode*>ans;
        //base
        if(s>e)return {NULL};
        if(s==e)return {new TreeNode(s)};
        
        
        for(int i=s;i<=e;i++){
            vector<TreeNode*>left=solve(s,i-1); //left
            vector<TreeNode*>right=solve(i+1,e); //right
            
              for (auto l : left){
                 for (auto r : right){
                     TreeNode*node=new TreeNode(i);
                     node->left=l;
                     node->right=r;
                     ans.push_back(node);
                } 
              }
                
                   
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        
        return solve(1,n);
    }
};