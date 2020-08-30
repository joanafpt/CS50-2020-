#include <stdio.h>
#include <cs50.h>

int main(void)
{

    int currentLine;
    int hash;
    int height;

    do
    {
        height = get_int("Please insert a number between 0 and 8: \n");
    } while (height < 0 || height > 8);

    for (currentLine = 0; currentLine < height; currentLine++)
    {
        for (hash = 0; hash <= currentLine; hash++)
        {
            printf("#");
        }
        printf("\n");
    }
}
