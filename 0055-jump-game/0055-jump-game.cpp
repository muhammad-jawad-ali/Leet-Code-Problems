class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int required = n-1;
        int range = nums[0];
        cout << range << endl << required << endl << endl;

        for(int i=0;i<n && i<=range;i++){
            if(nums[i]>=required){
                return true;
            }
            if((nums[i] + i) >= range){
                range = i + nums[i];
            }
            required--;
            cout << range << endl << required << endl << endl;

        }
        return false;

    }
};