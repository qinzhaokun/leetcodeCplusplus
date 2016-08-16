class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        
        int left=0;int eirht = 0;
        gen(0,0,"",ret,n);
        return ret;
    }
    
    void gen(int left, int right, string tmp, vector<string> &ret,int n){
        if(left == n){
            for(int i = right;i < n;i++){
                tmp += ')';
            }
            ret.push_back(tmp);
            return;
        }
        if(left > right){
            gen(left,right+1,tmp+')',ret,n);
        }
        gen(left+1,right,tmp+'(',ret,n);
    }
};
