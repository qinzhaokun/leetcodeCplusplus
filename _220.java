public class Solution {
    public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
        if(t < 0) return false;
        long b = (long)(t+1);
        Map<Long,Long> map = new HashMap<>();
        for(int i = 0;i < nums.length;i++){
            long index = ((long)nums[i]-Integer.MIN_VALUE)/b;
            if(map.containsKey(index)) return true;
            if(map.containsKey(index-1)){
                long a = map.get(index-1);
                if(Math.abs(nums[i]-a) <= t) return true;
            }
            if(map.containsKey(index+1)){
                long a = map.get(index+1);
                if(Math.abs(nums[i]-a) <= t) return true; 
            }
            map.put(index,(long)nums[i]);
            if(i-k>=0){
                long removeIndex = ((long)nums[i-k]-Integer.MIN_VALUE)/b;
                map.remove(removeIndex);
            }
        }
        return false;
    }
}
