#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    long creditCardNumber;

    creditCardNumber = get_long("Number: \n");
 
    char str[256];
    sprintf(str, "%ld", creditCardNumber);
    //printf("%s\n", str);
    int len;
    len = strlen(str);
    //printf("%s %d\n", str, len);


    if(len < 13 || len > 16){
        printf("%s", "INVALID\n");
        return 0;
    }

    int emptyValue = 0;
    int secondDigit;
    int firstDigit;
    int sumOfTwoDigits;
    int sumOfAllFirstDigits;
    int secondEmptyValue = 0;
    int finalValueTererere;
    int temporarySum = 0;

    if (len % 2 == 0)
    {
        for (int i = len; i >= 0; i -= 2)
        {

            int temp2 = str[i] - '0';
            int duplicated = temp2 * 2;
            temp2 = 0;

            if (duplicated < 9 && duplicated >= 0)
            {
                emptyValue = emptyValue + duplicated;
            }

            if (duplicated > 9)
            {
                secondDigit = duplicated % 10;
                firstDigit = duplicated / 10 % 10;
            }
            sumOfTwoDigits = firstDigit + secondDigit;

            secondDigit = 0;
            firstDigit = 0;
            temporarySum = temporarySum + sumOfTwoDigits;
            sumOfTwoDigits = 0;
            sumOfAllFirstDigits = sumOfTwoDigits + emptyValue;
            sumOfAllFirstDigits = temporarySum + emptyValue; //ADDED
        }

        for (int j = len - 1; j >= 0; j -= 2)
        {

            int temp3 = str[j] - '0';
            secondEmptyValue = secondEmptyValue + temp3;
        }

        finalValueTererere = sumOfAllFirstDigits + secondEmptyValue;

        if (finalValueTererere % 10 == 0)
        {
            //se cartao começa por 4 é visa

            if(str[0] == '4'){
                printf("%s", "VISA\n");
            }
           //se cartao começa por 50, 51 -- 55 é mastercard

           if(str[0] == '5'){
               if(str[1] == '1' || str[1] == '2' || str[1] == '3' || str[1] == '4' || str[1] == '5'){
                  printf("%s", "MASTERCARD\n");
               }else{
                   printf("INVALID\n"); //5673598276138003
               }
           }
           // printf("%s", "Last digit is 0! Valid card.");
           // printf("\n");
        }
        else
        {
            printf("%s", "INVALID\n");
           // printf("\n");
        }
    }

    else
    {
        for (int i = len - 2; i >= 1; i -= 2)
        {
            int temp2 = str[i] - '0';
            int duplicated = temp2 * 2;
            temp2 = 0;

            if (duplicated < 9 && duplicated >= 0)
            {
                emptyValue = emptyValue + duplicated;
            }

            if (duplicated > 9)
            {
                secondDigit = duplicated % 10;
                firstDigit = duplicated / 10 % 10;

            }
            sumOfTwoDigits = firstDigit + secondDigit;

            secondDigit = 0;
            firstDigit = 0;

            temporarySum = temporarySum + sumOfTwoDigits;
            sumOfTwoDigits = 0;

            sumOfAllFirstDigits = sumOfTwoDigits + emptyValue;

            sumOfAllFirstDigits = temporarySum + emptyValue;
        }

        //printf("%i %s", sumOfAllFirstDigits, "sumOfAllFirstDigits");
        //printf("\n");

        for (int k = len - 1; k >= 0; k -= 2)
        {

            int temp4 = str[k] - '0';
            secondEmptyValue = secondEmptyValue + temp4;
        }

        finalValueTererere = sumOfAllFirstDigits + secondEmptyValue;

        if (finalValueTererere % 10 == 0 && str[0] == '3')
        {
            if(str[1] == '4' || str[1] == '7'){
                printf("%s", "AMEX\n");

            }
            else{ //369421438430814
                printf("%s", "INVALID\n");
            }
          //  printf("%s", "Last digit is 0! Valid card.");
          //  printf("\n");

        }
        else if ( finalValueTererere % 10 == 0 && str[0] == '4'){
                printf("%s", "VISA\n");

            }
        else
        {
            printf("%s", "INVALID\n");
           // printf("\n");

        }
    }
}
