/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        ListNode*temp=new ListNode(0);
        temp->next=head;
        ListNode*prev=temp;
        
        // cout<<prev->val<<endl;
        for(int i=1;i<left;i++){
            prev=prev->next;
        }
        // cout<<prev->val<<endl;
        ListNode*curr=prev->next;
        
        for(int i=0;i<right-left;i++){
            ListNode*next=curr->next;
            curr->next=next->next;
            next->next=prev->next;
            prev->next=next;
        }
        
       
        return temp->next;
    }
};