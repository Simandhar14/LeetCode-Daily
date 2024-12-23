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
    int minimumOperations(TreeNode* root) {
        int operations = 0;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            vector<int> level;
            int n = que.size();
            while (n--) {
                TreeNode*node = que.front();
                level.push_back(node->val);
                que.pop();
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
            vector<int> sortedlevel = level;
            sort(begin(sortedlevel), end(sortedlevel));
            unordered_map<int, int> mp;
            for (int i = 0; i < sortedlevel.size(); i++) {
                mp[sortedlevel[i]] = i;
            }
            vector<bool> visited(level.size(), false);
            for (int i = 0; i < level.size(); i++) {
                if (visited[i] || mp[level[i]] == i)
                    continue;
                int j = i;
                int cycle = 0;
                while (!visited[j]) {
                    visited[j] = true;
                    int index = mp[level[j]];
                    j = index;
                    cycle++;
                }
                if (cycle > 1) {
                    operations += (cycle - 1);
                }
            }
        }
        return operations;
    }
};