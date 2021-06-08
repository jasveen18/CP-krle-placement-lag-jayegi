def removeNthNodeFromEnd(head, n):
    """
    Function to remove the nth node from end in place
    O(N) Time | O(Space)
    args:
        head of linked list
        n - nth node
    returns:
        none
    """

    first = head
    second = head
    counter = 1

    # Have your second pointer ahead by n
    while counter <= n:
        second = second.next
        counter += 1

    # Check for head, remove 2nd node with value copied
    if second is None:
        head.value = head.next.value
        head.next = head.next.next
        return

    # Traverse both of them at same pace
    while second.next is not None:
        second = second.next
        first = first.next

    # Now we are one step behind the node to remove
    first.next = first.next.next
    return
