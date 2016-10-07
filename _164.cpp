class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return 0;
        int minn = nums[0]; int maxx = nums[0];
        
        for(int i = 1;i < n;i++){
            if(minn > nums[i]) minn = nums[i];
            if(maxx < nums[i]) maxx = nums[i];
        }
        
        int gap = (maxx-minn)/(n-1);
        
        if(gap == 0) gap++;
        
        int l = (maxx)/gap;
        int Min[l+1]; int Max[l+1];
        memset(Min,-1,sizeof(Min)); memset(Max,-1,sizeof(Max));
        
        for(int i = 0;i < n;i++){
            int t = nums[i] - minn;
            int index = t/gap;
            if(Min[index] == -1){
                Min[index] = nums[i]; Max[index] = nums[i];
            }
            else{
                Min[index] = min(Min[index],nums[i]);
                Max[index] = max(Max[index],nums[i]);
            }
        }
        
        int ret = 0;int last = minn;
        for(int i = 0;i < l+1;i++){
            if(Max[i] != -1){
                ret = max(ret,Min[i]-last);
                last = Max[i];
            }
        }
        return ret;
    }
};
