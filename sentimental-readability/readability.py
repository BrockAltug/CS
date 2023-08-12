# import the get_string function from the cs50 library
from cs50 import get_string


# Main method
def main():
    # prompt the user to input some text
    text = get_string("Text: ")
    letters, words, sentences = count_elements(text)
    L = letters / words * 100
    S = sentences / words * 100
    index = compute_index(L, S)
    grade_level = get_grade_level(index)
    print(grade_level)


# method to count letters, words, and sentences in the given text
def count_elements(text):
    letters = sum(1 for char in text if char.isalpha())
    words = len(text.split())
    sentences = sum(1 for char in text if char in [".", "!", "?"])
    return letters, words, sentences


# method to compute the Coleman-Liau index
def compute_index(L, S):
    return 0.0588 * L - 0.296 * S - 15.8


# method to get the corresponding grade level
def get_grade_level(index):
    rounded_index = round(index)
    if rounded_index >= 16:
        return "Grade 16+"
    elif rounded_index < 1:
        return "Before Grade 1"
    else:
        return f"Grade {rounded_index}"


# check if the script is being run as the main program
if __name__ == "__main__":
    # call the main method to start the program
    main()
