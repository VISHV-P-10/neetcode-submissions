// class Solution {
// public:
//     unordered_set<vector<int>> numset;
//     void solve(vector<int> &nums,vector<int> &temp){
//         if(temp.size()==nums.size()){
//             numset.insert(temp);
//             return ;
//         }
//         for(int i=0;i<nums.size();i++){
//             if(numset.find(nums[i])==numset.end()){
//             // gonna take
//             temp.push_back(nums[i]);
//             //numset.insert(nums[i]);
//             solve(nums,temp);
//             // not gonna take 
//             temp.pop_back();

//             }
//         }
//     }
//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         // need to do this using permutations 1
//         vector<int> temp;
//         solve(nums,temp);
//         return vector<vector<int>>(numset.begin(),numset.end());
//     }
// };

class Solution {

private:

    set<vector<int>> numset;

    void solve(vector<int>& nums,
               vector<int>& temp,
               vector<bool>& visited) {

        if(temp.size() == nums.size()) {
            numset.insert(temp);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {

            if(visited[i])
                continue;

            visited[i] = true;

            temp.push_back(nums[i]);

            solve(nums, temp, visited);

            temp.pop_back();

            visited[i] = false;
        }
    }

public:

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        vector<int> temp;
        vector<bool> visited(nums.size(), false);

        solve(nums, temp, visited);

        return vector<vector<int>>(numset.begin(), numset.end());
    }
};