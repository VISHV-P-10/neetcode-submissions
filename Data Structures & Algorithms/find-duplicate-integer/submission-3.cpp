class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // can be solved in o(n)
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans=0;
        for(int i=1;i<n;i++){
            if(nums[i-1]==nums[i]){
                ans = nums[i];
            }
        }
        return ans;
    }
};
