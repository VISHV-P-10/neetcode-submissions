class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // just need to sort this hoe in lexicographical order

        int n = strs.size();
        sort(strs.begin(),strs.end());
        // need to compare the first string and last string
        if(strs.size()==0) return "";
        if(strs.size()==1) return strs[0];
        string first = strs[0];
        string last= strs[n-1];
        // need to find the minimiun lenghts among these two strings
        // cuz for the loop itself
        int mini = min(first.length(),last.length());
        string ans="";
        for(int i=0;i<mini;i++){
            if(first[i]==last[i]) ans+=first[i];
            else break;
        }
        return ans;
    }
};