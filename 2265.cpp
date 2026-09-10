//cpp
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
    int count = 0;
    typedef pair<int, int> p;
    p solve(TreeNode* root) {
        if (!root)
            return {0, 0};
        p l = solve(root->left);
        p r = solve(root->right);
        int nodes = 1 + l.first + r.first;
        int sum = root->val + l.second + r.second;
        if (sum / nodes == root->val)
            count++;
        return {nodes, sum};
    }
    int averageOfSubtree(TreeNode* root) {
        p result = solve(root);
        return count;
    }
};
