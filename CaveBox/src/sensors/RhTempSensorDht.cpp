#include "IRhTempSensor.h"
#include <DHT.h>

class RhTempSensorDht : IRhTempSensor {
private:
    int ahtSdaPin;
    int ahtSclPin;
    DHT dht;
public:
    RhTempSensorDht(int dhtPin) : dht(dhtPin, DHT22)
    {
    }

    ~RhTempSensorDht() override
    {
    }

    void setup() override
    {
        dht.begin();
    }

    RhTempData getSensorData() override
    {
        RhTempData rhTempData;
        rhTempData.relativeHumidity = dht.readHumidity();
        rhTempData.temperature = dht.readTemperature();
        return rhTempData;
    }
};