class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        sort(candidates.begin(),candidates.end());
        vector<int> now;
        dfs(candidates,0,target,now,ret);
        return ret;
    }
    
    void dfs(vector<int>& candidates, int i, int target,vector<int> now, vector<vector<int>>& ret){
        if(target == 0) 
        {
            vector<int> a;
            for(int i = 0;i < now.size();i++){
                a.push_back(candidates[now[i]]);
            }
            ret.push_back(a);
        }
        else if(target < 0 || i == candidates.size() || (i < candidates.size() && candidates[i] > target)){
            return;
        }
        else{
            if(i > 0 && candidates[i] == candidates[i-1] && (now.size() == 0 || (now.size() > 0 && *(now.end()-1) != i-1))){
                
            }
            else{
                now.push_back(i);
                dfs(candidates,i+1,target-candidates[i],now, ret);
                now.pop_back();
            }
            
            dfs(candidates,i+1,target,now,ret);
        }
    }
};

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        sort(candidates.begin(),candidates.end());
        vector<int> now;
        dfs(candidates,0,target,now,ret);
        return ret;
    }
    
    void dfs(vector<int>& candidates, int i, int target,vector<int> now, vector<vector<int>>& ret){
        if(target == 0) 
        {
            ret.push_back(now);
        }
        else if(target < 0 || i == candidates.size() || (i < candidates.size() && candidates[i] > target)){
            return;
        }
        else{
            for(int j = i;j < candidates.size();j++){
                if(j != i && candidates[j] == candidates[j-1]) continue;
                else{
                    now.push_back(candidates[j]);
                    dfs(candidates,j+1,target-candidates[j],now,ret);
                    now.pop_back();
                }
            }
        }
    }
};
