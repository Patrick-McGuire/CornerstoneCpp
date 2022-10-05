#ifndef ARDUINOSERIAL_ARDUINOINTERFACE_H
#define ARDUINOSERIAL_ARDUINOINTERFACE_H

#include "string"




/**
 * Serial LIB
 */


#define ARDUINO_WAIT_TIME 2000

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

class Serial {
public:
    //Serial comm handler
    HANDLE hSerial;
    //Connection status
    bool connected;
    //Get various information about the connection
    COMSTAT status;
    //Keep track of last error
    DWORD errors;

public:
    //Initialize Serial communication with the given COM port
    explicit Serial(const char *portName);

    //Close the connection
    ~Serial();

    int Available() const {
        LPDWORD aaD;
        LPCOMSTAT aD;
        return ClearCommError(hSerial, aaD, aD);
    }

    //Read data in a buffer, if nbChar is greater than the
    //maximum number of bytes available, it will return only the
    //bytes available. The function return -1 when nothing could
    //be read, the number of bytes actually read.
    int ReadData(char *buffer, unsigned int nbChar);

    /**
     * Generally a non-blocking read function that checks if there is data available before attempting to read
     * @param buffer
     * @param nbChar
     * @return
     */
    int ReadNonblock(char *buffer, unsigned int nbChar) {
        return Available() ? ReadData(buffer, nbChar) : 0;
    };

    //Writes data from a buffer through the Serial connection
    //return true on success.
    bool WriteData(const char *buffer, unsigned int nbChar);

    //Check if we are actually connected
    bool IsConnected();
};

Serial::Serial(const char *portName) {
    //We're not yet connected
    this->connected = false;

    //Try to connect to the given port throuh CreateFile
    this->hSerial = CreateFile(portName,
                               GENERIC_READ | GENERIC_WRITE,
                               0,
                               NULL,
                               OPEN_EXISTING,
                               FILE_ATTRIBUTE_NORMAL,
                               NULL);

    //Check if the connection was successfull
    if (this->hSerial == INVALID_HANDLE_VALUE) {
        //If not success full display an Error
        if (GetLastError() == ERROR_FILE_NOT_FOUND) {

            //Print Error if neccessary
            printf("ERROR: Handle was not attached. Reason: %s not available.\n", portName);

        } else {
            printf("ERROR!!!");
        }
    } else {
        //If connected we try to set the comm parameters
        DCB dcbSerialParams = {0};

        //Try to get the current
        if (!GetCommState(this->hSerial, &dcbSerialParams)) {
            //If impossible, show an error
            printf("failed to get current m_serial parameters!\n");
        } else {
            //Define m_serial connection parameters for the arduino board
            dcbSerialParams.BaudRate = CBR_9600;
            dcbSerialParams.ByteSize = 8;
            dcbSerialParams.StopBits = ONESTOPBIT;
            dcbSerialParams.Parity = NOPARITY;
            //Setting the DTR to Control_Enable ensures that the Arduino is properly
            //reset upon establishing a connection
            dcbSerialParams.fDtrControl = DTR_CONTROL_ENABLE;

            //Set the parameters and check for their proper application
            if (!SetCommState(hSerial, &dcbSerialParams)) {
                printf("ALERT: Could not set Serial Port parameters\n");
            } else {
                //If everything went fine we're connected
                this->connected = true;
                //Flush any remaining characters in the buffers
                PurgeComm(this->hSerial, PURGE_RXCLEAR | PURGE_TXCLEAR);
                //We wait 2s as the arduino board will be reseting
                Sleep(ARDUINO_WAIT_TIME);
            }
        }
    }

}

Serial::~Serial() {
    //Check if we are connected before trying to disconnect
    if (this->connected) {
        //We're no longer connected
        this->connected = false;
        //Close the m_serial handler
        CloseHandle(this->hSerial);
    }
}

int Serial::ReadData(char *buffer, unsigned int nbChar) {
    //Number of bytes we'll have read
    DWORD bytesRead;
    //Number of bytes we'll really ask to read
    unsigned int toRead;

    //Use the ClearCommError function to get status info on the Serial port
    ClearCommError(this->hSerial, &this->errors, &this->status);

    //Check if there is something to read
    if (this->status.cbInQue > 0) {
        //If there is we check if there is enough data to read the required number
        //of characters, if not we'll read only the available characters to prevent
        //locking of the application.
        if (this->status.cbInQue > nbChar) {
            toRead = nbChar;
        } else {
            toRead = this->status.cbInQue;
        }

        //Try to read the require number of chars, and return the number of read bytes on success
        if (ReadFile(this->hSerial, buffer, toRead, &bytesRead, NULL)) {
            return bytesRead;
        }

    }

    //If nothing has been read, or that an error was detected return 0
    return 0;

}


bool Serial::WriteData(const char *buffer, unsigned int nbChar) {
    DWORD bytesSend;

    //Try to write the buffer on the Serial port
    if (!WriteFile(this->hSerial, (void *) buffer, nbChar, &bytesSend, 0)) {
        //In case it don't work get comm error and return false
        ClearCommError(this->hSerial, &this->errors, &this->status);

        return false;
    } else
        return true;
}

bool Serial::IsConnected() {
    //Simply return the connection status
    return this->connected;
}


class Arduino {
public:
    static const int m_bufSize = 2048;
    char m_buf[m_bufSize] = "";       // Overkill
    Serial *m_serial;
public:

    explicit Arduino(const char *port) {
        std::string portStr = R"(\\.\)" + std::string(port);
        m_serial = new Serial(portStr.c_str());
    }



    int available() const {
        return m_serial->Available();
    }

    std::string read() {
        memset(m_buf, 0, m_bufSize);
        std::cout << m_serial->ReadNonblock(m_buf, m_bufSize - 1) << "\n";
        return m_buf;
    }

    void write(const std::string &msg) const {
        m_serial->WriteData(msg.c_str(), msg.length());
    }

};

#endif //ARDUINOSERIAL_ARDUINOINTERFACE_H
