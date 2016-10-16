public class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        ArrayList<ArrayList<Integer>> adj = new ArrayList<ArrayList<Integer>> ();
        
        for(int i = 0;i < numCourses;i++) adj.add(new ArrayList<Integer> ());
        
        for(int i = 0 ;i < prerequisites.length;i++){
            adj.get(prerequisites[i][0]).add(prerequisites[i][1]);
        }
        boolean [] isVisited = new boolean[numCourses];
        for(int i = 0;i < numCourses;i++){
            if(!dfs(isVisited,adj,i)) return false;
        }
        return true;
    }
    
    public boolean dfs(boolean [] isVisited, ArrayList<ArrayList<Integer>> adj, int i){
        if(isVisited[i]){
            isVisited[i] = false;
            return false;
        }
        isVisited[i] = true;
        ArrayList a = adj.get(i);
        for(int j = 0;j < a.size();j++){
            if(!dfs(isVisited,adj,(int)a.get(j))){
                isVisited[i] = false;
                return false;
            }
        }
        isVisited[i] = false;
        return true;
    }
}
