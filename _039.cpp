class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> now;
        dfs(0,target,now,candidates,ret);
        return ret;
    }
    
    void dfs(int i, int target, vector<int> now, vector<int>& candidates,vector<vector<int>>& ret){
        if(target < 0) return;
        if(target == 0){
            ret.push_back(now);
        }
        else{
            for(int j = i;j < candidates.size();j++){
                //dfs(i+1,target,now,candidates,ret);
                if(j > 0 && candidates[j] == candidates[j-1]) continue;
                now.push_back(candidates[j]);
                dfs(j,target-candidates[j],now,candidates,ret);
                now.pop_back();
            }
        }
    }
};
