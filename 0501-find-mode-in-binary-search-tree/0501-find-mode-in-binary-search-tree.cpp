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
    void dfs(TreeNode* root){
        if(!root){
            return;
        }

        mp[root->val]++;
        dfs(root->left);
        dfs(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        int maxi = 0;

        for(auto p: mp){
            maxi = max(maxi,p.second);
        }
        vector<int> ans;

        for(auto p: mp){
            if(p.second == maxi){
                ans.push_back(p.first);
            }
        }
        return ans;
        
    }
};