class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size() == 0) return 0;
        int m = triangle.size();
        int n = triangle[m-1].size();
        int * dp = new int[n];
        memset(dp,0,n*sizeof(int));
        dp[0] = triangle[0][0];
        for(int i = 1;i < m;i++){
            int l = triangle[i].size();
            dp[l-1] = dp[l-2]+triangle[i][l-1];
            for(int j = l-2;j > 0;j--){
                dp[j] = min(dp[j],dp[j-1]) + triangle[i][j];
            }
            dp[0] = dp[0] + triangle[i][0];
        }
        
        int ret = dp[0];
        for(int i = 1;i < n;i++){
            ret = min(ret,dp[i]);
        }
        return ret;
    }
};
