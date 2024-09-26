class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> nums1;
        int k = 0;
        for(int i=0;i<n-1;i++){
            if(nums[i] == nums[i+1]){
                continue;
            }
            nums1.push_back(nums[i]);
            k++;
        }
        if(nums1[k-1]!=nums[n-1])
        {
            nums1.push_back(nums[n-1]);
            k++;
        }
        nums = nums1;
        return k;
    }
};