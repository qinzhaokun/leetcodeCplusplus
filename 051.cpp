class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        char **q = new char*[n];
        vector<vector<string>> ret;
        for(int i = 0;i < n;i++){
            q[i] = new char[n];
        }
        int a[n];
        memset(a,-1,sizeof(a));
        dfs(q,a,0,n,ret);
        return ret;
    }
    
    void dfs(char** q, int *a, int i, int n,vector<vector<string>> &ret){
        if(i == n){
            ret.push_back(package(q,n));
            return;
        }
        for(int j = 0;j < n;j++){
            //same column
            if(a[j] != -1) continue;
            int k = 0;
            for(;k < n;k++){
                if(a[k] != -1 && abs(i-a[k]) == abs(j-k)) break;
            }
            if(k == n){
                q[i][j] = 'Q';
                a[j] = i;
                dfs(q,a,i+1,n,ret);
                a[j] = -1;
                q[i][j] = '.'; 
            }
        }
    }
    
    vector<string> package(char** q, int n){
        vector<string> ret;
        for(int i = 0;i < n;i++){
            string a = "";
            for(int j = 0;j < n;j++){
                if(q[i][j] == 'Q') a += 'Q';
                else a += '.';
            }
            ret.push_back(a);
        }
        return ret;
    }
};
