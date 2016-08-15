class Solution {
    string map[8] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
public:

    void dfs(string answer, string d, vector<string> &ret){
        if(d.size() == 0){
            ret.push_back(answer);
        }
        else{
            int t = d[0]-'2';
            string all = map[t];
            for(int i = 0;i < all.length();i++){
                dfs(answer+all[i],d.substr(1),ret);
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if(digits.size() == 0) return ret;
        dfs("",digits,ret);
        return ret;
    }
};
