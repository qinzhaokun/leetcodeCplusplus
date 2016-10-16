class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        int min = 0;
        int j = 0;int sum = 0;
        for(int i = 0;i < n;i++){
            sum += nums[i];
            if(sum >=s){
                while(sum>=s){
                    sum-=nums[j];
                    j++;
                }
                j--;
                sum+=nums[j];
                if(min == 0 || min > (i-j+1)) min = i-j+1;
                sum-=nums[j];
                j++;
            }
        }
        return min;
    }
};
