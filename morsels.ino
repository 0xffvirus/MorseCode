#include <LiquidCrystal.h>
#define ARRAYSIZE 10
String results[36] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int Button = 6;
long onTime = 0;
String name = "";
String name2 = "";
int lastReading = LOW;
int sublastread = LOW;
int bounceTime = 50;
int holdTime = 250;
int hold = 0;
int single = 0;

long lastSwitchTime = 0;
long doubleTime = 750;
void setup() {
  Serial.begin(9600);
  pinMode(Button, INPUT);

  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Morse Code");
  delay(2000);
  lcd.clear();

}

void loop() {
  lcd.setCursor(0, 1);
  lcd.print(name2); 
  int reading = digitalRead(Button);
  if (reading == HIGH && lastReading == LOW) {
    onTime = millis();
  }
  

  if (reading == HIGH && lastReading == HIGH) {
    if ((millis() - onTime) > holdTime) {
      name += "-";
      lcd.setCursor(0, 0);
      lcd.clear();
      lcd.print(name);
      delay(500);
      hold = 1;
    }
  }

  if (reading == LOW && lastReading == HIGH) {
    if (((millis() - onTime) > bounceTime) && hold != 1) {
      onRelease();
    }
    if (hold = 1) {
      hold = 0;
    }   
  }

  lastReading = reading;

  if (single == 1 && (millis() - lastSwitchTime) > doubleTime) {
    name += ".";
      lcd.setCursor(0, 0);
      lcd.clear();
      lcd.print(name);
    single = 0;
  }
}
void Letters() {
  if (name == ".-") {
    name = "";
    name2 +=results[0];
  }
  if (name == "-...") {
    name = "";
    name2 +=results[1];
  }
  if (name == "-.-.") {
    name = "";
    name2 +=results[2];
  }
  if (name == "-..") {
    name = "";
    name2 +=results[3];
  }
  if (name == ".") {
    name = "";
    name2 +=results[4];
  }
   if (name == "..-.") {
    name = "";
    name2 +=results[5];
  }
  if (name == "--.") {
    name = "";
    name2 +=results[6];
  }
   if (name == "....") {
    name = "";
    name2 +=results[7];
  }
  if (name == "..") {
    name = "";
    name2 +=results[8];
  }
   if (name == ".---") {
    name = "";
    name2 +=results[9];
  }
  if (name == "-.-") {
    name = "";
    name2 +=results[10];
  }
  if (name == ".-..") {
    name = "";
    name2 +=results[11];
  }
  if (name == "--") {
    name = "";
    name2 +=results[12];
  }
  if (name == "-.") {
    name = "";
    name2 +=results[13];
  }
  if (name == "---") {
    name = "";
    name2 +=results[14];
  }
  if (name == ".--.") {
    name = "";
    name2 +=results[15];
  }
  if (name == "--.-") {
    name = "";
    name2 +=results[16];
  }
  if (name == ".-.") {
    name = "";
    name2 +=results[17];
  }
  if (name == "...") {
    name = "";
    name2 +=results[18];
  }
  if (name == "-") {
    name = "";
    name2 +=results[19];
  }
  if (name == "..-") {
    name = "";
    name2 +=results[20];
  }
  if (name == "...-") {
    name = "";
    name2 +=results[21];
  }
  if (name == ".--") {
    name = "";
    name2 +=results[22];
  }
  if (name == "-..-") {
    name = "";
    name2 +=results[23];
  }
  if (name == "-.--") {
    name = "";
    name2 +=results[24];
  }
   if (name == "--..") {
    name = "";
    name2 +=results[25];
  }
   if (name == ".----") {
    name = "";
    name2 +=results[26];
  }
  if (name == "..---") {
    name = "";
    name2 +=results[27];
  }
  if (name == "...--") {
    name = "";
    name2 +=results[28];
  }
  if (name == "....-") {
    name = "";
    name2 +=results[29];
  }
  if (name == ".....") {
    name = "";
    name2 +=results[30];
  }
  if (name == "-....") {
    name = "";
    name2 +=results[31];
  }
  if (name == "--...") {
    name = "";
    name2 +=results[32];
  }
  if (name == "---..") {
    name = "";
    name2 +=results[33];
  }
  if (name == "----.") {
    name = "";
    name2 +=results[34];
  }
  if (name == "-----") {
    name = "";
    name2 +=results[35];
  }
  
}
void onRelease() {

  if ((millis() - lastSwitchTime) >= doubleTime) {
    single = 1;
    lastSwitchTime = millis();
    return;
  }  

  if ((millis() - lastSwitchTime) < doubleTime) {
    Letters();
    single = 0;
    lastSwitchTime = millis();
  }  



}



