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
    void reorderList(ListNode* head) {
        vector<ListNode*>temp;
        ListNode*curr=head;
        while(curr){
           temp.push_back(curr);
           curr=curr->next;
        }
        
        int n=temp.size();
        int l=1,r=n-1;
        
        for(int i=1;i<n;i++){
            if(i%2){
                head->next=temp[r--];
            }
            else{
                head->next=temp[l++];
            }
            head=head->next;
        }
        
        head->next=NULL;
        
    }
};