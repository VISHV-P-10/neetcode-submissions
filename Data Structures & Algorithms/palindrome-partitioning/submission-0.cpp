// class Solution {
// public:
//     int size;
//     bool check(string s, int l,int r){
//         // start from i and end to the idx
//         // int l=i;
//         // int r = idx;
//         while(l<=r){
//             if(s[l]!=s[r]){
//                 return false;
//             }
//             l++;
//             r--;
//         }
//         return true;
//     }
//     void solve(string &s, int index, vector<char> &curr,vector<vector<string>>&res){
//         // base case
//         if(index==size){
//             res.push_back(curr);
//             return ;
//         }
//         // need to travers in the loop
//         for(int i=index;i<size;i++){
//             if(check(s,idx,i)){
//                 curr.push_back(s.substr(i,idx-i+1));
//                 solve(s,idx+1,curr);
//                 curr.pop_back();
//             }
//         }
//     }
//     vector<vector<string>> partition(string s) {
//         // making a dummy string to store the answers
//         size = s.length();
//     vector<vector<string>> res;
//         vector<string> curr;
//         solve(s,0,curr,res);
//         return res;
//     }
// };

class Solution {
public:
    int n;
    
    bool isPalindrome(string &s, int l, int r) {
        
        while(l < r) {
            if(s[l] != s[r])
                return false;
            l++;
            r--;
        }
        
        return true;
        
    }
    
    void backtrack(string &s, int idx, vector<string> curr, vector<vector<string>> &result) {
        
        if(idx == n) {
            result.push_back(curr);
            return;
        }
        
        
        for(int i = idx; i<n; i++) {
            
            if(isPalindrome(s, idx, i)) {
                
                curr.push_back(s.substr(idx, i-idx+1));
                
                backtrack(s, i+1, curr, result);
                
                curr.pop_back();
                
            }
            
        }
        
    }
    
    vector<vector<string>> partition(string s) {
        n = s.length();
        vector<vector<string>> result;
        vector<string> curr;
        
        backtrack(s, 0, curr, result);
        
        return result;
        
    }
};
