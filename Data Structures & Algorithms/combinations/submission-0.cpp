class Solution {
public:
    vector<vector<int>> res;
    void solve(int start, int &n, vector<int> &temp,int k){
        // base case
        if(k==0){
            res.push_back(temp);
            return;
        }
        if(start > n) return ;
        // inlcude the element
        temp.push_back(start);
        // travers in the tree
        solve(start+1,n,temp,k-1); // if we're includeding then we need to reduce this god damn k
        // excludeing thing
        temp.pop_back();
        solve(start+1,n,temp,k);
    }
    vector<vector<int>> combine(int n, int k) {
        // do this again by include and exclude thing
        vector<int> temp;
        solve(1,n,temp,k);
        return res;
    }
};