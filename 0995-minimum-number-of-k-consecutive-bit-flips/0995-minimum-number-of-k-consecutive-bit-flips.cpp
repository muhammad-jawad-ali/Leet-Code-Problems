class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int flip = 0;
        int ans = 0;
        int N = nums.size();
        vector<int> flipped(N, 0);

        for(int i=0;i<N;i++){
            if (i >= k) {
                flip ^= flipped[i - k];
            }
            if (flip == nums[i]) {
                if (i + k > N) {
                    return -1;
                }
                flipped[i] = 1;
                flip ^= 1;
                ans++;
            }
        }
        return ans;
    }
};

















