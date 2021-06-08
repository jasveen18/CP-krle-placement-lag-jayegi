def isLoopPresent(head):
    """
    Function to return the node where loop starts
    O(N) Time | O(1) Space
    args:
        head node of the linked list
    returns:
        True if loop is present, false if loop is not present
    """
    first = head
    second = head

    # Traverse the linked list with slow and fast pointer
    while second is not None and second.next is not None:
        first = first.next
        second = second.next.next

        # Loop found
        if first == second:
            return True

    # Loop not found
    return False


def findLoop(head):
    """
    Function to return the node where loop starts
    O(N) Time | O(1) Space
    args:
        head node of the linked list
    returns:
        node from where the loop starts
    """
    first = head.next
    second = head.next.next

    # Let them meet first
    while first != second:
        first = first.next
        second = second.next.next

    # Pull first pointer to head and then traverse in same pace
    first = head
    while first != second:
        first = first.next
        second = second.next

    return first


def lengthOfLoop(head):
    """
    Function to return the length of loop present
    O(N) Time | O(1) Space
    args:
        head node of the linked list
    returns:
        integer value, the length of loop
    """
    first = head.next
    second = head.next.next

    # Let them meet first
    while first != second:
        first = first.next
        second = second.next.next

    # Pull first pointer to head and then traverse in same pace
    first = head
    while first != second:
        first = first.next
        second = second.next

    # Now we have the start node of loop, we can count the nodes
    countNodes = 0
    while first != second:
        first = first.next
        countNodes += 1

    return countNodes
