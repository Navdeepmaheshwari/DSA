//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string s)
{
    // your code here
    int n=s.size();
    int i=0,j=0;
    int freq[26]={0};
    int ans=0;
    while(j<n){
        
        freq[s[j]-'a']++;
        while(i<j&&freq[s[j]-'a']>1){
            freq[s[i]-'a']--;
            i++;
        }
        
        ans=max(ans,j-i+1);
        j++;
    }
    return ans;
}