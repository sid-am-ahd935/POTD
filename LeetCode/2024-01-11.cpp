// ***    1026. Maximum Difference Between Node and Ancestor    *** //

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
    int dfs(TreeNode* root, int minN, int maxN) {
        if(root == NULL) {
            return maxN-minN;
        }

        maxN = max(maxN, root -> val);
        minN = min(minN, root -> val);
        // int ans = max(abs(minN - root -> val), abs(maxN - root -> val)),
        int ans1 = dfs(root -> left, minN, maxN),
            ans2 = dfs(root -> right, minN, maxN);

        return max(ans1, ans2);
        // return max({ans1, ans2, ans});
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, INT_MAX, INT_MIN);
    }
};
