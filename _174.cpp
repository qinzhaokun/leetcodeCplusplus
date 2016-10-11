class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        if(m == 0) return 0;
        int n = dungeon[0].size();
        vector<vector<int>> dp(m);
        for(int i = 0;i < m;i++) dp[i] = vector<int>(n);
        
        dp[m-1][n-1] = max(-dungeon[m-1][n-1],0);
        
        for(int i = m-2;i >= 0;i--){
            dp[i][n-1] = -dungeon[i][n-1] + dp[i+1][n-1];
            if(dp[i][n-1] < 0) dp[i][n-1] = 0;
        }
        for(int j = n-2;j >= 0;j--){
            dp[m-1][j] = -dungeon[m-1][j] + dp[m-1][j+1];
            if(dp[m-1][j] < 0) dp[m-1][j] = 0;
        }
        
        for(int i = m-2;i >= 0;i--){
            for(int j = n-2;j >= 0;j--){
                dp[i][j] = -dungeon[i][j] + min(dp[i+1][j],dp[i][j+1]);
                if(dp[i][j] < 0) dp[i][j] = 0;
            }
        }
        
        return dp[0][0]+1;
    }
};
