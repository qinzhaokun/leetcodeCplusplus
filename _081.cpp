class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int i = 0; int j = nums.size()-1;
        
        while(i <= j){
            int mid = i + (j-i)/2;
            if(nums[mid] == target) return true;
            
            if(nums[mid] > nums[i]){
                if(target >= nums[i] && target < nums[mid]){
                    j = mid-1;
                }
                else{
                    i = mid+1;
                }
            }
            else if(nums[mid] < nums[i]){
                if(target > nums[mid] && target <= nums[j]){
                    i = mid+1;
                }
                else{
                    j = mid-1;
                }
            }
            else{
                i++;
            }
        }
        
        return false;
    }
};
