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
    int ans = 0; // Variable to store the count of valid pairs

    // Helper function to find leaf nodes and calculate distances
    vector<int> findLeafDistances(TreeNode* root, int distance) {
        // If the node is null, return an empty vector
        if (!root) return {};

        // If the node is a leaf, return a vector with distance 1 (itself)
        if (!root->left && !root->right) return {1};

        // Recursively get distances from left and right subtrees
        vector<int> leftDistances = findLeafDistances(root->left, distance);
        vector<int> rightDistances = findLeafDistances(root->right, distance);

        // Vector to store new distances after incrementing
        vector<int> newDistances;

        // Check pairs from left and right distances
        for (int l : leftDistances) {
            for (int r : rightDistances) {
                // If the sum of distances is within the given limit, increment the answer
                if (l + r <= distance) ans++;
            }
        }

        // Increment distances and add to newDistances if they are less than the given limit
        for (int l : leftDistances) {
            if (l + 1 < distance) newDistances.push_back(l + 1);
        }
        for (int r : rightDistances) {
            if (r + 1 < distance) newDistances.push_back(r + 1);
        }

        // Return the new distances
        return newDistances;
    }

    // Main function to count pairs
    int countPairs(TreeNode* root, int distance) {
        findLeafDistances(root, distance);
        return ans;
    }
};