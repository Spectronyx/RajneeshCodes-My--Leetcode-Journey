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
    unordered_map<int,int> mp;
    int preIndex = 0;

    TreeNode* build(vector<int>& preorder,int low,int high){
        if(low > high) return nullptr;

        int val = preorder[preIndex++];
        TreeNode* root = new TreeNode(val);

        int mid = mp[val];

        root->left = build(preorder,low,mid-1);
        root->right = build(preorder,mid+1,high);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder,vector<int> &inorder){
        for(int i = 0;i < preorder.size();i++){
            mp[inorder[i]] = i;
        }

        return build(preorder,0,preorder.size()-1);    
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(),inorder.end());
        preIndex = 0;

        return buildTree(preorder,inorder);
        
    }
};