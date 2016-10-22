/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public int countNodes(TreeNode root) {
        return count(root,-1,-1);
    }
    
    public int count (TreeNode root, int left, int right){
        if(root == null) return 0;
        if(left == -1){
            TreeNode node = root;
            left = 0;
            while(node!= null){
                node = node.left;
                left++;
            }
        }
        if(right == -1){
            TreeNode node = root;
            right = 0;
            while(node != null){
                node = node.right;
                right++;
            }
        }
        
        if(left == right) return (2 << (left-1)) - 1;
        else return 1 + count(root.left, left-1,-1) + count(root.right,-1,right-1);
    }
}
