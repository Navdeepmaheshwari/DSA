class Solution {
public:
    void merge(vector<int>&count,vector<pair<int,int>> &v,int low,int mid,int high){
        int i=low,j=mid+1;
        int cnt=0;
        int k=0;
        vector<pair<int, int>>temp(high-low+1);
        while(i<=mid&&j<=high){
            if(v[i].first<=v[j].first){
                count[v[i].second] += cnt;
                temp[k++]=v[i++];
            }
            else{
               cnt++;
               temp[k++]=v[j++];
            }
        }
        
        while(i<=mid){
             count[v[i].second] += cnt;
            temp[k++]=v[i++];
        }
        
         while(j<=high){
             temp[k++]=v[j++];
        }
        
          for (int i = low; i <= high; i++) 
          {
            v[i] = temp[i - low];
          }
    }
    
    void mergeSort(vector<int>&count,vector<pair<int,int>> &v,int low,int high){
        
        if(high>low){
            int mid=low+(high-low)/2;
            mergeSort(count,v,low,mid);
            mergeSort(count,v,mid+1,high);
            
            merge(count,v,low,mid,high);
        }
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int> > v(n);
        for (int i = 0; i < n; i++)   
            v[i] = {nums[i], i};

        vector<int> count(n, 0);
        mergeSort(count, v, 0, n-1);

        return count;
    }
};