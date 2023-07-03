//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	vector<pair<int, int>> train(n);
        for(int i=0;i<n;i++){
            train[i]={arr[i], dep[i]};
        }
        sort(train.begin(), train.end());
        priority_queue<int, vector<int>, greater<int>> waiting;
        
        int curr=0, res=0;
        for(int i=0;i<n;i++){
            while(!waiting.empty() && waiting.top()<train[i].first){
                curr--;
                waiting.pop();
            }
            curr++;
            res=max(res, curr);
            waiting.push(train[i].second);
        }
        return res;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends