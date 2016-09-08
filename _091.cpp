class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        int *dp = new int[n];
        memset(dp,0,n*sizeof(int));
        
        if(n == 0) return n;
        if(n == 1){
            if(s[0] == '0') return 0;
            else return 1;
        }
        
        dp[0] = 1;
        if(s[0] == '0') return 0;
        if(s[1] != '0') dp[1] += dp[0];
        if(s[1] == '0' && s[0] > '2') return 0;
        if(s[0] == '1' || (s[0] == '2' && s[1] < '7')) dp[1]++;
        
        for(int i = 2;i < n;i++){
            if(s[i] != '0') dp[i] += dp[i-1];
            else{
                if(s[i-1] > '2' || s[i-1] == '0') return 0;
            }a
            if(s[i-1] != '0' && (s[i-1] == '1' || (s[i-1] == '2' && s[i] < '7'))) dp[i] += dp[i-2];
        }
        
        return dp[n-1];
    }
};
