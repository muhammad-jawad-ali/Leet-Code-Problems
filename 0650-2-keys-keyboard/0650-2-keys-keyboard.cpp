class Solution {
public:
    int minSteps(int n) {
        if(n == 1)
        return 0;
        if(n<6)
        return n;

        int ans=0;
        int i=2;
        while(n != 1){
            if(n % i == 0){
                n /= i;
                ans += i;
                i = 1;
            }
            i++;
        }

        if(ans == 0){
            return n;
        }        
        return ans;

    }
};