#ifndef CURRENTCONDITIONSDISPLAY_H
#define CURRENTCONDITIONSDISPLAY_H

#include "observer.h"
#include "displayelement.h"
#include "subject.h"

class CurrentConditionsDisplay : public Observer, public DisplayElement
{
private:
    float temperature;
    float humidity;
    Subject *weatherData;
public:
    CurrentConditionsDisplay(Subject *weatherData);
    void update(float temperature, float humidity, float pressure);
    void display();
};

#endif // CURRENTCONDITIONSDISPLAY_H
