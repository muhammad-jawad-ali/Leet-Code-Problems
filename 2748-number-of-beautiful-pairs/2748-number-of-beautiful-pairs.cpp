class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int len = nums.size();
    int count = 0;
    vector<int> leadingDigit(len);

    for (int i = 0; i < len; ++i) {
        int n = nums[i];
        while (n >= 10)
            n /= 10;
        leadingDigit[i] = n;
    }

    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (std::gcd(leadingDigit[i], nums[j] % 10) == 1) {
                cout << nums[i] << ", " << nums[j]  << " = " << std::gcd(nums[i], nums[j]) << endl;
                count++;
            }
        }
    }

    return count;
    }
};