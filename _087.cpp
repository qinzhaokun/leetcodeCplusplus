class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n1 = s1.length(); int n2 = s2.length();
        if(n1 != n2) return false;
        
        bool ***dp = new bool**[n1];
        for(int i = 0;i < n1;i++){
            dp[i] = new bool*[n1];
            for(int j = 0;j < n1;j++){
                dp[i][j] = new bool[n1+1];
                memset(dp[i][j],false,(n1+1)*sizeof(bool));
            }
        }
        
        for(int i = 0;i < n1;i++){
            for(int j = 0;j < n2;j++){
                if(s1[i] == s2[j]) dp[i][j][1] = true;
            }
        }
        
        for(int k = 2;k <= n1;k++){
            for(int i = 0;i + k <= n1;i++){
                for(int j = 0;j + k <= n1;j++){
                    //calculate dp[i][j][k]
                    
                    for(int t = 1;t < k;t++){
                        if(dp[i][j][t] && dp[i+t][j+t][k-t]){
                            dp[i][j][k] = true;
                            break;
                        }
                        if(dp[i][j+k-t][t] && dp[i+t][j][k-t]){
                            dp[i][j][k] = true;
                            break;
                        }
                    }
                }
            }
        }
        
        return dp[0][0][n1];
    }
};
