public class Solution {
    public int nthUglyNumber(int n) {
        int [] ans = new int[n];
        ans[0] = 1;
        int p2 = 0;
        int p3 = 0;
        int p5 = 0;
        for(int i = 1;i < n;i++){
            ans[i] = Math.min(ans[p2]*2,Math.min(ans[p3]*3,ans[p5]*5));
            
            if(ans[p2]*2 == ans[i]) p2++;
            if(ans[p3]*3 == ans[i]) p3++;
            if(ans[p5]*5 == ans[i]) p5++;
        }
        return ans[n-1];
    }
}
