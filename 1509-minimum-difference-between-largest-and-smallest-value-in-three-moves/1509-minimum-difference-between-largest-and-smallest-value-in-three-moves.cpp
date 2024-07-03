class Solution {
public:
    int minDifference(vector<int>& nums) {
        int N = nums.size();
        if (N < 4) {
            return 0;
        }
        
        sort(nums.begin(), nums.end());
        
        int min_diff = INT_MAX;
        
        // Case 1: Remove the three largest elements
        min_diff = min(min_diff, nums[N-4] - nums[0]);
        
        // Case 2: Remove the two largest elements and the smallest element
        min_diff = min(min_diff, nums[N-3] - nums[1]);
        
        // Case 3: Remove the largest element and the two smallest elements
        min_diff = min(min_diff, nums[N-2] - nums[2]);
        
        // Case 4: Remove the three smallest elements
        min_diff = min(min_diff, nums[N-1] - nums[3]);
        
        return min_diff;
    }
};
