class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        int count = 1;
        queue<string> q;
        q.push(beginWord);
        if(beginWord == endWord) return count;
        while(!q.empty()){
            count++;
            int size = q.size();
            for(int i = 0;i < size;i++){
                string t = q.front(); q.pop();
                for(int k = 0;k < t.length();k++){
                    for(int j = 0;j < 25;j++){
                        char tmp = 'a' + j;
                    if(t[k] != tmp){
                        string newOne = t.substr(0,k) + tmp + t.substr(k+1);
                        if(newOne == endWord) return count;
                        else if(wordList.find(newOne) != wordList.end()){
                            q.push(newOne);
                            wordList.erase(newOne);
                        }
                    }
                    }
                }
            }
        }
        return 0;
    }
};
