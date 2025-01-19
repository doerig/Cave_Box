#ifndef RHTEMPSENSORDHT_H
#define RHTEMPSENSORDHT_H

#include "RhTempSensor.h"
#include <DHT.h>

class RhTempSensorDht : public RhTempSensor {
private:
    int ahtSdaPin;
    int ahtSclPin;
    DHT dht;
public:
    RhTempSensorDht(int dhtPin);
    ~RhTempSensorDht() override;
    void setup() override;
    RhTempData getSensorData() override;
};

#endif /* RHTEMPSENSORDHT_H */