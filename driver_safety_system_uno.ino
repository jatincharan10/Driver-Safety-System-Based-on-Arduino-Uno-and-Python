#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);;
const int buzzer_Pin = 8;
const int led_Pin = 13;
char sleep_status = 0;
const int alcoholSensorPin = A0;
const int alcoholThreshold = 300;
void setup() {
Serial.begin(9600);
pinMode(buzzer_Pin, OUTPUT);
pinMode(led_Pin, OUTPUT);
lcd.begin(16, 2);
lcd.print("Driver Sleep ");
lcd.setCursor(0,2);
lcd.print("Detection SYSTEM");
digitalWrite(buzzer_Pin, LOW);
digitalWrite(led_Pin, LOW);
}
void loop()
{
while (Serial.available() > 0)
{
sleep_status = Serial.read();
if(sleep_status == 'b')
{
lcd.clear();
lcd.print("Please wake up");
digitalWrite(buzzer_Pin, HIGH);
digitalWrite(led_Pin, HIGH);
delay(2000);
digitalWrite(buzzer_Pin, LOW);
digitalWrite(led_Pin, LOW);
delay(100);
}
else if(sleep_status == 'a')
{
lcd.clear();
lcd.print("All Ok");
lcd.setCursor(0,2);
lcd.print("Drive Safe");
digitalWrite(buzzer_Pin, LOW);
digitalWrite(led_Pin, LOW);
delay(2000);
}
else
{
/* Do Nothing */
}
}
}
 // Read the analog value from the alcohol sensor
 int alcoholValue = analogRead(alcoholSensorPin);

 // Print the alcohol value to the serial monitor
 Serial.print("Alcohol Sensor Value: ");
 Serial.println(alcoholValue);

 // Check if the alcohol value exceeds the threshold
 if (alcoholValue > alcoholThreshold) {
 // If alcohol is detected, activate the alarm (e.g., buzzer or LED)
 digitalWrite(alarmPin, HIGH);
 Serial.println("Warning: Alcohol detected!"); // Print warning to Serial Monitor
 } else {
 // If no alcohol is detected, turn off the alarm
 digitalWrite(alarmPin, LOW);
 }
 // Delay to allow reading stabilization
 delay(500);
}