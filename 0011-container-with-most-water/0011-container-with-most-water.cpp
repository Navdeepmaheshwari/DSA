class Solution {
public:
    int maxArea(vector<int>& height) {
        int mxarea=0;
        int p1=0;
        int p2=height.size()-1;
        
        while(p1<p2){
            
            int h=min(height[p1],height[p2]);
            int currarea=h*(p2-p1);
             mxarea=max(mxarea, currarea);
            
            while(height[p1]<=h && p1<p2) p1++;
            while(height[p2]<=h && p1<p2) p2--;
        }
        return mxarea;
        
    }
};