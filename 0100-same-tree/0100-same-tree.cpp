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
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // base case 1;
        if(p == nullptr && q == nullptr){
            return true;
        }

        // base case 2 (jab ek hi nullptr ho ya fir val alag alag ho)
        if(p == nullptr || q == nullptr || p->val != q->val){
            return false;
        }

        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};