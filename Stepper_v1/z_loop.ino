void loop ()
{
  unsigned long timingTable[2*numbers];
  //unsigned long timingTableInterval[numbers];
  int pot = analogRead(pinSpeedControl);
  
  pot = 500;
  
  unsigned long M = constrain( map( pot,0,1023,microMmin,microMmax), microMmin,microMmax );
  
  M=90000uL;  //300000uL;    //1500000uL;
  
  // half step 200000ul = 150u/min
  // 1/4step 800000uL = 147u/min
  // full step 90000uL = 191u/min
  
  Serial.println( (int)sqrt(M) );
  
   unsigned long prev = 0uL; 
  //timingTable[0]=0;
  for (int i=0; i<numbers; ++i)
  {
        unsigned long curr = (baseTable[i] / (int)sqrt(M)) ;
        timingTable[i] = curr - prev - impulseWidth;
        prev = curr;
        Serial.println(timingTable[i]);
  }
  
  Serial.println("------------------");
  
  int j = 1;
  for (int i=numbers; i<2*numbers; ++i)
  {
        timingTable[i] = timingTable[numbers-j];
        ++j;
        Serial.println(timingTable[i]);
  }  
  
  

    digitalWrite(pin_motor_DIR, LOW);

 delay(5);

    while(buttonState()==ON)
    {
      unsigned long prevm = millis();
        digitalWrite(pin_motor_EN, HIGH);
        
        delay(20);
        digitalWrite(pin_motor_DIR, LOW);
        delayMicroseconds (200);
        
        for (int i=0; i<2*numbers; ++i)
        {
            for (int j = 0; j < microStepping ; ++j)
            {
                digitalWrite(pin_motor_PUL, LOW);
                delayMicroseconds(impulseWidth);
                digitalWrite(pin_motor_PUL, HIGH);    
                delayMicroseconds(timingTable[i]);   
            }
          
        }
        
        delay (20);
        digitalWrite(pin_motor_DIR, HIGH);
        delayMicroseconds (200);
        
        for (int i=0; i<2*numbers; ++i)
        {
            for (int j = 0; j < microStepping ; ++j)
            {
                digitalWrite(pin_motor_PUL, LOW);
                delayMicroseconds(impulseWidth);
                digitalWrite(pin_motor_PUL, HIGH);    
                delayMicroseconds(timingTable[i]);    
            }
        }
        //Serial.println(60000uL/(millis()-prevm));
    }
digitalWrite(pin_motor_EN, HIGH); // HIGH for holding torque, LOW for let rotate
}
