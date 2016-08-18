class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0;int j = n-1;
        while(i < j){
            int mid = i+ (j-i)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                j = mid-1;
            }
            else{
                i = mid+1;
            }class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int i = 0;int j = nums.size()-1;
        vector<int> ret;
        while(i < j){
            int mid = i + (j-i)/2;
            if(nums[mid] >= target){
                j = mid;
            }
            else{
                i = mid+1;
            }
        }
        if(nums[i] != target){
            ret.push_back(-1);
            ret.push_back(-1);
        }
        else{
            ret.push_back(i);
            i = 0;j = nums.size()-1;
            
            while(i < j){
                int mid = i + (j-i)/2 + 1;
                if(nums[mid] <= target){
                    i = mid;
                }
                else{
                    j = mid-1;
                }
            }
            
            ret.push_back(i);
        }
        return ret;
    }
};
        }
        if(nums[i] < target) return i+1;
        else return i;
    }
};
