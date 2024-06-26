class Solution {
public:
    int calPoints(vector<string>& operations) {
        int N = operations.size();
        vector<int> nums;
        for(int i=0;i<N;i++){
            string s = operations[i];
            if(s == "C")
                nums.pop_back();
            else if (s == "D"){
                nums.push_back(nums[nums.size()-1]*2);
            }
            else if (s == "+"){
                nums.push_back(nums[nums.size()-1] + nums[nums.size()-2]);
            }
            else{
                nums.push_back(stoi(s));
            }
        }

        int res=0;
        for(int i=0;i<nums.size();i++){
            res += nums[i];
        }
        return res;
    }
};