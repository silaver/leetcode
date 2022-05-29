/*
    SILA ER
    ID: 20201701041
    
    TC: O(n)
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
    int diameter;
    
    int longestPath(TreeNode* node){
        if(node == NULL)
            return 0;
        
        //find the longest path 
        int leftPath = longestPath(node->left); 
        int rightPath = longestPath(node->right);
        
        diameter = max(diameter, leftPath + rightPath); //update the diameter if leftPath+ rightPath is larger
        
        return max(leftPath, rightPath) +1 ;
        //return the longest path, add 1 for the path connecting the node and its parent
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0;
        longestPath(root);
        return diameter;
    }
};

/*
    Diameter is maximum of leftPath + rightPath for all the nodes. The leftPath and rightPath are calculated by the max path of their child + 1. We are iterating over the whole tree calculating the longestPath, therefore, we calculate diameter as well.
    longestPath takes TreeNode as input and returns the longest path from it to the leaf node. It will recursively visit children nodes and retrieve the longest paths from them to the leaf first, and then add 1 to the longer one before returning it as the longest path. Diameter is calculated in between as the leftPath+rightPath for every node. 
    SC is O(n) because of recursive calls.

*/