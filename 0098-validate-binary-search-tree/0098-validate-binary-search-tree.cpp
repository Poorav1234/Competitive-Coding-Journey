class Solution {
public:
    bool validateTree(TreeNode* root, long minVal, long maxVal) {
        if(root == nullptr) return true;

        if(root->val <= minVal || root->val >= maxVal)
            return false;

        return validateTree(root->left, minVal, root->val) &&
               validateTree(root->right, root->val, maxVal);
    }

    bool isValidBST(TreeNode* root) {
        return validateTree(root, LONG_MIN, LONG_MAX);
    }
};