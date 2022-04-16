/*
    SILA ER
    ID: 20201701041
    Time Complexity: O(n logn)
    Space Complexity: O(n)

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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root)
            return nullptr;
        
        if (root->val == val)
            return root;
        
        if (root->val > val)
            return searchBST(root->left, val);
        
        return searchBST(root->right, val); 
    }
};
/*
    STRATEGY
    Simply check if the root is empty, if it is return null. If the value of the root is equal to val, return root. If the value of the node is bigger than val, search the left subtree. If it is bigger, search the right subtree.
    TC is O(n logn) because no matter what, we are searching the half of the tree.
    SC is O(n), n being the number of nodes in the tree.
*/