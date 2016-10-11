public class Solution {
    public String largestNumber(int[] nums) {
        String [] a = new String[nums.length];
        for(int i = 0;i < nums.length;i++){
            a[i] = String.valueOf(nums[i]);
        }
        Arrays.sort(a, new Comparator<String>(){
            //@Override
           public int compare(String a, String b){
               String aa = a+b;
               String bb = b+a;
               return bb.compareTo(aa);
           } 
        });
        if("0".equals(a[0])) return a[0];
        StringBuilder sb = new StringBuilder();
        for(int i = 0;i < a.length;i++){
            sb.append(a[i]);
        }
        return sb.toString();
    }
}
