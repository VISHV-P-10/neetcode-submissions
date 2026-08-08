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
     int helper(TreeNode* root, int &count, int max_val){
        if(root==NULL) return 0;
        if(root->val >= max_val) count++;
        max_val = max(max_val, root->val);
        helper(root->left, count, max_val);
        helper(root->right, count, max_val);

        return count;
     }
public:
    int goodNodes(TreeNode* root) {
        // need to compair ts with every node in the path of root to leaf node
        if(root==NULL) return 0;
        int count=0;
        int max_val =root->val;
        helper(root,count,max_val);
        return count;

    }
};
