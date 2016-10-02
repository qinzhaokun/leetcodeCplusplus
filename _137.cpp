class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int bits[32];
        memset(bits,0,sizeof(bits));
        
        for(int i = 0;i < nums.size();i++){
            for(int j = 0;j < 32;j++){
                bits[j] += ((nums[i]>>j)&1);
            }
        }
        
        int ret = 0;
        for(int i = 0;i < 32;i++){
            ret |= ((bits[i]%3)<<i);
        }
        return ret;
    }
};
