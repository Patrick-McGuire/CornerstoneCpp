#include <stdio.h>
#include <tchar.h>
#include "ArduinoInterface.h"    // Library described above
#include <string>
#include <iostream>

// application reads from the specified m_serial port and reports the collected data
int main(int argc, _TCHAR *argv[]) {
    Arduino arduino("COM35");
    std::cout << arduino.m_serial->IsConnected() << "\n";
    std::string arduinoMessage;
    while (arduinoMessage != "bruh") {
        arduinoMessage = arduino.read();
//        if(arduinoMessage.length() > 0) {
//            std::cout << arduinoMessage << std::endl;
//        }
    }
    return 0;

//    printf("Welcome to the m_serial test app!\n\n");
//
//    Serial* SP = new Serial(R"(\\.\COM35)");    // adjust as needed
//
//    if (SP->IsConnected())
//        printf("We're connected");
//
//    char incomingData[256] = "";			// don't forget to pre-allocate memory
//    //printf("%s\n",incomingData);
//    int dataLength = 255;
//    int readResult = 0;
//
//    while(SP->IsConnected())
//    {
////        LPDWORD aaD;
////        LPCOMSTAT aD;
//////        int a = ClearCommError(SP->hSerial, aaD, aD);
//////        std::cout << a << "\n";
//
////        if(ClearCommError(SP->hSerial, aaD, aD) != 0) {
//            readResult = SP->ReadData(incomingData, dataLength);
//            // printf("Bytes read: (0 means no data available) %i\n",readResult);
//            incomingData[readResult] = 0;
//
//            printf("%s", incomingData);
////        }
//        Sleep(1000);
//        printf("afds\n");
//    }
//    return 0;
}
