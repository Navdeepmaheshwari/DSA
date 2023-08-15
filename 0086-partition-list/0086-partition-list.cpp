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
    ListNode* partition(ListNode* head, int x) {
        ListNode*node1=new ListNode(0);
        ListNode*node2=new ListNode(0);
        ListNode*less=node1;
        ListNode*grt=node2;
        while(head!=NULL){
            if(head->val<x)
            {    
              node1->next=head;
              node1=node1->next;
              head=head->next;
              node1->next=NULL;
            }
            else{
                node2->next=head;
                node2=node2->next;
                head=head->next;
                node2->next=NULL;
                
            }
        }
        node1->next=grt->next;
        
        return less->next;
    }
};