class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool a[256];
        memset(a,false,sizeof(a));
        int j = 0;
        int max = 0;
        for(int i = 0;i < s.length();i++){
            if(!a[s[i]-' ']) a[s[i]-' '] = true;
            else{
                if(max < i-j) max = i-j;
                while(a[s[i]-' ']){
                    a[s[j]-' '] = false;
                    j++;
                }
                a[s[i]-' '] = true;
            }
        }
        if(s.length()-j > max) max = s.length()-j;
        return max;
    }
};
