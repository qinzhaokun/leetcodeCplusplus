class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int count = 0;
        while(m != n){
            m = m >> 1;
            n = n >> 1;
            count++;
        }
        for(int i = 0;i < count;i++){
            m = m << 1;
        }
        return m;
    }
};
