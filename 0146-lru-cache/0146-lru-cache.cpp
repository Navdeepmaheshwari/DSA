class LRUCache {
public:
    //Doubly Linked List
    class ListNode {
    public:
        int key;
        int val;
        ListNode*next;
        ListNode*prev;
        
        ListNode(int key,int val){
            this->key=key;
            this->val=val;
            this->next=NULL;
            this->prev=NULL;
        }
    };

    int size=0;
    unordered_map<int,ListNode*>mp;
    
    ListNode*head=new ListNode(0,0);
    ListNode*tail=new ListNode(0,0);

    LRUCache(int capacity) {
        size=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    void add(ListNode*curr){
        //adding node between head and head->next;
        curr->next=head->next;
        head->next->prev=curr;
        curr->prev=head;
        head->next=curr;
        mp[curr->key]=curr;
    }
    
    void remove(ListNode*curr){
        mp.erase(curr->key);
        curr->prev->next=curr->next;
        curr->next->prev=curr->prev;
    }
    
    
    int get(int key) {
        
        if(mp.find(key)==mp.end())return -1;
        
        ListNode*curr=mp[key];
        remove(curr);
        add(curr);
        return curr->val;
    }
    
    void put(int key, int value) {
        
        if(mp.find(key)!=mp.end()){
            remove(mp[key]);
        };
        
        if(mp.size()==size){
            remove(tail->prev);//beacuse we insert from right to left;
        }
        
        ListNode*temp=new ListNode(key,value);
        add(temp);

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
