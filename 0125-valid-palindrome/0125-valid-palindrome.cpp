class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int k = 0;
        for(int i=0;i<n;i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                s[k++] = s[i];
            }
            else if(s[i] >= 'A' && s[i] <= 'Z'){
                s[k++] = s[i]+32;
            }
        }

        int mid = k/2;
        for(int i=0;i<mid;i++){
            if(s[i] != s[k-1-i]){
                return false;
            }
        }
        
        return true;
    }
};