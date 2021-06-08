def reverseLinkedListIterative(head):
    """
    Function to reverse a given linked list, iteratively.
    O(N) Time | O(1) Space
    args:
        head of the linked list
    return:
        reversed linked list
    """
    slow, curr, fast = None, head, head

    # Update the bindings
    while curr is not None:
        fast = fast.next
        curr.next = slow

        # Move one step ahead
        slow = curr
        curr = fast

    return slow


def reverseLinkedListRecursive(head):
    """
    Function to reverse a given linked list, recursively.
    O(N) Time | O(1) Space
    args:
        head of the linked list
    return:
        reversed linked list
    """
    # Base Case
    if head is None or head.next is None:
        return head

    # Recursive Case
    residual = reverseLinkedListRecursive(head.next)

    # Operations
    head.next.next = head
    head.next = None

    return residual
