class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        
        int max = nums[0];
        int localMax = max;
        for(int i = 1;i < n;i++){
            if(localMax <= 0) localMax = nums[i];
            else localMax += nums[i];
            if(localMax > max) max = localMax;
        }
        return max;
    }
};
