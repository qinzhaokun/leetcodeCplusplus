public class Solution {
    public String simplifyPath(String path) {
        List<String> s = new ArrayList<>();
        if(path == null || path.length() == 0) return "";
        String [] arr = path.split("/");
        for(String each:arr){
            if(each.equals(".") || each.length()==0) continue;
            else if(each.equals("..")){
                if(!s.isEmpty()){
                    s.remove(s.size()-1);
                }
            }
            else{
                s.add(each);
            }
        }
        
        StringBuilder sb = new StringBuilder();
        for(int i = 0;i < s.size();i++){
            sb.append("/");
            sb.append(s.get(i));
        }
        String re = sb.toString();
        return re.length()==0 ? "/":re;
    }
}
