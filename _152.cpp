class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        
        int a = nums[0];
        int b = nums[0];
        int m = nums[0];
        for(int i = 1;i < n;i++){
            if(nums[i] > 0){
                a *= nums[i];
                b *= nums[i];
                
            }
            else{
                int tmpb = a*nums[i];
                int tmpa = b*nums[i];
                a = tmpa;
                b = tmpb;
            }
            a = max(a,nums[i]);
            b = min(b,nums[i]);
            m = max(m,a);
        }
        return m;
    }
};
