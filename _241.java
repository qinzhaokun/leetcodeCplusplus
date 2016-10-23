public class Solution {
    public List<Integer> diffWaysToCompute(String input) {
        int n = input.length();
        List<Integer> ans = new ArrayList();
        for(int i = 0;i < n;i++){
            char c = input.charAt(i);
            if(c == '*'){
                List<Integer> left = diffWaysToCompute(input.substring(0,i));
                List<Integer> right = diffWaysToCompute(input.substring(i+1));
                
                for(int j = 0;j < left.size();j++){
                    for(int k = 0;k < right.size();k++){
                        ans.add((int)left.get(j)*(int)right.get(k));
                    }
                }
            }
            else if(c == '+'){
                List<Integer> left = diffWaysToCompute(input.substring(0,i));
                List<Integer> right = diffWaysToCompute(input.substring(i+1));
                
                for(int j = 0;j < left.size();j++){
                    for(int k = 0;k < right.size();k++){
                        ans.add((int)left.get(j)+(int)right.get(k));
                    }
                }
            }
            else if(c == '-'){
                List<Integer> left = diffWaysToCompute(input.substring(0,i));
                List<Integer> right = diffWaysToCompute(input.substring(i+1));
                
                for(int j = 0;j < left.size();j++){
                    for(int k = 0;k < right.size();k++){
                        ans.add((int)left.get(j)-(int)right.get(k));
                    }
                }
            }
        }
        if(ans.size() == 0){
            ans.add(Integer.valueOf(input));
        }
        return ans;
    }
}
