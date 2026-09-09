// class Solution {
// public:
//     int characterReplacement(string s, int k) {
//         int res = 0;
//         unordered_set<char> charset(s.begin(),s.end());
//         for(char c :charset){
//             int count =0,l=0;
//             for(int r=0;r<s.size();r++){
//                 if(s[r]==c) count++;

//                 while((r-l+1) - count > k){
//                     if(s[l]==c) count--;
//                     l++;
//                 }
//                 res = max(res,r-l+1);
//             }

//         }
//         return res;
//     }
// };

class Solution {
public:
    int characterReplacement(string s, int k) {
         int n = s.length();
        int freq[26] = {0};

        int maxLen = 0;
        int maxFreq = 0;
        int left = 0, right = 0;

        while (right < n) {
            char ch = s[right];

            freq[ch - 'A']++;
            maxFreq = max(maxFreq, freq[ch - 'A']);

            if ((right - left + 1) - maxFreq > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
            right++;
        }

        return maxLen;
    }
};