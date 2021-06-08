def rearrangeLinkedList(head, k):
    """
    Function to rearrange linked list such as the elements
    are grouped as smaller than k and larger than k. The elements
    should retain their initial relative ordering after rearranging.

    Input - 
    LL: 3 -> 0 -> 5 -> 2 -> 1 -> 4
    k: 3

    Output - 
    LL: 0 -> 2 -> 1 -> 3 -> 5 -> 4

    O(N) time | O(1) space
    args:
        head of the linked list
        value of parition element, k
    returns:
        rearranged linked list
    """
    smallListHead, smallListTail = None, None
    equalListHead, equalListTail = None, None
    largeListHead, largeListTail = None, None

    currNode = head
    while currNode is not None:
        if currNode.value < k:
            smallListHead, smallListTail = growLinkedList(
                smallListHead, smallListTail, currNode)
        elif currNode.value > k:
            largeListHead, largeListTail = growLinkedList(
                largeListHead, largeListTail, currNode)
        else:
            equalListHead, equalListTail = growLinkedList(
                equalListHead, equalListTail, currNode)

        # Traverse ahead and clean out the next pointer
        prevNode = currNode
        currNode = currNode.next
        prevNode.next = None

        # Update the bindings of small -> equal -> large, while handling all cases
        firstListHead, firstListTail = connectLinkedLists(
            smallListHead, smallListTail, equalListHead, equalListTail)
        finalListHead, finalListTail = connectLinkedLists(
            firstListHead, firstListTail, largeListHead, largeListTail)


def growLinkedList(head, tail, newNode):
    """
    Given head, tail and a node, add the new node to the linked list.
    Returns:
        head and new tail
    """
    newHead = head
    newTail = newNode

    # Check for head
    if newHead is None:
        newHead = newNode

    # Update tail
    if tail is not None:
        tail.next = newTail

    return (newHead, newTail)


def connectLinkedLists(headOne, tailOne, headTwo, tailTwo):
    """
    Takes in details of two linked list and connect them
    """
    # Get the head and tail
    newHead = headOne if headOne is not None else headTwo
    newTail = tailTwo if tailTwo is not None else tailOne

    # If we have values in first list, make connection
    if tailOne is not None:
        tailOne.next = headTwo

    return (newHead, newTail)
