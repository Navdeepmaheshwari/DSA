class Solution {
public:
    bool static cmp(vector<int> &a,vector<int> &b){
        if(a[1]==b[1]){
            return a[0]<b[0];
        }
        return a[1]<b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),cmp); //Sort on the basis of last day.
        priority_queue<int>pq;
        int total=0;
        
        for(auto x:courses){
            if(total+x[0]<=x[1]){
                total+=x[0];
                pq.push(x[0]);
            }
            else{
                
                if(!pq.empty()&&pq.top()>x[0]){
                    total-=pq.top();
                    pq.pop();
                    total+=x[0];
                    pq.push(x[0]);
                }
            }
        }
        return pq.size();
    }
};