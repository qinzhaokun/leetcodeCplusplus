class Solution {
public:
    void reverseWords(string &s) {
        int n = s.length();
        string ret = "";int j = n-1;
        while(j >= 0){
            while(j >= 0 && s[j] == ' ') j--;
            if(j < 0) break;
            int i = j-1;
            while(i >= 0 && s[i] != ' ') i--;
            if(ret != "") ret += " ";
            for(int k = i+1;k <= j;k++) ret += s[k];
            j = i-1;
        }
        s = ret;
    }
};
