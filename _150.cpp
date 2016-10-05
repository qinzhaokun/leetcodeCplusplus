class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i = 0;i < tokens.size();i++){
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/"){
                int num = 0;
                int j = 0; bool negative = false;
                if(tokens[i][0] == '-') {negative = true;j++;}
                while(j < tokens[i].length()){
                    num = 10*num + (tokens[i][j]-'0');j++;
                }
                if(negative) num = -num;
                s.push(num);
            }
            else{
                int a = s.top();s.pop();
                int b = s.top();s.pop();
                if(tokens[i] == "+"){
                    s.push(a+b);
                }
                else if(tokens[i] == "-"){
                    s.push(b-a);
                }
                else if(tokens[i] == "*"){
                    s.push(a*b);
                }
                else{
                    s.push(b/a);
                }
            }
        }
        return s.top();
    }
};
