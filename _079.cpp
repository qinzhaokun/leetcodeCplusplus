class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool result = false;
        int m = board.size();
        if(m == 0) return word.length()==0;
        bool **isV = new bool*[m];
        for(int i = 0;i < m;i++){
            isV[i] = new bool[board[0].size()];
            memset(isV[i],false,board[0].size()*sizeof(bool));
        }
        for(int i = 0;i < m;i++){
            for(int j = 0;j < board[0].size();j++){
                dfs(board,word,i,j,0,isV,result);
                if(result) return true;
            }
        }
        return result;
    }
    
     void dfs(auto& b, string word, int i, int j, int len,bool **isV, bool &result){
         int d[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
         if(len == word.length()-1 && word[len] == b[i][j]){
             result = true;
             return;
         }
         if(result || word[len] != b[i][j]) return;
         isV[i][j] = true;
         for(int k = 0;k < 4;k++){
             int newI = i + d[k][0];
             int newJ = j + d[k][1];
             if(newI >= 0 && newI < b.size() && newJ >= 0 && newJ < b[0].size() && !isV[newI][newJ]){
                 dfs(b,word,newI,newJ,len+1,isV,result);
             }
         }
         isV[i][j] = false;
     }
};
