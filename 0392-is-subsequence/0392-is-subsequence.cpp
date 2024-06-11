class Solution {
public:
    bool isSubsequence(string s, string t) {
    int sl = s.length();
    int count = 0,temp=0;
    int tl = t.length();
    for(int i=0;i<sl;i++){
        for(int j=temp;j<tl;j++){
            
            if(t[j]==s[i]){
                
                count++;
                temp = j;
                s[i] = ' ';
                t[j] = ' ';
                break;
            }
        }
    }
    
    if(count == sl){
        return true;
    }
    return false;
    }
};