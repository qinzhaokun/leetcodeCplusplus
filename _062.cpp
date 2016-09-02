class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 1 || n == 1) return 1;
        
        if(m > n){
            m += n;
            n = m-n;
            m = m-n;
        }
        m--;n--;
        //calulate (m+n)!/(m!*n!)
        
        long ret = 1;
        long r1 = 1;
        for(int i = 1;i <= m+n;i++){
            if(i <= m) r1*=i;
            if(i > n) ret *= i;
        }
        
        return (int)(ret/r1);
    }
};
