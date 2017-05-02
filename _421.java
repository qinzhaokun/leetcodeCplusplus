public class Solution {
    public int findMaximumXOR(int[] nums) {
        Tries root = new Tries();
        int max = 0;
        if(nums.length > 0) insert(root,nums[0]);
        for(int i = 1;i < nums.length;i++){
            int tmp = query(root,nums[i]);
            if(tmp > max) max = tmp;
            insert(root,nums[i]);
        }
        return max;
    }
    
    public void insert(Tries root, int val){
        Tries cur = root;
        for(int i = 31;i >= 0;i--){
            int t = ((val >> i)&1);
            if(cur.child[t] == null){
                cur.child[t] = new Tries();
            }
            cur = cur.child[t];
        }
    }
    
    public int query(Tries root, int val){
        int ret = 0;
        Tries cur = root;
        for(int i = 31;i >= 0;i--){
            int t = ((val >> i)&1);
            t = 1-t;
            if(cur.child[t] != null){
                ret |= (1<<i);
                cur = cur.child[t];
            }
            else{
                cur = cur.child[1-t];
            }
        }
        return ret;
    }
}

class Tries{
    Tries [] child;
    
    Tries(){
        child = new Tries[2];
    }
}

