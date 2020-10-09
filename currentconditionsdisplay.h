#ifndef CURRENTCONDITIONSDISPLAY_H
#define CURRENTCONDITIONSDISPLAY_H

#include "observer.h"
#include "displayelement.h"
#include "subject.h"
#include <QWidget>

class CurrentConditionsDisplay : public Observer, public DisplayElement, public QWidget
{
private:
    float temperature;
    float humidity;
    Subject *weatherData;
    QLabel *temp;
    QLabel *hum;
    QLabel *press;
public:
    CurrentConditionsDisplay(Subject *weatherData);
    void update(float temperature, float humidity, float pressure);
    void display();
};

#endif // CURRENTCONDITIONSDISPLAY_H
