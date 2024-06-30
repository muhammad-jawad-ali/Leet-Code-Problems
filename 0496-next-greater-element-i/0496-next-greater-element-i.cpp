class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int N1 = nums1.size();
        int N2 = nums2.size();
        vector<int> ans;

        bool greater = false;
        for(int i=0;i<N1;i++){
            int j=0;
            while(nums1[i] != nums2[j]){
                j++;
            }
            for(;j<N2;j++){
                if(nums2[j] > nums1[i] ){
                    greater = true;
                    ans.push_back(nums2[j]);
                    break;
                }
            }
            if(!greater){
                ans.push_back(-1);
            }
            greater = false;
        }
        return ans;
    }
};