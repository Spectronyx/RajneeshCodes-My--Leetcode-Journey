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

class BSTIterator{
public:
    stack<TreeNode*> st;

    bool reverse = true;


    BSTIterator(TreeNode* root,bool isReverse){
        reverse = isReverse;
        pushAll(root);
    }

    bool hasNext(TreeNode* root){
        return !st.empty();
    }

    int next(){
        TreeNode* temp = st.top();
        st.pop();
        if(!reverse) pushAll(temp->right);
        else pushAll(temp->left);
        return temp->val;
    }

    void pushAll(TreeNode* root){
        while(root){
            st.push(root);
            if(!reverse){
                root = root->left;
            }else{
                root = root->right;
            }
        }
    }

};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root ) return false;

        BSTIterator l(root,false);
        BSTIterator r(root,true);

        int i = l.next();
        int j = r.next();

        while(i < j){
            if(i+j == k) return true;
            else if(i+j < k) i = l.next();
            else j = r.next();
        }
        return false;
    }
};