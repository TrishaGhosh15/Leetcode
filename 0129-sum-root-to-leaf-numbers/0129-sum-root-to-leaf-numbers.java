/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int ans=0;
    public int sumNumbers(TreeNode root) {
        dfs(root,0);
        return ans;
    }
    public void dfs(TreeNode root,int x)
    {
        if (root!=null)
        {
            x+=root.val;
            if (root.left==null&&root.right==null)
                ans+=x;
            x*=10;
            dfs(root.left,x);
            dfs(root.right,x);
        }
    }
}