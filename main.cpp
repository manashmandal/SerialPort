#include <iostream>
#include "SerialPort.h"
#include <stdio.h>
#include <string.h>
#include <tchar.h>


using namespace std;

int main()
{
    SerialPort *arduino = new SerialPort("\\\\.\\COM20");
    cout << arduino->isConnected() << endl;

    int dataLength = 255;
    char incomingData[dataLength];
    int readResult = 0;
    while (arduino->isConnected()){
        readResult = arduino->readSerialPort(incomingData, dataLength);
        incomingData[readResult] = 0;
        printf("%s", incomingData);
        Sleep(10);
    }
}
