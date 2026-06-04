/*Code and information obtained from the following source:
    https://www.geeksforgeeks.org/c/c-arrays/

*/

#include "stdio.h"

int example_1(){ 
    //array items can be selected by their index
    int arr[] = {2, 4, 8, 12, 16, 18};
    int x = arr[2];
    printf("%d", x);
    return 0;
}

int example_2(){
    
}

int main(){
    /*  ARRAYS
    Store a fixed-size sequence of elements of the same data type.
    Elements can be accessed through their index (arrays are zero-indexed)
    */
    example_1();
    return 0;
}