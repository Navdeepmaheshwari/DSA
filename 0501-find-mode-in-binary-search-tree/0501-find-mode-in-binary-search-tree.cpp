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
    int mx = INT_MIN;
    void traverse(TreeNode*root,unordered_map<int,int>&mp){
        if(root){
            mp[root->val]++;
            mx=max(mx,mp[root->val]);
            traverse(root->left,mp);
            traverse(root->right,mp);
        }
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int>mp; //node,cnt
        traverse(root,mp);
        
        vector<int>ans;
        for(auto x:mp){
            if(x.second==mx){
                ans.push_back(x.first);
            }
        }

        return ans;
    }
};