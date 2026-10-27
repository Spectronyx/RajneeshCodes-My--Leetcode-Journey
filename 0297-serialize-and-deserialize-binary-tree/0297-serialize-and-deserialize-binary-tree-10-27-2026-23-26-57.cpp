/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    
    void dfs(TreeNode*root,string& ans){
        if(!root){
            ans += "N,";
            return;
        }

        ans += to_string(root->val)+",";

        
        dfs(root->left,ans);
        dfs(root->right,ans);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;

        dfs(root,ans);
        return ans;
    }

    TreeNode* construct(string &data,int& i){
        int j = data.find(',',i);
        string token = data.substr(i,j-i);
        i = j+1;

        if(token == "N") return nullptr;

        TreeNode* root = new TreeNode(std::stoi(token));
        root->left = construct(data,i);
        root->right = construct(data,i);

        return root;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        return construct(data,i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));