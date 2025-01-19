#include "RhTempSensorDht.h"

RhTempSensorDht::RhTempSensorDht(int dhtPin) : dht(dhtPin, DHT22)
{
}

RhTempSensorDht::~RhTempSensorDht()
{
}

void RhTempSensorDht::setup()
{
    dht.begin();
}

RhTempData RhTempSensorDht::getSensorData()
{
    RhTempData rhTempData;
    rhTempData.relativeHumidity = dht.readHumidity();
    rhTempData.temperature = dht.readTemperature();
    return rhTempData;
}