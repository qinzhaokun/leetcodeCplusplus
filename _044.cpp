class Solution {
public:
    bool isMatch(string s, string p) {
        int n1 = s.length();
        int n2 = p.length();
        bool** dp = new bool*[n1+1];
        for(int i = 0;i <= n1;i++) {
            dp[i] = new bool[n2+1];
            memset(dp[i], false, (n2+1)*sizeof(bool));
        }
        
        dp[0][0] = true;
        for(int i = 0;i < n2;i++){
            if(p[i] == '*' && dp[0][i]){
                dp[0][i+1] = true;
            }
        }
        
        for(int i = 0;i < n1;i++){
            for(int j = 0;j < n2;j++){
                //dp[i+1][j+1]
                if((s[i] == p[j] || p[j] == '?') && dp[i][j]) dp[i+1][j+1] = true;
                else if(p[j] == '*'){
                    if(dp[i+1][j] || dp[i][j+1]) dp[i+1][j+1] = true;
                }
            }
        }
        return dp[n1][n2];
    }
};
