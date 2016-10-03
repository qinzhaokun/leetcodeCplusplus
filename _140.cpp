class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        int n = s.length();
        int memory[n+1];
        memset(memory,0,sizeof(memory));
        map<int,vector<string>> m;
        return dfs(s,0,wordDict,memory,m);
    }
    
    vector<string> dfs(string s, int i,  unordered_set<string>& wordDict, int memory[], map<int,vector<string>> &m){
        if(i >= s.length()){
            vector<string> r;
            r.push_back("");
            m[i] = r;
            return r;
        }
        for(int j = 1; i+j<= s.length();j++){
            string t = s.substr(i,j);
            if(wordDict.find(t) != wordDict.end()){
                if(memory[i+j] == 1){
                   vector<string> c(m[i+j]);
                   
                   if(m.find(i) == m.end()){
                       for(int j = 0;j < c.size();j++) {
                           if(c[j].length() == 0){
                               c[j] = t; 
                           }
                           else{
                               c[j] = t + " " + c[j]; 
                           }
                       }
                       
                       m[i] = c;
                   }
                   else{
                       for(int j = 0;j < c.size();j++) {
                           if(c[j].length() == 0){
                               c[j] = t; 
                           }
                           else{
                               c[j] = t + " " + c[j]; 
                           }
                           m[i].push_back(c[j]);
                       }
                   }
                }
                else if(memory[i+j] == -1){
                    continue;
                }
                else{
                    vector<string> r = dfs(s,i+j, wordDict, memory, m);
                    if(r.size() == 0){
                        memory[i+j] = -1;
                    }
                    else{
                        memory[i+j] = 1;
                        vector<string> c(r);
                        if(m.find(i) == m.end()){
                            for(int j = 0;j < c.size();j++) {
                                if(c[j].length() == 0){
                                    c[j] = t; 
                                }
                                else{
                                    c[j] = t + " " + c[j]; 
                                }
                            }
                            m[i] = c;
                        }
                        else{
                            for(int j = 0;j < c.size();j++) {
                                if(c[j].length() == 0){
                                    c[j] = t; 
                                }
                                else{
                                    c[j] = t + " " + c[j]; 
                                }
                                m[i].push_back(c[j]);
                            }
                        }
                    }
                }
            }
        }
        if(m.find(i) != m.end()){
            return m[i];
        }
        else{
            vector<string> r;
            return r;
        }
    }
};
