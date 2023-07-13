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
    void traverse(TreeNode*root,unordered_map<int,int>&mp){
        if(root){
            mp[root->val]++;
            traverse(root->left,mp);
            traverse(root->right,mp);
        }
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int>mp; //node,cnt
        traverse(root,mp);
        
        //finding maximum cnt;
        priority_queue<pair<int,int>>pq;
        for(auto x:mp){
            pq.push({x.second,x.first});
        }
        
        int mx=pq.top().first;
        vector<int>ans;
        while(!pq.empty()&&pq.top().first==mx){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};