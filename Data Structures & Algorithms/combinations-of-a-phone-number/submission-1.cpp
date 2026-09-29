// class Solution {
// public:
//     vector<string> res;
//     void solve(int index,string &digits,vector<string> &temp,unordered_map<char,string> &mp){
//         // base case
//         if(index>= digits.length()){
//             res.push_back(temp);
//             return;
//         }
//         // in the string
//         char ch = digits[idx];
//         string str = mp[ch];
//         for(int i=0;i<str.length();i++){
//             // taking 
//             temp.push_back(str[i]);
//             // explore
//             solve(index+1,digits,temp,mp);
//             // remove
//             temp.pop_back();
//         }
//     }
//     vector<string> letterCombinations(string digits) {
//         // start thingking man
//         // i need a temp string
//         string temp = "";
//         // make a map to store thw things
//         unordered_map<char,string> mp;
//         mp['2'] ="abc";
//         mp['3'] ="def";
//         mp['4'] ="ghi";
//         mp['5'] ="jkl";
//         mp['6'] ="mno";
//         mp['7'] ="pqrs";
//         mp['8'] ="tuv";
//         mp['9'] ="wxyz";
//         solve(0,digits,temp,mp);
//         return res;
//     }
// };

class Solution {
public:
    vector<string> result;
    
    void solve(int idx, string &digits, string &temp, unordered_map<char, string> &mp) {
        
        if(idx >= digits.length()) {
            result.push_back(temp);
            return;
        }
        
        
        char ch = digits[idx];
        string str = mp[ch];
        
        for(int i = 0; i<str.length(); i++) {
            
            //Do
            temp.push_back(str[i]);
            solve(idx+1, digits, temp, mp);
            temp.pop_back();
            
        }
        
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0)
            return {};
        
        unordered_map<char, string> mp;
        
        mp['2'] =  "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        
        string temp = "";
        
        solve(0, digits, temp, mp);
        
        return result;
    }
};