public class Solution {
    public int hIndex(int[] citations) {
        Arrays.sort(citations);
        int n = citations.length;
        for(int i = n-1;i >= 0;i--){
            if(citations[n-1-i] >= i+1) return i+1;
        }
        return 0;
    }
}
