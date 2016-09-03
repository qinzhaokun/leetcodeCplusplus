class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.length(); int n = b.length();
        
        int i = m-1;int j = n-1;
        string ret = ""; int add = 0;
        while(i >= 0 || j >= 0){
            int tmp = add;
            if(i >= 0) tmp += (int)(a[i]-'0');
            if(j >= 0) tmp += (int)(b[j]-'0');
            add = tmp/2;
            ret = to_string(tmp%2) + ret;
            i--;j--;
        }
        
        if(add){
            ret = "1" + ret;
        }
        return ret;
    }
};
