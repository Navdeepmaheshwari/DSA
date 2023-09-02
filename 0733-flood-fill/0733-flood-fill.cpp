class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,-1,0,1};
    void fill(vector<vector<int>>& image, int sr, int sc, int color,int m,int n,int&curr){
        if(sr<0||sr>=m||sc<0||sc>=n||curr!=image[sr][sc]||image[sr][sc]==color)return;
        int temp=image[sr][sc];
        image[sr][sc]=color;
        
        for(int i=0;i<4;i++){
            int nx=sr+dx[i],ny=sc+dy[i];
            fill(image,nx,ny,color,m,n,temp);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int m=image.size(),n=image[0].size();
        fill(image,sr,sc,color,m,n,image[sr][sc]);
        return image;
    }
};