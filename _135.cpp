class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int *candy = new int[n];
        if(n == 0) return 0;
        candy[0] = 0;
        for(int i = 1;i < n;i++){
            if(ratings[i] > ratings[i-1]) candy[i] = candy[i-1]+1;
            else candy[i] = 0;
        }
        int sum = candy[n-1];
        for(int i = n-2;i >= 0;i--){
            if(ratings[i] > ratings[i+1] && candy[i] <= candy[i+1]){
                candy[i] = candy[i+1]+1;
            }
            sum += candy[i];
        }
        
        return sum+n;
    }
};
