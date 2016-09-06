class Solution {
public:
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
