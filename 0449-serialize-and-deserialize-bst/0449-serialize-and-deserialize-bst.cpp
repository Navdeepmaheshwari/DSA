/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)return "";
        
        string encode="";
        //Using Level Order Traversal
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode*curr=q.front();
            q.pop();
            
            if(curr==NULL){
                encode.append("#,");;
            }else{
                encode.append(to_string(curr->val)+',');;
            }
            
            if(curr!=NULL){
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        // cout<<encode<<endl;
        return encode;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int n=data.size();
        if(n==0)return NULL;
        int ind=0;
        string curr="";
        queue<TreeNode*>q;
        while(ind<n&&data[ind]!=','){
            curr+=data[ind++];
        }
        // cout<<curr<<endl;
        
        TreeNode* root = new TreeNode(stoi(curr));
        q.push(root);
        
        while(!q.empty()){
            TreeNode*node=q.front();
            q.pop();
            curr="";
            ind++;
            while(ind<n&&data[ind]!=','){
                curr+=data[ind++];
            }
            
            // cout<<curr<<endl;

            if(curr == "#") {
                node->left = NULL; 
            }
            else {
                TreeNode* leftNode = new TreeNode(stoi(curr)); 
                node->left = leftNode; 
                q.push(leftNode); 
            }
            
            curr="";ind++;
            while(ind<n&&data[ind]!=','){
                curr+=data[ind++];
            }
            
            // cout<<curr<<endl;

             if(curr == "#") {
                node->right = NULL; 
            }
            else {
                TreeNode* rightNode = new TreeNode(stoi(curr)); 
                node->right = rightNode; 
                q.push(rightNode); 
            }
            
        }
        return root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;