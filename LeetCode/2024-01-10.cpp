// ***    872. Leaf-Similar Trees    *** //

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
private:
    void dfs(TreeNode* head, vector<int> &leaf) {
        if(head == NULL) {
            return;
        }
        if(head -> left == NULL && head -> right == NULL) {
            leaf.push_back(head -> val);
            return;
        }

        dfs(head -> left, leaf);
        dfs(head -> right, leaf);
        return;
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1, leaf2;
        dfs(root1, leaf1);
        dfs(root2, leaf2);

        return leaf1 == leaf2;
    }
};
