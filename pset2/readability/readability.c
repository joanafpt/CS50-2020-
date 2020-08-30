#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int main(void)
{
    string text;
    int numberOfLetters = 0;
    int numberOfSentences = 0;
    int numberOfWords = 1;
    float l;
    float s;
    float index;
    do
    {
        text = get_string("Text: ");

    }
    while (strlen(text) == 0 || isspace(text[0]));

    int len = strlen(text);

    for (int i = 0; i < len; i++)
    {
        //printf("%c, %s", text[i], "text*** \n");
        //get number of sentences:
        if (text[i] == 33 || text[i] == 63 || text[i] == 46)
        {
            //printf("%c %s", text[i], "this char is a punct sign\n");
            numberOfSentences++;
        }
        //get number of letters:
        else if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
        {
            numberOfLetters++;
        }
        //get number of words:
        else if (text[i] == 32)
        {
            numberOfWords++;
        }
    }

    l = (float) numberOfLetters * 100 / (float) numberOfWords;
    s = (float)  numberOfSentences * 100 / (float)  numberOfWords;

    index = 0.0588 * l - 0.296 * s - 15.8;

    if (index > 16)
    {
        printf("%s", "Grade 16+\n");
    }
    else if(index < 0) {
        printf("%s", "Before Grade 1\n");
    }
    else if(index > 9 && index < 16){
         printf("Grade %2.f\n", index);
    }
    else if(index > 0 && index < 10){
        printf("Grade%2.f\n", index);
    }

}



