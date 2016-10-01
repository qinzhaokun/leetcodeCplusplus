class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if(m == 0) return;
        int n = board[0].size();
        for(int i = 0;i < n;i++){
            if(board[0][i] == 'O'){
                bfs(board,0,i);
            }
            if(board[m-1][i] == 'O'){
                bfs(board,m-1,i);
            }
        }
        for(int i = 1;i < m-1;i++){
            if(board[i][0] == 'O'){
                bfs(board,i,0);
            }
            if(board[i][n-1] == 'O'){
                bfs(board,i,n-1);
            }
        }
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                else if(board[i][j] == 'T'){
                    board[i][j] = 'O';
                }
            }
        }
    }
    
    void bfs(vector<vector<char>> &b, int i, int j){
        b[i][j] = 'T';
        int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        int n = b[0].size();
        queue<int> q;
        q.push(i*n+j);
        while(!q.empty()){
            int t = q.front();
            int ii = t/n;int jj = t%n;
            //b[ii][jj] = 'T';
            q.pop();
            for(int k = 0;k < 4;k++){
                int newI = ii + d[k][0];
                int newJ = jj + d[k][1];
                if(newI >= 0 && newI < b.size() && newJ >= 0 && newJ < b[0].size() && b[newI][newJ] == 'O'){
                    b[newI][newJ] = 'T';
                    q.push(newI*n+newJ);
                }
            }
        }
        
    }
};
