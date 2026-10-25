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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;

        if(root==nullptr)
        {
            return res;
        }        

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int size=q.size();
            queue<int> q1;

            for(int i=0;i<size;i++)
            {
                TreeNode* x = q.front();
                q.pop();

                q1.push(x->val);
                if(x->left!=nullptr)
                {
                    q.push(x->left);
                }
                if(x->right!=nullptr)
                {
                    q.push(x->right);
                }
            }
            res.push_back(q1.back());
        }        
        return res;
    }
};