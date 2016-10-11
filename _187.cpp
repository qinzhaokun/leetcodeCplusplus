class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();
        vector<string> ret;
        if(n <= 10) return ret;
        int f = 0;int mask = 0;
        for(int i = 0;i < 10;i++){
            f = f<<2;
            int t = 0;
            if(s[i] == 'C') t = 1;
            else if(s[i] == 'G') t = 2;
            else if(s[i] == 'T') t = 3;
            f |= t;
            mask = mask << 2;
            mask |= 3;
        }
        unordered_map<int,int> map;
        map[f] = 1;
        for(int i = 10;i < n;i++){
            f = f << 2;
            int t = 0;
            if(s[i] == 'C') t = 1;
            else if(s[i] == 'G') t = 2;
            else if(s[i] == 'T') t = 3;
            f |= t;
            f = f&mask;
            if(map.find(f) != map.end()){
                if(map[f] == 1){
                   ret.push_back(s.substr(i-9,10));
                   map[f] = 2; 
                }
                
            }
            else{
                map[f] = 1;
            }
        }
        return ret;
    }
};
