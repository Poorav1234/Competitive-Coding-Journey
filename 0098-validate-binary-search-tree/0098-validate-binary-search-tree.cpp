class Solution {
public:
    bool validateTree(TreeNode* root, int minVal, int maxVal) {
        if(root == nullptr) return true;

        if(root->val <= minVal || root->val >= maxVal)
            return false;

        return validateTree(root->left, minVal, root->val) &&
               validateTree(root->right, root->val, maxVal);
    }

    bool isValidBST(TreeNode* root) {
        return validateTree(root, INT_MIN, INT_MAX);
    }
};