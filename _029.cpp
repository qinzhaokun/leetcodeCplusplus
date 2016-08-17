class Solution {
public:
    int divide(int dividend, int divisor) {
        long b = (long)dividend;long a = (long)divisor;
        bool flag = false;
        if((a < 0 && b > 0) || (a > 0 && b < 0)){
            flag = true;
            
        }
        if(a < 0){
            a=-a;
        }
        if(b<0){
            b=-b;
        }
        
        long ret = 0;
        
        while(b>=a){
            long base = a;
            long re = 1;
            while(b >= base){
                b -= base;
                ret += re;
                base *= 2;
                re *=2;
            }
        }
        
        if(flag){
            ret = -ret;
        }
        if(ret >= INT_MAX) return INT_MAX;
        else if(ret <= INT_MIN) return INT_MIN;
        else return ret;
        
    }
};
