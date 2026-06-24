/*
 * MEMORY LEAK DEMO
 * This code was created with AI
 * Green LED (Pin 8):
 *   Heap memory is still available.
 *
 * Red LED (Pin 9):
 *   Heap memory has been exhausted due to a memory leak.
 */

#include <stdlib.h>

const int GREEN_LED = 8;
const int RED_LED = 9;

void setup() {

  Serial.begin(9600);

  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(RED_LED, LOW);

  Serial.println("=== MEMORY LEAK DEMO ===");
}

void loop() {

  // Allocate 100 bytes from the heap
  char *buffer = (char *)malloc(100);

  // If malloc() fails, the heap has been exhausted
  if (buffer == NULL) {

    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, HIGH);

    Serial.println("Memory allocation FAILED.");
    Serial.println("Heap memory exhausted due to memory leak.");

    // Stop the program
    while (true) {
    }
  }

  // Fill the allocated memory (optional, just to use it)
  for (int i = 0; i < 100; i++) {
    buffer[i] = 'A';
  }

  // IMPORTANT:
  // We intentionally DO NOT call:
  // free(buffer);
  //
  // This creates the memory leak.

  Serial.println("Allocated another 100 bytes...");

  // Wait about 250 ms before leaking another block.
  // After roughly 20 allocations (~2000 bytes),
  // the Arduino Uno's 2 KB SRAM will be exhausted,
  // taking about 5 seconds.
  delay(250);
}