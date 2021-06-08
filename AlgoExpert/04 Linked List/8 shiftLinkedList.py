class LinkedList:
    def __init__(self, value):
        self.value = value
        self.next = None


def shiftLinkedList(head, k):
    """
    Function to shift linked list forward or backward as desired
    args:
        head of the linked list
        integer, shifting number (pos or neg)
    return:
        shifted linked list
    """

    listLength = 1
    listTail = head

    # Get length of the list while retaining the tail node
    while listTail.next is not None:
        listTail = listTail.next
        listLength += 1

    # Get offset within length
    offset = abs(k) % listLength
    if offset == 0:
        return head

    # Set new tail position depending on forward or backward
    newTailPosition = listLength - offset if k > 0 else offset

    # Go to the node that will be the new tail
    newTail = head
    for i in range(1, newTailPosition):
        newTail = newTail.next

    # Change the bindings
    newHead = newTail.next
    newTail.next = None
    listTail.next = head

    return newHead
