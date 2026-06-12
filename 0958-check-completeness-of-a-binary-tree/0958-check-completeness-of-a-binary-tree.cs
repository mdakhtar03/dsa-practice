/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    public bool IsCompleteTree(TreeNode root) {
           Queue<TreeNode> q = new Queue<TreeNode>();
    q.Enqueue(root);

    bool isNull = false;

    while (q.Count > 0)
    {
        TreeNode temp = q.Dequeue();

        if (temp == null)
        {
            isNull = true;
        }
        else
        {
            if (isNull)
            {
                return false;
            }

            q.Enqueue(temp.left);
            q.Enqueue(temp.right);
        }
    }

    return true;
    }
}