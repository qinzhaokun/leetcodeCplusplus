class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m == 0) return 0;
        int n = matrix[0].size();
        
        vector<int> dp;
        int max = 0;
        for(int i = 0;i < n;i++) {
            if(matrix[0][i] == '1'){
                dp.push_back(1);
                max = 1;
            }
            else{
                dp.push_back(0);
            }
        }
        int localMax = largestRectangleArea(dp);
        if(localMax > max) max = localMax;
        for(int i = 1;i < m;i++){
            for(int j = 0;j < n;j++){
                if(matrix[i][j] == '1') dp[j]++;
                else dp[j] = 0;
            }
            int localMax = largestRectangleArea(dp);
            if(localMax > max) max = localMax;
        }
        return max;
    }
    
        int largestRectangleArea(vector<int>& heights) {
        stack<int> s; int max1 = 0;
        for(int i = 0;i < heights.size();i++){
            if(s.empty() || heights[i] > heights[s.top()]) s.push(i);
            else{
                while(!s.empty() && heights[i] <= heights[s.top()]){
                    int index = s.top();
                    s.pop();
                    int left = s.empty()?-1:s.top();
                    max1 = max(max1,(i-left-1)*heights[index]);
                }
                
                s.push(i);
            }
        }
        while(!s.empty()){
            int index = s.top();
            s.pop();
            int left = s.empty()?-1:s.top();
            int l = heights.size()-1-left;
            max1 = max(max1,l*heights[index]);
        }
        return max1;
    }
    
    
};
