class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0) return 0;
        int *left = new int [n];
        int *right = new int [n];
        memset(left,0,n*sizeof(int));
        memset(right,0,n*sizeof(int));
        int MIN = prices[0];
        for(int i = 1;i < n;i++){
            left[i] = left[i-1];
            if(MIN >= prices[i]) MIN = prices[i];
            else{
                left[i] = max(left[i],prices[i]-MIN);
            }
        }
        
        int MAX = prices[n-1];
        int ret = left[n-1];
        for(int j = n-2;j >= 0;j--){
            right[j] = right[j+1];
            if(prices[j] >= MAX) MAX = prices[j];
            else{
                right[j] = max(right[j],MAX-prices[j]);
            }
            ret = max(ret,right[j] + left[j]);
        }
        return ret;
    }
};
