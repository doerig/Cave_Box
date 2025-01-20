#ifndef RHTEMPSENSOR_H
#define RHTEMPSENSOR_H

struct RhTempData {
    double temperature;
    double relativeHumidity;
};

class RhTempSensor {
public: 
    virtual void setup() = 0;
    virtual RhTempData getSensorData() = 0;
    virtual ~RhTempSensor() {}
};

#endif /*RHTEMPSENSOR_H*/