class Solution {
public:
    bool checkInclusion(string s1, string s2) {
         int n= s1.length();
         int m = s2.length();
        // if(n>m) return false;
        // sort(begin(s1),end(s1));
        // for(int i=0;i<=m-n;i++){
        //     string substring = s2.substr(i,n);
        //     sort(substring.begin(),substring.end());
        //     if(s1==substring){
        //         return true;
        //     }
        // }
        // return false;

        vector<int> freq_s1(26,0);
        vector<int> freq_s2(26,0);
        // store this shit for the s1
        for(char &ch:s1){
            freq_s1[ch-'a']++;
        }
        int i=0;
        int j=0;
        while(j<m){
            freq_s2[s2[j]-'a']++;
            // that condition of window size
            if(j-i+1 > n){
                freq_s2[s2[i]-'a']--;
                i++;
            }
            if(freq_s1 == freq_s2) return true;
            j++;
        }
        return false;
    }
};
