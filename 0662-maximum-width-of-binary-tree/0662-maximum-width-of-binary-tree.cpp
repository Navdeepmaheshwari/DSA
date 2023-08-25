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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        long long ans=1;
        
        while(!q.empty()){
            
            long long sz=q.size(); 
            long long startInd=q.front().second;
            long long endInd=q.back().second;
            ans=max(ans,endInd-startInd+1);
            while(sz>0){
                auto node=q.front();
                q.pop();
               
                TreeNode*curr=node.first;
                long long idx=node.second-startInd; //for overflow handle
                
                if(curr->left){
                    q.push({curr->left,2*idx+1});
                }
                if(curr->right){
                    q.push({curr->right,2*idx+2});
                }
                sz--;
            }
            
        }
        
        return ans;
    }
};