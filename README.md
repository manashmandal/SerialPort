# SerialPort

## C++ Library for Serial Communication with following criteria

*  Plain C++ Compatible
*  Windows Supported
*  Include and Run Type Library
*  supports softwareserial
*  supports serial event
*  fixed minor bugs

## Documentation
[Here is a blog post about the library](https://medium.com/@ManashMandal/serial-communication-with-an-arduino-using-c-on-windows-d08710186498#.f94efw74b)

### Initialization
```cpp
#include "SerialPort.hpp"
#include <iostream>

const char *portName = "\\\\.\\COM20";

//Declare a global object
SerialPort *arduino;

int main(void)
{
  arduino = new SerialPort(portName);
  std::cout << "Is connected: " << arduino->isConnected() << std::endl;
}
```

### Sending Data
```cpp
#define DATA_LENGTH 255

#include "SerialPort.hpp"
#include <iostream>

const char *portName = "\\\\.\\COM20";

//Declare a global object
SerialPort *arduino;

//Here '\n' is a delimiter 
const char *sendString = "Hello World\n"; 

int main(void)
{
  arduino = new SerialPort(portName);
  if (arduino->isConnected()){
    bool hasWritten = arduino->writeSerialPort(sendString, DATA_LENGTH);
    if (hasWritten) std::cout << "Data Written Successfully" << std::endl;
    else std::cerr << "Data was not written" << std::endl;
  }
}
```

### Receiving Data
```cpp
#define DATA_LENGTH 255

#include "SerialPort.hpp"
#include <iostream>

const char *portName = "\\\\.\\COM20";

//Declare a global object
SerialPort *arduino;

char receivedString[DATA_LENGTH];

int main(void)
{
  arduino = new SerialPort(portName);
  if (arduino->isConnected()){
    int hasRead = arduino->readSerialPort(receivedString, DATA_LENGTH);
    if (hasRead) std::cout <<  receivedString << "\n";
    else std::cerr << "Error occured reading data" << "\n";
  }
}
```
