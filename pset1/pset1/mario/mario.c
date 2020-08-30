#include <stdio.h>
#include <cs50.h>

int height;
int space;
int hash;
int currentLine;

int main(){
    do {
         height = get_int("Please select number between 0 and 8: \n");
    }
    while(height <= 0 || height > 8);

 for(currentLine = 0; currentLine < height; currentLine++){

     for(space = height-currentLine-1; space > 0; space--){
        printf(" ");   
     }
     for(hash = height-currentLine; hash <= height; hash++){
         printf("#");    
     }
     printf("\n");
 }
}