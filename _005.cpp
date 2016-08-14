class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int max = 0;
        int max_left=0;
        for(int i = 0;i < n && n-i > max/2;){
            int j = i+1;
            int left = i-1;
            i++;
            while(i < n && s[i] == s[i-1]) i++; //skip the duplicate character
            int right = i;
            while(left >= 0 && right < n && s[left] == s[right]){
                left--;
                right++;
            }
            int len = right-left-1;
            if(len > max){
                max = len;
                max_left = left+1;
            }
        }
        return s.substr(max_left,max);
    }
};
