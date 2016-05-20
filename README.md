# SerialPort

## C++ Library for Serial Communication with following criteria

* Plain C++ Compatible
* Windows Supported
* Include and Run Type Library


## Documentation

### Initialization
```cpp
#include "SerialPort.h"
#include <iostream>

char* portName = "\\\\.\\COM20";

//Declare a global object
SerialPort *arduino;

int main(void)
{
  arduino = new SerialPort(portName);
  std::cout << "is connected: " << arduino->isConnected() << std::endl;
}
```

