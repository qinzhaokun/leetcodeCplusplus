class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i < nums.size();i++){
            if(nums[i] == i+1) continue;
            else{
                if(nums[i]>0&& nums[i]<= n && nums[nums[i]-1] != nums[i]){
                    swap(nums,i,nums[i]-1);
                    i--;
                }
            }
        }
        
        for(int i = 0;i < n;i++){
            if(nums[i] != i+1) return i+1;
        }
        return n+1;
    }
    
    void swap(vector<int>& nums, int i, int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};
