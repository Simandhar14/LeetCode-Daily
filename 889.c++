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
TreeNode *solve(int prestart,int poststart,int preend,vector<int>& preorder, vector<int>& postorder)
{
    if(prestart>preend) return NULL;
    TreeNode *root=new TreeNode(preorder[prestart]);
    if(prestart==preend)return root;
    int nextnode=preorder[prestart+1];
    int j=poststart;
    while(postorder[j]!=nextnode) j++;
    int nodes=j-poststart+1;
    root->left=solve(prestart+1,poststart,prestart+nodes,preorder,postorder);
    root->right=solve(prestart+nodes+1,j+1,preend,preorder,postorder);
    return root;
}
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return solve(0,0,preorder.size()-1,preorder,postorder);
    }
};