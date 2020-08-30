#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc == 1)
    {
        printf("Usage: ./substitution key");
        printf("\n");
        return 1;
    }

    printf("%i %s", argc, " argumentos passados");
    printf("\n");

    string key = argv[1];
    int lengthOfKey = strlen(key);
    string plaintext;
    string comparativeAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int lengthOgComparativeAlphabet = strlen(comparativeAlphabet); //vai ser sp 26, ate q pt vale a pena declarar?
    string minAlpha = "abcdefghijklmnopqrstuvwxyz";
    int lenOfMinAlpha = strlen(minAlpha);
    char ch = ' ';
    char emptyChar = ' ';

    if (argc != 2 || !isalpha(*argv[1]))
    {
        //aceitar so um arg e q tem de ser alfab
        printf("%s", "Please provide valid key, with 26 length and only letters.\n");
        return 1; //ERROR!
    }

    else if (lengthOfKey != 26)
    {
        printf("%s", "Please provide valid key, with 26 length and only letters.\n");
        return 1; //error!
    }


    for(int y = 0; y < lengthOfKey; y++){
        if(!isalpha(key[y])){
          printf("%s", "Please provide valid key, with 26 length and only letters.\n");
        return 1; //error!
        }
    }



char *copyStr = argv[1];
  for (int g = 0; g < strlen(copyStr); g++){
         copyStr[g] = tolower(copyStr[g]);
  }
 for(int b = 0; b < lengthOfKey; b++){
        if( strchr(copyStr, minAlpha[b]) == NULL){
            printf("Please provide key with no repeated values\n");
           return 1;
        }
    }

    do
    {
        plaintext = get_string("plaintext: ");
    }

    while (strlen(plaintext) == 0 || isblank(plaintext[0]));
    int lengthOfInput = strlen(plaintext);
    printf("%s", "ciphertext: ");
    for (int a = 0; a < lengthOfInput; a++)
    {
        emptyChar = plaintext[a];

        if (isalpha(plaintext[a]))
        {
            for (int j = 0; j < lengthOgComparativeAlphabet; j++)
            {
                if (emptyChar == comparativeAlphabet[j])
                {                  
                    key[j] = toupper(key[j]); // atençao aqui                  
                    printf("%c", key[j]); //OK                   
                }
            }

            for (int k = 0; k < lenOfMinAlpha; k++)
            {
                if (emptyChar == minAlpha[k])
                {
                    
                    key[k] = tolower(key[k]);                  
                    printf("%c", key[k]); // OK
                    
                }
            }

        } // fim do if is alpha
        //se n for apha, simplesmente imprime cm está
        else if (!isalpha(plaintext[a]))
        {
            printf("%c", plaintext[a]);
        }
    }
    printf("\n");
    return 0;
}