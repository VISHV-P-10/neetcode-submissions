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

// class Solution {
// private:
// // need to find the preorder values on the inorder array
//     int find(vector<int>& inorder,int preidx,int inst,int inend){
//         for(int i=inst;i<inend;i++){
//             if(inorder[i]==preidx) return i;
//         }
//         return -1;
//     }
//     TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int &preidx,int inst,int inend){
//         // base case for the traversal end
//         if(inend<inst) return NULL;
//         // make a new node
//         TreeNode* root = new TreeNode(preorder[preidx]);
//         // make left and right nodes
//         int pos = find(inorder,preidx,inst,inend);
//         root->left = solve(preorder,inorder,preidx+1,inst,pos-1);
//         root->right = solve(preorder,inorder,preidx + (pos-inst)+1,inend);

//         return root;

//     }
// public:
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//             int preidx=0;
//             return solve(preorder,inorder,preidx,0,inorder.size()-1);
//     }
// };

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rootIdx = 0;
        return build(preorder, inorder, rootIdx, 0, inorder.size()-1);
    }
    
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& rootIdx, int left, int right) {
        if (left > right) return NULL;
        int pivot = left;  // find the root from inorder
        while(inorder[pivot] != preorder[rootIdx]) pivot++;
        
        rootIdx++;
        TreeNode* newNode = new TreeNode(inorder[pivot]);
        newNode->left = build(preorder, inorder, rootIdx, left, pivot-1);
        newNode->right = build(preorder, inorder, rootIdx, pivot+1, right);
        return newNode;
    }
};
