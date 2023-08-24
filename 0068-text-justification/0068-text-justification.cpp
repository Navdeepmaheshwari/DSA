class Solution {
public:
    vector<string> fullJustify(vector<string>& w, int maxW) {
        int n=w.size();
        vector<string>ans;
         int currLen = 0;
        int cntWord = 0;
        int j = 0;
        for(int i=0;i<n;i++){
            
            if(currLen+w[i].size()+cntWord<=maxW){
                currLen+=w[i].size();
                cntWord++;
            }
            else{
                string temp = "";
                int totalSpaces = maxW - currLen;
                int spaces = cntWord > 1 ? totalSpaces / (cntWord - 1) : totalSpaces;
                int extra = cntWord > 1 ? totalSpaces % (cntWord - 1) : 0;
                
                
                while (j < i) {
                    temp += w[j++];
                    if (j < i) {
                        int space_to_add = spaces + (extra-- > 0 ? 1 : 0);
                        temp += string(space_to_add, ' ');
                        totalSpaces -= space_to_add;
                    }
                }
                
                if (cntWord == 1) {
                    temp += string(totalSpaces, ' ');
                }

                ans.push_back(temp);
                j = i;
                currLen = 0;
                cntWord = 0;
                i--;  
            }
        }
        
            string temp = "";
            int len = 0;
            while (j < n) {
                len += w[j].length();
                temp += w[j++];
                if (j < n) {
                    temp += " ";
                    len++;
                }
            }

            temp += string(maxW - len, ' ');
            ans.push_back(temp);

        return ans;
    }
};