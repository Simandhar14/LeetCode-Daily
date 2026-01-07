class Solution {
public:
    const int MOD = 1e9 + 7;
    long long totalSum = 0;
    long long maxProd = 0;
    long long calculateSum(TreeNode* root) {
        if (!root) return 0;
        return root->val + calculateSum(root->left) + calculateSum(root->right);
    }
    
    long long dfs(TreeNode* root) {
        if (!root) return 0;
        long long leftSum = dfs(root->left);
        long long rightSum = dfs(root->right);
        long long subtreeSum = root->val + leftSum + rightSum;
        long long product = subtreeSum * (totalSum - subtreeSum);
        maxProd = max(maxProd, product);  
        return subtreeSum;
    }
    
    int maxProduct(TreeNode* root) {
        totalSum = calculateSum(root);
        dfs(root);
        return maxProd % MOD;
    }
};
