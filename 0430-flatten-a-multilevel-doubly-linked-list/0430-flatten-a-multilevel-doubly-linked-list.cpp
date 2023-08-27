/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head)return head;
        Node*curr=head;
        stack<Node*>st;
        
        st.push(head);
        
        while(!st.empty()){
            Node*node=st.top();
            st.pop();
            
            if(node->next)st.push(node->next);
            if(node->child)st.push(node->child);
            
            if(!st.empty()){
                node->next=st.top();
                st.top()->prev=node;
            }
            node->child=NULL;
        }
        
        return curr;
        
    }
};