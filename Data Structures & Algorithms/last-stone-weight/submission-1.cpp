class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // make a prioruty queue and load stones values in it
        priority_queue<int> maxheap;
        for(int i=0;i<stones.size();i++){
            maxheap.push(stones[i]);
        }
        while(maxheap.size()>1){
            int y = maxheap.top();
            maxheap.pop();
            int x = maxheap.top();
            maxheap.pop();
            if(y!=x){
                int next = y-x;
                maxheap.push(next);
            }
        }
        if(maxheap.size()>0) return maxheap.top();
        return 0;
    }
};
