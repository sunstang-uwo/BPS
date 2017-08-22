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
#include "string"

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
int BPS_STATUS = 0;


//CLASS DEFINITIONS
// Use a class to handle sensor measurements for temperature, current and voltage
// Will read sensor measurements in voltage and convert to final values
class Sensor {
    double volt_val;
    double final_val;
    int sensor_address;
    string type; // Will dictate if measurement is temp, current or volt.
    
private:
    double read_sensor(){
        
        return volt_val;
    }
    
    double calculate_final_value(){
        if (type == "Temperature"){
            // Calculate temperature from thermistor value
            //TODO: Add temp. calculations
            final_val = 0;}
        else if (type == "Current"){
            // Calculate the current from the current sensor
            //TODO: Add current calculations
            final_val = 0;}
        else if (type == "Voltage"){
            // Calculate the voltage
            //TODO: Add voltage calculations
            final_val = 0;}
        else{
            
            return BPS_STATUS = STATUS_CODE_SOFTWARE_ERROR;}
        
        return final_val;
    }
    
public:
    Sensor(int, string); //Constructor
};

//Sensor class constructor. Sets sensor address ID on initialization
Sensor::Sensor(int id, string measurement){
    sensor_address = id;
    type = measurement;
    
}

// BOARD INITIALIZATION
// All sensor boards will be intitialized from the main board
class I2C {
    int id;
    
public:
    
};

// ERROR HANDLING


