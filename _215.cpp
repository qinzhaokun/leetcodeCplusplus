class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return findK(nums,0,n-1,k);
    }
    
    int findK(vector<int> & nums, int i, int j, int k){
        int t = i;
        for(int s = i+1;s <= j;s++){
            if(nums[s] <= nums[i]){
                t++;
                int tmp = nums[t];
                nums[t] = nums[s];
                nums[s] = tmp;
            }
        }
        int tmp = nums[t];
        nums[t] = nums[i];
        nums[i] = tmp;
        
        if(j-t == k-1) return nums[t];
        else if(j-t > k-1) return findK(nums,t+1,j,k);
        else return findK(nums,i,t-1,k-(j-t+1));
    }
};
