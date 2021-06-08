# Linked List Representation
class LinkedList:
    def __init__(self, value):
        self.value = value
        self.next = None


def sumOfLinkedList(linkedListOne, linkedListTwo):
    """
    Function to add two numbers represented as linked list
    O(max(N, M)) time | O(max(N, M)) space
    args:
        head of two linked lists
    returns:
        new linked list as digits in value of sum
    """
    newLinkedListHead = LinkedList(0)
    currentNode = newLinkedListHead
    carry = 0

    nodeOne, nodeTwo = linkedListOne, linkedListTwo

    # while we have anything to add in the linked list
    while nodeOne is not None or nodeTwo is not None or carry != 0:
        # Check if value is present, else zero
        valueOne = nodeOne.value if nodeOne is not None else 0
        valueTwo = nodeTwo.value if nodeTwo is not None else 0

        # Take sum and digit of the node
        sumOfValue = valueOne + valueTwo + carry
        newValue = sumOfValue % 10

        # Append new node to the result
        newNode = LinkedList(newValue)
        currentNode.next = newNode
        currentNode = currentNode.next

        # Update carry and move ahead while handling end of list cases
        carry = sumOfValue // 10
        nodeOne = nodeOne.next if nodeOne is not None else None
        nodeTwo = nodeTwo.next if nodeTwo is not None else None

    return newLinkedListHead.next
