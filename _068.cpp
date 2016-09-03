class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ret;
        if(!maxWidth) return words;
        int j = 0;int len = 0;
        for(int i = 0;i < words.size();i++){
            len += words[i].length();
            if(len > maxWidth-(i-j)){
                len -= words[i].length();
                ret.push_back(formart(words,j,i-1,maxWidth,len));
                len = 0;
                j = i;
                i--;
            }
        }
        string last = words[j];
        for(int i = j+1;i < words.size();i++){
            last += (" " + words[i]);
        }
        for(int i = last.length();i < maxWidth;i++){
            last += " ";
        }
        ret.push_back(last);
        return ret;
    }
    
    string formart(vector<string>& words, int i, int j, int maxWidth, int len){
        int numExtra = j-i;
        int space = maxWidth-len;
        string ret = words[j];
        if(i == j){
            for(int k = words[j].length();k < maxWidth;k++) ret += " ";
        }
        else{
            for(int k = j-1;k >= i;k--){
                int c = space/numExtra;
                for(int t = 0;t < c;t++){
                    ret = " " + ret;
                }
                ret = words[k] + ret;
                space -= c;
                numExtra--;
            }
        }
        return ret;
    }
};
