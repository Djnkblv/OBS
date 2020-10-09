#include <QApplication>
#include "weatherdata.h"
#include "currentconditionsdisplay.h"
#include <QThread>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    WeatherData *weatherData = new WeatherData();

    CurrentConditionsDisplay *current = new CurrentConditionsDisplay(weatherData);
    current->show();


    weatherData->setMeasurementsChanged(80, 65, 30.4);
    weatherData->setMeasurementsChanged(85, 61, 28.2);

    return a.exec();
}
