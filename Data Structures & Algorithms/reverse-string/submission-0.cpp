class Solution {
public:
    void reverseString(vector<char>& s) {
        // naive solution
        // in s.size/2 time complexity 
        int n = s.size();
        int i=0;
        int j = n-1;
        while(i<j){
            if(s[i]!=s[j]) swap(s[i],s[j]);
            i++; j--;
        }
      //  return s;
    }
};