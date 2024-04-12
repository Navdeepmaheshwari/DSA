class Solution {
public:
    int trap(vector<int>& height) {
       int n=height.size(),ans=0;
       vector<int>lmax(n),rmax(n);
        lmax[0]=height[0];
        rmax[n-1]=height[n-1];
        for(int i=1; i<n-1; i++)
        {
            lmax[i]=max(height[i],lmax[i-1]);
        }
        for(int i=n-2; i>=0; i--)
        {
            rmax[i]=max(height[i],rmax[i+1]);
        }
        for(auto x:lmax)cout<<x<<" ";
        cout<<endl;
        for(auto x:rmax)cout<<x<<" ";
        cout<<endl;
        for(int i=1; i<n-1; i++)
        {
            ans = ans + (min(lmax[i],rmax[i])-height[i]);
        }
        return ans;
        
    }
};