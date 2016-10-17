public class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        return Math.max(max(nums,0,n-2),max(nums,1,n-1));
    }
    
    int max(int [] nums, int i, int j){
        int n = j-i+1;
        int a = nums[i];
        int b = 0;
        for(int k = i+1;k <= j;k++){
            int aa = b + nums[k];
            int bb = Math.max(a,b);
            a = aa;
            b = bb;
        }
        return Math.max(a,b);
    }
}
