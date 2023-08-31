class Solution {
public:
    int eatenApples(vector<int>& ap, vector<int>& d) {
        int n=ap.size();
        
        priority_queue< pair<int,int>, vector<pair<int,int>> ,greater<>>pq;
        int maxi=0;

        for(int i=0; i<n; i++){
            maxi=max(maxi,i+d[i]);
        }
        cout<<maxi<<endl;

        // for(int i=0;i<n;i++){
        //     if(ap[i]>0) pq.push({d[i]+i,ap[i]});  //rot day, no of apples
        // }
        
        
        int cnt=0;
        for(int day=0;day<maxi;day++){
            
            if(!pq.empty()&&pq.top().first<=day)pq.pop();
           
            if(day<n&&ap[day]>0) pq.push({d[day]+day,ap[day]});
            
            if(!pq.empty())
            {
                int x=pq.top().first;
                int y=pq.top().second;
                pq.pop();
                // cout<<x<<" "<<y<<" "<<cnt<<endl;

                if(y>0)cnt++;
                y--;
                if(y>0)pq.push({x,y});
            }
        }
        
        return cnt;
        
    }
};