//This code was made with help from AI


#include <string.h>

/*
 * ==========================================================
 * CONTROLLED BUFFER OVERFLOW SIMULATION (TEACHING VERSION)
 * ==========================================================
 *
 * Instead of relying on real stack memory layout (unreliable),
 * we simulate memory as a single contiguous array.
 *
 * This guarantees:
 *  - predictable "adjacent memory"
 *  - visible overflow effects every time
 *  - consistent classroom behavior
 */

// ==========================================================
// LED OUTPUT PINS
// ==========================================================
const int GREEN_LED = 8;   // normal operation
const int RED_LED   = 9;   // overflow detected

// ==========================================================
// SIMULATED MEMORY REGION
// ==========================================================
//
// We create one continuous block of memory.
// We manually divide it into "variables".
//
// Layout:
// -------------------------------------------------
// [ username buffer ][ status flag ][ guard value ]
// -------------------------------------------------
char memory[20];

// We define offsets into this memory block:

#define USERNAME_START 0
#define USERNAME_SIZE 10

#define STATUS_INDEX 10
#define GUARD_INDEX  11

// ==========================================================
// SETUP
// ==========================================================
void setup() {

  Serial.begin(9600);

  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, LOW);

  Serial.println("=== SIMULATED BUFFER OVERFLOW DEMO ===");
  Serial.println("Enter a username:");
}

// ==========================================================
// LOOP
// ==========================================================
void loop() {

  if (Serial.available() > 0) {

    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, LOW);

    // Temporary input buffer (safe input area)
    char temp[64];

    int len = Serial.readBytesUntil('\n', temp, 63);
    temp[len] = '\0';

    // ======================================================
    // STEP 1: INITIALIZE SIMULATED MEMORY
    // ======================================================
    //
    // We reset the memory region before each run so behavior
    // is consistent for students.
    memset(memory, 0, sizeof(memory));

    // Set known values in "protected" region
    memory[STATUS_INDEX] = 0;  // system state (should never change)
    memory[GUARD_INDEX]  = 0x55; // sentinel guard value

    // ======================================================
    // STEP 2: UNSAFE COPY (SIMULATED OVERFLOW)
    // ======================================================
    //
    // We deliberately write WITHOUT bounds checking.
    // If input exceeds 10 bytes, it overwrites:
    //   - status flag
    //   - guard value
    for (int i = 0; i < len; i++) {
      memory[USERNAME_START + i] = temp[i];
    }

    // ======================================================
    // STEP 3: READ BACK VALUES FROM SIMULATED MEMORY
    // ======================================================

    char *username = &memory[USERNAME_START];
    char status    = memory[STATUS_INDEX];
    char guard     = memory[GUARD_INDEX];

    Serial.print("Username: ");
    Serial.println(username);

    Serial.print("Status: ");
    Serial.println((int)status);

    Serial.print("Guard: ");
    Serial.println((int)guard);

    // ======================================================
    // STEP 4: DETECT OVERFLOW EFFECT
    // ======================================================
    //
    // In a correct system:
    //   status = 0
    //   guard  = 0x55
    //
    // If either changes → overflow occurred
    if (status != 0 || guard != 0x55) {

      Serial.println("!!! BUFFER OVERFLOW DETECTED !!!");
      digitalWrite(RED_LED, HIGH);

    } else {

      Serial.println("Memory OK");
      digitalWrite(GREEN_LED, HIGH);
    }

    Serial.println("-------------------------");
    Serial.println("Enter username:");
  }
}