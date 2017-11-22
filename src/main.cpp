#include <Arduino.h>
#include <Wire.h>
#include <stdlib.h>
#include <USBAPI.h>
#include <SPI.h>
#include <HardwareSerial.h>

int atexit(void (* /*func*/ )()) { return 0; }

// Weak empty variant initialization function.
// May be redefined by variant files.
void initVariant() __attribute__((weak));
void initVariant() { }

void setupUSB() __attribute__((weak));
void setupUSB() { }


int main() {
    init();

    initVariant();

#if defined(USBCON)
    USBDevice.attach();
#endif
    Serial.begin(9600);
    delay(1000);
    int i = 0;
    i++;
    while (i < 4) {
        Serial.println("v1");
        delay(1000);
        Serial.println("v2");
    }

    return 0;
}