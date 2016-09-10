class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        string tmp ="";
        if(s.length() < 4) return ret;
        for(int i = 0;i < 3 && i < s.length();i++){
            int num = 0;
            int k = 0;
            while(k <= i){
                num = 10*num+(s[k]-'0');
                k++;
            }
            if(num <= 255){
                dfs(ret,tmp+to_string(num) + '.',i+1,1,s);
            }
            if(i == 0 && s[0] == '0') break;
        }
        
        return ret;
    }
    
    void dfs(auto &ret, string tmp, int i, int n, string s){
        if(i == s.length() && n == 4){
            string copy(tmp);
            ret.push_back(tmp.substr(0,tmp.length()-1));
            return;
        }
        if(s.length()-i > (4-n)*3 || s.length()-i < 4-n) return;
        
        for(int j = i;j < s.length() && j < i+3;j++){
            int num = 0;
            int k = i;
            while(k <= j){
                num = 10*num+(s[k]-'0');
                k++;
            }
            if(num <= 255){
                dfs(ret,tmp+to_string(num)+'.',j+1,n+1,s);
            }
            if(j == i && s[i] == '0') break;
        }
    }
};
