#include "IRhTempSensor.h"
#include <Arduino.h>
#include <Adafruit_SHT31.h>

class RhTempSensorSht31 : IRhTempSensor {
private:
    int ahtSdaPin;
    int ahtSclPin;
    TwoWire I2CAHT = TwoWire(1); // Use 2nd i2c interface for sensor.;
    Adafruit_SHT31 sht = Adafruit_SHT31(&I2CAHT);
public:
    RhTempSensorSht31(int ahtSdaPin, int ahtSclPin)
    {
        this->ahtSdaPin = ahtSdaPin;
        this->ahtSclPin = ahtSclPin;
    }

    ~RhTempSensorSht31() override
    {
    }

    void setup() override
    {
        I2CAHT.begin(ahtSdaPin, ahtSclPin, 100000);

        if (!sht.begin(0x44)) // Set to 0x45 for alternate i2c addr
        {
            Serial.println("Could not find SHT31? Check wiring");
        }
    }

    RhTempData getSensorData() override
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
};