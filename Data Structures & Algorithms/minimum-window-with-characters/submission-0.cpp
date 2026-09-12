class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        if(t.length()>n){
            return "";
        }
        map<char,int> mp;
        for(char &ch : t){
            mp[ch]++;
        }

        int reqcount = t.length();
        int i=0,j=0;
        int min_win_size = INT_MAX;
        int start_i=0;

        // story start
        while(j<n){
            char ch = s[j];
            if(mp[ch]>0)
                reqcount--;
            mp[ch]--;

            while(reqcount==0){
                int curr_win_size = j-i+1;
                if(min_win_size>curr_win_size){
                    min_win_size = curr_win_size;
                    start_i = i;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0){
                    reqcount++;
                }
                i++;
            }
            j++;
        }
        return min_win_size==INT_MAX?"":s.substr(start_i,min_win_size);
    }
};
