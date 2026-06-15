//Code originally obtained from https://www.youtube.com/watch?v=DplxIq0mc_Y and modified for the purposes of this course

#include <stdio.h>

void printAge(int *pAge)
{
   printf("You are %d years old\n", *pAge); //dereference
}

int main()
{
   // pointer = a "variable-like" reference that holds a memory address to another variable, array, etc.
   // some tasks are performed more easily with pointers
   // * when included before a variable name means that it is a pointer to the type of data defined before the variable name
   // * = indirection operator (value at address) to dereferrence
   //You can thinkg of the & symbol to mean "the address of"

   int age = 21;
   int *pAge = &age; //pAge is a pointer to an integer and it is equal to the address of variable age. We use int here because age is of type int. If we don't know the type, use void. If we use an incorrect type, we'll get an error

   printAge(pAge);

   // printf("address of age: %p\n", &age); //%p is the specifier to display a memory address
   // printf("value of pAge: %p\n", pAge);
   // printf("size of age: %d bytes\n", sizeof(age)); //
   // printf("size of pAge: %d bytes\n", sizeof(pAge)); //returns the number of bytes. pointers use 8 bytes
   // printf("value of age: %d\n", age);
   // printf("value at stored address: %d\n", *pAge); //dereferencing

   return 0;
}