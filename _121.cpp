class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ret = 0;
        int Min = INT_MAX;
        for(int i = 0;i < n;i++){
            if(prices[i] <= Min) Min = prices[i];
            else{
                ret = max(ret,prices[i]-Min);
            }
        }
        return ret;
    }
};
