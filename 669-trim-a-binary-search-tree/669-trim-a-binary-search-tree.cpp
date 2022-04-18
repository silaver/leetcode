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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (!root)
            return root;
        
        if (root->val >= low && root->val <= high) { 
            root->left = trimBST(root->left, low, high);
            root->right = trimBST(root->right, low, high);
            return root;
        }
        
        if (root->val < low) {
            return trimBST(root->right, low, high);
        }

        return trimBST(root->left, low, high);
    }
};
/*
    STRATEGY
    First, check if the root is empty. Then, check if the value of the node is between the desired range. If it is between the range of [low, high], recursively keep calling the function to get the trimmed subtree. 
    If the value of the root is smaller than low, return the right subtree. If the value of the root is bigger than high, return the left subtree.
    TC is O(h) because we are searching the tree.
    SC is O(n) because of the recursive calls.
*/