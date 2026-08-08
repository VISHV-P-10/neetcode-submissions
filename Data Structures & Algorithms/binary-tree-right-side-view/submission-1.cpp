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
    private:
    void helper(TreeNode* root, int lvl, vector<int> &ans){
        if(root==NULL) return ;
        if(ans.size()==lvl) ans.push_back(root->val);
        // for right side view we gonna travers rigth side of the tree first
        helper(root->right,lvl+1,ans);
        helper(root->left,lvl+1,ans);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        // we can do this using itrative approatch if we just put 
        // right side of the node first
        
        // itrative approatch
        // vector<int> ans;
        // if(root==NULL) return ans;
        // queue<TreeNode*> q;
        // q.push(root);
        // while(!q.empty()){
        //     int n = q.size();
        //     ans.push_back(q.front()->val);
        //     while(n!=0){
        //         TreeNode* temp = q.front();
        //         q.pop();
        //         if(temp->right) q.push(temp->right);
        //         if(temp->left) q.push(temp->left);
        //         n--;
        //     }
        // }
        // return ans;

        // try recursive approatch 
        vector<int> ans;
        int lvl=0;
        helper(root,0,ans);
        return ans;
    }
};
