//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countFractions(int n, int nu[], int de[])
    {
        unordered_map<double ,int>mp;
        int cnt=0;
        for(int i=0;i<n;i++){
            double a=1.0*nu[i]/de[i];
            // double b=1-a;
            double b= (de[i] - nu[i])*1.0/de[i];
            // cout<<a<<" "<<b<<endl;
            if(mp.find(b)!=mp.end()){
                cnt+=mp[b];
            }
            
            mp[a]++;
        }
        
        // for(auto x:mp){
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        return cnt;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends