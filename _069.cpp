class Solution {
public:
    int mySqrt(int x) {
        if(x < 2) return x;
        
        long i = 1;long j = x-1;
        while(i < j){
            long mid = i + (j-i)/2;
            
            if(mid*mid>x){
                j = mid-1;
            }
            else if(mid*mid < x){
                i = mid+1;
            }
            else{
                return mid;
            }
        }
        if(i*i<=x) return i;
        else return i-1;
    }
};
