//Select your modem
//SSL/TLS is currently supported only with SIM8xx series
#define TINY_GSM_MODEM_SIM800

//Increase RX buffer
#define TINY_GSM_RX_BUFFER 256

//NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
#include <TinyGsmClient.h> //https://github.com/vshymanskyy/TinyGSM
//NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN

//NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
// Your GPRS credentials
// Leave empty, if missing user or pass
char apn[]  = "prepaid.dna.fi";
char user[] = "";
char pass[] = "";
//NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN

//NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
//GSM Module RX pin to ESP32 2
//GSM Module TX pin to ESP32 4
#define rxPin 0
#define txPin 1
HardwareSerial sim800(1);
TinyGsm modem(sim800);
//NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN

//NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
TinyGsmClientSecure gsm_client_secure_modem(modem, 0);
//NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
void loop(){
 if (sim800.available())
 Serial.write(sim800.read());

 if (Serial.available()) {
 while(Serial.available()){
 sim800.write(Serial.read());
 }
 sim800.println();
 }
}

//**************************************************************************************************
void setup() {
  Serial.begin(115200);
  Serial.println("esp32 serial initialize");
  
  sim800.begin(9600, SERIAL_8N1, rxPin, txPin);
  Serial.println("SIM800L serial initialize");

 
  //NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
  //Restart takes quite some time
  //To skip it, call init() instead of restart()
  Serial.println("Initializing modem...");
  modem.restart();
  String modemInfo = modem.getModemInfo();
  Serial.print("Modem: ");
  Serial.println(modemInfo);  // not displaying
}

