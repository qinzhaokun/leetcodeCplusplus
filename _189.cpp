class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        if(k == 0) return;
        int i = 0; int j = n-k-1;
        while(i < j){
            ex(nums[i],nums[j]);
            i++;j--;
        }
        i = n-k;j=n-1;
        while(i < j){
            ex(nums[i],nums[j]);
            i++;
            j--;
        }
        i = 0;j = n-1;
        while(i < j){
            ex(nums[i],nums[j]);
            i++;j--;
        }
    }
    
    void ex(int &a, int &b){
        a += b;
        b = a-b;
        a-=b;
    }
};
