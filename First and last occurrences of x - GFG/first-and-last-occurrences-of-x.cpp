//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> find(int nums[], int n , int target )
    {
        // code here\
         int n=nums.size();
        int l=0,h=n-1;
        int i=-1,j=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(nums[mid]==target){
               int temp=mid;
                while(mid>0&&nums[mid-1]==target){
                    mid--;
                }
                i=mid;
                
                while(temp<n-1&&nums[temp+1]==target){
                    temp++;
                }
                j=temp;
                return {i,j};
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
            else{
               h=mid-1; 
            }
        }
        return {i,j};
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends