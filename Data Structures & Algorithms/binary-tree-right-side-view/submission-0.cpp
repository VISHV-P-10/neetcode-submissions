/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        // we can do this using itrative approatch if we just put 
        // right side of the node first
        
        // itrative approatch
        vector<int> ans;
        if(root==NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            ans.push_back(q.front()->val);
            while(n!=0){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->right) q.push(temp->right);
                if(temp->left) q.push(temp->left);
                n--;
            }
        }
        return ans;
    }
};
