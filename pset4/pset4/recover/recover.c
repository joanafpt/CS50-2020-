#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    //accept 1 command-line only
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    char *infile = argv[1];
    // printf("%s", infile);
    //  printf("\n");

    //tentar abrir e reprod erro se n for possivel abrir
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 1;
    }

    unsigned char storage[512];
    char fileName[8]; //tem 8 de tamanho pq é suposto o ficheiro chamar-se "xxx.jpg" + \0
    FILE *outptr = NULL;
    int jpgsCounter = 0;

    //repeat until the end of card:

    while (fread(&storage, sizeof(storage), 1, inptr) || feof(inptr) == 0)
    {       
        if (storage[0] == 0xff && storage[1] == 0xd8 && storage[2] == 0xff &&
            (storage[3] & 0xf0) == 0xe0)
        {
            printf("Parabéns, é um JPG\n");

            //n se pode abrir um ficheiro q ja ta aberto,
            //por isso, validar se ele ja está em uso (aka aberto), e fecha-lo:
            if (outptr != NULL)
            {
                fclose(outptr);
            }
     
            sprintf(fileName, "%03i.jpg", jpgsCounter); //escrever o nome do ficheiro
            outptr = fopen(fileName, "w");
            jpgsCounter++;
        }
        if (outptr != NULL)
        {
            fwrite(&storage, sizeof(storage), 1, outptr);
        }
    }

    //fechar sempre para evitar memory leaks
    if (inptr != NULL)
    {
        fclose(inptr);
    }
  //fechar sempre para evitar memory leaks
    if (outptr != NULL)
    {
        fclose(outptr);
    }

    return 0;
}
