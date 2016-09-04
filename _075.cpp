class Solution {
public:
    void sortColors(vector<int>& nums) {
        int last0 = -1;int last1 = 0;
        
        for(int k = 0;k < nums.size();k++){
            if(nums[k] == 0){
                nums[++last0] = 0;
                if(last1 != 0) nums[last0+last1] = 1;
                if(last0+last1 != k) nums[k] = 2;
            }
            else if(nums[k] == 1){
                nums[last0+(++last1)] = 1;
                if(last0 + last1 != k) nums[k] = 2;
            }
        }
    }
};
