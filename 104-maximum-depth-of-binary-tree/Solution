/*
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
    int maxDepth(TreeNode* root) {
        if(root == NULL) 
            return 0;
        int maxLeft = maxDepth(root->left);
        int maxRight = maxDepth(root->right);
        return max(maxLeft, maxRight)+1;
    }
    
};
/*
    STRATEGY
    We go to left and right nodes. Keeping how many times we go each side in a variable, we return the max value between the two. We add 1 because of the root.
    TC is O(n) because we traverse n nodes.
    SC is O(n) because of recursive calls.

*/
