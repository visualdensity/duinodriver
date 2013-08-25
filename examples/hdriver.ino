#include <DuinoDriver.h>

DuinoDriver driver;
HDriver sideA;
HDriver sideB;

void setup()
{
    Serial.begin(9600);

    sideA.enablePin = 2;
    sideA.inputA = 3;
    sideA.inputB = 4;
    sideA.speed = 50;
    
    sideB.enablePin = 7;
    sideB.inputA = 5;
    sideB.inputB = 6;
    sideB.speed = 50;

    driver.setSideA(sideA);
    driver.setSideB(sideB);
}

void loop()
{
    char command = 0;
    
    if (Serial.available() > 0) {
                command = Serial.read();

                Serial.print("Received: ");
                Serial.println(command);
                
                if( command == 'w' ) {
                    driver.motorsOn();
                    driver.forward();
                }

                if( command == 's' ) {
                    driver.motorsOn();
                    driver.reverse();
                }

                if( command == 'a' ) {
                    driver.motorsOn();
                    driver.left();
                }

                if( command == 'd' ) {
                    driver.motorsOn();
                    driver.right();
                }

                if( command == 'x' ) {
                    driver.motorsOff();
                }
     }

     delay(150);
}
