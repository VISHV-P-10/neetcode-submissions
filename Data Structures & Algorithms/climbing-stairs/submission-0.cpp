class Solution {
// this problem is same as fibbonacci series
private:
    int solve(int x,int n, vector<int>&dp){
        // do top down approatch
        if(x==n) return 1; // we've reatched to the top
        if(x>n) return 0; // just gone further then the limit
        // check if the values already stored in the dp array
        if(dp[x]!= -1) return dp[x];
        int left = solve(x+1, n, dp);
        int right = solve(x+2, n, dp);

    // need to return the total
        return dp[x] = left + right;

    }
 
public:
    int climbStairs(int n) {
        // just going fot the memoization
        vector<int> dp(n+1,-1); // created a DP array to save overlapping
        // sublapping subproblems
        return solve(0,n,dp);
    }
};
