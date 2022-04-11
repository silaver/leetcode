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
    void depthFirst(TreeNode* root, int targetSum, vector<int>& temp, vector<vector<int>>& ans) {
        
        if(root == nullptr)
            return;
        
        targetSum -= root->val;
        temp.push_back(root->val);
        
        if(root->left == nullptr && root->right == nullptr && targetSum == 0)
            ans.push_back(temp);
        
        depthFirst(root->left,targetSum,temp,ans);
        depthFirst(root->right,targetSum,temp,ans);
        temp.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        vector<vector<int>> ans;
        
        if(root == nullptr)
            return ans;
        
        depthFirst(root,targetSum,temp,ans);
        
        return ans;
    }
};

/*
    STRATEGY
    Instead of creating a sum variable to keep track of the target, we decrement taregtSum by the current root value. We push that value to the vector, and check if the current node is a leaf and whether we have reached targetSum == 0. If this is true, we push the path into the answer vector. Then, we call right and left subtrees with recursion. We pop the last element from temp array after second call to avoid merging the of elements of two different paths. We return ans.
    Time Complexity: O(n) because we are pushing n elements into a vector.
    Space Compelxity: O(n) because we are using DFS to recursively traverse subtrees.
*/
