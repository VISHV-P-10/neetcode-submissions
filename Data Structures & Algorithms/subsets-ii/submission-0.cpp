// class Solution {
// public:
//    // vector<vector<int>> res;
//     unordered_set<vector<vector<int>>> eleset;
//     void solve(vector<int>& nums, int index,vector<int> &temp){
//         // base case
//         if(index> nums.size()){
//             eleset.insert(temp);
//             return ;
//         }
//         temp.push_back(nums[index]);
//         solve(nums,index+1,temp);
//         //eleset.insert()
//         temp.pop_back();
//         solve(nums,index+1,temp);
//     }
//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//         // use the subset 1 logic here but add unordered set also
//         vector<int> temp;
//         solve(nums,0,temp);
//         return eleset; 
//     }
// };

class Solution {
public:

    set<vector<int>> eleset;

    void solve(vector<int>& nums, int index, vector<int>& temp) {

        if(index >= nums.size()) {
            eleset.insert(temp);
            return;
        }

        // Take
        temp.push_back(nums[index]);
        solve(nums, index + 1, temp);

        // Don't take
        temp.pop_back();
        solve(nums, index + 1, temp);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<int> temp;

        solve(nums, 0, temp);

        return vector<vector<int>>(eleset.begin(), eleset.end());
    }
};