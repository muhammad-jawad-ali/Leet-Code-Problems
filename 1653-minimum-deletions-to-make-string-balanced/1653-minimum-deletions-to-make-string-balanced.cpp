class Solution {
public:
    
    int minimumDeletions(string s) {
        int a=0;
        int b=0;
        int n = s.size();
        int count = 0;
        for(int i=0;i<n;i++){
            if(s[i] == 'b')
            b++;
            else
            if(b>0){
                b--;
                count++;
            }
        }
        return count;
    }
};