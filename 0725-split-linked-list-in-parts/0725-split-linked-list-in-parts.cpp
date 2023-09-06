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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode*curr=head;
        vector<ListNode*>ans(k,NULL);
        if(!head)return ans;
        int len=0;
        while(curr){
            len++;
            curr=curr->next;
        }
        // cout<<len<<endl;
        
        int n=len/k; //length of each part
        int extraNode=len%k;
        
        ListNode*prev=NULL;
        curr=head;
        for(int i=0;i<k;i++){
            
            ans[i]=curr;
            
            //if we have extrNode then we run to n+1(length of part+1);
            if(extraNode>0){
                for(int j=0;j<n+1;j++){
                   prev=curr;
                    curr=curr->next;
                }
                
                prev->next=NULL;
            }
            
            // else we run to only n(length of part)
            else{
                for(int j=0;j<n;j++){
                     prev=curr;
                     curr=curr->next;
                }
                prev->next=NULL;
            }
            
            extraNode--; //decrease extraNodes
            
        }
        return ans;
    }
};