#include <ThreeWire.h>  
#include <RtcDS1302.h>

ThreeWire myWire(3, 2, 4); // DAT (IO), CLK (SCLK), RST (CE)
RtcDS1302<ThreeWire> Rtc(myWire);

#include <SoftwareSerial.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include "HX711.h"

SoftwareSerial GSM_Module(11, 10); // (TX, RX)

#define ONE_WIRE_BUS 8
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

const int analogPin = A0;
const int inputValues[] = {0, 2, 4, 7, 10, 21, 50, 150};
const int outputValues[] = {44, 57, 64, 66, 70, 73, 78, 92};
const int tableSize = sizeof(inputValues) / sizeof(inputValues[0]);

const int LOADCELL_DOUT_PIN = 6; //WHITE
const int LOADCELL_SCK_PIN = 7; //GREEN
HX711 scale;

#define rpi 9

void setup() {
    Serial.begin(19200);

    pinMode(rpi, INPUT_PULLUP);

    Rtc.Begin();

    // Set the date and time to June 12, 2024, 2:41 PM
    RtcDateTime setTime(2024, 6, 12, 4, 59, 45);
    Rtc.SetDateTime(setTime);

    if (!Rtc.GetIsRunning()) {
        Serial.println("RTC is not running, starting it now");
        Rtc.SetIsRunning(true);
    }

    Serial.println("RTC initialized and time set.");
  
  // Initialize GSM module
  GSM_Module.begin(19200);
  delay(1000); // Give some time for the GSM module to initialize
  
  // Initialize temperature sensor
  sensors.begin();

  // Initialize weight sensor
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale(-22842.70);  // Calibrated value
  // scale.tare();  // Reset the scale to 0
  Serial.println("Scale ready.");
}

void loop() {
    RtcDateTime now = Rtc.GetDateTime();
    int waxmoth = (digitalRead(rpi));
    if (waxmoth == HIGH){
      gate();
    }

    // Check for specific times to print the message
    if ((now.Hour() == 0 && now.Minute() == 0 && now.Second() == 10)){
      zero();
    }

    if ((now.Hour() == 1 && now.Minute() == 0 && now.Second() == 10)){
      one();
    }

    if ((now.Hour() == 2 && now.Minute() == 0 && now.Second() == 10)){
      two();
    }

    if ((now.Hour() == 3 && now.Minute() == 0 && now.Second() == 10)){
      three();
    }

    if ((now.Hour() == 4 && now.Minute() == 0 && now.Second() == 10)){
      four();
    }

    if ((now.Hour() == 5 && now.Minute() == 0 && now.Second() == 10)){
      five();
    }

    if ((now.Hour() == 6 && now.Minute() == 0 && now.Second() == 10)){
      six();
    }

    if ((now.Hour() == 7 && now.Minute() == 0 && now.Second() == 10)){
      seven();
    }

    if ((now.Hour() == 8 && now.Minute() == 0 && now.Second() == 10)){
      eight();
    }

    if ((now.Hour() == 9 && now.Minute() == 0 && now.Second() == 10)){
      nine();
    }

    if ((now.Hour() == 10 && now.Minute() == 0 && now.Second() == 10)){
      ten();
    }

    if ((now.Hour() == 11 && now.Minute() == 0 && now.Second() == 10)){
      eleven();
    }

    if ((now.Hour() == 12 && now.Minute() == 0 && now.Second() == 10)){
      twelve();
    }

    if ((now.Hour() == 13 && now.Minute() == 0 && now.Second() == 10)){
      thirteen();
    }

    if ((now.Hour() == 14 && now.Minute() == 0 && now.Second() == 10)){
      fourteen();
    }

    if ((now.Hour() == 15 && now.Minute() == 0 && now.Second() == 10)){
      fifteen();
    }

    if ((now.Hour() == 16 && now.Minute() == 0 && now.Second() == 10)){
      sixteen();
    }

    if ((now.Hour() == 17 && now.Minute() == 0 && now.Second() == 10)){
      seventeen();
    }

    if ((now.Hour() == 18 && now.Minute() == 0 && now.Second() == 10)){
      eighteen();
    }

    if ((now.Hour() == 19 && now.Minute() == 0 && now.Second() == 10)){
      nineteen();
    }

    if ((now.Hour() == 20 && now.Minute() == 0 && now.Second() == 10)){
      twenty();
    }

    if ((now.Hour() == 21 && now.Minute() == 0 && now.Second() == 10)){
      twentyone();
    }

    if ((now.Hour() == 22 && now.Minute() == 0 && now.Second() == 10)){
      twentytwo();
    }

    if ((now.Hour() == 23 && now.Minute() == 0 && now.Second() == 10)){
      twentythree();
    }

    delay(2000); // Check every 2 seconds
}

void gate() {
  float tempC = getTemperature();
  int soundLevel = getSoundLevel();
  float weight = getWeight();

  String message = "Bee Hive 2\n" + 
                    String("Adult wax moth detected. Gate closed. \n") + 
                    String("Temp: ") + String(tempC, 1) + " C\n" + 
                    String("Sound: ") + String(soundLevel) + " dB\n" + 
                    String("Weight: ") + String(weight, 1) + " kg";

  Serial.print("Sending message: ");
  Serial.println(message);

  // Send message via GSM
  carl(message); delay(500); 
  earl(message); delay(500);
  jim(message); delay(500); 
  regine(message); delay(500); 
  nath(message); delay(500);

  String Omessage = "Bee Hive 2\n" + String("1");

 // Serial.print("Sending message: ");
 // Serial.println(Omessage);

  // Send message via GSM
 // oled(Omessage);
 // delay(500);
}

void zero() {
  float tempC = getTemperature();
  int soundLevel = getSoundLevel();
  float weight = getWeight();

  String message = "Bee Hive 2\n" + 
                    String("12:00 am\n") + 
                    String("Temp: ") + String(tempC, 1) + " C\n" + 
                    String("Sound: ") + String(soundLevel) + " dB\n" + 
                    String("Weight: ") + String(weight, 1) + " kg";

  Serial.print("Sending message: ");
  Serial.println(message);

  // Send message via GSM
  carl(message); delay(500); 
  earl(message); delay(500);
  jim(message); delay(500); 
  regine(message); delay(500); 
  nath(message); delay(500);

  String Omessage = "Bee Hive 2\n" + String("12\n") + String(tempC, 0) + "\n" + String(soundLevel) + " \n" + String(weight, 0);

  Serial.print("Sending message: ");
  Serial.println(Omessage);

  // Send message via GSM
  oled(Omessage);
  delay(500);
}

void one() {
  float tempC = getTemperature();
  int soundLevel = getSoundLevel();
  float weight = getWeight();

  String message = "Bee Hive 2\n" + String("1:00 am\n") + String("Temp: ") + String(tempC, 1) + " C\n" + String("Sound: ") + String(soundLevel) + " dB\n" + String("Weight: ") + String(weight, 1) + " kg";

  Serial.print("Sending message: ");
  Serial.println(message);

  // Send message via GSM
  carl(message); delay(500); earl(message); delay(500); jim(message); delay(500); regine(message); delay(500); nath(message); delay(500);

  String Omessage = "Bee Hive 2\n" + String("1\n") + String(tempC, 0) + "\n" + String(soundLevel) + " \n" + String(weight, 0);

  Serial.print("Sending message: ");
  Serial.println(Omessage);

  // Send message via GSM
  oled(Omessage);
  delay(500);
}

void two() {
  float tempC = getTemperature();
  int soundLevel = getSoundLevel();
  float weight = getWeight();

  String message = "Bee Hive 2\n" + String("2:00 am\n") + String("Temp: ") + String(tempC, 1) + " C\n" + String("Sound: ") + String(soundLevel) + " dB\n" + String("Weight: ") + String(weight, 1) + " kg";

  Serial.print("Sending message: ");
  Serial.println(message);

  // Send message via GSM
  carl(message); delay(500); earl(message); delay(500); jim(message); delay(500); regine(message); delay(500); nath(message); delay(500);

  String Omessage = "Bee Hive 2\n" + String("2\n") + String(tempC, 0) + "\n" + String(soundLevel) + " \n" + String(weight, 0);

  Serial.print("Sending message: ");
  Serial.println(Omessage);

  // Send message via GSM
  oled(Omessage);
  delay(500);
}

void three() {
  float tempC = getTemperature();
  int soundLevel = getSoundLevel();
  float weight = getWeight();

  String message = "Bee Hive 2\n" + 
                    String("3:00 am\n") + 
                    String("Temp: ") + String(tempC, 1) + " C\n" + 
                    String("Sound: ") + String(soundLevel) + " dB\n" + String("Weight: ") + String(weight, 1) + " kg";


  Serial.print("Sending message: ");
  Serial.println(message);

  // Send message via GSM
  carl(message); delay(500); earl(message); delay(500); jim(message); delay(500); regine(message); delay(500); nath(message); delay(500);

  String Omessage = "Bee Hive 2\n" + String("3\n") + String(tempC, 0) + "\n" + String(soundLevel) + " \n" + String(weight, 0);

  Serial.print("Sending message: ");
  Serial.println(Omessage);

  // Send message via GSM
  oled(Omessage);
  delay(500);
}

void four() {
  float tempC = getTemperature();
  int soundLevel = getSoundLevel();
  float weight = getWeight();

  String message = "Bee Hive 2\n" + String("4:00 am\n") + String("Temp: ") + String(tempC, 1) + " C\n" + String("Sound: ") + String(soundLevel) + " dB\n" + String("Weight: ") + String(weight, 1) + " kg";

  Serial.print("Sending message: ");
  Serial.println(message);

  // Send message via GSM
  carl(message); delay(500); earl(message); delay(500); jim(message); delay(500); regine(message); delay(500); nath(message); delay(500);

  String Omessage = "Bee Hive 2\n" + String("4\n") + String(tempC, 0) + "\n" + String(soundLevel) + " \n" + String(weight, 0);

  Serial.print("Sending message: ");
  Serial.println(Omessage);

  // Send message via GSM
  oled(Omessage);
  delay(500);
}

void five() {
  float tempC = getTemperature();
  int soundLevel = getSoundLevel();
  float weight = getWeight();

  String message = "Bee Hive 2\n" + String("5:00 am\n") + String("Temp: ") + String(tempC, 1) + " C\n" + String("Sound: ") + String(soundLevel) + " dB\n" + String("Weight: ") + String(weight, 1) + " kg";

  Serial.print("Sending message: ");
  Serial.println(message);

  // Send message via GSM
  carl(message); delay(500); earl(message); delay(500); jim(message); delay(500); regine(message); delay(500); nath(message); delay(500);

  String Omessage = "Bee Hive 2\n" + String("5\n") + String(tempC, 0) + "\n" + String(soundLevel) + " \n" + String(weight, 0);

  Serial.print("Sending message: ");
  Serial.println(Omessage);

  // Send message via GSM
  oled(Omessage);
  delay(500);
}

void six() {
  float tempC = getTemperature();
  int soundLevel = getSoundLevel();
  float weight = getWeight();

  String message = "Bee Hive 2\n" + String("6:00 am\n") + String("Temp: ") + String(tempC, 1) + " C\n" + String("Sound: ") + String(soundLevel) + " dB\n" + String("Weight: ") + String(weight, 1) + " kg";

  Serial.print("Sending message: ");
  Serial.println(message);

  // Send message via GSM
  carl(message); delay(500); earl(message); delay(500); jim(message); delay(500); regine(message); delay(500); nath(message); delay(500);

  String Omessage = "Bee Hive 2\n" + String("6\n") + String(tempC, 0) + "\n" + String(soundLevel) + " \n" + String(weight, 0);

  Serial.print("Sending message: ");
  Serial.println(Omessage);

  // Send message via GSM
  oled(Omessage);
  delay(500);
}

void seven() {
  float tempC = getTemperature();
  int soundLevel = getSoundLevel();
  float weight = getWeight();

  String message = "Bee Hive 2\n" + String("7:00 am\n") + String("Temp: ") + String(tempC, 1) + " C\n" + String("Sound: ") + String(soundLevel) + " dB\n" + String("Weight: ") + String(weight, 1) + " kg";

  Serial.print("Sending message: ");
  Serial.println(message);

  // Send message via GSM
  carl(message); delay(500); earl(message); delay(500); jim(message); delay(500); regine(message); delay(500); nath(message); delay(500);

  String Omessage = "Bee Hive 2\n" + String("7\n") + String(tempC, 0) + "\n" + String(soundLevel) + " \n" + String(weight, 0);

  Serial.print("Sending message: ");
  Serial.println(Omessage);

  // Send message via GSM
  oled(Omessage);
  delay(500);
}

void eight() {
  float tempC = getTemperature();
  int soundLevel = getSoundLevel();
  float weight = getWeight();

  String message = "Bee Hive 2\n" + String("8:00 am\n") + String("Temp: ") + String(tempC, 1) + " C\n" + String("Sound: ") + String(soundLevel) + " dB\n" + String("Weight: ") + String(weight, 1) + " kg";

  Serial.print("Sending message: ");
  Serial.println(message);

  // Send message via GSM
  carl(message); delay(500); earl(message); delay(500); jim(message); delay(500); regine(message); delay(500); nath(message); delay(500);

  String Omessage = "Bee Hive 2\n" + String("8\n") + String(tempC, 0) + "\n" + String(soundLevel) + " \n" + String(weight, 0);

  Serial.print("Sending message: ");
  Serial.println(Omessage);

  // Send message via GSM
  oled(Omessage);
  delay(500);
}

void nine() {
  float tempC = getTemperature();
  int soundLevel = getSoundLevel();
  float weight = getWeight();

  String message = "Bee Hive 2\n" + String("9:00 am\n") + String("Temp: ") + String(tempC, 1) + " C\n" + String("Sound: ") + String(soundLevel) + " dB\n" + String("Weight: ") + String(weight, 1) + " kg";

  Serial.print("Sending message: ");
  Serial.println(message);

  // Send message via GSM
  carl(message); delay(500); earl(message); delay(500); jim(message); delay(500); regine(message); delay(500); nath(message); delay(500);

  String Omessage = "Bee Hive 2\n" + String("9\n") + String(tempC, 0) + "\n" + String(soundLevel) + " \n" + String(weight, 0);

  Serial.print("Sending message: ");
  Serial.println(Omessage);

  // Send message via GSM
  oled(Omessage);
  delay(500);
}

void ten() {
  float tempC = getTemperature();
  int soundLevel = getSoundLevel();
  float weight = getWeight();

  String message = "Bee Hive 2\n" + String("10:00 am\n") + String("Temp: ") + String(tempC, 1) + " C\n" + String("Sound: ") + String(soundLevel) + " dB\n" + String("Weight: ") + String(weight, 1) + " kg";

  Serial.print("Sending message: ");
  Serial.println(message);

  // Send message via GSM
  carl(message); delay(500); earl(message); delay(500); jim(message); delay(500); regine(message); delay(500); nath(message); delay(500);

  String Omessage = "Bee Hive 2\n" + String("10\n") + String(tempC, 0) + "\n" + String(soundLevel) + " \n" + String(weight, 0);

  Serial.print("Sending message: ");
  Serial.println(Omessage);

  // Send message via GSM
  oled(Omessage);
  delay(500);
}

void eleven() {
  float tempC = getTemperature();
  int soundLevel = getSoundLevel();
  float weight = getWeight();

  String message = "Bee Hive 2\n" + String("11:00 am\n") + String("Temp: ") + String(tempC, 1) + " C\n" + String("Sound: ") + String(soundLevel) + " dB\n" + String("Weight: ") + String(weight, 1) + " kg";

  Serial.print("Sending message: ");
  Serial.println(message);

  // Send message via GSM
  carl(message); delay(500); earl(message); delay(500); jim(message); delay(500); regine(message); delay(500); nath(message); delay(500);

  String Omessage = "Bee Hive 2\n" + String("11\n") + String(tempC, 0) + "\n" + String(soundLevel) + " \n" + String(weight, 0);

  Serial.print("Sending message: ");
  Serial.println(Omessage);

  // Send message via GSM
  oled(Omessage);
  delay(500);
}

void twelve() {
  float tempC = getTemperature();
  int soundLevel = getSoundLevel();
  float weight = getWeight();

  String message = "Bee Hive 2\n" + String("12:00 pm\n") + String("Temp: ") + String(tempC, 1) + " C\n" + String("Sound: ") + String(soundLevel) + " dB\n" + String("Weight: ") + String(weight, 1) + " kg";

  Serial.print("Sending message: ");
  Serial.println(message);

  // Send message via GSM
  carl(message); delay(500); earl(message); delay(500); jim(message); delay(500); regine(message); delay(500); nath(message); delay(500);

  String Omessage = "Bee Hive 2\n" + String("12\n") + String(tempC, 0) + "\n" + String(soundLevel) + " \n" + String(weight, 0);

  Serial.print("Sending message: ");
  Serial.println(Omessage);

  // Send message via GSM
  oled(Omessage);
  delay(500);
}

void thirteen() {
  float tempC = getTemperature();
  int soundLevel = getSoundLevel();
  float weight = getWeight();

  String message = "Bee Hive 2\n" + String("1:00 pm\n") + String("Temp: ") + String(tempC, 1) + " C\n" + String("Sound: ") + String(soundLevel) + " dB\n" + String("Weight: ") + String(weight, 1) + " kg";

  Serial.print("Sending message: ");
  Serial.println(message);

  // Send message via GSM
  carl(message); delay(500); earl(message); delay(500); jim(message); delay(500); regine(message); delay(500); nath(message); delay(500);

  String Omessage = "Bee Hive 2\n" + String("1\n") + String(tempC, 0) + "\n" + String(soundLevel) + " \n" + String(weight, 0);

  Serial.print("Sending message: ");
  Serial.println(Omessage);

  // Send message via GSM
  oled(Omessage);
  delay(500);
}

void fourteen() {
  float tempC = getTemperature();
  int soundLevel = getSoundLevel();
  float weight = getWeight();

  String message = "Bee Hive 2\n" + String("2:00 pm\n") + String("Temp: ") + String(tempC, 1) + " C\n" + String("Sound: ") + String(soundLevel) + " dB\n" + String("Weight: ") + String(weight, 1) + " kg";

  Serial.print("Sending message: ");
  Serial.println(message);

  // Send message via GSM
  carl(message); delay(500); earl(message); delay(500); jim(message); delay(500); regine(message); delay(500); nath(message); delay(500);

  String Omessage = "Bee Hive 2\n" + String("2\n") + String(tempC, 0) + "\n" + String(soundLevel) + " \n" + String(weight, 0);

  Serial.print("Sending message: ");
  Serial.println(Omessage);

  // Send message via GSM
  oled(Omessage);
  delay(500);
}

void fifteen() {
  float tempC = getTemperature();
  int soundLevel = getSoundLevel();
  float weight = getWeight();

  String message = "Bee Hive 2\n" + String("3:00 pm\n") + String("Temp: ") + String(tempC, 1) + " C\n" + String("Sound: ") + String(soundLevel) + " dB\n" + String("Weight: ") + String(weight, 1) + " kg";

  Serial.print("Sending message: ");
  Serial.println(message);

  // Send message via GSM
  carl(message); delay(500); earl(message); delay(500); jim(message); delay(500); regine(message); delay(500); nath(message); delay(500);

  String Omessage = "Bee Hive 2\n" + String("3\n") + String(tempC, 0) + "\n" + String(soundLevel) + " \n" + String(weight, 0);

  // Send message via GSM
  oled(Omessage);
  delay(500);
}

void sixteen() {
  float tempC = getTemperature();
  int soundLevel = getSoundLevel();
  float weight = getWeight();

  String message = "Bee Hive 2\n" + String("4:00 pm\n") + String("Temp: ") + String(tempC, 1) + " C\n" + String("Sound: ") + String(soundLevel) + " dB\n" + String("Weight: ") + String(weight, 1) + " kg";

  Serial.print("Sending message: ");
  Serial.println(message);

  // Send message via GSM
  carl(message); delay(500); earl(message); delay(500); jim(message); delay(500); regine(message); delay(500); nath(message); delay(500);

  String Omessage = "Bee Hive 2\n" + String("4\n") + String(tempC, 0) + "\n" + String(soundLevel) + " \n" + String(weight, 0);

  Serial.print("Sending message: ");
  Serial.println(Omessage);

  // Send message via GSM
  oled(Omessage);
  delay(500);
}

void seventeen() {
  float tempC = getTemperature();
  int soundLevel = getSoundLevel();
  float weight = getWeight();

  String message = "Bee Hive 2\n" + String("5:00 pm\n") + String("Temp: ") + String(tempC, 1) + " C\n" + String("Sound: ") + String(soundLevel) + " dB\n" + String("Weight: ") + String(weight, 1) + " kg";

  Serial.print("Sending message: ");
  Serial.println(message);

  // Send message via GSM
  carl(message); delay(500); earl(message); delay(500); jim(message); delay(500); regine(message); delay(500); nath(message); delay(500);

  String Omessage = "Bee Hive 2\n" + String("5\n") + String(tempC, 0) + "\n" + String(soundLevel) + " \n" + String(weight, 0);

  Serial.print("Sending message: ");
  Serial.println(Omessage);

  // Send message via GSM
  oled(Omessage);
  delay(500);
}

void eighteen() {
  float tempC = getTemperature();
  int soundLevel = getSoundLevel();
  float weight = getWeight();

  String message = "Bee Hive 2\n" + String("6:00 pm\n") + String("Temp: ") + String(tempC, 1) + " C\n" + String("Sound: ") + String(soundLevel) + " dB\n" + String("Weight: ") + String(weight, 1) + " kg";

  Serial.print("Sending message: ");
  Serial.println(message);

  // Send message via GSM
  carl(message); delay(500); earl(message); delay(500); jim(message); delay(500); regine(message); delay(500); nath(message); delay(500);

  String Omessage = "Bee Hive 2\n" + String("6\n") + String(tempC, 0) + "\n" + String(soundLevel) + " \n" + String(weight, 0);

  Serial.print("Sending message: ");
  Serial.println(Omessage);

  // Send message via GSM
  oled(Omessage);
  delay(500);
}

void nineteen() {
  float tempC = getTemperature();
  int soundLevel = getSoundLevel();
  float weight = getWeight();

  String message = "Bee Hive 2\n" + String("7:00 pm\n") + String("Temp: ") + String(tempC, 1) + " C\n" + String("Sound: ") + String(soundLevel) + " dB\n" + String("Weight: ") + String(weight, 1) + " kg";

  Serial.print("Sending message: ");
  Serial.println(message);

  // Send message via GSM
  carl(message); delay(500); earl(message); delay(500); jim(message); delay(500); regine(message); delay(500); nath(message); delay(500);

  String Omessage = "Bee Hive 2\n" + String("7\n") + String(tempC, 0) + "\n" + String(soundLevel) + " \n" + String(weight, 0);

  Serial.print("Sending message: ");
  Serial.println(Omessage);

  // Send message via GSM
  oled(Omessage);
  delay(500);
}

void twenty() {
  float tempC = getTemperature();
  int soundLevel = getSoundLevel();
  float weight = getWeight();

  String message = "Bee Hive 2\n" + String("8:00 pm\n") + String("Temp: ") + String(tempC, 1) + " C\n" + String("Sound: ") + String(soundLevel) + " dB\n" + String("Weight: ") + String(weight, 1) + " kg";

  Serial.print("Sending message: ");
  Serial.println(message);

  // Send message via GSM
  carl(message); delay(500); earl(message); delay(500); jim(message); delay(500); regine(message); delay(500); nath(message); delay(500);

  String Omessage = "Bee Hive 2\n" + String("8\n") + String(tempC, 0) + "\n" + String(soundLevel) + " \n" + String(weight, 0);

  Serial.print("Sending message: ");
  Serial.println(Omessage);

  // Send message via GSM
  oled(Omessage);
  delay(500);
}

void twentyone() {
  float tempC = getTemperature();
  int soundLevel = getSoundLevel();
  float weight = getWeight();

  String message = "Bee Hive 2\n" + String("9:00 pm\n") + String("Temp: ") + String(tempC, 1) + " C\n" + String("Sound: ") + String(soundLevel) + " dB\n" + String("Weight: ") + String(weight, 1) + " kg";

  Serial.print("Sending message: ");
  Serial.println(message);

  // Send message via GSM
  carl(message); delay(500); earl(message); delay(500); jim(message); delay(500); regine(message); delay(500); nath(message); delay(500);

  String Omessage = "Bee Hive 2\n" + String("9\n") + String(tempC, 0) + "\n" + String(soundLevel) + " \n" + String(weight, 0);

  Serial.print("Sending message: ");
  Serial.println(Omessage);

  // Send message via GSM
  oled(Omessage);
  delay(500);
}

void twentytwo() {
  float tempC = getTemperature();
  int soundLevel = getSoundLevel();
  float weight = getWeight();

  String message = "Bee Hive 2\n" + String("10:00 pm\n") + String("Temp: ") + String(tempC, 1) + " C\n" + String("Sound: ") + String(soundLevel) + " dB\n" + String("Weight: ") + String(weight, 1) + " kg";

  Serial.print("Sending message: ");
  Serial.println(message);

  // Send message via GSM
  carl(message); delay(500); earl(message); delay(500); jim(message); delay(500); regine(message); delay(500); nath(message); delay(500);

  String Omessage = "Bee Hive 2\n" + String("10\n") + String(tempC, 0) + "\n" + String(soundLevel) + " \n" + String(weight, 0);

  Serial.print("Sending message: ");
  Serial.println(Omessage);

  // Send message via GSM
  oled(Omessage);
  delay(500);
}

void twentythree() {
  float tempC = getTemperature();
  int soundLevel = getSoundLevel();
  float weight = getWeight();

  String message = "Bee Hive 2\n" + String("11:00 pm\n") + String("Temp: ") + String(tempC, 1) + " C\n" + String("Sound: ") + String(soundLevel) + " dB\n" + String("Weight: ") + String(weight, 1) + " kg";

  Serial.print("Sending message: ");
  Serial.println(message);

  // Send message via GSM
  carl(message); delay(500); earl(message); delay(500); jim(message); delay(500); regine(message); delay(500); nath(message); delay(500);

  String Omessage = "Bee Hive 2\n" + String("11\n") + String(tempC, 0) + "\n" + String(soundLevel) + " \n" + String(weight, 0);

  Serial.print("Sending message: ");
  Serial.println(Omessage);

  // Send message via GSM
  oled(Omessage);
  delay(500);
}

float getTemperature() {
  sensors.requestTemperatures();
  float tempC = sensors.getTempCByIndex(0);
  Serial.print("Temperature: ");
  Serial.print(tempC);
  Serial.println(" °C");
  return tempC;
}

int getSoundLevel() {
  int sensorValue = analogRead(analogPin);
  int mappedValue = mapCustom(sensorValue, inputValues, outputValues, tableSize);
  Serial.print("Sound Level: ");
  Serial.print(mappedValue);
  Serial.println(" dB");
  return mappedValue;
}

float getWeight() {
  float weight = scale.get_units();
  Serial.print("Weight: ");
  Serial.print(weight, 3);
  Serial.println(" kg");
  return weight;
}

void carl(String message) {
  GSM_Module.println("AT+CMGF=1"); // Set SMS to text mode
  delay(1000);
  GSM_Module.println("AT+CMGS=\"09456103058\"");
  delay(1000);
  GSM_Module.println(message); // Message content
  delay(1000);
  GSM_Module.write(26); // ASCII code of CTRL+Z to send the message
  delay(1000);
  Serial.println("Message Sent Carl");
}

void earl(String message) {
  GSM_Module.println("AT+CMGF=1"); // Set SMS to text mode
  delay(1000);
  GSM_Module.println("AT+CMGS=\"09089075480\"");
  delay(1000);
  GSM_Module.println(message); // Message content
  delay(1000);
  GSM_Module.write(26); // ASCII code of CTRL+Z to send the message
  delay(1000);
  Serial.println("Message Sent Earl");
}

void jim(String message) {
  GSM_Module.println("AT+CMGF=1"); // Set SMS to text mode
  delay(1000);
  GSM_Module.println("AT+CMGS=\"09310261665\"");
  delay(1000);
  GSM_Module.println(message); // Message content
  delay(1000);
  GSM_Module.write(26); // ASCII code of CTRL+Z to send the message
  delay(1000);
  Serial.println("Message Sent Jim");
}

void regine(String message) {
  GSM_Module.println("AT+CMGF=1"); // Set SMS to text mode
  delay(1000);
  GSM_Module.println("AT+CMGS=\"09651859176\"");
  delay(1000);
  GSM_Module.println(message); // Message content
  delay(1000);
  GSM_Module.write(26); // ASCII code of CTRL+Z to send the message
  delay(1000);
  Serial.println("Message Sent Regine");
}

void nath(String message) {
  GSM_Module.println("AT+CMGF=1"); // Set SMS to text mode
  delay(1000);
  GSM_Module.println("AT+CMGS=\"09082984116\"");
  delay(1000);
  GSM_Module.println(message); // Message content
  delay(1000);
  GSM_Module.write(26); // ASCII code of CTRL+Z to send the message
  delay(1000);
  Serial.println("Message Sent Nath");
}


void oled(String Omessage) {
  GSM_Module.println("AT+CMGF=1"); // Set SMS to text mode
  delay(1000);
  GSM_Module.println("AT+CMGS=\"09626374792\"");
  delay(1000);
  GSM_Module.println(Omessage); // Message content
  delay(1000);
  GSM_Module.write(26); // ASCII code of CTRL+Z to send the message
  delay(1000);
  Serial.println("Message Sent Tracker");
}

// Custom mapping function for sound sensor
int mapCustom(int value, const int* inValues, const int* outValues, int size) {
  if (value <= inValues[0]) {
    return outValues[0];
  }
  if (value >= inValues[size - 1]) {
    return outValues[size - 1];
  }
  
  for (int i = 0; i < size - 1; i++) {
    if (value >= inValues[i] && value < inValues[i + 1]) {
      return map(value, inValues[i], inValues[i + 1], outValues[i], outValues[i + 1]);
    }
  }
  
  return outValues[size - 1]; // Fallback, should never hit this
}

