/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int> level;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int sum = 0;
            int n = que.size();
            while (n--) {
                TreeNode* node = que.front();
                que.pop();
                sum += node->val;
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
            level.push_back(sum);
        }

        root->val = 0;
        que.push(root);
        int i = 1;
        while (!que.empty()) {
            int n = que.size();
            while (n--) {
                TreeNode* node = que.front();
                que.pop();
                int sibling = node->left == NULL ? 0 : node->left->val;
                sibling += node->right == NULL ? 0 : node->right->val;
                if (node->left) {
                    node->left->val = level[i] - sibling;
                    que.push(node->left);
                }
                if (node->right) {
                    node->right->val = level[i] - sibling;
                    que.push(node->right);
                }
            }
            i++;
        }
        return root;
    }
};