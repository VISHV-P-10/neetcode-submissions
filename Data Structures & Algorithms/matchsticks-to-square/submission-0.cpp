// class Solution {
// public:
//     bool solve(int i,vector<int>& matchsticks,vector<int>&side){
//         // base case
//         if(i==matchsticks.size()){
//             return side[0]==side[1] && side[1]==side[2] && side[2]==side[3];
//         }

//         for(int j=0;j<4;j++){
//             side[j]+= matchsticks[i];
//             if(solve(i+1))
//         }
//     }
//     bool makesquare(vector<int>& matchsticks) {
//         // need to make empty side array
//         sort(matchsticks.begin(),matchsticks.end());
//         // need to find the perimeter
//         int sum = accumulate(matchsticks.begin(),matchsticks.end(),0);
//         if(sum%4 !=4) return false;

//         vector<int> side(4,0);
//        return solve(0,matchsticks,side);
//     }
// };

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int totalLength = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (totalLength % 4 != 0) return false;

        int length = totalLength / 4;
        vector<int> sides(4, 0);
        sort(matchsticks.rbegin(), matchsticks.rend());

        return dfs(matchsticks, sides, 0, length);
    }

private:
    bool dfs(vector<int>& matchsticks, vector<int>& sides, int index, int length) {
        if (index == matchsticks.size()) {
            return true;
        }

        for (int i = 0; i < 4; i++) {
            if (sides[i] + matchsticks[index] <= length) {
                sides[i] += matchsticks[index];
                if (dfs(matchsticks, sides, index + 1, length)) return true;
                sides[i] -= matchsticks[index];
            }

            if (sides[i] == 0) break;
        }

        return false;
    }
};