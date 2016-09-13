class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length();
        int n2 = s2.length();
        int n3 = s3.length();
        if(n1 + n2 != n3) return false;
        
        bool ** dp = new bool *[n1+1];
        for(int i = 0;i < n1+1;i++){
            dp[i] = new bool [n2+1];
            memset(dp[i],false,(n2+1)*sizeof(bool));
        }
        
        dp[0][0] = true;
        for(int i = 1;i <= n1;i++){
            dp[i][0] = dp[i-1][0] && s1[i-1] == s3[i-1];
        }
        for(int j = 1;j <= n2;j++){
            dp[0][j] = dp[0][j-1] && s2[j-1] == s3[j-1];
        }
        for(int i = 0;i < n1;i++){
            for(int j = 0;j < n2;j++){
                dp[i+1][j+1] = (dp[i][j+1] && s1[i] == s3[i+j+1]) || (dp[i+1][j] && s2[j] == s3[i+j+1]);
            }
        }
        
        return dp[n1][n2];
    }
};
