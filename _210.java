public class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        ArrayList<ArrayList<Integer>> adj = new ArrayList<ArrayList<Integer>> ();
        
        for(int i = 0;i < numCourses;i++) adj.add(new ArrayList<Integer> ());
        
        for(int i = 0 ;i < prerequisites.length;i++){
            adj.get(prerequisites[i][0]).add(prerequisites[i][1]);
        }
        boolean [] isVisited = new boolean[numCourses];
        boolean [] tmpVisited = new boolean[numCourses];
        List<Integer> ret = new ArrayList<>();
        for(int i = 0;i < numCourses;i++){
            if(!isVisited[i]){
                if(!dfs(isVisited,tmpVisited,adj,i,ret)) {
                int [] empty = {};
                return empty;
                }
            }
        }
        int [] re = new int[ret.size()];
        for(int i = 0;i < re.length;i++) re[i] = ret.get(i);
        return re;
    }
    
    
    public boolean dfs(boolean [] isVisited, boolean [] tmpVisited,ArrayList<ArrayList<Integer>> adj, int i, List<Integer> ret){
        if(tmpVisited[i]){
            return false;
        }
        isVisited[i] = true;
        tmpVisited[i] = true;
        ArrayList a = adj.get(i);
        for(int j = 0;j < a.size();j++){
            if(tmpVisited[(int)a.get(j)]) return false;
            if(isVisited[(int)a.get(j)]) continue;
            if(!dfs(isVisited,tmpVisited,adj,(int)a.get(j),ret)){
                return false;
            }
        }
        ret.add(i);
        tmpVisited[i] = false;
        return true;
    }
}
