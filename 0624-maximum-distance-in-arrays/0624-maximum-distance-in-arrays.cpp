class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int minVal = arrays[0][0]; // Start with the first array's minimum
        int maxVal = arrays[0].back(); // Start with the first array's maximum

        int result = 0;

        for (int i = 1; i < arrays.size(); i++) {
            // Compare with current minimum and maximum from previous arrays
            result = max(result, max(abs(maxVal - arrays[i][0]), abs(arrays[i].back() - minVal)));

            // Update global minimum and maximum
            minVal = min(minVal, arrays[i][0]);
            maxVal = max(maxVal, arrays[i].back());
        }

        return result;
    }
};
