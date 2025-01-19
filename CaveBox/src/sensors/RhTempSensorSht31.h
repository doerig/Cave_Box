#ifndef RHTEMPSENSORSHT31_H
#define RHTEMPSENSORSHT31_H

#include "RhTempSensor.h"
#include <Adafruit_SHT31.h>

class RhTempSensorSht31 : public RhTempSensor {
private:
    int ahtSdaPin;
    int ahtSclPin;
    TwoWire I2CAHT = TwoWire(1); // Use 2nd i2c interface for sensor.
    Adafruit_SHT31 sht = Adafruit_SHT31(&I2CAHT);
public:
    RhTempSensorSht31(int ahtSdaPin, int ahtSclPin);
    ~RhTempSensorSht31() override;
    void setup() override;
    RhTempData getSensorData() override;
};

#endif /* RHTEMPSENSORSHT31_H */