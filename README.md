##Setup instructions##
- Board: ESP32-C3 Supermini + SIM800L V1
- Power: Li-ion 18650, 3.7v

##Wiring##
1. Connect SIM800l VCC to Li-ion 18650 "+"
2. Connect SIM800l GND to Li-ion 18650 "-"
3. Connect C3 0 to SIM800l RXD
4. Connect C3 1 to SIM800l TXD
5. Connect C3 GND to Sim800l Li-ion 18650 "-"
6. Connect C3 to PC Via USB = Monitoring & Commands

7. NOTE: Do not connect 5V into C3 while connected via USB (debug & Upload)

##Registering SIM800l to network#

1. AT+CREG=1
2. AT+SAPBR=3,1,"CONTYPE","GPRS"
3. AT+SAPBR=3,1,"APN","APN-address" //replace APN-address based on your ISP
4. AT+SAPBR=1,1
5. AT+CREG? (+CREG: 1,1 // 1,1 means that SIM800l is connected into your "home network".)

If SIM800l led blinks two times per second = Connected
