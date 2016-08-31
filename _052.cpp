class Solution {
public:
    int totalNQueens(int n) {
        int ret = 0;
        int a[n+1];
        memset(a,0,sizeof(a));
        dfs(1,n,a,ret);
        return ret;
    }
    
    void dfs(int i, int n, int *a, int& ret){
        if(i == n+1) ret++;
        else{
            for(int j = 1;j <= n;j++){
                if(a[j]) continue;
                int k = 1;
                for(;k <= n;k++){
                    if(a[k] && abs(i-a[k]) == abs(j-k)) break;
                }
                if(k == n+1){
                    a[j] = i;
                    dfs(i+1,n,a,ret);
                    a[j] = 0;
                }
            }
        }
    }
};
