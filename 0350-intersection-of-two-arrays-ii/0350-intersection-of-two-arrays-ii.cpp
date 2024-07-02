class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        // int N=0;
        int N1 = nums1.size();
        int N2 = nums2.size();
        // if(N1>N2)
        // N = N2;
        // else
        // N = N1;

        vector<int> ans;
        

        for(int i=0;i<N1;i++){
            for(int j=0;j<N2;j++){
                if(nums1[i]==nums2[j]){
                    nums2[j] = - 1;
                    ans.push_back(nums1[i]);
                    break;
                }
            }
        }
        return ans;
    }
};