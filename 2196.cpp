//cpp
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
    typedef pair<int, int> p;

    void solve(TreeNode* node, int root, unordered_map<int, p>& mp) {
        if (mp.count(root)) {
            int leftChild = mp[root].first;
            int rightChild = mp[root].second;

            if (leftChild != -1) {
                node->left = new TreeNode(leftChild);
                solve(node->left, leftChild, mp);
            }

            if (rightChild != -1) {
                node->right = new TreeNode(rightChild);
                solve(node->right, rightChild, mp);
            }
        }
    }

    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, p> mp;
        unordered_set<int> children;

        for (auto& desc : descriptions) {
            int parent = desc[0];
            int child = desc[1];
            int left = desc[2];

            children.insert(child);

            if (!mp.count(parent)) {
                mp[parent].first = -1;
                mp[parent].second = -1;
            }

            if (left)
                mp[parent].first = child;
            else
                mp[parent].second = child;
        }

        int root = -1;

        for (auto& desc : descriptions) {
            int parent = desc[0];

            if (!children.count(parent)) {
                root = parent;
                break;
            }
        }

        TreeNode* node = new TreeNode(root);
        solve(node, root, mp);

        return node;
    }
};
