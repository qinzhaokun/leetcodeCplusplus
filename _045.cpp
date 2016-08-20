class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        
        int max = 0;
        int step = 0;
        int i = 0;
        int nextMax = 0;
        while(max < n-1 && i < n){
            if(i > max){
                step++;
                max = nextMax;
            }
            
            if(i+nums[i] > nextMax) nextMax = i+nums[i];
                
            i++;
        }
        return step;
    }
};
