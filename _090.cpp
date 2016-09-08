class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ret;
        vector<int> tmp;
        dfs(ret,tmp,nums,0);
        return ret;
    }
    
    void dfs(auto &ret, auto &tmp, auto & nums, int i){
        vector<int> copy(tmp);
        ret.push_back(tmp);
        for(int j = i;j < nums.size();j++){
            if(j > i && nums[j] == nums[j-1]) continue;
            tmp.push_back(nums[j]);
            dfs(ret,tmp,nums,j+1);
            tmp.pop_back();
        }
    }
};
