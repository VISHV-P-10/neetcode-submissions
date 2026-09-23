class Solution {
public:
    int n;
    vector<vector<int>>res;
    unordered_set<int> st;
    void solve(vector<int>& nums, vector<int> & temp){
        // base case
        if(temp.size()==n){
            res.push_back(temp);
            return;
        }

        // we need to try every tree branch start from 0 so
        for(int i=0;i<n;i++){
            // check in set
            if(st.find(nums[i])==st.end()){ // element not in the set
                temp.push_back(nums[i]);
                // insert in the set also
                st.insert(nums[i]);
                // leap of faith
                solve(nums,temp);

                // revert back
                temp.pop_back();
                st.erase(nums[i]);
                // explore
               // solve(nums,temp);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        // now here we can see we need to make all possible senerios so here we need to use recusrion
        // we need to perform swapping
        n = nums.size();
        vector<int> temp;
        solve(nums,temp);
        return res;
    }
};
