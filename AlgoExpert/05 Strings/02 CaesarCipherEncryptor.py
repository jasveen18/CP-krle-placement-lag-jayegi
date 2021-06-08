def caesarCipherEncryptor(string, key):
    """
    Shift letter by key amount
    args:
        string and key
    return:
        shifted string
    """

    newLetters = []
    newKey = key % 26       # To avoid any overflow

    for letter in string:
        newLetters.append(getNewLetter(letter, newKey))

    return "".join(newLetters)


# Return the updated letter
def getNewLetter(letter, key):
    newLetterCode = ord(letter) + key
    return chr(newLetterCode) if newLetterCode <= 122 else chr(96 + newLetterCode % 122)
