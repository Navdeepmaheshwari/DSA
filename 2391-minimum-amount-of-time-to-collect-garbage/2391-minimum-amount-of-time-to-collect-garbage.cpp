class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int cnt=0;
         // unordered_map<char,int>mp;
        int garM=0,garP=0,garG=0;
        for(int i=0;i<garbage.size();i++){
            
           for(auto c:garbage[i]){
               
               cnt++;
                 if(c == 'M') garM = i;
                else if(c == 'G') garG = i;
                else garP = i;
           }
        }
        
        for(int i=1;i<travel.size();i++){
            travel[i]=travel[i-1]+travel[i];
        }
        
        if(garM>0){
            cnt+=travel[garM-1];
        }
         if(garP>0){
            cnt+=travel[garP-1];
        }
         if(garG>0){
            cnt+=travel[garG-1];
        }
        
        return cnt; 
    }
};