class Solution {
public:
    int findMin(vector<int>& nums) {
        int i = 0; int j = nums.size()-1;
        while(i < j){
            if(nums[i] < nums[j]) break;
            int mid = (i+j)>>1;
            if(nums[mid] > nums[i]) i = mid+1;
            else if(nums[mid] < nums[i]) j = mid;
            else i++;
        }
        return nums[i];
    }
};
