// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */

// class Solution {
// public:
// int count=0;
//     void height(TreeNode* root){
//         if(root==NULL) return;
//         queue<TreeNode*> q;
//         int count=0;
//         q.push(root);
//         q.push(nullptr);
//         while(!q.empty()){
//             TreeNode* temp = q.front();
//             if(temp==nullptr){
//                 count++;
//                 if(!q.empty()) q.push(nullptr);
//             }
//             else{

//             if(root->left) q.push(root->left);
//             if(root->right) q.push(root->right);
//             }
//         }
//     }
//     int maxDepth(TreeNode* root) {
//         // // going to use recusrion in this
//         // // base case
//         // if(root==NULL) return 0;

//         // return 1 + max(maxDepth(root->left),maxDepth(root->right));

//         // now goinf to use itrative lvl order traversal
//       //  int count=0;
//         height(root);
//         return count;
//     }
// };


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
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> q;
        if (root != nullptr) {
            q.push(root);
        }

        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            level++;
        }
        return level;
    }
};