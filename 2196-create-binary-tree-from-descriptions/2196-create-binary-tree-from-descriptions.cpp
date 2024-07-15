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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodeMap;
        unordered_set<int> children;

        // Create nodes and mark children
        for (const auto& desc : descriptions) {
            int parentVal = desc[0];
            int childVal = desc[1];
            bool isLeft = desc[2] == 1;

            // Create parent node if it doesn't exist
            if (nodeMap.find(parentVal) == nodeMap.end()) {
                nodeMap[parentVal] = new TreeNode(parentVal);
            }
            // Create child node if it doesn't exist
            if (nodeMap.find(childVal) == nodeMap.end()) {
                nodeMap[childVal] = new TreeNode(childVal);
            }

            // Link parent and child
            if (isLeft) {
                nodeMap[parentVal]->left = nodeMap[childVal];
            } else {
                nodeMap[parentVal]->right = nodeMap[childVal];
            }

            // Mark child nodes
            children.insert(childVal);
        }

        // Find the root (a node that is never a child)
        TreeNode* root = nullptr;
        for (const auto& desc : descriptions) {
            if (children.find(desc[0]) == children.end()) {
                root = nodeMap[desc[0]];
                break;
            }
        }

        return root;
    }
};