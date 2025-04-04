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
int maxdepth=0;
void storedepth(TreeNode* root,unordered_map<int,int>&mp,int depth)
{
    if(!root) return;
    mp[root->val]=depth;
    storedepth(root->left,mp,depth+1);
    storedepth(root->right,mp,depth+1);
}
TreeNode *lca(TreeNode *root,unordered_map<int,int>&mp)
{
    if(!root || mp[root->val]==maxdepth) return root;
   
    TreeNode *leftn=lca(root->left,mp);
    TreeNode *rightn=lca(root->right,mp);
    if(leftn && rightn) return root;
    return leftn!=NULL ? leftn : rightn;
}
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        unordered_map<int,int>mp;
        storedepth(root,mp,0);
        int p=-1,q=-1;
        for(auto temp:mp)
        {
            maxdepth=max(maxdepth,temp.second);
        }
        return lca(root,mp);
    }
};
