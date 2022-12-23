# TODO
from cs50 import get_string


def main():
    text = get_string("Text: ")
    # Count letters
    letters = count_letters(text)
    # print(f"{letters}")
    # count words
    words = count_words(text)
    # count sentences
    sentences = count_sentences(text)

    l = (letters / words) * 100
    s = (sentences / words) * 100
    index = round(0.0588 * l - 0.296 * s - 15.8)

    if(index >= 16):
        print("Grade 16+")
    elif(index < 1):
        print("Before Grade 1")
    else:
        print(f"Grade {index}")


def count_letters(text):
    letter = 0
    for i in range(len(text)):
        if(text[i].lower().isalpha() == True):
            letter += 1
    return letter


def count_words(text):
    words = 1
    for i in range(len(text)):
        if(text[i] == " "):
            words += 1
    return words


def count_sentences(text):
    sentences = 0
    for i in range(len(text)):
        if(text[i] == "." or text[i] == "!" or text[i] == "?"):
            sentences += 1
    return sentences


main()