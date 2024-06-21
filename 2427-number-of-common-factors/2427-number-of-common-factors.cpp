class Solution {
public:
    int commonFactors(int a, int b) {
        int small ;
        int count = 0;
        if(a>b)
        small = b;
        else
        small = a;
        for(int i=1;i<=small;i++){
            if(a%i == 0 && b%i == 0 ){
                count++;
            }
        }
        return count;
    }
};