class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        vector<int> ret;
        if(m == 0){
            return ret;
        }
        int n = matrix[0].size();
        
        int il = 0;int ir = n-1;
        int jl = 0;int jr = m-1;
        
        while(il <= ir && jl <= jr){
            for(int k = il;k <= ir;k++){
                ret.push_back(matrix[jl][k]);
            }
            for(int k = jl+1;k <= jr;k++){
                ret.push_back(matrix[k][ir]);
            }
            if(jr != jl){
                for(int k = ir-1;k >= il;k--){
                    ret.push_back(matrix[jr][k]);
                }
            }
            if(il != ir){
                for(int k = jr-1;k >= jl+1;k--){
                    ret.push_back(matrix[k][il]);
                }
            }
            il++;ir--;
            jl++;jr--;
        }
        
        return ret;
    }
};
