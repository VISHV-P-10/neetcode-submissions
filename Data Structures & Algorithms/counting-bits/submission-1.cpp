class Solution {
public:
    vector<int> countBits(int n) {
        // extream brute force
        int number=0;
        vector<int> ans;
        while(number<=n){
            // checking bit by bit
            int count=0;
            for(int bit=0;bit<32;bit++){
                count+= (number>>bit)&1;
            }
            ans.push_back(count);
            number++;
        }
        return ans;

    }
};