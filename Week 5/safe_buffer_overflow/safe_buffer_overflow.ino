#include <string.h>  // Needed for strlen() and strcpy()

// Maximum allowed username size (including null terminator)
const int USERNAME_SIZE = 10;

// LED output pins
const int GREEN_LED = 8;  // turns ON when input is valid
const int RED_LED = 9;    // turns ON when input is invalid

// Temporary buffer to safely store incoming Serial data
// This is larger than needed so we can safely validate input first
char temp[64];

// Final buffer where we store validated username
char username[USERNAME_SIZE];

void setup() {

  // Start serial communication so we can read from Serial Monitor
  Serial.begin(9600);

  // Set LED pins as outputs so we can control them
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  // Ensure both LEDs start OFF
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, LOW);

  // Print instructions to the user
  Serial.println("=== SAFE BUFFER DEMO ===");
  Serial.println("Enter a username (max 9 characters):");
}

void loop() {

  // Check if user has typed anything into Serial Monitor
  if (Serial.available() > 0) {

    // Turn off LEDs before processing new input
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, LOW);

    // Read input from Serial until newline ('\n')
    // Store into temp buffer safely (max 63 chars + null terminator)
    int length = Serial.readBytesUntil('\n', temp, 63);

    // Convert input into a proper C string by adding null terminator
    temp[length] = '\0';

    // Handle Windows-style newline (\r\n)
    // Remove carriage return if present
    if (length > 0 && temp[length - 1] == '\r') {
      temp[length - 1] = '\0';
    }

    // ===========================
    // INPUT VALIDATION STEP
    // ===========================

    // Check if input is empty OR too long for username buffer
    // We do this BEFORE copying into the smaller buffer
    if (strlen(temp) > 0 && strlen(temp) < USERNAME_SIZE) {

      // SAFE CASE:
      // Input is within bounds, so we can safely copy it
      strcpy(username, temp);

      // Display accepted username
      Serial.print("VALID USERNAME: ");
      Serial.println(username);

      // Turn ON green LED to indicate success
      digitalWrite(GREEN_LED, HIGH);

    } else {

      // INVALID CASE:
      // Either empty input or too long for buffer
      Serial.println("ERROR: Invalid username (too long or empty)");

      // Turn ON red LED to indicate rejection
      digitalWrite(RED_LED, HIGH);
    }

    // Prompt user again
    Serial.println();
    Serial.println("Enter username:");
  }
}