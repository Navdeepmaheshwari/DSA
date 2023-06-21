/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode*curr=node;
        ListNode*temp=curr->next;
        
        swap(curr->val,temp->val);
        curr->next=temp->next;
        delete(temp);
    }
};