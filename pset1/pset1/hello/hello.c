#include <stdio.h>
#include <cs50.h>
#include <string.h>
int main(void)
{

  string  yourName = get_string("What is your name?\n");

    printf("Hello, %s\n", yourName);
}