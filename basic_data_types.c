/*Code and information obtained from the following sources:
    https://www.geeksforgeeks.org/c/data-types-in-c/
    https://www.w3schools.com/c/c_booleans.php
*/

#include <stdio.h>
#include <stdbool.h> //must be included to use the boolean data type

//From https://www.youtube.com/watch?v=87SH2Cn0s9A, we have a summary of the following format specifiers: to represent different data types

//format specifier % = defines and formats a type of data to be displayed

// c% = character
// %s = string (array of characters)
// %f = float
// %lf = double
// %d = integer

// %.1 = decimal precision
// %1 = minimum field width
// %- = left align

int integers(){
    /* INTEGERS 
    Stores whole numbers (positive, negative, or zero).
    We use int keyword to declare the integer variable:
    Size: typically 4 bytes, Range: -2,147,483,648 to 2,147,483,647.
    Format specifier: %d.
    */
    int var = 22;
    int var2 = 30;
    int var3 = 40;
    printf("var = %d, %d, %d", var, var2, var3);
    return 0;
}

int characters(){
    /* CHARACTERS
    Stores a single character (like ‘A’, ‘b’, or ‘5’).
    Size: typically 1 byte, Range: -128 to 127 (signed by default).
    Format specifier: %c.
    */
    char ch = 'h';
    printf("ch = %c", ch);

    return 0;
}

int floats(){
    /* FLOATS
    Stores decimal numbers (numbers with fractional part).
    Size: typically 4 bytes, Approximate range: 3.4e-38 to 3.4e+38.
    Format specifier: %f.
    */
    float val = 12.45;
    
    printf("val = %.f", val);
    return 0;
}

double doubles(){ 
    /* DOUBLES
    Stores decimal numbers with more precision than float.
    Size: typically 8 bytes, Approximate range: 1.7e-308 to 1.7e+308.
    Format specifier: %lf.  
    */
    double val = 5.4521;
    
    printf("val = %lf", val);
    return val; //returning a data type of double
}

void voids(){
    /* VOID DATA TYPE
    Represents no value or empty type.
    Used in functions that do not return any value.
    Can also be used for generic pointers (void *) in memory operations.
    */
   printf("This function prints this statement but has no return statement!");
}

int bools(){
    bool y = true;
    bool z = false;
    printf("Y is %d and z is %d", y, z); //1 means true and 0 means false
    return 0;
}

int constants(){
    const float PI = 3.14159; // CANNOT BE CHANGED
    //PI = 5.0; //WILL GIVE ERROR
    printf("The value of Pi is %f", PI);
    return 0;
}

int main(){

    // integers();
    // characters();
    // floats();
    // double x = doubles();
    // printf("\nThis is my response from function doubles %lf", x); //returning the double as a double to keep and display all the information in the double
    // voids();
    // bools();
    // constants();
    return 0;
}

//Other data types include shorts, long long, signed and unsigned ints, etc. More about those in this tutorial: https://www.youtube.com/watch?v=87SH2Cn0s9A


