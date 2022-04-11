/*
    SILA ER
    ID: 20201701041
    Time Complexity: O(n)
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) //check if the node is empty
            return false;
        
        targetSum -= root->val; //subtract the nodes value from targetSum
        
        if((root->left == nullptr) && (root->right == nullptr) && (targetSum == 0))
            return true;    //if it is a leaf node, and the target sum is 0 return true
        
        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
        //either one of them should be true, so we OR root->left and root->right
    }
};

/*
    STRATEGY
    Instead of creating another variable to store the sum and comparing it with the target, we subtract the values of the nodes from targetSum. Using DFS, we traverse the tree recursively. Check if the current node has null nodes in both left and right and if the targetsum is equal to zero. If it is, return 0. We OR the recursive calls because one of them should be true, and this equals to bitwise OR operation.
    Time Complexity is O(n) becuse we call the function n times.
    Space Complexity is O(n) because recursion takes up space.
*/
