class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m == 0) return false;
        int n = matrix[0].size();
        
        int i = 0;int j = m*n-1;
        while(i <= j){
            int mid = i + (j-i)/2;
            int ii = mid/n;
            int jj = mid%n;
            if(matrix[ii][jj] == target) return true;
            else if(matrix[ii][jj] < target){
                i = mid+1;
            }
            else{
                j = mid-1;
            }
        }
        return false;
    }
};
