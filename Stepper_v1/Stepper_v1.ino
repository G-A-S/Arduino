long SerialSpeed = 57600L;

boolean e = true; //режим разработки

const boolean ON = true;
const boolean OFF = false;
const boolean UP = true;
const boolean DOWN = false;
const boolean open = 1;
const boolean close = 0;



bool logS (String text) {
  logS(text,true);
  return true;
}

bool logS (String text, boolean show) {
  boolean ln = true;
  if(e&&show)ln?Serial.println(text):Serial.print(text);
  return true;  
} 
