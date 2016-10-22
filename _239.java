public class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int j = 0; int last = 0;
        if(nums.length == 0 || nums.length-k+1 <=0) return new int[0];
        int [] ans = new int[nums.length-k+1];
        int index = 0;
        for(int i = 0;i < nums.length;i++){
            if(nums[i] > nums[j]) j = i;
            if(i == k-1){
                ans[index++] = nums[j];
                continue;
            }
            if(i >= k){
                last++;
                if(j == last-1){
                    j = last;
                    for(int t = last+1;t <= i;t++){
                        if(nums[t] > nums[j]) j = t;
                    }
                }
                ans[index++] = nums[j];
            }
        }
        return ans;
    }
}
