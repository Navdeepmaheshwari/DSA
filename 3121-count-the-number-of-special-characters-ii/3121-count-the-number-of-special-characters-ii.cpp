class Solution {
public:
    int numberOfSpecialChars(string word) {
         vector<int> lower(26, -1), upper(26, -1);
        for (int i=0;i<word.size();i++)
        {
            if (isupper(word[i]))
            {
                if(upper[word[i]-'A']==-1)  upper[word[i] - 'A']=i;
            }
            else{ 
                lower[word[i] - 'a']=i;
            }
        }
        
        // for(auto x:lower){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        //  for(auto x:upper){
        //     cout<<x<<" ";
        // }
        // cout<<endl;

        int res = 0;
        for (int i = 0; i < 26; i++)
        {
            if (lower[i] != -1 && upper[i] != -1 && upper[i]>lower[i])
            {
                res++;
            }
        }

        return res;
    }
};