#ifndef MAIN_H
#define MAIN_H

void changeRHSetpoint(double newSetPoint);
void setFAEInterval();
void initController();
int updateDHT();
void outputPID();
void updateLED();
void checkHumidityAcheivable();
void fanControl();
void fanErrorState();
void increaseRH();
void decreaseRH();
void RHErrorState();

#endif /*MAIN_H*/