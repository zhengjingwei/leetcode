# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        p1 = headA ; p2 = headB
        len1 = 0; len2 = 0;
        
        while p1 is not None:
            p1 = p1.next
            len1 += 1
        while p2 is not None:
            p2 = p2.next
            len2 += 1
            
        p1 = headA; p2 = headB
        while len1 > len2:
            p1 = p1.next
            len1 -= 1
        while len2 > len1:
            p2 = p2.next
            len2 -= 1
            
        while p1 is not None and p1 is not p2:
            p1 = p1.next
            p2 = p2.next
        
        return p1 if p1 is not None else None