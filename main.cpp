#include <iostream>
#include "SerialPort.hpp"
#include <stdio.h>
#include <string.h>

using namespace std;

char* portName = "\\\\.\\COM20";

#define MAX_DATA_LENGTH 255

char incomingData[MAX_DATA_LENGTH];

char ledON[] = "ON\n";
char ledOFF[] = "OFF\n";

SerialPort *arduino;

const unsigned int BLINKING_DELAY = 1000;

#define SEND

void exampleReceiveData(void)
{
    int readResult = arduino->readSerialPort(incomingData, MAX_DATA_LENGTH);
    printf("%s", incomingData);
    Sleep(10);
}

void exampleWriteData(unsigned int delayTime)
{
    arduino->writeSerialPort(ledON, MAX_DATA_LENGTH);
    Sleep(delayTime);
    arduino->writeSerialPort(ledOFF, MAX_DATA_LENGTH);
    Sleep(delayTime);
}

void autoConnect(void)
{
  
    while(1) {
        
        std::cout << "Searching in progress";
       
        while (!arduino->isConnected()) {
            Sleep(100);
            std::cout << ".";
            arduino = new SerialPort(portName);
        }

        if (arduino->isConnected()) {
            std::cout  << std::endl << "Connection established at port " << portName << std::endl;
        }

        #ifdef SEND
            while(arduino->isConnected()) exampleWriteData(BLINKING_DELAY);
        #else // SEND
            while(arduino->isConnected()) exampleReceiveData();
        #endif // SEND
    }
}

int main()
{
    arduino = new SerialPort(portName);

    autoConnect();   
}
