class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        
        priority_queue<int,vector<int>,greater<>>pq;
        int maxDay=INT_MIN;
        for(auto x:events){
           maxDay=max(maxDay,x[1]); 
        }
        int cnt=0;
        int j=0;
        for(int i=1;i<=maxDay;i++){
        while(!pq.empty()&&pq.top()<i) { // end day is less than the current day
              pq.pop();
         } 
        
        while(j<events.size() && events[j][0]==i)// put all events start at day i
        { 
            pq.push(events[j][1]);
            j++;
        }
    
        if(!pq.empty())// we can attend an event today
        {
                pq.pop();// remove the event
                cnt++;// count that event
        }
          
        }
        return cnt;
    }
};