public class Solution {
    public List<String> summaryRanges(int[] nums) {
        int n = nums.length;
        List<String> list = new ArrayList<>();
        if(n == 0) return list;
        int j = 0;
        for(int i = 1;i < n;i++){
            if(nums[i] != nums[i-1]+1){
                if(i-1 == j){
                    String tmp = String.valueOf(nums[j]);
                    list.add(tmp);
                }
                else{
                    String tmp = nums[j] + "->" + nums[i-1];
                    list.add(tmp);
                }
                j = i;
            }
        }
        if(j == n-1){
            String tmp = String.valueOf(nums[j]);
            list.add(tmp);
        }
        else{
            String tmp = nums[j] + "->" + nums[n-1];
            list.add(tmp);
        }
        
        return list;
    }
}
