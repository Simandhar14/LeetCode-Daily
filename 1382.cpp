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
    TreeNode* buildTree(int left, int right, vector<int>& values) {
        if (left > right)
            return nullptr;
        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(values[mid]);
        root->left = buildTree(left, mid-1, values);
        root->right = buildTree(mid + 1, right, values);
        return root;
    }
    void inorder(TreeNode* root, vector<int>& values) {
        if (!root)
            return;
        inorder(root->left, values);
        values.push_back(root->val);
        inorder(root->right, values);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> values;
        inorder(root, values);
        int left = 0, right = values.size() - 1;
        return buildTree(0, right, values);
    }
};

//java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
        TreeNode buildTree(int left, int right,  List<Integer>values) {
        if (left > right)
            return null;
        int mid = left + (right - left) / 2;
        TreeNode root = new TreeNode(values.get(mid));
        root.left = buildTree(left, mid-1, values);
        root.right = buildTree(mid + 1, right, values);
        return root;
    }
    void inorder(TreeNode root,   List<Integer>values) {
        if (root==null)
            return;
        inorder(root.left, values);
        values.add(root.val);
        inorder(root.right, values);
    }
    public TreeNode balanceBST(TreeNode root) {
        List<Integer>values=new ArrayList();
        inorder(root,values);
        return buildTree(0,values.size()-1,values);
    }
}
