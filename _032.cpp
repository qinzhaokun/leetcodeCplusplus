class Solution {
public:
    int longestValidParentheses(string s) {
         int n = s.length();
        //char [] s = S.toCharArray();
        stack<int> stack;
        int max = 0;
        for(int i = 0;i < n;i++){
            if(s[i] == '('){
                stack.push(i);
            }
            else{
                if(!stack.empty() && s[stack.top()] == '('){
                    stack.pop();
                    if(stack.empty()){
                        if(i+1 > max) max = i+1;
                    }
                    else{
                        int tmp = stack.top();
                        if(i-tmp > max) max = i-tmp;
                    }
                }
                else{
                    stack.push(i);
                }
            }
        }
        return max;
        
    }
};
