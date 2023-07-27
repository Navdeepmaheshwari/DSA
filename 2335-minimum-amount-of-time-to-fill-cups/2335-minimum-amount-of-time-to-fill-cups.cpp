class Solution {
public:
    int fillCups(vector<int>& amount) {
        int sec=0;
        priority_queue<int>pq;
        for(auto x:amount){
            if(x>0)pq.push(x);
        }
        while(!pq.empty()&&pq.size()>1){
            
            sec++;
            int x=pq.top();
            pq.pop();
            
            int y=pq.top();
            pq.pop();
            
            if(x-1>0)pq.push(x-1);
            if(y-1>0)pq.push(y-1);
            
        }
        
        if(!pq.empty())sec+=pq.top();
        return sec;
    }
};