class Solution {
public:
    string reverseParentheses(string s) {
    int N = s.size();
    int len = 0;
    int open = 0;
    bool flag = false;
    string t;
    string ans;
    stack<int> stk;

    // First pass to build the ans string with '-' and t string
    for(int i = 0; i < N; i++) {
        if(s[i] == '(') {
            stk.push(ans.size());
            open++;
        } else if(s[i] == ')') {
            int start = stk.top();
            stk.pop();
            reverse(ans.begin() + start, ans.end());
            open--;
        } else {
            ans += s[i];
        }
    }

    return ans;
}
};





















/*


        int N = s.size();
        int len = 0;
        int open = 0;
        bool flag = false;
        string t;
        string ans;

        for(int i=0;i<N;i++){
            flag = (open%2 == 1);
            if(s[i] == '('){
                open++;
            }
            else if(s[i] == ')'){
                open--;
            }
            else if(flag){
                ans += '-';
                t += s[i];
                len++;
            }
            else{
                ans += s[i];
            }
        }
        cout << len << endl;
        cout << t << endl << ans;
        int j=len;
        for(int i=0;i<ans.size();i++){
            if(ans[i] == '-'){
                ans[i] = t[j-1];
                j--;
            }
        }

        return ans;

*/











/*


        int i = 0;
        int count=0;
        int rep=0;
        string str = s;
        for(int k=0;k<N;k++){
            if(s[k] == '('){
                rep++;
            }
        }

        for(int t=0;t<rep;t++){
            i=0;
            while(i<N){
            if(s[i] == '('){
                count = 0;
                while(s[count+i] != ')'){
                    count++;
                    if(s[count+i] == '('){
                        count =0;
                        break;
                    }
                }
                count--;
                for(int j=0;j<count;j++){
                    str[i+j+1] = s[i+count-j];
                }
                if(count>0){
                    
                    str[i] = '-';
                    str[i+count+1] = '-';
                    s=str;
                }

                cout << str << endl;
            }


            i++;
            }
        }
        string ans;
        for(int k=0;k<N;k++){
            if(s[k] != '-' && s[k] != '(' && s[k] != ')'){
                ans += s[k];
            }
        }

        return ans;

*/