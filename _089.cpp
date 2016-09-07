class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret;
        if(n == 0){
            ret.push_back(0);
            return ret;
        }
            
        ret.push_back(0);
        ret.push_back(1);

        for(int i = 1;i < n;i++){
            int j = ret.size()-1;
            while(j >= 0){
                ret.push_back((1<<i)+ret[j]);
                j--;
            }
        }
        
        return ret;
    }
};
