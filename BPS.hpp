
//  BPS.hpp
//  Sunstang 2018 BPS

#ifndef BPS_hpp
#define BPS_hpp

#include <stdio.h>
#include <Wire.h>
#include <LiquidCrystal.h>
#include <TimerOne.h>
#include <mcp_can.h>
#include <mcp_can_dfs.h>
#include <SPI.h>

#endif /* BPS_hpp */

using namespace std;

// CONSTANT BPS LIMITS - Set from Battery Datasheet
// TODO: Replace constants below with actual values
const float OVER_TEMPERATURE_DISCHARGE = 00;
const float OVER_TEMPERATURE_CHARGING = 00;

const float OVER_CURRENT_DISCHARGING = 00;
const float OVER_CURRENT_CHARGING = 00;

const float OVER_VOLTAGE = 00;
const float UNDER_VOLTAGE = 00;


//Battery Pack Status Codes
const int STATUS_CODE_SAFE_TO_USE = 0;

const int STATUS_CODE_OVERTEMPERATURE_DISCHARGING = 1;
const int STATUS_CODE_OVERTEMPERATURE_CHARGING = 2;
const int STATUS_CODE_OVERCURRENT_DISCHARGING = 3;
const int STATUS_CODE_OVERCURRENT_CHARGING = 4;
const int STATUS_CODE_OVERVOLTAGE = 5;
const int STATUS_CODE_UNDERVOLTAGE = 6;

const int STATUS_CODE_SOFTWARE_ERROR = 98; // If raised, likely bug in code (is this neccesary?)
const int STATUS_CODE_HARDWARE_ERROR = 99; //TODO: Maybe use a smaller number?


//GLOBAL VARIABLES
int CAN_STATUS;
int TEMP_SENSOR_NUMBER = 8; //Number of temperature sensor boards
const int PERIOD = 1000000; //10Hz

enum measurement {voltage, current, temperature};
enum CARSTATE {CAR_IDLE, CAR_ACTIVE};
enum BPS_STATUS {BPS_OFF, BPS_ACTIVE, BPS_TRIP};
enum CHARGING_STATUS {CHARGING, DISCHARGING};


class main_board {
public:
    //INITIALIZATION
    void init(){
        // Set BPS_STATUS to 0
        volatile BPS_STATUS bps_stat = BPS_OFF;
        CAN_STATUS = 0;
        volatile CARSTATE car_state = CAR_IDLE;
        Serial.println("Initializing BPS...");
        
        analogWrite(8, 123); //Set fan duty cycle to 50%
        
        Timer1.initialize(PERIOD);
        //Timer1.attachInterrupt(timerISR);
        Serial.begin(9600);
        Serial.println("Initializing CAN...");
        for (int i=0; i<5 && CAN_STATUS==0; i++) {
            
        }
    }
};



