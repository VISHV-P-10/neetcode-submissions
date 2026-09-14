// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         int size = nums.size();
//         int l=0,r=1;
//         vector<int> ans;
//         if(size==1){
//             ans.push_back(nums[0]);
//             return ans;
//         }
//         if(k==1) return nums;
//         int maxi = max(nums[l],nums[r]);
//         while(r<size){
//             maxi = max(nums[r],maxi);
//             if((r-l+1)==k){
//                 ans.push_back(maxi);
//                 l++;
//                 continue;
//             }
//             r++;
//         }
//         return ans;
//     }
// };


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> ans;

        int l = 0;
        int r = 0;
        int maxi = INT_MIN;

        while (r < n) {

            // Add the new element to the window
            maxi = max(maxi, nums[r]);

            // If window size becomes k
            if (r - l + 1 == k) {

                // Store the maximum of this window
                ans.push_back(maxi);

                // If the element leaving the window
                // was the maximum, recalculate maxi
                if (nums[l] == maxi) {
                    maxi = INT_MIN;

                    for (int i = l + 1; i <= r; i++) {
                        maxi = max(maxi, nums[i]);
                    }
                }

                // Move left pointer
                l++;
            }

            // Move right pointer
            r++;
        }

        return ans;
    }
};