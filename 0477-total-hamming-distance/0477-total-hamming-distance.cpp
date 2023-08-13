class Solution {
public:
    //O(32*N)
        int totalHammingDistance(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<32;i++){
            int one=0,zero=0;
            for(auto num:nums){
               
                if(num&(1<<i)){
                    one++;
                }
                else{
                    zero++;
                }
                
            }
            sum+=(one*zero);
        }
        
        return sum;
    }
    
    //O(N^2k) k is set bits
//     int totalHammingDistance(vector<int>& nums) {
//         int sum=0;
//         int n=nums.size();
//         for(int i=0;i<n;i++){
            
//             for(int j=i+1;j<n;j++){
                
//                 int a=nums[i],b=nums[j];
//                 int XOR=a^b;
//                 int cnt=0;
                
//                 while(XOR){
//                    cnt+=XOR&1;
//                    XOR= XOR>>1;     
//                 }
                
//                 sum+=cnt;
                
//             }
//         }
        
//         return sum;
//     }
};