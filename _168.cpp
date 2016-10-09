class Solution {
public:
    string convertToTitle(int n) {
        string ret = "";
        while(n>0){
            char t = 'A' + (n-1)%26;
            ret = t + ret;
            n = (n-1)/26;
        }
        return ret;
    }
};
