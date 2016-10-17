public class Solution {
    int max = 0;
    public List<String> findWords(char[][] board, String[] words) {
        //Set<String> set = new HashSet();
        
        List<String> ret = new ArrayList();
        if(board.length == 0) return ret;
        Tries root = BuildTries(words);
        boolean [][] isV = new boolean[board.length][board[0].length];
        for(int i = 0;i < board.length;i++){
            for(int j = 0;j < board[0].length;j++){
                if(root.children[board[i][j]-'a'] != null)
                    dfs(isV,board,"",i,j,root.children[board[i][j]-'a'],ret);
            }
        }
        return ret;
    }
    
    
    public void dfs(boolean [][] isV, char [][] b,String tmp, int i, int j, Tries node,List<String> ret){
        tmp += b[i][j];
        if(node.end && !ret.contains(tmp)){
            ret.add(tmp);
        }
        if(tmp.length() > max) return;
        isV[i][j] = true;
        int [][] d = {{-1,0},{1,0},{0,1},{0,-1}};
        for(int k = 0;k < 4;k++){
            int ii = i + d[k][0]; int jj = j + d[k][1];
            if(ii >= 0 && ii < isV.length && jj >= 0 && jj < isV[0].length && !isV[ii][jj] && node.children[b[ii][jj]-'a'] != null){
                dfs(isV,b,tmp,ii,jj,node.children[b[ii][jj]-'a'],ret);
            }
        }
        isV[i][j] = false;
    }
    
    public Tries BuildTries(String [] words){
        Tries root = new Tries();
        for(String each:words){
            Tries t = root;
            for(int i = 0;i < each.length();i++){
                int index = each.charAt(i)-'a';
                if(t.children[index] == null) t.children[index] = new Tries();
                t = t.children[index];
            }
            t.end = true;
            if(max < each.length()) max = each.length();
        }
        return root;
    }
}

class Tries {

    Tries [] children;
    boolean end;
    
    Tries(){
        children = new Tries[26];
        end = false;
    }
    
}
