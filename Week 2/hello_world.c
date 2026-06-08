#include "stdio.h" //This includes certain input/output functions in C

//Comments use double forward slashes
/* Multiline comments use ateriscs and forward slashes
like this */

//The main function is the first function that the program runs automatically
int main(){
    printf("Hello world.\n"); //Most lines in C end in a semicolon
    printf("This line uses an escape character to create a new line\n"); //The forward slash is the escape character
    printf("This line uses escape characters to create tab spaces between the following numbers: 1\t2\t3\t4\t5");
    printf("\n"); //Prints a new line
    puts("This is a line printed with puts"); //Puts prints a string and automatically adds a newline at the end.
    return 0;
}

//More on escape sequences here: https://www.geeksforgeeks.org/c/escape-sequence-in-c/ 