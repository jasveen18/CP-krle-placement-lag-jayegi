# Doubly Linked List
# Each node to connected to another and we can traverse in both direction.

# One node with value and next pointer
class Node:
    def __init__(self, value):
        self.value = value
        self.next = None
        self.prev = None


class DoublyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    # O(1) time | O(1) space
    def setHead(self, node):
        if self.head is None:
            self.head = node
            self.tail = node
            return
        self.insertBefore(self.head, node)

    # O(1) time | O(1) space
    def setTail(self, node):
        if self.tail is None:
            self.setHead(node)
            return
        self.insertAfter(self.tail, node)

    # O(1) time | O(1) space
    def insertBefore(self, node, nodeToInsert):
        if nodeToInsert == self.head and nodeToInsert == self.tail:
            return

        # Set bindings of new node
        self.remove(nodeToInsert)
        nodeToInsert.prev = node.prev
        nodeToInsert.next = node

        # Set binding of prev and next nodes
        if node.prev is None:
            self.head = nodeToInsert
        else:
            node.prev.next = nodeToInsert

        node.prev = nodeToInsert

    # O(1) time | O(1) space
    def insertAfter(self, node, nodeToInsert):
        if nodeToInsert == self.head and nodeToInsert == self.tail:
            return

        # Set bindings of new node
        self.remove(nodeToInsert)
        nodeToInsert.prev = node
        noteToInsert.next = node.next

        # Set binding of prev and next nodes
        if node.next is None:
            self.tail = nodeToInsert
        else:
            node.next.prev = nodeToInsert

        node.next = nodeToInsert

    # O(p) time | O(1) space
    def insertAtPosition(self, position, nodeToInsert):
        # Insertion at head
        if position == 1:
            self.setHead(nodeToInsert)
            return

        node = self.head
        currentPosition = 1
        # Traverse the linked list to find position
        while node is not None and currentPosition != position:
            node = node.next
            currentPosition += 1

        if node is not None:    # insert at position
            self.insertBefore(node, nodeToInsert)
        else:       # we reached the end, so insert at tail
            self.setTail(nodeToInsert)

    # O(n) time | O(1) space
    def removeNodesWithValue(self, value):
        node = self.head

        # Traverse to the end of the linked list
        while node is not None:
            # Keep track of next node
            nodeToRemove = node
            node = node.next
            if nodeToRemove.value == value:
                self.remove(nodeToRemove)

    # O(1) time | O(1) space
    def remove(self, node):
        # If head / tail, then take care of that
        if node == self.head:
            self.head = self.head.next
        if node == self.tail:
            self.tail = self.tail.prev

        # Remove the node from linked list
        self.removeNodeBindings(self, node)

    # O(n) time | O(1) space
    def containsNodeWithValue(self, value):
        node = self.head

        # Traverse until we reach the end or find the value
        while node is not None and node.value != value:
            node = node.next

        return node is not None

    # O(1) time | O(1) space
    def removeNodeBindings(self, node):
        # Change pointers for prev node
        if node.prev is not None:
            node.prev.next = node.next

        # Change pointer for next node
        if node.next is not None:
            node.next.prev = node.prev

        # Now remove any left-over bindings
        node.prev = None
        node.next = None
