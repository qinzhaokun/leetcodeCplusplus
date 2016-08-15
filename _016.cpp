class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        
        int n = nums.size();
        int min = INT_MAX;
        int ret = 0;
        for(int i = 0;i < n;i++){
            int j = i+1; int k = n-1;
            while(j < k){
                int t = nums[i] + nums[j] + nums[k];
                if(t > target){
                    if(min > t-target) {ret = t;min = t-target;}
                    k--;
                }
                else if(t < target){
                    j++;
                    if(min > target-t) {ret = t;min = target-t;}
                }
                else{
                    return t;
                }
            }
        }
        return ret;
    }
};
