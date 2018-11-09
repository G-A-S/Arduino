int PIN_DETECTION   = 2;
int PIN_TRIGGER_CAM = 5;
int PIN_TRIGGER_ESP = 6;
int PIN_LED = 13;


unsigned long visitingInterval     = 10uL * 60uL * 1000uL;
unsigned long noDetectionInterval  =        15uL * 1000uL;
unsigned long visitorCheckInterval =        30uL * 1000uL;


void setup (void)
{
  pinMode(PIN_DETECTION, INPUT);
  pinMode(PIN_TRIGGER_CAM, OUTPUT);
  pinMode(PIN_TRIGGER_ESP, OUTPUT);
  
  pinMode(PIN_LED, OUTPUT);
  
  digitalWrite(PIN_DETECTION, LOW);
  digitalWrite(PIN_TRIGGER_CAM, LOW); 
  digitalWrite(PIN_TRIGGER_ESP, LOW);
  
  digitalWrite(PIN_LED, digitalRead (PIN_DETECTION));
  
  attachInterrupt(0, setLED, CHANGE);

}

void loop (void)
{
  boolean visitorDetected = false;

  while ( digitalRead (PIN_DETECTION) == LOW ) {}; // no detection signal
  
  delay(noDetectionInterval);  // if detected - delay

  unsigned long startvisitorCheck = millis();
  
  while ( millis() < startvisitorCheck + visitorCheckInterval ) // loop for checking if there is a visitor or not
  {
      if ( digitalRead (PIN_DETECTION) == HIGH && visitorDetected == false) // if after 'noDetectionInterval' a detection occures, there is a visitor
      {
          visitorDetected = true;
          trigger(); // trigger CAM and ESP
      }
  }
  
  if ( visitorDetected == true ) // if there is a visitor, delay for visit
  {
      delay(visitingInterval); 
  }
  
} //loop

void trigger ()
{
    digitalWrite(PIN_TRIGGER_CAM, HIGH); 
    digitalWrite(PIN_TRIGGER_ESP, HIGH);
    delay(5);
    digitalWrite(PIN_TRIGGER_CAM, LOW); 
    digitalWrite(PIN_TRIGGER_ESP, LOW);
}

void setLED ()
{
  digitalWrite(PIN_LED, digitalRead (PIN_DETECTION));
}
