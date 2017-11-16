# BPS
SunStang's 2018 Battery Protection System
Designed for the team's first cruiser style vehicle

The main board is controlled by a custom Arduino Mega and receives current and temperature sensor measurements in the form of voltages. This will reduce the amount of coding and hardware required compared to previous BPS' systems using multiple Arduino Nanos.

Currently the pin out has not been designed yet, but below is a rough idea of the pins that will be required:
- 2 pins for I2C for temp/current boards
- MISO/MOSI/SCK for voltage board SPI and CAN
- 1 pin for slave select (SS) for voltage board (digital)
- 1 pin for the fan pwm (digital)
- 1 pin for CAN SS (digital)
- 1-3? pins for LCD SS (digital)
- 3 pins for relays (digital)


The main board handles the following tasks:
- Initialize CAN to communicate with telemetry (Uses the MCP2515/MCP2551 chips & mcp_can.h)
- Send out voltage/current/temperature values on CAN to telemetry at ??? rate
- Activate the pack fans (@ 50% duty cycle?)
- Initially read the current, voltage and temperature on start-up before activating the main batteries
- Read the current sensor value from I2C
- Read the temperature board from I2C
- Read the voltage board values using SPI (Using LT DC1894 & DC1941 dev boards) (Pins ???)
- Activate the relays to turn on/off the array, motor and car based on BPS status and voltage/current levels
- Shut down the car when BPS faults occur
- Initialize and update the battery box/driver display LCD (Could have individual LCD in battery box for current, temp and voltage )
- Update the LCD display with BPS status and current/voltage/temp values
- Read voltage/temp/current at rate of ???
- Handles reading all neccesary measurements using interrupt task handling???
-
