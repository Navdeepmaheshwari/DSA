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
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL) return {};
        queue<TreeNode*> q;
        q.push(root);q.push(NULL);
        vector<int> level,ans;
        while(!q.empty()) {
            TreeNode* front=q.front();
            q.pop();
            if(front==NULL) {
                if(!q.empty()) q.push(NULL);
                int max=*max_element(level.begin(), level.end());
                level.clear();
                ans.push_back(max);  
            }else{
                level.push_back(front->val);
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            } 
        }
        return ans;
    }
};