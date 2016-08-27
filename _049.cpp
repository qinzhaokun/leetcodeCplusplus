class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        map<string,vector<string>*> m;
        
        for(int i = 0;i < strs.size();i++){
            string value = strs[i];
            sort(strs[i].begin(),strs[i].end());
            if(m.find(strs[i]) == m.end()){
                vector<string>* t = new vector<string>;
                t->push_back(value);
                m[strs[i]] = t;
            }
            else{
                m[strs[i]]->push_back(value);
            }
        }
        
        for(map<string,vector<string>*>::iterator iter = m.begin();iter != m.end();iter++){
            ret.push_back(*(iter->second));
        }
        return ret;
    }
};
