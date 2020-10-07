#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include "subject.h"
#include <QList>

class WeatherData : public Subject
{
private:
    QList<Observer*> *observers;
    float temperature;
    float humidity;
    float pressure;
public:
    WeatherData();
    void registerObserver(Observer *o);
    void removeObserver(Observer *o);
    void notifyObserver();
    void setMeasurementsChanged(float temp, float humidity, float pressure);
    void measurementsChanged();
};

#endif // WEATHERDATA_H
