//LIBRARIES - all libraries can be installed via Arduino Library Manager
#include <LiquidCrystal_I2C.h> //library for LCD display
#include <Wire.h>              // library for I2C connection
#include <RTClib.h>            // library for real time clock 
#include <Button.h>            // library for easy handling of buttons: https://github.com/madleech/Button
#include "Musik.h"



LiquidCrystal_I2C lcd(0x27, 18, 2); //declaration of the Display
RTC_DS1307 rtc;                     //declaration of the RTC device

//PINOUT
#define buzzerPin 4



//Alarm Setting Variables
bool isAlarmSet = false;
bool didItRing = false;
short int AlarmHH = 12; //storing the alarm time setting - hours
short int AlarmMM = 33;  //storing the alarm time setting - minutes

short unsigned int CurrentHH = 0; //storing the current time - hours
short unsigned int CurrentMM = 0; //storing the current time - minutes
bool ifTimeDisplay = true;  //boolean value to decide if to show time, useful for limiting flickering of the screen

//Button Declarations and Control Variables
Button redButton(6); 
Button whiteButton(7);
Button yellowButton(2);
Button greenButton(5);

bool whiteButtonState = false;
bool redButtonState = false;
bool yellowButtonState = false;
bool greenButtonState = false;

int alarmSetMode = 0; // 0 = alarmSetMode off, 1 = set hours, 2 = set minutes


//Setup function, executed once after reboot
void setup() {
pinMode(buzzerPin, OUTPUT); 
digitalWrite(buzzerPin,LOW);

Serial.begin(9600); //initialisation of serial monitor

//LCD display initialisation
lcd.init();
lcd.backlight();

//RTC initialisation
rtc.begin();
rtc.adjust(DateTime(2026, 05, 11, 15, 12, 10)); //this sets the "start" time for the clock - need to be executed only once per unit; then it stores the time itself

//Set inital alarm to one minute after the current time (for better testing)
DateTime currentTime = rtc.now();
AlarmHH = currentTime.hour();
AlarmMM = currentTime.minute() + 1;
if(AlarmMM >= 60) {
  AlarmMM = 0;
  AlarmHH = (AlarmHH + 1) % 24;
}

//Buttons initialisation
redButton.begin();
whiteButton.begin();
yellowButton.begin();
greenButton.begin();


}

//timeOnScreen function reads the time from RTC and displays it on the LCD display
void timeOnScreen(){

  DateTime now = rtc.now(); //declaring an object for storing the RTC time
  lcd.setCursor(0,0);
  lcd.print("Time: ");
  if(now.hour()<10) lcd.print('0'); //used to maintain nice format on the display
  lcd.print(now.hour());
  CurrentHH = now.hour();
  lcd.print(":");
  if(now.minute()<10) lcd.print('0');
  lcd.print(now.minute());
  CurrentMM = now.minute();
  lcd.print(":");
  if(now.second()<10) lcd.print('0');
  lcd.print(now.second());
  lcd.print("    ");

  /* serial prints for debugging
  Serial.print("Time:");
  Serial.print(now.hour());
  Serial.print(":");
  Serial.println(now.minute());*/
}

//alarmToggle function switches the setting of the alarm On and Off, using the white button
int alarmToggle(){
  if(didItRing) {
    turnAlarmOff();
  }

  if(whiteButton.released()){
    Serial.print("Alarm clock state: ");
    whiteButtonState = !whiteButtonState;
     //Serial.print("WBS: ");
     //Serial.println(whiteButtonState);

  if(whiteButtonState){
    lcd.setCursor(0, 1);
    lcd.print("Alarm is ON           ");
    isAlarmSet = true;
  }else{
    turnAlarmOff();
  }
}

if(isAlarmSet == 1) return 1;
else return 0;
}


void turnAlarmOff() {
    lcd.setCursor(0, 1);
    lcd.print("Alarm is OFF          ");
    isAlarmSet = false;
    didItRing = false;
}


//menuToggle function switches the clock view into set-the-alarm view  
void menuToggle(){
  
  if(redButton.released()) alarmSetMode = (alarmSetMode + 1) % 3;

  if(alarmSetMode != 0) {
    ifTimeDisplay = false;
  }
  else {
    ifTimeDisplay = true;
    return;
  }

  if(alarmSetMode == 1){ //Setting the hours
    ifTimeDisplay = false;
    
    while(alarmSetMode == 1) {
      setAlarm();
      
      printAlarmTimeWithoutBlinking();

      waitInterruptableFor500Ms(1);

      lcd.setCursor(0, 0);
      lcd.print("Alarm set: ");
      lcd.print("  ");
      lcd.print(":");
      if(AlarmMM <10) lcd.print("0");
      lcd.print(AlarmMM);

      waitInterruptableFor500Ms(1);
    }


    while(alarmSetMode == 2) {
      setAlarm();
      
      printAlarmTimeWithoutBlinking();
      
      waitInterruptableFor500Ms(2);

      lcd.setCursor(0, 0);
      lcd.print("Alarm set: ");
      if(AlarmHH <10) lcd.print("0");
      lcd.print(AlarmHH);
      lcd.print(":");
      lcd.print("  ");

      waitInterruptableFor500Ms(2);
    }
  }
}


void printAlarmTimeWithoutBlinking() {
      lcd.setCursor(0, 0);
      lcd.print("Alarm set: ");
      if(AlarmHH <10) lcd.print("0");
      lcd.print(AlarmHH);
      lcd.print(":");
      if(AlarmMM <10) lcd.print("0");
      lcd.print(AlarmMM);
}


void waitInterruptableFor500Ms(int setMode) {
  for(int i = 0; i < 10; i++) {
    if(alarmSetMode != setMode) {
      break;
    }
    delay(50);
    setAlarm();
  }
}


//setAlarm function operates Yellow and Green Buttons to set the desired alarm time in the set-the-alarm view
void setAlarm(){
  if(redButton.released()) alarmSetMode = (alarmSetMode + 1) % 3;

  if(alarmSetMode == 1) {
    if(yellowButton.released()) {
      AlarmHH = (AlarmHH - 1 + 24) % 24;
      printAlarmTimeWithoutBlinking();
    }
    else if(greenButton.released()) {
      AlarmHH = (AlarmHH + 1) % 24;
      printAlarmTimeWithoutBlinking();
    }
  }

  else if(alarmSetMode == 2) {
    if(yellowButton.released()) {
      AlarmMM = (AlarmMM - 1 + 60) % 60;
      printAlarmTimeWithoutBlinking();
    }
    else if(greenButton.released()) {
      AlarmMM = (AlarmMM + 1) % 60;
      printAlarmTimeWithoutBlinking();
    }
  }
}   

//alarmRing function checks the alarm conditions and enables the buzzer 
void alarmRing(){

if(isAlarmSet==true && CurrentHH == AlarmHH && CurrentMM == AlarmMM && didItRing==false){
      lcd.setCursor(0, 1);
      lcd.print("Alarm Rings!          ");
      playTetris(redButton);
      didItRing=true;
      alarmToggle();
  }
}



//LOOP - main function of our programme

void loop() {

//delay(20);
  
  if(ifTimeDisplay) timeOnScreen(); //displaying the clock
  alarmToggle();                    //checking if the alarm function is on or off (and handling its input)
  menuToggle();                     //checking if the set-the-alarm view is on or off (and handling its input)
  alarmRing();                      //checking if the the alarm should ring (and executing it if yes)

  //Serial info for debugging
  /*Serial.print("ATime:");
  Serial.print(AlarmHH);
  Serial.print(":");
  Serial.println(AlarmMM);


  Serial.print("CTime:");
  Serial.print(CurrentHH);
  Serial.print(":");
  Serial.println(CurrentMM);

  Serial.print("IsAlarmSet: ");
  Serial.println(isAlarmSet);*/       
}
