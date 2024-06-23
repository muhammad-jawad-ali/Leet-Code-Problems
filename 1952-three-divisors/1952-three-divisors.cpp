class Solution {
public:
    bool isThree(int n) {
        int i=2;
        while(i<n){
            if(n%i == 0){
                return true;
            }
            i++;
        }
        return false;
    }
};