#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    char *key;
    string plaintext;
    char character;

    if (argc != 2 || !isdigit(*argv[1]))
    {
        //aceitar so um arg e q tem de ser um numero
        printf("%s", "Usage: ./caesar key\n");
        return 1; // 0 é qd ta td fixe
    }

    else
    {
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if ((int)argv[1][i] >= 65 && (int)argv[1][i] <= 90)
            {
                printf("%s", "Usage: ./caesar key\n");
                return 1;
            }
            else if ((int)argv[1][i] >= 97 && (int)argv[1][i] <= 122)
            {
                printf("%s", "Usage: ./caesar key\n");
                return 1;
            }
        }
        key = argv[1];

        int k;
        k = atoi(argv[1]);
        printf("%i", k); // key provided by user's input
        printf("\n");

        do
        {
            plaintext = get_string("plaintext: ");
        }

        while (strlen(plaintext) == 0 || isblank(plaintext[0]));
        //agora começa a cifragem :D
        int plaintextLength = strlen(plaintext);
        printf("ciphertext: ");
        for (int j = 0; j < plaintextLength; j++)
        {
            //se o char ORIGINAL nao representa uma letra, deixa estar como está
            if (!isalpha((int)plaintext[j]))
            {
                printf("%c", (int)plaintext[j]);
            }
            else if (isalpha((int)plaintext[j]))
            {
                //se char é uma letra e é minusculoo :
                if (islower((int)plaintext[j]))
                {
                    character = (char)(((int)plaintext[j] + k - 97) % 26 + 97);
                    printf("%c", character);
                    character = ' ';
                }

                //se char é letra e é maiusculo
                else if (isupper((int)plaintext[j]))
                {
                    character = (char)(((int)plaintext[j] + k - 65) % 26 + 65);
                    printf("%c", character);
                    character = ' ';
                }
            }

            // printf( "%c", character );
            //  character = ' ';
        } // fim do for q percorre o plaintext

        printf("\n");

    } //isto é do fim do  else

    return 0;
}