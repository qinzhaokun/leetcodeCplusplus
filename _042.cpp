class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int* a = new int[n];
        
        if(n == 0) return 0;
        
        a[0] = height[0];
        for(int i = 1;i < n;i++){
            a[i] = max(a[i-1],height[i]);
        }
        
        int sum = 0;
        int rightmax = height[n-1];
        for(int i = n-2;i > 0;i--){
            rightmax = max(rightmax,height[i]);
            sum += (min(a[i],rightmax)-height[i]);
        }
        return sum;
    }
    
    int max(int i, int j){
        return i >= j ? i:j;
    }
    int min(int i, int j){
        return i >= j ? j:i;
    }
};
