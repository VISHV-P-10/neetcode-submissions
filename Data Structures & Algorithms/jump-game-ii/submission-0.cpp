// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         int n = nums.size();
//         int goal = n-1;
//         int l=0,r=0;
//         int far = 0;
//         int jumps=0;
//         while(r!=goal){
//             far = max(far, l+nums[l]);
//             l = r+1;
//             r = far;
//             jumps++;
//         }
//         // for(int i=l;i<=r;i++){
//         //     far = max(far, i + nums[i]);
//         //     l= r+1;
//         //     r = far;
//         //     jumps++;
//         //     if(far == goal) return jumps;
//         // }
//     return jumps;
        
//     }
// };

class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0, l = 0, r = 0;

        while (r < nums.size() - 1) {
            int farthest = 0;
            for (int i = l; i <= r; i++) {
                farthest = max(farthest, i + nums[i]);
            }
            l = r + 1;
            r = farthest;
            res++;
        }
        return res;
    }
};
