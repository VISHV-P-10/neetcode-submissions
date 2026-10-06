class Solution {
public:
    vector<vector<int>> res;

    void solve(vector<int>& nums, vector<int>& temp,
               int target, int index) {

        // Target achieved
        if(target == 0) {
            res.push_back(temp);
            return;
        }

        // Target exceeded
        if(target < 0) {
            return;
        }

        for(int i = index; i < nums.size(); i++) {

            // Choose
            temp.push_back(nums[i]);

            // Explore
            // i, because we can reuse nums[i]
            solve(nums, temp, target - nums[i], i);

            // Backtrack
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;

        solve(nums, temp, target, 0);

        return res;
    }
};
