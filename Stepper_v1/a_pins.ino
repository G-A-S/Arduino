
//-------------------------определение пинов -------------------------------------------------------
const byte all = 100; // Все пины

const int pin_button = 2;


const int pin_motor_EN = 6;
const int pin_motor_DIR = 7;
const int pin_motor_PUL = 8;


const int pin_led_13 = 13; //Светодиод, если потребуется


const int pinSpeedControl = A0;

//-------------------------------------------------------------------------------------------Функции---------------------------------------------------------------------------------

int Interrupt(int _pin){
  switch (_pin) {
   case 2: return 0;
   case 3: return 1;
   default: return 999;
  }
  
}



//-------------------------------------------------------------------------------------------pin_init***********************************************************************************************
void pin_init (byte _pin) {

  if (_pin == 99 || _pin == all) {  

    pinMode(pin_motor_EN,  OUTPUT);  digitalWrite(pin_motor_EN, HIGH);
    pinMode(pin_motor_DIR, OUTPUT);  digitalWrite(pin_motor_DIR, HIGH);
    pinMode(pin_motor_PUL, OUTPUT);  digitalWrite(pin_motor_PUL, HIGH);
       
    pinMode(pin_led_13, OUTPUT);    digitalWrite(pin_led_13, LOW);

    pinMode(pin_button, INPUT);   //digitalWrite(pin_button, HIGH);  
  }   
} // Конец pin_init


const bool ON = true;
const bool OFF = false;
bool buttonState()
{
    if(digitalRead(pin_button) == HIGH) return ON;
    else return OFF;
}

