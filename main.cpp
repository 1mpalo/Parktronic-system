#include <NewPing.h>
#include <LiquidCrystal_I2C.h>

#define PIN_TRIG 10
#define PIN_ECHO 8
#define RED_LED_PIN 4
#define YELLOW_LED_PIN 3
#define GREEN_LED_PIN 2
#define ZOOMMER_PIN 6
#define MAX_DISTANCE 200 


NewPing sonar(PIN_TRIG, PIN_ECHO, MAX_DISTANCE);


LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  pinMode(RED_LED_PIN,OUTPUT);
  
  pinMode(YELLOW_LED_PIN,OUTPUT);
  
  pinMode(GREEN_LED_PIN,OUTPUT);
  
  pinMode(ZOOMMER_PIN,OUTPUT);
  
  digitalWrite(RED_LED_PIN,LOW);
  
  digitalWrite(YELLOW_LED_PIN,LOW);
  
  digitalWrite(GREEN_LED_PIN,LOW);

  lcd.begin(16, 2);

  lcd.setBacklight(HIGH);//optional
  
}


  int flag = 1; //for messages

  
void loop() {

  // Получаем значение от датчика расстояния и сохраняем его в переменную
  unsigned int distance = sonar.ping_cm();
  if(distance == 0)
  {
    
    lcd.print("ERROR Too far or");
    lcd.setCursor(0,1);
    lcd.print("connect problem(");
    delay(30000);
  }
  
  lcd.print("     ");
  lcd.print(distance);
  lcd.print(" sm");
  
  if(flag == 1)
  {
    lcd.setCursor(4, 1);
    lcd.print("It`s ok!");
  }
  else if(flag == 2)
  {
    lcd.setCursor(3, 1);
    lcd.print("Be careful");
  }
  else if(flag == 3)
  {
    lcd.setCursor(2, 1);
    lcd.print("DANGEROUS!!!");
  }

  if(distance > 25)
  {
    digitalWrite(GREEN_LED_PIN,HIGH);
    digitalWrite(YELLOW_LED_PIN,LOW);
    digitalWrite(RED_LED_PIN,LOW);
    flag = 1;
    delay(400);
  }

  if(distance < 25 && distance > 15)
  {
    digitalWrite(GREEN_LED_PIN,LOW);
    digitalWrite(YELLOW_LED_PIN, HIGH);
    digitalWrite(RED_LED_PIN,LOW);
  }
  
  if(distance < 10)
  {
    digitalWrite(GREEN_LED_PIN,LOW);
    digitalWrite(YELLOW_LED_PIN,LOW);
    digitalWrite(RED_LED_PIN,HIGH);
  }

  if(distance < 25 && distance >= 20)
  {
    digitalWrite(ZOOMMER_PIN, HIGH);
    delay(100);
    digitalWrite(ZOOMMER_PIN,LOW);
    flag = 1;
    delay(1000);
  }

  if(distance < 20 && distance > 17)
  {
    digitalWrite(ZOOMMER_PIN, HIGH);
    delay(100);
    digitalWrite(ZOOMMER_PIN,LOW);
    flag = 1;
    delay(450);
  }

  if(distance < 17 && distance > 13)
  {
    digitalWrite(ZOOMMER_PIN, HIGH);
    delay(100);
    digitalWrite(ZOOMMER_PIN,LOW);

    flag = 2;
    delay(230);
  }

  if(distance < 13 && distance > 10)
  {
    digitalWrite(ZOOMMER_PIN, HIGH);
    delay(100);
    digitalWrite(ZOOMMER_PIN,LOW);
    flag = 2;
    delay(150);
  }

  if(distance < 10 && distance >= 7)
  {
    digitalWrite(ZOOMMER_PIN, HIGH);
    delay(100);
    digitalWrite(ZOOMMER_PIN,LOW);
    flag = 3;
    delay(50);
  }

  if(distance < 7 && distance > 5)
  {
    digitalWrite(ZOOMMER_PIN, HIGH);
    delay(100);
    digitalWrite(ZOOMMER_PIN,LOW);
    flag = 3;
    delay(20);
  }

  if(distance <= 5)
  {
    digitalWrite(ZOOMMER_PIN, HIGH);
  }
  else
  {
    digitalWrite(ZOOMMER_PIN, LOW);
  }

  


  // Печатаем расстояние в мониторе порта
  lcd.clear();
}
