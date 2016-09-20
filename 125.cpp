class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;int j = s.length()-1;
        
        while(i < j){
            int tmp = 0;
            while(i < j){
                if(s[i] >= 'a' && s[i] <= 'z') {
                    tmp = s[i]-'a';
                    break;
                }
                if(s[i] >= 'A' && s[i] <= 'Z'){
                    tmp = s[i]-'A';
                    break;
                }
                if(s[i] >= '0' && s[i] <= '9'){
                    tmp = s[i]-'a';
                    break;
                }
                i++;
            }
            int tmp2 = 0;
            while(i < j){
                if(s[j] >= 'a' && s[j] <= 'z'){
                    tmp2 = s[j] - 'a';
                    break;
                }
                if(s[j] >= 'A' && s[j] <= 'Z'){
                    tmp2 = s[j] - 'A';
                    break;
                }
                if(s[j] >= '0' && s[j] <= '9'){
                    tmp2 = s[j] - 'a';
                    break;
                }
                j--;
            }
            
            if(i < j && tmp != tmp2) return false;
            else{
                i++;j--;
            }
        }
        return true;
    }
};
