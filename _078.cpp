class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> tmp;
        dfs(ret,tmp,nums,0);
        return ret;
    }
    
    void dfs(auto &ret, auto &tmp, auto &nums, int i){
        vector<int> copy(tmp);
        ret.push_back(tmp);
        for(int j = i;j < nums.size();j++){
            tmp.push_back(nums[j]);
            dfs(ret,tmp,nums,j+1);
            tmp.pop_back();
        }
    }
};
