class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
     // doing firstly with the brteu force
     // by checking for each station 
    //  int n = gas.size();
    //  for(int i=0;i<n;i++){
    //     int tank = gas[i] - cost[i];
    //     if(tank<0) continue;

    //     int j = (i+1)%n;
    //     while(j!=i){
    //         tank += gas[j] - cost[j];
    //         if(tank<0) break;
    //         j = (j+1)%n;
    //     }
    //     if(j==i) return i;
    //  }   
    //  return -1;

    // there is some two pointer approcthc also , im not goin for that rn
    // to do greedy i need to we need the  diffrenec in hte fuel thing
    // first there is a base case condition overthere
    if(accumulate(gas.begin(),gas.end(),0) < accumulate(cost.begin(),cost.end(),0)) return -1;

    int tol = 0;
    int ans =0;
    for(int i =0;i<gas.size();i++){
        tol += (gas[i]-cost[i]);

        if(tol <0){
            tol =0;
            ans=i+1;
        }
    }
    return ans;
    }
};
