class LRUCache:
    def __init__(self, maxSize):
        """
        Implementation of LRU Cache using Doubly linked list and Hashmaps
        args:
            max size of cache
        """
        # Hash table
        self.cache = {}
        # Max size
        self.maxSize = maxSize or 1
        # Current size of cache
        self.currentSize = 0
        # Doubly Linked List to store the sequence of usage
        self.listOfMostRecent = DoublyLinkedList()

    def insertKeyValuePair(self, key, value):
        """
        Function to insert a new value in cache, checks if key already present.
        O(1) time | O(1) space
        args: key, value
        """

        if key not in self.cache:       # If new item is given
            if self.currentSize == self.maxSize:       # Check if cache is full, then remove LRU element
                self.evictLeastRecent()
            else:
                self.currentSize += 1
            self.cache[key] = DoublyLinkedListNode(key, value)
        else:                           # Element already present in Cache
            self.replaceKey(key, value)

        # Update most recent in the cache
        self.updateMostRecent(self.cache[key])

    def getValueFromKey(self, key):
        """
        Function to return the value if key exists in the cache.
        O(1) time | O(1) space
        args:
            key
        return:
            value of corresponding key
        """
        if key not in self.cache:
            return None

        self.updateMostRecentKey(self.cache[key])
        return self.cache[key].value

    def getMostRecentKey(self):
        """
        Return the most recent used key
        O(1) time | O(1) space
        """
        return self.listOfMostRecent.head.key

    # Helper function to update the most recently used key
    def updateMostRecentKey(self, node):
        self.listOfMostRecent.setHeadTo(node)

    # Helper function to replace the value of key already present in cache
    def replaceKey(self, key, value):
        if key not in self.cache:
            raise Exception("The provided key is not in cache.")
        self.cache[key].value = value

    # Helper function to remove the LRU key when cache is full
    def evictLeastRecent(self):
        keyToRemove = self.listOfMostRecent.tail.key
        self.listOfMostRecent.removeTail()
        del self.cache[keyToRemove]


# Take Directly from Linked List Construction Class
class DoublyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def setHeadTo(self, node):
        if self.head == node:           # If same head
            return
        elif self.head is None:         # If empty linked list
            self.head = node
            self.tail = node
        elif self.head == self.tail:    # If only one element present
            self.tail.prev = node
            self.head = node
            self.head.next = self.tail
        else:                           # Other cases
            if self.tail == node:
                self.removeTail()
            node.removeBindings()
            self.head.prev = node
            node.next = self.head
            self.head = node

    def removeTail(self):
        # If linked list is empty
        if self.tail is None:
            return

        # If only one element
        if self.tail == self.head:
            self.head = None
            self.tail = None
            return

        # Remove tail and update bindings
        self.tail = self.tail.prev
        self.tail.next = None


class DoublyLinkedListNode:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.prev = None
        self.next = None

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
