#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    string text = get_string("Text: ");
    int characters = 0;
    int sentences = 0;
    int words = 1;
    int n;
    char i;

    for (n = 0, i = text[n]; i != '\0'; n += 1)
    {
        i = text[n];
        if (isalpha(i))
        {
            characters += 1;
        }
        else if (i == '.' || i == '!' || i == '?')
        {
            sentences += 1;
        }
        else if (i == ' ')
        {
            words += 1;
        }
    }
    float L = ((float) characters) / words * 100;
    float S = ((float) sentences) / words * 100;
    float index0 = 0.0588 * L - 0.296 * S - 15.8;
    int index = round(index0);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
