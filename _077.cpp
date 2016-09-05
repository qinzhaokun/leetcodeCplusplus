class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> tmp;
        dfs(ret,tmp,n,1,k);
        return ret;
    }
    
    void dfs(vector<vector<int>> &ret, vector<int> &tmp, int n, int i, int k){
        if(tmp.size() == k){
            vector<int> copy(tmp);
            ret.push_back(copy);
            return;
        }
        for(int j = i;j <= n;j++){
            if(n-j+1+tmp.size() < k) break;
            tmp.push_back(j);
            dfs(ret,tmp,n,j+1,k);
            tmp.pop_back();
        }
    }
};
