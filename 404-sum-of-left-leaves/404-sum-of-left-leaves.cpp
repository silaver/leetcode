/*
    SILA ER
    ID: 20201701041
    Time Complexity: O(n)
    Space Complexity: O(h) h:height
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

class Solution{
public:
    int sum = 0;
    int sumOfLeftLeaves(TreeNode* root) 
    {
        if(root == NULL)
            return 0;
        
        if(root->left != NULL && root->left->left == NULL && root->left->right == NULL)
            sum += root->left->val;
        
        sumOfLeftLeaves(root->left);
        sumOfLeftLeaves(root->right);
        return sum;
    }
};

/*
    STRATEGY
    Set the sum variable to 0 initially. See if the current nodes left node is a leaf node by checking if root->left is not null, root->left->left is null and root->left->right is null. If this is true, add the value of the node to the sum variable. Recursively go to right and left. Return sum.
    TC is O(n) because in the worst case we have to go to the all n nodes.
    SC is O(h) because we go down the trees height if the number of the nodes are equal to the trees height.

*/