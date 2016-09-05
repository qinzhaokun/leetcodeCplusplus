class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();
        int i = 1;
        for(int j = 2;j < nums.size();j++){
            if(nums[j] == nums[i] && nums[j] == nums[i-1]) continue;
            else{
                swap(nums[j],nums[i+1]);
                i++;
            }
        }
        return i+1;
    }
    
    void swap(int &i ,int &j){
        int t = i;
        i = j;
        j = t;
        
    }
};
