class LinkedList:
    def __init__(self, value):
        self.value = value
        self.next = None


def removeDuplicatesFromLinkedList(linkedList):
    """
    Function to remove duplicate value nodes
    args:
        head of a linked list
    returns:
        linked list with unique elements
    """

    currentNode = linkedList
    while currentNode is not None:
        nextDistinctNode = currentNode.next

        # Traverse a new pointer till the duplicates elements are present.
        while nextDistinctNode is not None and nextDistinctNode.value == currentNode.value:
            nextDistinctNode = nextDistincNode.next

        currentNode.next = nextDistinctNode
        currentNode = currentNode.next

    return linkedList
