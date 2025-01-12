#include "IRhTempSensor.h"
#include <Arduino.h>
#include <Adafruit_AHTX0.h>

class RhTempSensorAht20 : IRhTempSensor {
private:
    int ahtSdaPin;
    int ahtSclPin;
    Adafruit_AHTX0 aht;
    TwoWire I2CAHT = TwoWire(1); // Use 2nd i2c interface for sensor.;
public:
    RhTempSensorAht20(int ahtSdaPin, int ahtSclPin)
    {
        this->ahtSdaPin = ahtSdaPin;
        this->ahtSclPin = ahtSclPin;
    }

    ~RhTempSensorAht20() override
    {
    }

    void setup() override
    {
        I2CAHT.begin(ahtSdaPin, ahtSclPin, 100000);

        if (!aht.begin(&I2CAHT))
        {
            Serial.println("Could not find AHT? Check wiring");
        }
    }

    RhTempData getSensorData() override
    {
        sensors_event_t humidity;
        sensors_event_t temp;
        aht.getEvent(&humidity, &temp);

        RhTempData rhTempData;
        rhTempData.relativeHumidity = humidity.relative_humidity;
        rhTempData.temperature = temp.temperature;
        return rhTempData;
    }
};