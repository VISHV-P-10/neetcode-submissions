// class Solution {
// public:
//     vector<int> twoSum(vector<int>& numbers, int target) {
//         // lets just try right now
//         // i know its gonna be solved by tp
//         int n = numbers.size();
//         int i=0;
//         int j=n-1;
//         vector<int> ans;
//         while(i<j){
//             int add = numbers[i]+numbers[j];
//             if(add==target){
//                 ans.push_back(numbers[i]);
//                 ans.push_back(numbers[j]);
//             }
//             else if(add >target) j--;
//             else i++;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;

        while (l < r) {
            int curSum = numbers[l] + numbers[r];

            if (curSum > target) {
                r--;
            } else if (curSum < target) {
                l++;
            } else {
                return { l + 1, r + 1 };
            }
        }
        return {};
    }
};