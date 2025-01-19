#ifndef RHTEMPSENSORAHT20_H
#define RHTEMPSENSORAHT20_H

#include "RhTempSensor.h"
#include <Adafruit_AHTX0.h>

class RhTempSensorAht20 : public RhTempSensor {
private:
    int ahtSdaPin;
    int ahtSclPin;
    Adafruit_AHTX0 aht;
    TwoWire I2CAHT = TwoWire(1); // Use 2nd i2c interface for sensor.
public:
    RhTempSensorAht20(int ahtSdaPin, int ahtSclPin);
    ~RhTempSensorAht20() override;
    void setup() override;
    RhTempData getSensorData() override;
};

#endif /* RHTEMPSENSORAHT20_H */