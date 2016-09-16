class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        for(int j = 1;j < prices.size();j++){
            if(prices[j] > prices[j-1]){
                ret += (prices[j]-prices[j-1]);
            }
        }
        return ret;
    }
};
