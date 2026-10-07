// class Solution {
// public:
// set<vector<int>> res;
// void solve(vector<int>& candidates,vector<int>&temp,int target,int index){
//     // base case
//     if(target==0) {
//         res.insert(temp);
//         return;
//     }
//     if(target<0) return;
//     for(int i =index;i<candidates.size();i++){
//     if(i>index && candidates[i]==candidates[i+1]){
//         continue;
//     }
//         temp.push_back(candidates[i]);
//         solve(candidates,temp,target-candidates[i],i+1);
//         temp.pop_back();
//     }
// }
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         sort(candidates.begin(),candidates.end());
//         vector<int> temp;
//         solve(candidates,temp,target,0);
//         return vector<vector<int>>(res.begin(),res.end());
//     }
// };
class Solution {
public:
 set<vector<int>> res;

 void solve(vector<int>& candidates,vector<int>& temp, int target,int index){
    // base case
    if(target ==0){
        res.insert(temp);
        return ;
    }
    if(target <0)return;

    for(int i=index;i<candidates.size();i++){
        // include 
        if( i> index && candidates[i] == candidates[i-1]) continue;
        temp.push_back(candidates[i]);
        solve(candidates,temp,target-candidates[i],i+1);
        temp.pop_back();
    }
 }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // use sets instead of the 2d res vector
        // sort that hoe
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        solve(candidates,temp,target,0);
        return vector<vector<int>>(res.begin(),res.end());
    }
};