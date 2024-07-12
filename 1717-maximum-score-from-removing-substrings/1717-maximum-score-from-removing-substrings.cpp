class Solution {
public:
    int maximumGain(string s, int x, int y) {
        s += '-';
        int res=0;
        char ch,ch1;
        if(x>y){
            ch = 'a';
            ch1 = 'b';
            }
        else{
            int t = x;
            x=y;
            y=t;
            ch = 'b';
            ch1 = 'a';
        }
        cout << ch << ch1 << endl;
        int N = s.size();
        int i=0;
        while(s[i] != '-'){
            if(s[i] == ch && s[i+1] == ch1){
                s.erase(i,2);
                res += x;
                i--;
                i--;
                if(i<-1)
                i=-1;
                cout << res ;
            }
            cout << s << endl;
            i++;
        }
        int j=0;
        while(s[j] != '-'){
            if(s[j] == ch1 && s[j+1] == ch){
                s.erase(j,2);
                res += y;
                j--;
                j--;
                if(j<-1)
                j=-1;
                cout << res ;
            }
            cout << s << endl;
            j++;
        }
        return res;
    }
};