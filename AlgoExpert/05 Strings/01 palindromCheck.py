# O(n) time | O(1) space
def isPalindrome(string):
    leftIdx = 0
    rightIdx = len(string) - 1

    # Traverse
    while leftIdx < rightIdx:
        if string[leftIdx] != string[rightIdx]:
            return False
        leftIdx += 1
        rightIdx -= 1

    # Is a palindrome
    return True
