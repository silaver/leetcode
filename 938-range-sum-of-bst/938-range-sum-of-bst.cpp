/*
    SILA ER
    ID: 20201701041
    Time Complexity: O()
    Space Complexity: O()
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
    int sum = 0;
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == nullptr)
            return (sum > 0) ? sum : 0;
        
        if(root->val < low)
            return rangeSumBST(root->right, low, high);
        
        if(root->val > high)
            return rangeSumBST(root->left, low, high);
        
        else
        {
            sum += root->val;
            sum = rangeSumBST(root->left, low, high);
            sum = rangeSumBST(root->right, low, high);
        }
        return sum;   
    }
};
/*
    STRATEGY
    Set the sum to 0. Check if the current nodes value is
    1. Null,
    2. Smaller than the low value,
    3. Bigger than the high value.
    
    If the first condition is true, check if sum is bigger than zero. If it is 0, return sum. If it is not, then return 0.
    If the second condition is true, go to root->right because our current node is not in the range. Proceed to bigger numbers.
    If the third condition is true, go to root->left because our current node is not in the range. Proceed to smaller numbers.
    If none of these are true, our value of the node is in the range. Add root->val to the sum. Continue with BST.
*/