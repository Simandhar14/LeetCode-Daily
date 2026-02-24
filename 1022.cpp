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
    void solve(TreeNode* root, vector<string>& numbers, string str) {
        str.push_back(root->val + '0');
        if (!root->left && !root->right) {
            numbers.push_back(str);
            return;
        }
        if (root->left)
            solve(root->left, numbers, str);
        if (root->right)
            solve(root->right, numbers, str);
    }
    int sumRootToLeaf(TreeNode* root) {
        if(!root) return 0;
        vector<string> numbers;
        string str = "";
        solve(root, numbers, str);
        int result = 0;
        for (string& number : numbers) {
            int decimal = 0;
            int len = number.length();
            for (char& ch : number) {
                decimal += (ch - '0') * (1 << (len - 1));
                len--;
            }
            result += decimal;
        }
        return result;
    }
};
