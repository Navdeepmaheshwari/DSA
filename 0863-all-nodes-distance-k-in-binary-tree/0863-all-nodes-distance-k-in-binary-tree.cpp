/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
         if(k==0)
            return {target->val};
        
        unordered_map<int,vector<int>>mp; //adjacency list
        vector<int>ans;
        unordered_map<int,bool> vis;
        graph(root,mp);
        // for(auto x:mp){
        //     cout<<x.first<<">";
        //     for(auto y:x.second){
        //         cout<<y<<" ";
        //     }
        //     cout<<endl;
        // }
        
        //Now do bfs traversal
        queue<int>q;
        q.push(target->val);
        while(!q.empty()){
            
            if(k==0){
                break;
            }
            
            k--;
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
            
        }
        
        //queue contains the nodes val which is at distance k
        while(!q.empty()){
           ans.push_back(q.front());q.pop(); 
        }
        return ans;
        
    }
};