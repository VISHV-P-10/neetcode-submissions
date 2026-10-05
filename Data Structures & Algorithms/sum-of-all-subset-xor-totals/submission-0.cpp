class Solution {
public:
int ans=0;
    void solve(vector<int>& nums, int index,int currxor){
        // base case
        if(index >= nums.size()){
            ans+= currxor;
            return;
        }
        // include the next element
        solve(nums,index+1, currxor^nums[index]);
        // not includeing
        solve(nums,index+1,currxor);
    }
    int subsetXORSum(vector<int>& nums) {
    // not going to make subset vector using the values directly
    solve(nums,0,0);
    return ans;
        
        
    }
};