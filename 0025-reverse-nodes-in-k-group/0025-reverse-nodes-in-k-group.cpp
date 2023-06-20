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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len=0;
        ListNode*temp=head;
        ListNode*list=new ListNode(0); //dummylist
        list->next=head;
        
        ListNode*prev=list,*curr=list,*nex=list;
        
        while(temp){
            temp=temp->next;
            len++;
        }
        // cout<<len;
        
        if(len<k)return head;
        
        while(len>=k){
            curr=prev->next; //prev ka agla curr
            nex=curr->next;   //curr ka agla nex
            for(int i=1;i<k;i++){
                curr->next=nex->next;
                nex->next=prev->next;
                prev->next=nex;
                nex=curr->next;
                
            }
            prev=curr;   
          len=len-k;
        }
        
        return list->next;
        
    }
};