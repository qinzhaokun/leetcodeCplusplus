public class Solution {
    public List<Integer> majorityElement(int[] nums) {
        int t1 = 0;
        int count1 = 0;
        int t2 = 0;
        int count2 = 0;
        List<Integer> ans = new ArrayList<>();
        for(int i = 0;i < nums.length;i++){
            if(count1 == 0){
                t1 = nums[i];
                count1 = 1;
            }
            else if(nums[i] == t1){
                count1++;
            }
            else if(count2 == 0){
                t2 = nums[i];
                count2++;
            }
            else if(t2 == nums[i]){
                count2++;
            }
            else{
                count1--;
                count2--;
                if(count1 == 0 && count2 > 0){
                    count1 = count2;
                    t1 = t2;
                    count2 = 0;
                }
            }
        }
        
        if(count1 > 0){
            count1 = 0;
            for(int i = 0;i < nums.length;i++){
                if(t1 == nums[i]) count1++;
            }
            if(count1 > nums.length/3) ans.add(t1);
        }
        if(count2 > 0){
            count2 = 0;
            for(int i = 0;i < nums.length;i++){
                if(t2 == nums[i]) count2++;
            }
            if(count2 > nums.length/3) ans.add(t2);
        }
    
        return ans;
    }
}
