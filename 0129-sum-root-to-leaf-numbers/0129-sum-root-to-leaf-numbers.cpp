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
    void solve(TreeNode* root, int &sum, string &s){
        if (root == nullptr) {
            return;
        }
        s.push_back(root->val + '0');
    
        if (root->left == nullptr && root->right == nullptr) {
            sum += stoi(s);
        } else {
            solve(root->left, sum, s);
            solve(root->right, sum, s);
        }

        s.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        string s = "";
        solve(root, sum ,s);
        return sum;
    }
};