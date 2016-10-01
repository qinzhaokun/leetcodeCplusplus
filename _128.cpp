class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int max = 0;
        map<int,int> m;
        for(int i = 0;i < nums.size();i++){
            if(m.find(nums[i]) != m.end()) continue;
            
            if(m.find(nums[i]-1) != m.end() && m.find(nums[i]+1) != m.end()){
                m[nums[i]] = nums[i];
                int left = m[nums[i]-1];
                int right = m[nums[i]+1];
                m[left] = right;
                m[right] = left;
                if(right-left+1 > max) max = right-left+1;
            }
            else if(m.find(nums[i]-1) != m.end()){
                int left = m[nums[i]-1];
                m[left] = nums[i];
                m[nums[i]] = left;
                if(nums[i]-left+1 > max) max = nums[i]-left+1;
            }
            else if(m.find(nums[i]+1) != m.end()){
                int right = m[nums[i]+1];
                m[right] = nums[i];
                m[nums[i]] = right;
                if(right-nums[i]+1> max) max = right-nums[i]+1;
            }
            else{
                m[nums[i]] = nums[i];
                if(max < 1) max = 1;
            }
        }
        return max;
    }
};
