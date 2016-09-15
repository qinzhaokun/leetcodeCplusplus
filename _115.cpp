class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        
        int ** dp = new int *[m+1];
        for(int i = 0;i < m+1;i++){
            dp[i] = new int[n+1];
            memset(dp[i],0,(n+1)*sizeof(int));
        }
        
        for(int i = 0;i <= m;i++){
            dp[i][0] = 1;
        }
        
        for(int i = 1;i < m+1;i++){
            for(int j = 1;j < n+1;j++){
                dp[i][j] = dp[i-1][j];
                if(s[i-1] == t[j-1]) dp[i][j] += dp[i-1][j-1];
            }
        }
        
        return dp[m][n];
    }
};
