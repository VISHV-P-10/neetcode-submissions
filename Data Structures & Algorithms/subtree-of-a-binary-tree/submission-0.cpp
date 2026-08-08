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
    // TreeNode find(TreeNode* root, int key){
    //     if(root!= NULL && root->val !=key){
    //         root = key>root->val?root->right:root->left;
    //     }
    //     return root;
    // }
    bool check(TreeNode* p,TreeNode* q){
        if(p ==NULL && q==NULL) return true;
        if((!p&&q) || (p&&!q)) return false;
        if(p->val != q->val) return false;

        return check(p->left,q->left) && check(p->right,q->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // // first we need a find funtion to find the subroot node in the main root 
        // int k = subRoot->val;
        // TreeNode* dummy = find(root,k);

        // // now we just need to compair the both dummy and subroot
        // return check(dummy,subRoot);

        if(root==NULL) return false;
        if(check(root,subRoot)) return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right,subRoot);
    }
};
