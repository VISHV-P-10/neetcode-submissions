class Solution {
public:
// using backtraking
    vector<vector<int>> res;

    void solve(vector<int>& nums,int i,vector<int> &temp){
        // base case
        if(i >= nums.size()){
            res.push_back(temp);
            return ;
        }
        // take the element ones
        temp.push_back(nums[i]);
        // recusive call
        solve(nums,i+1,temp);
        // not include
        temp.pop_back();
        // again recusrive call
        solve(nums,i+1,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int size = nums.size();
        vector<int> temp;
        solve(nums,0,temp);
        return res;
    }
};
