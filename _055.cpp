class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return true;
        int max = nums[0];
        int i = 0;
        while(i <= max){
            if(max >= n-1) return true;
            if(i + nums[i] > max) max = i+nums[i];
            i++;
        }
        return false;
    }
};
