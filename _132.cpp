class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        bool **dp = new bool*[n];
        for(int i = 0;i < n;i++){
            dp[i] = new bool[n];
            memset(dp[i],0,n*sizeof(bool));
        }
        
        for(int i = 0;i < n;i++){
            dp[i][i] = true;
            if(i+1 < n && s[i] == s[i+1]) dp[i][i+1] = true;
        }
        
        for(int k = 2;k < n;k++){
            for(int i = 0;i+k < n;i++){
                if(s[i] == s[i+k] && dp[i+1][i+k-1]) dp[i][i+k] = true;
            }
        }
        
        int * dp2 = new int [n];
        //memset(dp2,-1,n*sizeof(int));
        
        for(int i = 0;i < n;i++){
            dp2[i] = i;
            if(dp[0][i]) {dp2[i] = 0;continue;}
            for(int j = i;j > 0;j--){
                if(dp[j][i] && dp2[i] > dp2[j-1]) dp2[i] = dp2[j-1]+1;
            }
        }
        return dp2[n-1];
    }
};
