class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int cnt=0;
        int n=tickets.size();
        while(true){
           
            for(int i=0;i<n;i++){
              
                if(tickets[i]>0){
                    tickets[i]--;
                    cnt++;
                }
                
            if(i==k && tickets[i]==0)return cnt;
            }
        }
        return 0;
    }
};