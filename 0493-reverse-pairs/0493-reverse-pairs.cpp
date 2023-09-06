class Solution {
public:
     void merge(vector<int>&nums,int low,int mid,int high,int&cnt){
         
         //for every left check with right and left to mid and mid+1 to right are sorted array
         int right=mid+1;
         for(int left=low; left<=mid; left++){
            while(right<=high && nums[left] > 2*(long long)nums[right]){
                right++;
            }
            cnt += right-(mid+1);
        }
         
        int i=low,j=mid+1;
        vector<int>temp;
        while(i<=mid&&j<=high){
            if(nums[i]<=nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else{
               temp.push_back(nums[j]);
                j++; 
            }
        }
        
        while(i<=mid){
            temp.push_back(nums[i]);
            i++;
        }
        
         while(j<=high){
            temp.push_back(nums[j]);
            j++;
        }
        
          for (int i=low; i<=high; i++) 
          {
            nums[i] = temp[i-low];
          }
    }
    
     void mergeSort(vector<int>&nums,int low,int high,int&cnt){
        
        if(high>low){
            int mid=low+(high-low)/2;
            mergeSort(nums,low,mid,cnt);
            mergeSort(nums,mid+1,high,cnt);
            
            merge(nums,low,mid,high,cnt);
        }
    }
    
    int reversePairs(vector<int>& nums) {
        int cnt=0;
        int n=nums.size();
        mergeSort(nums,0,n-1,cnt);
        return cnt;
    }
};