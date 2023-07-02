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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL||k==0)return head;
        int n=1;
        ListNode*last=head;
        while(last->next){
            last=last->next;
            n++;
        }
        // cout<<last->val<<endl;
        
        //first make it circular
        last->next=head;
        
        k=k%n;
        for(int i=0;i<n-k;i++){
            last=last->next;
        }
        
        head=last->next;
        last->next=NULL;
        
        return head;
    }
    
};