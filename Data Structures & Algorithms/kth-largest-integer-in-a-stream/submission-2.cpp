class KthLargest {
public:
// idk why we created a global veriable
// also making global priority queue

int k;
 priority_queue<int,vector<int> , greater<int> > minheap;

    KthLargest(int k, vector<int>& nums) {
        // to store the min elements first and pop thwm , first and return the remaing ones
        // push the vecot eleemtns init
    this ->k = k;
    // nned to push elemenrs
    for(auto x : nums){
        minheap.push(x);
        if(minheap.size()>k){
            minheap.pop();
        }
    }


    }
    
    int add(int val) {
        // have to add this value in to the array
        // make priority queue for tend to greater elements 
        minheap.push(val);
        if(minheap.size()>k){
            minheap.pop();
        }
        // return the largets 
        return minheap.top();
    }
};
