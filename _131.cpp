class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.length();
        // bool **dp = new bool*[n];
        // for(int i = 0;i < n;i++){
        //     dp[i] = new bool[n];
        //     memset(dp[i],0,n*sizeof(bool));
        // }
        
        // for(int i = 0;i < n;i++){
        //     dp[i][i] = true;
        //     if(i+1 < n && s[i] == s[i+1]) dp[i][i+1] = true;
        // }
        
        // for(int k = 2;k < n;k++){
        //     for(int i = 0;i+k < n;i++){
        //         if(s[i] == s[i+k] && dp[i+1][i+k-1]) dp[i][i+k] = true;
        //     }
        // }
        vector<vector<string>> ret;
        vector<string> tmp;
        dfs(ret,tmp,0,n,s);
        return ret;
    }
    
    void dfs(vector<vector<string>> &ret, vector<string> tmp, int i, int n, string s){
        if(i == n){
            vector<string> copy(tmp);
            ret.push_back(copy);
            return;
        }      
        for(int j = i;j < n;j++){
            if(isP(s,i,j)){
                tmp.push_back(s.substr(i,j-i+1));
                dfs(ret,tmp,j+1,n,s);
                tmp.pop_back();
            }
        }
    }
    
    bool isP(string s, int i, int j){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;j--;
        }
        return true;
    }
};
