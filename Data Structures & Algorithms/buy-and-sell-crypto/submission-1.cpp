class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // solving this hoe using two pointers
        // taking one from start and other one from end
        int size = prices.size();
        int start=0;
        int end = 1;
        int maximum_profit=0;
        while(end < size){
            int maxi=0;
            if(prices[start]> prices[end]) start=end;
            else{
                maxi = prices[end] - prices[start];
                maximum_profit = max(maximum_profit,maxi);
                end++;
            }
           // start++;
        }
        return maximum_profit;
    }
};
