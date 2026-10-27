class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* curr = root;

        while (curr) {
            if (!curr->left) {
                result.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode* leftChild = curr->left;

                while (leftChild->right && leftChild->right != curr) {
                    leftChild = leftChild->right;
                }

                if (!leftChild->right) {
                    result.push_back(curr->val); // Preorder: visit first
                    leftChild->right = curr;
                    curr = curr->left;
                } else {
                    leftChild->right = nullptr;  // Thread remove
                    curr = curr->right;
                }
            }
        }

        return result;
    }
};