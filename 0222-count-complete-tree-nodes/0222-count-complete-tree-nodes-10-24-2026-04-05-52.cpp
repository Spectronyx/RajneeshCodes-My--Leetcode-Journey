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
    int height(TreeNode* root){
        if(!root) return 0;
        return 1+height(root->left);
    }
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        if(leftHeight == rightHeight) return pow(2,leftHeight)+countNodes(root->right);

        return pow(2,rightHeight)+countNodes(root->left);

        
        

    }
};