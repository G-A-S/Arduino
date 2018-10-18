
// ---------------------------Переменные счетчиков-----------------------------------------------
//typedef 
struct TIMER{
  unsigned long start; // Время последнего опроса
  unsigned long interval; // интервал ожидания 
}; //TIMER;

unsigned long current_time = millis(); // текущее время

//// Ожидание радио
////Максимальное время приема посылки с сервера
unsigned long radio_aktiv = 7000;
unsigned long radio_passiv = 20000;
struct TIMER timer_radioSend = {current_time, radio_aktiv};
struct TIMER timer_radioReceive = {current_time, 1000uL};  
struct TIMER timer_radioWaitReply = {current_time, 2000uL};
struct TIMER timer_radioCheckConnection = {current_time, 60000uL}; //1 minuta
struct TIMER timer_runOut_pumpTank = {current_time, 5000uL};
struct TIMER timer_flow_rate = {current_time, 5000uL};
struct TIMER timer_VolumeCheck = {current_time, 5000uL};
struct TIMER timer_checkBurstDelay = {current_time, 15000uL};
struct TIMER timer_checkLowPressure = {current_time, 15000uL};
struct TIMER timer_checkOverpressure = {current_time, 10000uL};

//-------------------------------------------------------------------------------------------Функции---------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------checkTimer
boolean checkTimer (struct TIMER *ptr_TIMER, boolean _to_restart)
{
  unsigned long _millis = millis();

  if ( _millis >= (ptr_TIMER -> start) + (ptr_TIMER -> interval) ) {
     if(_to_restart) ptr_TIMER -> start = _millis;
     return true;
  }
  else return false;
} // END checkTimer
boolean checkTimer (struct TIMER *ptr_TIMER)
{
  return checkTimer(ptr_TIMER, ON);
} // END checkTimer

// checkTimer(&...)
