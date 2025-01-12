#ifndef IRHTEMPSENSOR_H
#define IRHTEMPSENSOR_H

struct RhTempData {
    double temperature;
    double relativeHumidity;
};

class IRhTempSensor {
public: 
    virtual void setup() = 0;
    virtual RhTempData getSensorData() = 0;
    virtual ~IRhTempSensor() {}
};

#endif /*IRHTEMPSENSOR_H*/