class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if(m == 0) return 0;
        int n = obstacleGrid[0].size();
        
        int **dp = new int*[m];
        for(int i = 0;i < m;i++) dp[i] = new int[n];
        if(obstacleGrid[0][0]) return 0;
        dp[0][0] = 1;
        for(int i = 1;i < n;i++){
            if(!obstacleGrid[0][i] && dp[0][i-1]) dp[0][i] = 1;
            else dp[0][i] = 0;
        }
        
        for(int j = 1;j < m;j++){
            if(!obstacleGrid[j][0] && dp[j-1][0]) dp[j][0] = 1;
            else dp[j][0] = 0;
        }
        
        for(int i = 1;i < m;i++){
            for(int j = 1;j < n;j++){
                if(!obstacleGrid[i][j]){
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        
        return dp[m-1][n-1];
    }
};
