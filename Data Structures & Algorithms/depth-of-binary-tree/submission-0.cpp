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
    int count=0;
    void lvl(TreeNode* root){
        // again base case first
        if(root==NULL) return ;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node==nullptr){
                count++;
                if(!q.empty()) q.push(nullptr);
            }
            else{
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
    }
    int maxDepth(TreeNode* root) {
        // base case
        // if(root==NULL) return 0;
        // return 1 + max(maxDepth(root->left),maxDepth(root->right));

        // also can be done using level order traversal
        lvl(root);
        return count;
    }
};
