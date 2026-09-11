class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // need to find the set elements in each substring
        // int length=0;
        // for(int i =0;i<s.size();i++){
        //     unordered_set<char> charset;
        //     for(int j=i;j<s.size();j++){
        //         if(charset.find(s[j]) != charset.end()) break;
        //         charset.insert(s[j]);
        //     }
        //     length = max(length, (int)charset.size());
        // }
        // return length;

        // ** this above code will give runtime error cux of o(n*m) time complexity
        // we have to optimize it to o(n) by using sliding window
        unordered_set<char> charset;
        int start=0;
        int length=0;
        for(int end = 0;end<s.size();end++){
            while(charset.find(s[end]) != charset.end()){
                charset.erase(s[start]);
                start++;
            }
            charset.insert(s[end]);
            length = max(length, end-start+1);
        }
        return length;
    }
};
