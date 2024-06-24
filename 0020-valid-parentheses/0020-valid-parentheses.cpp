class Solution {
public:
    bool isValid(string s) {
        int N = s.length();
        if(N%2==1)
        return false;

        stack<char> stack;

        for(int i=0;i<N;i++){
            if(s[i] == '(' ||s[i] == '[' || s[i] == '{'){
                stack.push(s[i]);
            }
            else if(s[i] == ')' && stack.top() == '('){
                stack.pop();
            }
            else if(s[i] == ']' && stack.top() == '['){
                stack.pop();
            }
            else if(s[i] == '}' && stack.top() == '{'){
                stack.pop();
            }
            else
                return false;
        }

        

        return stack.empty();
    }
};