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
    int answer = INT_MAX;
    void findDepth(TreeNode* root, int depth){
        if(root == nullptr) return;
        if(root->left == nullptr && root->right == nullptr){
            answer = min(answer, depth);
            return;
        }
        depth++;
        findDepth(root->left, depth);
        findDepth(root->right, depth);
        depth--;
    }
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int s = 1;
        findDepth(root, s);
        return answer;
    }
};