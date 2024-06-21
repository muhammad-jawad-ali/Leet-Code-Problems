class Solution {
public:
    int diagonalPrime(std::vector<std::vector<int>>& nums) {
        int r = nums.size();
        int c = nums[0].size();
        int max = 0;

        for (int i = 0; i < r; i++) {
            if (isPrime(nums[i][i])) {
                if(max<nums[i][i]){
                    max = nums[i][i];
                }
            }
        }

        for (int i = 0; i < r; i++) {
            if (isPrime(nums[i][r - 1 - i])) {
                if(max<nums[i][r - 1 - i]){
                    max = nums[i][r - 1 - i];
                }
            }
        }

        return max;
    }
    bool isPrime(int n) {
        if (n <= 1) return false;
        if (n == 2 || n == 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) return false;
        }
        return true;
    }
};