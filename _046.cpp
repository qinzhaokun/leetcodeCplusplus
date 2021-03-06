class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> ret;
      perm(0,nums,ret);
      return ret;
    }
    
    void perm(int i, vector<int>& nums, vector<vector<int>>& ret){
        if(i == nums.size()){
            vector<int> one(nums);
            ret.push_back(one);
        }
        else{
            for(int j = i;j < nums.size();j++){
                swap(nums,i,j);
                perm(i+1,nums,ret);
                swap(nums,i,j);
            }
        }
    }
    
    void swap(vector<int>& nums, int i, int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};
