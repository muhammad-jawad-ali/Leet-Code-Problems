class Solution {
public:
    int rangeSum(std::vector<int>& nums, int n, int left, int right) {
        std::vector<long long> ans;  
        for(int i = 0; i < n; i++) {
            long long sum = 0;  
            for(int j = i; j < n; j++) {
                sum += nums[j];
                ans.push_back(sum);
            }
        }
        std::sort(ans.begin(), ans.end());
        long long res = 0;
        for(int i = left - 1; i <= right - 1; i++) {
            res += ans[i];
        }
        return res % 1000000007; 
    }
};
