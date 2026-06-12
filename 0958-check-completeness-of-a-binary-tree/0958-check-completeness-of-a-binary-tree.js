/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {boolean}
 */
var isCompleteTree = function(root) {
     let queue = [];
    queue.push(root);

    let isNULL = false;

    while (queue.length > 0) {
        let temp = queue.shift();

        if (temp === null) {
            isNULL = true;
        } else {
            if (isNULL === true) {
                return false;
            }

            queue.push(temp.left);
            queue.push(temp.right);
        }
    }

    return true;
};