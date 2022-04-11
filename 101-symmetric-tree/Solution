/*
    Time Complexity: O(n+m)
    Space Complexity: O(n+m)
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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q1; //left subtree
        queue<TreeNode*> q2; //right subtree
        
        q1.push(root->left);
        q2.push(root->right);
        
        while(!q1.empty())
        {
            if(q1.size() != q2.size()) //if the subtrees have different num of elements, they are not symmetrical
                return false;
            
            TreeNode* f1 = q1.front(); //get the front values
            TreeNode* f2 = q2.front();
            
            q1.pop();
            q2.pop();
            
            if((!f1 && f2) || (!f2 && f1)) //if one of them is null and the other one is not
                return false;
            
            if(f1 != NULL && f2 != NULL && f1->val != f2->val) //if the two nodes have different values
                return false;
            
            if(f1 != NULL)  //go to the next nodes of left subtree
            {           
                q1.push(f1->left);
                q1.push(f1->right);
            }
            
            if(f2 != NULL)            //go to the next nodes of right subtree
            {
                q2.push(f2->right);
                q2.push(f2->left);
            }
        }
        
        if(q1.size() == q2.size()) 
            return true;
        else 
            return false;
    }
};
/*
    STRATEGY
    We create two queues to store the left subtree and the right subtree. We check these conditions:
    1. If one of them is null and the other one is not
    2. If neither of them are null but they have different values.
    Return false if any of them is true. Push the next left and right nodes of both the left subtree and the right subtree into the queues. Pop the checked nodes.
    At the end, if the size of the queues are the same, we have a symmetric tree.
    Time Complexity is O(n+m) because we are using 2 queues to check the nodes of the subtrees.
    Space Complexity is O(n+m) because we are using two different queues.

*/
