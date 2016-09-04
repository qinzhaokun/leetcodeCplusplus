class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length(); int n =t.length();
        if(n > m) return "";
        
        int target[128];
        memset(target,0,128*sizeof(int));
        
        for(int i = 0;i < n;i++) target[t[i]-' ']++;
        
        int count = 0;
        int cur[128];
        memset(cur,0,128*sizeof(int));
        int j = 0;
        string ret = "";
        for(int i =0;i < m;i++){
            int index = s[i]-' ';
            if(target[index]){
                if(cur[index] < target[index]){
                    count++;
                    cur[index]++;
                }
                else{
                    cur[index]++;
                }
                
                if(count == n){
                    while(count == n){
                        int r = s[j]-' ';
                        if(target[r]){
                            if(cur[r] > target[r]) cur[r]--;
                            else{
                                if(ret.length()== 0 || ret.length() > i-j+1){
                                    ret = s.substr(j,i-j+1);
                                }
                                cur[r]--;
                                count--;
                            }
                        }
                        j++;
                    }
                }
            }
        }
        
        return ret;
    }
};
