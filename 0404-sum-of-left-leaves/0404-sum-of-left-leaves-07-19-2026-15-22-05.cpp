class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) return 0;
        
        int sum = 0;
        
        // Check if the left child exists and is a leaf
        if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr) {
            sum += root->left->val;
        }
        
        // Accumulate sums from both subtrees
        return sum + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};
