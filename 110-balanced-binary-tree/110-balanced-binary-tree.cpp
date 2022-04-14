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
    
    bool dfs(TreeNode* n, int &height){
        
        if(n==NULL)
            return true;
        
        int l = 0;
        int r = 0;
        bool lb = true;
        bool rb = true;
        
        lb = dfs(n->left,l);
        rb = dfs(n->right,r);
        
        if(lb == false || rb == false)
            return false;
        
        if(abs(l-r)>1)
            return false;
        
        height = max(l,r)+1;
        return true;
        
    }
    
    bool isBalanced(TreeNode* root) {
        int height = 0;
        return dfs(root,height);
            
    }
};