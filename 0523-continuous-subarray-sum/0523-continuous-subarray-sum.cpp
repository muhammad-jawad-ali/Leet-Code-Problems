class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int len = nums.size();
        if (len < 2) {
            return false;
        }

        int sum = 0;
        int prevR = 0; 
        unordered_set<int> r;

        for (int i = 0; i < len; ++i) {
            sum += nums[i];
            int currentR = sum % k;

            if (r.count(currentR)) {
                return true;
            }

            r.insert(prevR);
            prevR = currentR;
        }

        return false;
    }
};
