public class Solution {
    public int[] singleNumber(int[] nums) {
        int re = 0;
        for(int i = 0;i < nums.length;i++){
            re = re ^ nums[i];
        }
        int count = 0;
        while(count < 32){
            if(((re >> count)&1) == 1) break;
            count++;
        }
        int [] ans = new int [2];
        if(count == 32) return ans;
        ans[0] = ans[1] = re;
        for(int i = 0;i < nums.length;i++){
            if(((nums[i] >> count)&1) == 1){
                ans[0] ^= nums[i];
            }
            else{
                ans[1] ^= nums[i];
            }
        }
        return ans;
    }
}
