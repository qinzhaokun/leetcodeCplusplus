class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n);
        for(int i = 0;i < n;i++){
            ret[i] = vector<int>(n);
        }
        int index = 1;
        int il = 0;int ir = n-1;
        while(il <= ir){
            for(int i = il;i <= ir;i++){
                ret[il][i] = index++;
            }
            for(int i = il+1;i <= ir;i++){
                ret[i][ir] = index++;
            }
            for(int i = ir-1;i >= il;i--){
                ret[ir][i] = index++;
            }
            for(int i = ir-1;i >= il+1;i--){
                ret[i][il] = index++;
            }
            il++;ir--;
        }
        return ret;
    }
};
