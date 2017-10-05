//
//  main.hpp
//  Sunstang 2018 BPS
//
//  Created by Justin Butler on 2017-08-20.
//  Copyright © 2017 Justin Butler. All rights reserved.
//

#ifndef main_hpp
#define main_hpp

#include <stdio.h>
#include <TimerOne.h>
#include <Wire.h>

#endif /* main_hpp */

using namespace std;

// CONSTANT DECLARATIONS
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

const int STATUS_CODE_SOFTWARE_ERROR = 98; // If raised, likely bug in code
const int STATUS_CODE_HARDWARE_ERROR = 99; //TODO: Maybe use a smaller number?


//GLOBAL VARIABLES
int BPS_STATUS; //0 on startup, 1 when activated, 9 on BPS trip
int TEMP_SENSOR_NUMBER = 8; //Number of temperature sensor boards
const int PERIOD = 1000000; //10Hz

volatile boolean task_flag = false;
enum measurement {voltage, current, temperature};
enum CARSTATE {CAR_IDLE, CAR_ACTIVE};

// BOARD INITIALIZATION
class StartUp {
public:
    void wait_on_startup(){ //Initial function call, will handle all initialization and set BPS_STATUS to 1
        // Set BPS_STATUS to 0
        BPS_STATUS = 0;
        volatile CARSTATE car_state = CAR_IDLE;
        Serial.println("Initializing BPS...");
        
        
        while (BPS_STATUS != 1) {
            init_master();
            
        }
    };
    
    void init_master(){
        analogWrite(8, 123); //Set fan duty cycle to 50%
        
        Timer1.initialize(PERIOD);
        
        Serial.begin(9600);
        //Wire.begin(); TODO: Uncomment
        
    };
    
    void init_temp(){
        Serial.begin(9600);
    };
    
    void init_current(){
        
    };
    
    void init_can(){
        
    };
};

//CLASS DEFINITIONS
// Use a class to handle sensor measurements for temperature, current and voltage
// Will read sensor measurements in voltage and convert to final values
class Sensor {
    double adc_value;
    double final_value;
    int sensor_address;
    char type; // Will dictate if measurement is temp, current or volt.
    
private:
    
    
    double calculate_final_value(){
        if (type == temperature){
            // Calculate temperature from thermistor value
            //TODO: Add temp. calculations
            final_value = 0;}
        else if (type == current){
            // Calculate the current from the current sensor
            //TODO: Add current calculations
            final_value = 0;}
        else if (type == voltage){
            // Calculate the voltage
            //TODO: Add voltage calculations
            final_value = 0;}
        else{
            
            return BPS_STATUS = STATUS_CODE_SOFTWARE_ERROR;}
        
        return final_value;
    }
    
public:
    Sensor(measurement type, int); //Constructor
    
    double read_sensor(){
        return adc_value;
    }
    
};

//Sensor class constructor. Sets sensor address ID on initialization
Sensor::Sensor(enum measurement measurement, int id){
    sensor_address = id;
    type = measurement;
}

//TASK HANDLING
class Tasks {
    
public:
    void timerISR(){
        task_flag = true;
    }
    
    void WaitForFlag(){
        while (task_flag == false);
        task_flag = false; //resets flag after interrupt is finished
    }
    
    void Task_CheckVoltage(){
    
    }
    
    void Task_CheckTemp(){
    
    }
    
    void Task_CheckCurrent(){

    }
    
    void Task_UpdateLCD(){
        
    }
    
    void Task_SendCAN(){
        
    }
};

// ERROR HANDLING


