class Solution {
public:
    int numTrees(int n) {
        if(n < 3) return n;
        
        int *dp = new int[n+1];
        memset(dp,0,(n+1)*sizeof(int));
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3;i <= n;i++){
            for(int j = 0;j < i;j++){
                dp[i] += dp[j]*dp[i-1-j];
            }
        }
        return dp[n];
    }
};
