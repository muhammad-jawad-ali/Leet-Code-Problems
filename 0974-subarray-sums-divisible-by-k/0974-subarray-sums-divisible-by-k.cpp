class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
    int size = nums.size();
    int sum = 0, count = 0;
    
    for (int i = 0; i < size; ++i) {
        sum = 0;
        for (int j = i; j < size; ++j) {
            sum += nums[j];
            if (sum % k == 0) {
                count++;
            }
        }
    }
    
    return count;
}

};