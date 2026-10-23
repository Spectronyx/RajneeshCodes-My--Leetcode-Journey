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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>> q;
        if(root == nullptr) return 0;
        long long maxWidth = 0;
        long long i = 0; 
        q.push({root,i});


        while(!q.empty()){
            int size = q.size();

            long long base = q.front().second;
            long long  left = 0;
            long long right = 0;


            while(size--){
                auto  [front,index] = q.front();
                q.pop();

                long long i = index-base;
                right = i;


                if(front->left) q.push({front->left,2*i});
                if(front->right) q.push({front->right,2*i+1});
            }

            maxWidth = max(maxWidth,right-left+1);
        }
        return maxWidth;
    }
};