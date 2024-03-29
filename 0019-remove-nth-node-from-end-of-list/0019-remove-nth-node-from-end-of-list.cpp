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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*curr=head,*prev=NULL;
        int size=0;
        while(curr){
            size++;
            curr=curr->next;
        }
        curr=head;
        n=size-n;
        if(!n)return head=head->next;
        while(n--){
            prev=curr;
            curr=curr->next;
        }
        
        prev->next=curr->next;
        // cout<<size<<endl;
        return head;
    }
};