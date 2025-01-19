#include "RhTempSensorSht31.h"

RhTempSensorSht31::RhTempSensorSht31(int ahtSdaPin, int ahtSclPin) : ahtSdaPin(ahtSdaPin), ahtSclPin(ahtSclPin)
{
}

RhTempSensorSht31::~RhTempSensorSht31()
{
}

void RhTempSensorSht31::setup()
{
    I2CAHT.begin(ahtSdaPin, ahtSclPin, 100000);

    if (!sht.begin(0x44))
    {
        Serial.println("Could not find SHT31? Check wiring");
    }
}

RhTempData RhTempSensorSht31::getSensorData()
{
    float humidity;
    float temp;
    sht.readBoth(&temp, &humidity);

    RhTempData rhTempData;
    rhTempData.relativeHumidity = humidity;
    rhTempData.temperature = temp;
    return rhTempData;

    /* TODO: Try to use heater to prevent sensor drift in high humidity environments
    // Toggle heater enabled state every 30 seconds
    // An ~3.0 degC temperature increase can be noted when heater is enabled
    if (loopCnt >= 30) {
        enableHeater = !enableHeater;
        sht31.heater(enableHeater);
        Serial.print("Heater Enabled State: ");
        if (sht31.isHeaterEnabled())
        Serial.println("ENABLED");
        else
        Serial.println("DISABLED");
    */
}
