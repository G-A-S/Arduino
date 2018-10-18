
//-------------------------------------------------------------------------------------------setup()---------------------------------------------------------------------------------

void setup()  
{
  Serial.begin(SerialSpeed);
    if(e){Serial.println("start");} 
  pin_init (all);

//attachInterrupt(Interrupt(pin_FlowRate), FlowRate_counter, FALLING); //Если на 0-вом прерываниии - ноль, то выполняем.

    if ( numbers - 1 > sizeof(baseTable) ) {Serial.println("numbers to big"); while(1) {};}

    if(e)Serial.println("ready");

}
 

