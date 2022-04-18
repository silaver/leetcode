/*
    SILA ER
    ID: 20201701041
    TC: O(h)
    SC: O(n)
*/
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) 
            return new TreeNode(val);
        
        if(root->val > val) 
            root->left = insertIntoBST(root->left, val);
        
        else 
            root->right = insertIntoBST(root->right, val);
        
        return root;
    }
};

/*
    STRATEGY
    Check if the root is empty. If it is empty, return the new tree node as the root node. Then, compare the value of the root with the given value. 
    If it is bigger than val, that means that the value should be inserted to the left subtree.
    If it is smaller than val, that means that the value should be inserted to the right subtree.
    Insert the target value in the appropriate subtree and recursively call the function.
    
    TC is O(h) because in the worst case we traverse until the end of the tree.
    SC is O(n) because of the recursive calls.
*/