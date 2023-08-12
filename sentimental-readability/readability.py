from cs50 import get_string

def main():
    text = get_string("Text: ")
    letters, words, sentences = count_elements(text)
    L = letters / words * 100
    S = sentences / words * 100
    index = compute_index(L, S)
    grade_level = get_grade_level(index)
    print(grade_level)

def count_elements(text):
    letters = sum(1 for char in text if char.isalpha())
    words = len(text.split())
    sentences = sum(1 for char in text if char in ['.', '!', '?'])
    return letters, words, sentences

def compute_index(L, S):
    return 0.0588 * L - 0.296 * S - 15.8

def get_grade_level(index):
    rounded_index = round(index)
    if rounded_index >= 16:
        return "Grade 16+"
    elif rounded_index < 1:
        return "Before Grade 1"
    else:
        return f"Grade {rounded_index}"

if __name__ == "__main__":
    main()
