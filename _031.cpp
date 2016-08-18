class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        int j = n-2;
        while(j >= 0 && nums[j] >= nums[j+1]) {
            j--;
        }
        
        if(j >= 0){
            int i = n-1;
            while(nums[i] <= nums[j]) i--;
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }
        j++;
        int i = n-1;
        while(j < i){
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
            i--;j++;
        }
    }
    
};
