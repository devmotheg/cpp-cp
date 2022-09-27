/* Solution #1 */

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
    int helper(TreeNode* node) <%
        if (not node) return NULL;
        
        int leftcnt = helper(node->left);
        int rightcnt = helper(node->right);
        
        if (leftcnt == -1 or rightcnt == -1) return -1;
    
        if (abs(leftcnt - rightcnt) > 1) return -1;
        else return max(leftcnt, rightcnt) + 1;
    %>
    
public:
    bool isBalanced(TreeNode* root) {
        if (not root) return true;
        
        return helper(root) == -1 ? false : true;
    }
};

/* Solution #2 */

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
    bool isBalanced(TreeNode* root) {
        std::stack<TreeNode*> stack;
        TreeNode* node = root, *last = nullptr;
        unordered_map<TreeNode*, int> depths;
        
        while (!stack.empty() || node) {
            if (node)
                stack.push(node),
                node = node->left;
            else {
                node = stack.top();
                
                if (!node->right || last == node->right) {
                    stack.pop();
                    
                    int leftcnt = depths[node->left], rightcnt = depths[node->right];
                    
                    if (abs(leftcnt - rightcnt) > 1) return false;
                    
                    depths[node] = 1 + max(leftcnt, rightcnt);
                    
                    last = node, node = nullptr;
                } else
                    node = node->right;
            }
        }
        
        return true;
    }
};
