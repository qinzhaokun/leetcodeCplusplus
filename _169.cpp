class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ret = nums[0];
        int time = 1;
        for(int i = 1;i < nums.size();i++){
            if(nums[i] != ret){
                time--;
            }
            else{
                time++;
            }
            if(time == 0){
                ret = nums[i+1];
                time = 1;
                i++;
            }
        }
       return ret; 
    }
    
};
