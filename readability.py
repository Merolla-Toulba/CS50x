def main():

    # get user text input
    text = input("Text: ")

    # get the counts of letters, words, and sentences
    letters = letter_count(text)
    words = word_count(text)
    sentences = sentence_count(text)

    # Calculating the grade reading level
    gradeLevel = round((0.0588 * (letters / words) * 100) -
                       (0.296 * (sentences / words) * 100) - 15.8)

    # Printing the grade level
    if gradeLevel < 1:
        print("Before Grade 1")
    elif gradeLevel >= 1 and gradeLevel < 16:
        print("Grade", gradeLevel)
    elif gradeLevel >= 16:
        print("Grade 16+")


def letter_count(s):
    l = 0
    for i in range(len(s)):
        if s[i].isalpha():
            l += 1
    return l


def word_count(s):
    w = 0
    for i in range(len(s)):
        if s[i].isspace():
            w += 1
    wor = w + 1
    return wor


def sentence_count(s):
    sen = 0
    for i in range(len(s)):
        if s[i] in ["?", ".", "!"]:
            sen += 1
    return sen


main()
