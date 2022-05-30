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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> answer;                 // Create the answer vector
        
        if(!root)                                   // If the tree does not exist, return the empty vector
            return answer;
        
        queue<TreeNode*> q;                         // Create a queue for BSF
        
        q.push(root);                               // Push the root into BSF queue
        
        while(!q.empty()){
            int size = q.size();                    // Calculate the size to not add more than wanted elements to the subvectors
            vector<int> elems;                      // New vector to add into the vector
            
            while(size > 0){                        // Do this for the number of elements in that level
                TreeNode* node = q.front();
                q.pop();
                elems.push_back(node->val);         // Put the element in the sub tree
                
                if(node->left)
                    q.push(node->left);
                
                if(node->right)
                    q.push(node->right);
                
                size--;
            }
            
            answer.push_back(elems);                // Put the vector of elements into the answer vector
        }
        
        reverse(answer.begin(), answer.end());      // Reverse the vector, because it is filled in the reverse order
        return answer;
    }
};