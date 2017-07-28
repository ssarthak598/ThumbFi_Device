//
//  Demo code for FPC1020 Fingerprint Sensor
//  Created by Deray on 2015-10-07.
//

#include <SoftwareSerial.h>
#include <VirtualWire.h>
#include <FPC1020.h>

extern unsigned char l_ucFPID;
extern unsigned char rBuf[192];  //Receive return data
#define sw_serial_rx_pin 2 //  Connect this pin to TX on the FPC1020
#define sw_serial_tx_pin 3 //  Connect this pin to RX on the FPC1020
char *controller;
SoftwareSerial swSerial(sw_serial_rx_pin, sw_serial_tx_pin); // Fingerprint serial (RX, TX)
FPC1020 Finger(&swSerial);

void setup(){
    Serial.begin(9600);
    pinMode(4, INPUT); // IRQ
    pinMode(13, OUTPUT);
vw_set_ptt_inverted(true); //
vw_set_tx_pin(12);
vw_setup(2000);
    Serial.println("Hi");
}

void loop(){

             if( Finger.Search()){
             
             Serial.println( l_ucFPID, DEC);
              controller="3";
vw_send((uint8_t *)controller, strlen(controller));
vw_wait_tx();
             digitalWrite(13,HIGH);
             delay(50);
             digitalWrite(13,LOW);        
             }
             
             else {
               Serial.println("F");
             }                 
          //   delay(1000);
             
 
}
