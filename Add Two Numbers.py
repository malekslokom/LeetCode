# You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

# You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

# Example 1:


# Input: l1 = [2,4,3], l2 = [5,6,4]
# Output: [7,0,8]
# Explanation: 342 + 465 = 807.
# Example 2:

# Input: l1 = [0], l2 = [0]
# Output: [0]
# Example 3:

# Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
# Output: [8,9,9,9,0,0,0,1]
 

# Constraints:

# The number of nodes in each linked list is in the range [1, 100].
# 0 <= Node.val <= 9
# It is guaranteed that the list represents a number that does not have leading zeros.


# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        currentL1 = l1
        currentL2 = l2
        start=True
        

        toadd=currentL1.val+currentL2.val
        if toadd>9:
            dummy_head = ListNode(toadd%10)
            save=toadd/10
        else:
            dummy_head = ListNode(toadd)
            save=0
        current = dummy_head
        currentL1 = currentL1.next
        currentL2 = currentL2.next
        while currentL1 and currentL2:
            toadd=currentL1.val+currentL2.val+save
            if toadd>9:
                current.next=ListNode(toadd%10)
                save=toadd/10
            else:
                current.next=ListNode(toadd)
                save=0
            current=current.next
            currentL1 = currentL1.next
            currentL2 = currentL2.next
        while currentL1:
            toadd=currentL1.val+save
            if toadd>9:
                current.next=ListNode(toadd%10)
                save=toadd/10
            else:
                current.next=ListNode(toadd)
                save=0
            currentL1 = currentL1.next
            current=current.next
        while currentL2:
            toadd=currentL2.val+save
            if toadd>9:
                current.next=ListNode(toadd%10)
                save=toadd/10
            else:
                current.next=ListNode(toadd)
                save=0
            currentL2 = currentL2.next
            current=current.next
        if save != 0:
            current.next=ListNode(save)
            current=current.next
        return dummy_head