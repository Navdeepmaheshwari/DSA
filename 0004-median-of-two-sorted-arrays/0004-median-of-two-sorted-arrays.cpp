class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1=nums1.size(),l2=nums2.size();
        
        vector<int>merge(l1+l2);
        
        int i=0;
        int j=0;
        int k=0;
    
        while(i<l1 && j<l2)
        {
            if(nums1[i]==nums2[j])
            {
                merge[k++] = nums1[i++];
                merge[k++] = nums2[j++];                         
            }
            else if(nums1[i]>nums2[j])
            {
                merge[k++] = nums2[j++];
            }
            else
            {
                merge[k++] = nums1[i++];    
            }
        }

        while(i<l1)
        {
            merge[k++] = nums1[i++];
        }

        while(j<l2)
        {
            merge[k++] = nums2[j++];
        }
     
        
        for(auto x:merge){
            cout<<x<<" ";
        }
        cout<<endl;
        int n=l1+l2;
        double median;
        cout<<n<<endl;
        if(n%2==0){
            median=(merge[(n/2)-1]+merge[n/2])/2.0;
        }
        else{
            median= (double)merge[n/2];
        }
       
        return median;
    }
};