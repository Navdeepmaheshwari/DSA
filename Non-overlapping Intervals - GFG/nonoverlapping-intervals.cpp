//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
      bool static comp(vector<int>&a,vector<int>&b){
        if(a[1]==b[1])return a[0]<b[0];
        return a[1]<b[1];
    }
    int minRemoval(int n, vector<vector<int>> &inter) {
        // code here
         sort(inter.begin(),inter.end(),comp);//sort on the basis of end points
        int cnt=0;

        vector<int>prev=inter[0];
        for(int i=1;i<n;i++){
         
            if(prev[1]>inter[i][0])cnt++;
            else prev=inter[i];
        }
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        Solution obj;
        cout << obj.minRemoval(N, intervals) << endl;
    }
    return 0;
}
// } Driver Code Ends