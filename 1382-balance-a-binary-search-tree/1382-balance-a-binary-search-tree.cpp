class Solution {
public:
    void getVal(TreeNode* node, vector<int>& nums) {
        if (node == nullptr)
            return;
        getVal(node->left, nums);
        nums.push_back(node->val);
        getVal(node->right, nums);
    }

    TreeNode* createBST(const vector<int>& v, int start, int end) {
        if (start > end)
            return nullptr;

        int mid = start + (end - start) / 2; // Avoid potential overflow
        TreeNode* root = new TreeNode(v[mid]);
        root->left = createBST(v, start, mid - 1);
        root->right = createBST(v, mid + 1, end);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nums;
        getVal(root, nums);
        return createBST(nums, 0, nums.size() - 1);
    }
};