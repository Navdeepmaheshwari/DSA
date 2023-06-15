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
    int maxLevelSum(TreeNode* root) {
        vector<int>levelSum;
        queue<TreeNode*>q;
        q.push(root);
            
        while(!q.empty()){
            int n=q.size();
            int sum=0;
            for(int i=0;i<n;i++){
                auto x=q.front();q.pop();
                sum+=x->val;
                if(x->left)q.push(x->left);
                if(x->right)q.push(x->right);
            }
            levelSum.push_back(sum);
        }
        int ind=max_element(levelSum.begin(),levelSum.end())-levelSum.begin();
        return ind+1;
    }
};