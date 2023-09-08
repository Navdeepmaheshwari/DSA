class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int p1=0;
        int p2=n-1;
        int maxx=INT_MIN;
        
        while(p1<p2){
            int h=min(height[p1],height[p2]);
            int currArea=h*(p2-p1);
            maxx=max(maxx,currArea);
            
            // p1++;
            // p2--;
            if(height[p1]<=height[p2])p1++;
            else p2--;
        }
        
        return maxx;
    }
};