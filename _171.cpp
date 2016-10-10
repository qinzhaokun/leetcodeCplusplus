class Solution {
public:
    int titleToNumber(string s) {
        int j = 0;
        int ret = 0;
        while(j < s.length()){
            int t = s[j]-'A' + 1;
            ret = 26*ret + t;
            j++;
        }
        return ret;
    }
};
