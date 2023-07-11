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
   void graph(TreeNode*root, unordered_map<int,vector<int>>&mp){
        if(!root) return;
        if(root->left){
            mp[root->val].push_back(root->left->val);
            mp[root->left->val].push_back(root->val);  
        }
        
        if(root->right){
            mp[root->val].push_back(root->right->val);
            mp[root->right->val].push_back(root->val); 
        }
        
        graph(root->left,mp);
        graph(root->right,mp);
    }
    int amountOfTime(TreeNode* root, int start) {
        
        unordered_map<int,vector<int>>mp; //convert tree to graph first
        int time=0;
        unordered_map<int,bool> vis;
        graph(root,mp);
        
        // for(auto x:mp){
        //     cout<<x.first<<">";
        //     for(auto y:x.second){
        //         cout<<y<<" ";
        //     }
        //     cout<<endl;
        // }
        
        queue<int>q;
        q.push(start);
        while(!q.empty()){
            int len=q.size();
            for(int i=0;i<len;i++){
                int node=q.front();q.pop();
                vis[node]=true;
                
                for(auto x:mp[node]){
                    if(!vis[x]){
                        q.push(x);
                    }
                }
            }
            time++; 
        }
        return time-1;
    }
};