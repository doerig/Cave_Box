#include "RhTempSensorAht20.h"

RhTempSensorAht20::RhTempSensorAht20(int ahtSdaPin, int ahtSclPin) : ahtSdaPin(ahtSdaPin), ahtSclPin(ahtSclPin)
{
}

RhTempSensorAht20::~RhTempSensorAht20()
{
}

void RhTempSensorAht20::setup()
{
    I2CAHT.begin(ahtSdaPin, ahtSclPin);
    aht.begin(&I2CAHT);
}

RhTempData RhTempSensorAht20::getSensorData()
{
    sensors_event_t humidity, temp;
    aht.getEvent(&humidity, &temp);
    RhTempData rhTempData;
    rhTempData.relativeHumidity = humidity.relative_humidity;
    rhTempData.temperature = temp.temperature;
    return rhTempData;
}