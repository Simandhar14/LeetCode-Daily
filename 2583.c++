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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        long long result=0;
        if(!root) return result;
        queue<TreeNode *>que;
        priority_queue<long long,vector<long long>> pq;
        que.push(root);
        int level=0;
        while(!que.empty())
        {
            int n=que.size();
            long long sum=0;
            while(n--)
            {
                TreeNode *node=que.front();
                que.pop();
                sum+=node->val;
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            pq.push(sum);
            level++;
        }
        if(level<k) return -1;
        while(k!=1)
        {
            pq.pop();
            k--;
        }
        return pq.top();
    }
};