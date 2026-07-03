‎TASK 5.ino‎
Original file line number	Diff line number	Diff line change
@@ -0,0 +1,62 @@
// Pin definitions
const int buzzerPin = 8;
const int segPins[7] = {2, 3, 4, 5, 6, 7, 9}; // pins for segments a-g
// Segment encoding for digits 0-9
// Segments: a, b, c, d, e, f, g
const bool digits[10][7] = {
  {1,1,1,1,1,1,0}, // 0
  {0,1,1,0,0,0,0}, // 1
  {1,1,0,1,1,0,1}, // 2
  {1,1,1,1,0,0,1}, // 3
  {0,1,1,0,0,1,1}, // 4
  {1,0,1,1,0,1,1}, // 5
  {1,0,1,1,1,1,1}, // 6
  {1,1,1,0,0,0,0}, // 7
  {1,1,1,1,1,1,1}, // 8
  {1,1,1,1,0,1,1}  // 9
};
// Function to display a digit on the 7-segment display
void showDigit(int num) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segPins[i], digits[num][i]);
  }
}
void setup() {
  // Set buzzer pin as output
  pinMode(buzzerPin, OUTPUT);
  // Set all segment pins as output
  for (int i = 0; i < 7; i++) {
    pinMode(segPins[i], OUTPUT);
  }
  // Start Serial communication
  Serial.begin(9600);
  Serial.println("=== Beeping Countdown Starting ===");
  // Countdown loop from 9 to 1 (inside setup)
  int count = 9;
  while (count >= 1) {
    Serial.println(count);         // Print current count to Serial Monitor
    showDigit(count);              // Display digit on 7-segment
    tone(buzzerPin, 1000, 200);    // Short beep
    delay(1000);                   // Wait 1 second
    count--;
  }
  // After loop: show 0 on the display
  showDigit(0);
  // Play longer "completion" tone
  tone(buzzerPin, 1500, 1000);
  // Print completion message
  Serial.println("=== Countdown Complete ===");
}
void loop() {
  // loop() is empty — everything happens once in setup()
}
0 commit comments
Comments
0