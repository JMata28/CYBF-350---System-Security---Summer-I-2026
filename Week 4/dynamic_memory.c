//Example code from ChatGPT but modified for the purposes of this course

/*
malloc(size)
- Allocates a block of memory of given size on the heap
- Memory is uninitialized (contains garbage values)
- Returns a pointer to the allocated memory

calloc(n, size)
- Allocates memory for an array of n elements
- Initializes all allocated bytes to 0
- Returns a pointer to the allocated memory

realloc(ptr, new_size)
- Resizes a previously allocated heap block
- May move the memory to a new location if needed
- Preserves existing data up to the smaller of old/new size
- Returns a pointer to the new memory block

free(ptr)
- Releases previously allocated heap memory back to the system
- Prevents memory leaks
- Pointer should not be used after freeing (dangling pointer)
*/

#include <stdio.h>
#include <stdlib.h>

int mal_demo() {
    int *p = malloc(sizeof(int));  // Allocate space for one int

    *p = 42;                       // Store a value in the allocated memory

    printf("%d\n", *p);

    free(p);                       // Release the memory
    return 0;
}

int cal_demo() {
    int *arr = calloc(5, sizeof(int));
    printf("%d\n", arr[0]);  // Prints 0
    free(arr);
    return 0;
}

int real_demo() {

    int *arr = malloc(3 * sizeof(int));
    printf("malloc: created array of 3 ints\n");

    arr = realloc(arr, 5 * sizeof(int));
    printf("realloc: resized array to 5 ints\n");

    free(arr);
    printf("free: memory released\n");
    return 0;

}

int main(){
    mal_demo();
    // cal_demo();
    //real_demo();
    return 0;
}