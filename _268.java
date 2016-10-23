public class Solution {
    public int missingNumber(int[] nums) {
        for(int i = 0;i < nums.length;i++){
            if(nums[i] < nums.length){
                if(nums[i] != nums[nums[i]]){
                    //exchange nums[i] and nums[nums[i]]
                    int tmp = nums[nums[i]];
                    nums[nums[i]] = nums[i];
                    nums[i] = tmp;
                    i--;
                }
            }
        }
        
        for(int i = 0;i < nums.length;i++){
            if(nums[i] != i) return i;
        }
        return nums.length;
    }
}
