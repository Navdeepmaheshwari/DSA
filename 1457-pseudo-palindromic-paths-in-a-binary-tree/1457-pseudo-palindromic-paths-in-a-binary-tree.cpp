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
    void solve(TreeNode* root,vector<int> &vec,int &res)
    {
        if(root==NULL) return;
        vec[root->val]++;
        if(root->left==NULL and root->right==NULL)
        {
            int odd_count=0;
            for(int i=0;i<vec.size();i++)
            {
                if(vec[i]%2!=0)
                {
                    odd_count++;
                }
            }
            if(odd_count<=1) res++;
        }
        solve(root->left,vec,res);
        solve(root->right,vec,res);
        vec[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) 
    {
        vector<int> vec(10,0);
        int res=0;
        solve(root,vec,res);
        return res;
    }
};