// class Solution {
// public:
//     bool check(vector<int>& nums) {
//         // count how many time the array sequence breaking its order
//         // for sorted rotated condition it would be 0,1;
//         // int n= nums.size();
//         // int count=0;
//         // for(int i=0;i<n-1;i++){
//         //     if(nums[i]>nums[(i+1)%n]) count++;
//         // }
//         // if(nums[n-1]<nums[0]) count++;

//         // return count<=1;

        
//     }
// };

class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0, N = nums.size();

        for (int i = 0; i < N; i++) {
            if (nums[i] > nums[(i + 1) % N] && ++count > 1) {
                return false;
            }
        }

        return true;
    }
};