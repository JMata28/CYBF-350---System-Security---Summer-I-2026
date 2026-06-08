#include <unistd.h>

int main() {
    char buffer[100]; //Initialize an empty string of 100 bytes

    ssize_t bytes = read(0, buffer, 100); //Read what the user types (first 100 bytes) and save it inside the string "buffer"

    write(1, buffer, bytes); //Output to the terminal what is saved in "buffer"
    return 0;
}