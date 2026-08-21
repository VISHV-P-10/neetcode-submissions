// class Solution {
// public:
//     bool isPalindrome(string s) {
//         // remove the spaces
//         erase(s,' ');
//         // now assign two pointers
//         int i = 0;
//         int j = s.size()-1;

//         while(i<=j){
//             if(s[i]!=s[j]) return false;
//             i++; j--;
//         }
//         return true;
//     }
// };

class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.length() - 1;

        while (l < r) {
            while (l < r && !alphaNum(s[l])) {
                l++;
            }
            while (r > l && !alphaNum(s[r])) {
                r--;
            }
            if (tolower(s[l]) != tolower(s[r])) {
                return false;
            }
            l++; r--;
        }
        return true;
    }

    bool alphaNum(char c) {
        return (c >= 'A' && c <= 'Z' ||
                c >= 'a' && c <= 'z' ||
                c >= '0' && c <= '9');
    }
};
