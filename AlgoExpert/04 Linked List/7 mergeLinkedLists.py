# Linked List Representation
class LinkedList:
    def __init__(self, value):
        self.value = value
        self.next = next


def mergeLinkedListIterative(headOne, headTwo):
    """
    Iterative solution to merge two linked lists in sorted format
    O(N+M) time | O(1) space
    args:
        head of two sorted linked lists
    return:
        sorted merged linked list
    """

    # Check if any list is empty
    if headOne == None:
        return headTwo
    if headTwo == None:
        return headOne

    p1 = headOne
    p2 = headTwo

    # Initialize with correct head for result
    if p1.value <= p2.value:
        resHead = p1
        p1 = p1.next
    else:
        resHead = p2
        p2 = p2.next

    # Now that we have head, make a temp variable to modify further bindings
    currNode = resHead

    # Traverse over the two linked list and then connect as per order
    while p1 is not None or p2 is not None:
        # If any one list becomes empty
        if p1 == None:
            currNode.next = p2
            p2 = p2.next
            break
        elif p2 == None:
            currNode.next = p1
            p1 = p1.next
            break
        # Check the pointers with lower value
        elif p1.value <= p2.value:
            currNode.next = p1
            p1 = p1.next
        else:
            currNode.next = p2
            p2 = p2.next

        currNode = currNode.next

    return resHead


def mergeLinkedListRecursive(headOne, headTwo):
    """
    Recursive solution to merge two linked lists in sorted format
    O(N + M) time | O(N + M) space (for recursive stack)
    args:
        head of two sorted linked lists
    return:
        sorted merged linked list
    """

    # Base Case, if anyone of the linked list is empty
    if headOne == None:
        return headTwo
    if headTwo == None:
        return headOne

    # Recursive Case
    if headOne.value < headTwo.value:
        # Get the smaller subproblem, after smaller node
        headOne.next = mergeLinkedListRecursive(headOne.next, headTwo)
        return headOne
    else:
        headTwo.next = mergeLinkedListRecursive(headOne, headTwo.next)
        return headTwo

    return None
