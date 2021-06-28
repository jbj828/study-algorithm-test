/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} node
 * @return {void} Do not return anything, modify node in-place instead.
 */
<<<<<<< HEAD
 var deleteNode = function(node) {
    
};
=======
var deleteNode = function (node) {
  node.val = node.next.val;
  node.next = node.next.next;
};
>>>>>>> 947fa7d1b9b76578e8089b1746aa41584517625a
