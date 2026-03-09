#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define SENSOR 14
#define GREEN_LED 12
#define RED_LED 13
#define BUZZER 27

LiquidCrystal_I2C lcd(0x27,16,2);

String plate;

bool validFormat(String p){

  if(p.length()!=10) return false;

  if(!isAlpha(p[0]) || !isAlpha(p[1])) return false;
  if(!isDigit(p[2]) || !isDigit(p[3])) return false;
  if(!isAlpha(p[4]) || !isAlpha(p[5])) return false;

  if(!isDigit(p[6]) || !isDigit(p[7]) || !isDigit(p[8]) || !isDigit(p[9]))
  return false;

  return true;
}

void setup(){

  pinMode(SENSOR, INPUT_PULLUP);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  Serial.begin(115200);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("Vehicle System");
}

void loop(){

  int vehicle = digitalRead(SENSOR);

  if(vehicle == LOW){

    Serial.println("Vehicle Detected");

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Vehicle Found");

    delay(2000);

    Serial.println("Enter Plate:");
    lcd.setCursor(0,1);
    lcd.print("Scan Plate...");

    while(!Serial.available());

    plate = Serial.readStringUntil('\n');
    plate.trim();

    Serial.print("Detected Plate: ");
    Serial.println(plate);

    lcd.clear();

    if(!validFormat(plate)){

      Serial.println("WRONG FORMAT");

      lcd.setCursor(0,0);
      lcd.print("Wrong Format");
      lcd.setCursor(0,1);
      lcd.print("STOP");

      digitalWrite(GREEN_LED,LOW);
      digitalWrite(RED_LED,HIGH);
      tone(BUZZER,1000);
    }

    else if(plate == "TN74AQ1234" || plate == "TN10AB1234" || plate == "TN10AN1245" ||
plate == "KA01AB1234" ||
plate == "KA05MK5678" ||
plate == "KA03PQ4567" ||
plate == "DL10XY9876" ||
plate == "MH12AB3456" ||
plate == "AP09CD4321" ||
plate == "TS08EF6789"){

      Serial.println("VALID VEHICLE");

      lcd.setCursor(0,0);
      lcd.print("Vehicle Valid");
      lcd.setCursor(0,1);
      lcd.print("GO");

      digitalWrite(GREEN_LED,HIGH);
      digitalWrite(RED_LED,LOW);
      noTone(BUZZER);
    }

    else{

      Serial.println("INVALID VEHICLE");

      lcd.setCursor(0,0);
      lcd.print("Not Registered");
      lcd.setCursor(0,1);
      lcd.print("STOP");

      digitalWrite(GREEN_LED,LOW);
      digitalWrite(RED_LED,HIGH);
      tone(BUZZER,1000);
    }

    delay(4000);

    digitalWrite(GREEN_LED,LOW);
    digitalWrite(RED_LED,LOW);
    noTone(BUZZER);

    lcd.clear();
    lcd.print("Waiting...");
  }
}