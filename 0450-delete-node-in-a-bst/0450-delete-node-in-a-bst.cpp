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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return nullptr;
        }

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else {
            if (root->left == nullptr) {
                return root->right;
            }

            if (root->right == nullptr) {
                return root->left;
            }

            TreeNode* successor = root->right;

            while (successor->left != nullptr) {
                successor = successor->left;
            }

            root->val = successor->val;

            root->right = deleteNode(root->right, successor->val);
        }

        return root;        
    }
};