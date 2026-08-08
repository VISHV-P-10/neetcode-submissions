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
    // void find(TreeNode* root, int pos, int &l,int &r){
    //     if(root==NULL) return ;
    //     l = min(l,pos);
    //     r = max(r,pos);
    //     find(root->left, pos-1,l,r);
    //     find(root->right, pos+1,l,r);
    // }
    int height(TreeNode* root, int &maxi){
        if(root==NULL) return 0;
        int left_height = height(root->left, maxi);
        int right_height = height(root->right, maxi);
        maxi = max(maxi,left_height+right_height);
        
        return 1+ max(left_height,right_height);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        // int l=0,r=0;
        // // try to write the find funtion as the top view wala question
        // find(root,0,l,r); // that 0 is the current pos of the pointer
        // int dia = r-l;
        // return dia; 

        // that find funtion technique didn't work, so doing this with that
        // regular max height from both side method
        int maxi=0;
        height(root,maxi);
        return maxi;
    }
};
