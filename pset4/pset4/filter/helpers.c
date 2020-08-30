#include <stdio.h>
#include <math.h>
#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
   /* printf("%d", height);
    printf("\n");
    printf("%d", width);
    printf("\n");*/

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            float averageOfRGBFloat = (float)(image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3;
            int averageOfRGB = round(averageOfRGBFloat);
            //  printf("%d %s", averageOfRGB, "average of rgb \n");

            image[i][j].rgbtBlue = averageOfRGB;
            image[i][j].rgbtGreen = averageOfRGB;
            image[i][j].rgbtRed = averageOfRGB;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            float sepiaRed;
            float sepiaGreen;
            float sepiaBlue;

            sepiaRed = (float) .393 * image[i][j].rgbtRed +
                       .769 * image[i][j].rgbtGreen +
                       .189 * image[i][j].rgbtBlue;

            sepiaGreen = (float).349 * image[i][j].rgbtRed +
                         .686 * image[i][j].rgbtGreen +
                         .168 * image[i][j].rgbtBlue;

            sepiaBlue = (float).272 * image[i][j].rgbtRed +
                        .534 * image[i][j].rgbtGreen +
                        .131 * image[i][j].rgbtBlue;

            int intSepiaRed = round(sepiaRed);
            int intSepiaGreen = round(sepiaGreen);
            int intSepiaBlue = round(sepiaBlue);


            if (intSepiaRed > 255) {intSepiaRed = 255;}

             if(intSepiaGreen > 255){intSepiaGreen = 255;}

            if(intSepiaBlue > 255){ intSepiaBlue = 255;}


            image[i][j].rgbtBlue = intSepiaBlue;
            image[i][j].rgbtGreen = intSepiaGreen;
            image[i][j].rgbtRed = intSepiaRed;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    //dividir a width e dps round:

    int halfWidth = round(width / 2);
    printf("%i", halfWidth); //300 p uma image de 600
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < halfWidth; j++)
        {
            RGBTRIPLE temporary = image[i][j]; // 0 0

            // este vai guardar a ultima posicao: width - j - 1  - isto faz com q j ande para tras,
            //pq como o j é cada vez maior (está seer incrementado no loop interno)
            //, qd é envolvido numa suibtraçao faz com  o result dessa subtraçao seja um indice mais atras
            //(maior, pq width-2 é mais atras do que width-1, p ex)
            image[i][j] = image[i][width - j - 1];

            image[i][width - j - 1] = temporary;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    // required copy in order to blur pixels with the correct starting value
     RGBTRIPLE image2[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image2[i][j] = image[i][j];
        }
    }

//apply changes:
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //CANTO SUPERIOR ESQUERDO ///////////////////////////////////////////////////////////////////////////////

            if (image[i][j].rgbtBlue == image[0][0].rgbtBlue &&
                image[i][j].rgbtGreen == image[0][0].rgbtGreen &&
                image[i][j].rgbtRed == image[0][0].rgbtRed)
            {


          float blue = round((float)
          (image2[0][0].rgbtBlue +
          image2[0][1].rgbtBlue +
          image2[1][0].rgbtBlue +
          image2[1][1].rgbtBlue) / 4);

          float red = round((float)
          (image2[0][0].rgbtRed +
          image2[0][1].rgbtRed +
          image2[1][0].rgbtRed +
          image2[1][1].rgbtRed) / 4);


          float green = round((float)
          (image2[0][0].rgbtGreen +
          image2[0][1].rgbtGreen +
          image2[1][0].rgbtGreen +
          image2[1][1].rgbtGreen) / 4);


          image[0][0].rgbtBlue = blue;
          image[0][0].rgbtGreen = green;
          image[0][0].rgbtRed = red;

            }

            else if ( //CANTO INFERIOR DIREITO
                image[i][j].rgbtBlue == image[height - 1][width - 1].rgbtBlue &&
                image[i][j].rgbtGreen == image[height - 1][width - 1].rgbtGreen &&
                image[i][j].rgbtRed == image[height - 1][width - 1].rgbtRed)
            {

          float blue = round((float)
          (image2[height - 1][width - 1].rgbtBlue +
          image2[height - 1][width - 2].rgbtBlue +
          image2[height - 2][width - 1].rgbtBlue +
          image2[height - 2][width - 2].rgbtBlue) / 4);

          float red = round((float)
          (image2[height - 1][width - 1].rgbtRed +
          image2[height - 1][width - 2].rgbtRed +
          image2[height - 2][width - 1].rgbtRed +
          image2[height - 2][width - 2].rgbtRed) / 4);

          float green = round((float)
          (image2[height - 1][width - 1].rgbtGreen +
          image2[height - 1][width - 2].rgbtGreen +
          image2[height - 2][width - 1].rgbtGreen +
          image2[height - 2][width - 2].rgbtGreen) / 4);

                image[height-1][width-1].rgbtBlue = blue;
                image[height-1][width-1].rgbtGreen = green;
                image[height-1][width-1].rgbtRed = red;

            }

            //CANTO INFERIOR ESQUERDO
            else if (
                image[i][j].rgbtBlue == image[height - 1][0].rgbtBlue &&
                image[i][j].rgbtGreen == image[height - 1][0].rgbtGreen &&
                image[i][j].rgbtRed == image[height - 1][0].rgbtRed)
            {

            float blue = round((float)
            (image2[height - 1][0].rgbtBlue +
            image2[height - 2][0].rgbtBlue +
            image2[height - 2][1].rgbtBlue +
            image2[height - 1][1].rgbtBlue) / 4);

            float red = round((float)
            (image2[height - 1][0].rgbtGreen +
            image2[height - 2][0].rgbtGreen +
            image2[height - 2][1].rgbtGreen +
            image2[height - 1][1].rgbtGreen) / 4);

            float green = round((float)
            (image2[height - 1][0].rgbtRed +
            image2[height - 2][0].rgbtRed +
            image2[height - 2][1].rgbtRed +
            image2[height - 1][1].rgbtRed) / 4);

                image[height-1][0].rgbtBlue = blue;
                image[height-1][0].rgbtGreen = green;
                image[height-1][0].rgbtRed = red;
            }

            else if ( //CANTO SUPERIOR DIREITO
                image[i][j].rgbtBlue == image[0][width - 1].rgbtBlue &&
                image[i][j].rgbtGreen == image[0][width - 1].rgbtGreen &&
                image[i][j].rgbtRed == image[0][width - 1].rgbtRed)
            {

              float blue = round((float)
              (image2[0][width - 1].rgbtBlue +
              image2[0][width - 2].rgbtBlue +
              image2[1][width - 2].rgbtBlue +
              image2[1][width - 1].rgbtBlue) / 4);

              float green = round((float)
              (image2[0][width - 1].rgbtGreen +
              image2[0][width - 2].rgbtGreen +
              image2[1][width - 2].rgbtGreen +
              image2[1][width - 1].rgbtGreen) / 4);

              float red = round((float)
              (image2[0][width - 1].rgbtRed +
              image2[0][width - 2].rgbtRed +
              image2[1][width - 2].rgbtRed +
              image2[1][width - 1].rgbtRed) / 4);

                image[0][width-1].rgbtBlue = blue;
                image[0][width-1].rgbtGreen = green;
                image[0][width-1].rgbtRed = red;

            }

/////////////////////ATE AQUI TA TUDO CERTO -------------------------------------------

            //teste coluna esq

            else if (i != 0 && i != height-1 && j == 0){

                float b =
                round((float)
                (image2[i][j].rgbtBlue +
                image2[i - 1][j].rgbtBlue +
                image2[i - 1][j+1].rgbtBlue +
                image2[i + 1][j].rgbtBlue +
                image2[i + 1][j+1].rgbtBlue +
                image2[i][j+1].rgbtBlue) / 6) ;

                float r = round((float)
                (image2[i][j].rgbtRed +
                image2[i - 1][j].rgbtRed +
                image2[i - 1][j+1].rgbtRed +
                image2[i + 1][j].rgbtRed +
                image2[i + 1][j+1].rgbtRed +
                image2[i][j+1].rgbtRed) / 6) ;


                float g = round((float)
                (image2[i][j].rgbtGreen +
                image2[i - 1][j].rgbtGreen +
                image2[i - 1][j+1].rgbtGreen +
                image2[i + 1][j].rgbtGreen +
                image2[i + 1][j+1].rgbtGreen +
                image2[i][j+1].rgbtGreen) / 6 );

                image[i][j].rgbtBlue = b;
                image[i][j].rgbtGreen = g;
                image[i][j].rgbtRed = r;

            }

            //teste col direita

            else if(i != 0 && i != height-1 && j == width-1){

               float  b = round((float)
               (image2[i][j].rgbtBlue +
               image2[i - 1][j].rgbtBlue +
                image2[i - 1][j-1].rgbtBlue +
                image2[i][j-1].rgbtBlue +
                image2[i + 1][j].rgbtBlue +
                image2[i + 1][j-1].rgbtBlue) / 6);

                float g = round((float)
                (image2[i][j].rgbtGreen +
                image2[i - 1][j].rgbtGreen +
                image2[i - 1][j-1].rgbtGreen +
                image2[i][j-1].rgbtGreen +
                image2[i - 1][j].rgbtGreen +
                image2[i - 1][j-1].rgbtGreen) / 6 ) ;

                float r = round((float)
                (image2[i][j].rgbtRed +
                image2[i - 1][j].rgbtRed +
                image2[i - 1][j-1].rgbtRed +
                image2[i][j-1].rgbtRed +
                image2[i + 1][j].rgbtRed
                + image2[i + 1][j-1].rgbtRed) / 6   );

                image[i][j].rgbtBlue = b;
                image[i][j].rgbtGreen = g;
                image[i][j].rgbtRed = r;


            }

            //teste upper line

            else if(i == 0 && j != 0 && j != width-1){

              float b = round((float)
              (image2[i][j].rgbtBlue +
              image2[i][j - 1].rgbtBlue +
              image2[i][j + 1].rgbtBlue +
              image2[i+1][j - 1].rgbtBlue +
              image2[i+1][j].rgbtBlue +
              image2[i+1][j + 1].rgbtBlue) / 6);

              float  g = round((float)
              (image2[i][j].rgbtGreen +
              image2[i][j - 1].rgbtGreen +
              image2[i][j + 1].rgbtGreen +
              image2[i+1][j - 1].rgbtGreen +
              image2[i+1][j].rgbtGreen +
              image2[i+1][j + 1].rgbtGreen) / 6);

              float  r = round((float)
                                (image2[i][j].rgbtRed +
                                image2[i][j - 1].rgbtRed +
                                image2[i][j + 1].rgbtRed +
                                image2[i+1][j - 1].rgbtRed +
                                image2[i+1][j].rgbtRed +
                                image2[i+1][j + 1].rgbtRed) /  6);

        image[i][j].rgbtBlue = b;
        image[i][j].rgbtGreen = g;
        image[i][j].rgbtRed = r;

            }

            //teste bottom line

            else if(i == height-1 && j != 0 && j != width-1){

             float b = round((float)
             (image2[i][j].rgbtBlue +
             image2[i][j - 1].rgbtBlue +
             image2[i][j + 1].rgbtBlue +
             image2[i-1][j].rgbtBlue +
             image2[i-1][j - 1].rgbtBlue +
             image2[i-1][j + 1].rgbtBlue) / 6);

             float g = round((float)
             (image2[i][j].rgbtGreen +
             image2[i][j - 1].rgbtGreen +
             image2[i][j + 1].rgbtGreen +
             image2[i-1][j].rgbtGreen +
             image2[i-1][j - 1].rgbtGreen +
             image2[i-1][j + 1].rgbtGreen) /6);

              float r = round((float)
                         (image2[i][j].rgbtRed +
                          image2[i][j - 1].rgbtRed +
                          image2[i][j + 1].rgbtRed +
                          image2[i-1][j].rgbtRed +
                          image2[i-1][j - 1].rgbtRed +
                          image2[i-1][j + 1].rgbtRed) / 6);

            image[i][j].rgbtBlue = b;
            image[i][j].rgbtGreen = g;
            image[i][j].rgbtRed = r;

            }


            else {

         float  r = round((float)
           (image2[i][j].rgbtRed +
           image2[i - 1][j].rgbtRed +
           image2[i + 1][j].rgbtRed +
           image2[i + 1][j - 1].rgbtRed +
           image2[i + 1][j + 1].rgbtRed +
           image2[i][j + 1].rgbtRed +
           image2[i][j - 1].rgbtRed +
           image2[i - 1][j + 1].rgbtRed +
           image2[i - 1][j - 1].rgbtRed) / 9);


           float b = round((float)
           (image2[i][j].rgbtBlue +
           image2[i - 1][j].rgbtBlue +
           image2[i + 1][j].rgbtBlue +
           image2[i + 1][j - 1].rgbtBlue +
           image2[i + 1][j + 1].rgbtBlue +
           image2[i][j + 1].rgbtBlue +
           image2[i][j - 1].rgbtBlue +
           image2[i - 1][j + 1].rgbtBlue +
           image2[i - 1][j - 1].rgbtBlue) / 9);


           float g = round((float)
           (image2[i][j].rgbtGreen +
           image2[i - 1][j].rgbtGreen +
           image2[i + 1][j].rgbtGreen +
           image2[i + 1][j - 1].rgbtGreen +
           image2[i + 1][j + 1].rgbtGreen +
           image2[i][j + 1].rgbtGreen +
           image2[i][j - 1].rgbtGreen +
           image2[i - 1][j + 1].rgbtGreen +
           image2[i - 1][j - 1].rgbtGreen) / 9);


            image[i][j].rgbtBlue = b;
            image[i][j].rgbtGreen = g;
            image[i][j].rgbtRed = r;


            }



        }
    }



    return;
}
