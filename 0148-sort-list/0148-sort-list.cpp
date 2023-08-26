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
    ListNode* sortList(ListNode* head) {
        priority_queue<int,vector<int>,greater<>>pq;
        ListNode*curr=head;
        while(curr){
            pq.push(curr->val);
            curr=curr->next;
        }
        
        curr=head;
        while(curr){
            int val=pq.top();pq.pop();
            curr->val=val;
            curr=curr->next;
        }
        return head;
    }
};