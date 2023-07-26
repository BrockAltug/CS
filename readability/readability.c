#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// methods
// int count_letters using string input
int count_letters(string text);
// int count_words using string input
int count_words(string text);
// int count_sentences using string input
int count_sentences(string text);
// int variable to calculate the sentence grade level using the letters, words, and sentences
int calculate_grade_level(int letters, int words, int sentences);

// Main method
int main(void)
{
    // get input text from the user
    string text = get_string("Text: ");

    // count the number of letters, words, and sentences in the text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // calculate the grade level using the Coleman-Liau index formula
    int grade_level = calculate_grade_level(letters, words, sentences);

    // print the grade levels
    if (grade_level < 1)
    // if grade level is less than 1
    {
        printf("Before Grade 1\n");
    }
    // else if grade level is greater than or equal to 16
    else if (grade_level >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade_level);
    }
}

// method to count the number of letters in the text
int count_letters(string text)
{
    // new int variable for count starting at 0
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

// method to count the number of words in the text
int count_words(string text)
{
    int count = 1;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isspace(text[i]))
        {
            count++;
        }
    }
    return count;
}

// method to count the number of sentences in the text
int count_sentences(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
    return count;
}

// method to calculate the grade level using the Coleman-Liau index formula
int calculate_grade_level(int letters, int words, int sentences)
{
    // letters = letters divided by words * 100
    float L = (float) letters / words * 100;
    // sentences = sentences divided by words * 100
    float S = (float) sentences / words * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    return (int) (index + 0.5); // round the index to the nearest integer
}